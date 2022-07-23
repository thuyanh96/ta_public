/*
 * connect.h
 *
 *  Created on: May 2, 2021
 *      Author: qu
 */

#ifndef SRC_CORE_CONNECT_H_
#define SRC_CORE_CONNECT_H_

#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <core/php2cpp.h>

using namespace std;
sql::Driver *driver;
unique_ptr<sql::Connection> _con;
bool is_sql_connected = false;

//map::map<String, clause> core;
arr_slss_ts _dbc;
arr_sssl_ts _dbi;

mutex _db_m;
mutex _lock;
;

const arr_ls VALUEX_TABLES = { { 0, "gi" }, { 1, "gi_f" }, { 2, "go" }, { 3,
		"go_f" }, { 4, "rels" }, { 5, "rules" }, { 6, "rules_tmp" }, { 7,
		"rules_tmp_f" } };
const arr_ls ALL_TABLES = { { 0, "gi" }, { 1, "gi_f" }, { 2, "go" },
		{ 3, "go_f" }, { 4, "rels" }, { 5, "rules" }, { 6, "rules_tmp" }, { 7,
				"rules_tmp_f" }, { 8, "cmds" }, { 9, "new_defi" }, { 10,
				"new_vocal" }, { 11, "settings" } };
const arr_lls ALL_INDEXS = { { 0, { { 0, "new_vocal" }, { 1, "vocal_str" } } },
		{ 1, { { 0, "go" }, { 1, "c1" } } } };

void connect_sql() {
	try {
		driver = get_driver_instance();
		_con = unique_ptr<sql::Connection>(
				driver->connect("tcp://127.0.0.1:3306", "ta", "1234"));
		_con->setSchema("thuyanh");
		is_sql_connected = true;
	} catch (exception *e) {
		cout << "Cannot connect db...\n";
		exit(0);
	}
}
arr_ll find_table_name_pos_on_query_str(arr_ls _arr) {
	for (auto const& [_k, _v] : _arr) {
		_arr[_k] = strtolower(_v);
	}
	string _operation = _arr[0];
	string _find_after = "";
	if (_operation == "select")
		_find_after = "from";
	else if (_operation == "update")
		_find_after = "update";
	else if (_operation == "insert")
		_find_after = "into";
	else if (_operation == "delete")
		_find_after = "from";
	else if (_operation == "alter")
		_find_after = "table";
	else if (_operation == "drop")
		_find_after = "table";
	arr_ll _keys_of_table_name = array_keys_with_value(_arr, _find_after);
	for (unsigned long _i = 0; _i < _keys_of_table_name.size(); _i++) {
		_keys_of_table_name[_i]++;
	}
	return _keys_of_table_name;
}
string update_table_name_prefix_on_query_str(string _str, string _prefix =
		_db_prefix) {
	// $str = trim ( $str );
	arr_ls _arr = explode(" ", _str);
	arr_ll _pos_of_table_name = find_table_name_pos_on_query_str(_arr);
	for (auto const& [_k, _pos] : _pos_of_table_name) {
		if (strpos(_arr[_pos], "(") == -1)
			_arr[_pos] = _prefix + _arr[_pos];
	}
	return implode(" ", _arr);
}
//void get_mysql_columns() {
//	if (!is_sql_connected)
//		connect_sql();
//	unique_ptr<sql::Statement> _stmt = unique_ptr<sql::Statement>(
//			_con->createStatement());
//	unique_ptr<sql::ResultSet> _res;
//	unique_ptr<sql::Statement> _stmt = unique_ptr<sql::Statement>(
//			_con->createStatement());
//	unique_ptr<sql::ResultSet> _res;
//}
string get_1st_table_name_from_query(string _query) {
	arr_ls _words_arr = explode(" ", _query);
	arr_ll _keys_of_table_name = find_table_name_pos_on_query_str(_words_arr);
	//string _table_name;
	long _tmp_v = -1;
	for (auto const& [_k, _v] : _keys_of_table_name) {
		if (strpos(_words_arr[_v], "(") > 0)
			continue;
		_tmp_v = _v;
	}
	if (_tmp_v == -1)
		throw("cannot detect table name");
	return _words_arr[_tmp_v];
}
arr_lss dbsr(string _query, bool _echo_query = false, bool _add_linit = false) {
	_db_m.lock();
	double _dbt0 = microtime(true);
	_query = update_table_name_prefix_on_query_str(_query);
	if (!is_sql_connected)
		connect_sql();
	unique_ptr<sql::Statement> _stmt = unique_ptr<sql::Statement>(
			_con->createStatement());
	unique_ptr<sql::ResultSet> _res;
	sql::ResultSetMetaData *_res_meta;
	try {

		map<long, map<string, string>> _returnx;
		vector<string> _columns_name;
		_res = unique_ptr<sql::ResultSet>(_stmt->executeQuery(_query));
		_res_meta = _res->getMetaData();
		bool _result_has_id_col = false;
		long _columns_count = _res_meta->getColumnCount();
		for (long _j = 1; _j <= _columns_count; _j++) {
			string _column_name = _res_meta->getColumnLabel(_j);
			if (_column_name == "id") {
				_result_has_id_col = true;
				break;
			}
		}
		if (_result_has_id_col) {
			while (_res->next()) {
				long _id = _res->getInt64("id");
				map<string, string> _tmp_map;
				for (long _j = 1; _j <= _columns_count; _j++) {
					string _column_name = _res_meta->getColumnLabel(_j);
					try {
						string _value = _res->getString(_column_name);
						_returnx[_id][_column_name] = _value;
					} catch (...) {
						;
					}
				}
				//_index++;
			}
		} else {
			long _index = 0;
			while (_res->next()) {
				//long _id = _res->getInt64("id");
				map<string, string> _tmp_map;
				for (long _j = 1; _j <= _columns_count; _j++) {
					string _column_name = _res_meta->getColumnLabel(_j);
					try {
						string _value = _res->getString(_column_name);
						_returnx[_index][_column_name] = _value;
					} catch (...) {
						;
					}
				}
				_index++;
			}
		} //delete _res_meta;
//		delete _res;
//		delete _stmt;
		_db_m.unlock();
		_dbt += microtime(true) - _dbt0;
		return _returnx;
	} catch (...) {
//		delete _res;
		//delete _stmt;
		//delete _res_meta;
		_db_m.unlock();
		_dbt += microtime(true) - _dbt0;
		return map<long, map<string, string>> { };
	}
}
long dbqr(string _query, bool _echo_query = false, bool _1 = false) {
	//long return;
	_db_m.lock();
	double _dbt0 = microtime(true);
	_query = update_table_name_prefix_on_query_str(_query);
	if (stripos(_query, "select") >= 0) {
		_db_m.unlock();
		throw 41;
	}
	if (!is_sql_connected)
		connect_sql();
	unique_ptr<sql::Statement> _stmt = unique_ptr<sql::Statement>(
			_con->createStatement());
	unique_ptr<sql::ResultSet> _res;
	try {
		_res = unique_ptr<sql::ResultSet>(_stmt->executeQuery(_query));
//		delete _res;
//		delete _stmt;
		_db_m.unlock();
		return 1;
	} catch (sql::SQLException &_e) {
//		delete _res;
//		delete _stmt;
//		string _str(_e.what());
		if (_e.getErrorCode() == 0) {
			_db_m.unlock();
			return 1;
		}
		echo("SQL Error:" + ts((long) _e.getErrorCode()) + "\n");
		_db_m.unlock();
		_dbt += microtime(true) - _dbt0;
		return -1;
	}
}
//===================================================================================
//==================================================================================
//==================================================================================
string str_i_between(string _base_str, string _start_str, string _end_str) {
	long _start_pos;
	long _end_pos;
	_start_pos = stripos(_base_str, _start_str);
	_end_pos = stripos(_base_str, _end_str);
	if (_start_pos == -1 || _end_pos == -1 || _start_pos >= _end_pos)
		return "";
	_start_pos += strlen(_start_str);
	return substr(_base_str, _start_pos, (_end_pos - _start_pos));
}
string str_i_from_begin(string _base_str, string _find_str) {
	long _pos;
	_pos = strpos(_base_str, _find_str);
	if (_pos == -1)
		return "";
	return substr(_base_str, 0, _pos);
}
string str_i_to_end(string _base_str, string _find_str) {
	long _pos;
	_pos = strpos(_base_str, _find_str);
	if (_pos == -1)
		return "";
	return substr(_base_str, _pos + strlen(_find_str));
}
string cut_and_get_1st_word(string &_str) {
	long _pos_of_word_begin;
	arr_ls _arr;
	long _k;
	string _char;
	long _pos_of_word_end;
	string _return;
	_pos_of_word_begin = 0;
	_arr = str_split(_str);
	for (auto const& [_k, _char] : _arr) {
		if (_char != " ") {
			_pos_of_word_begin = _k;
			break;
		}
	}
	if (_pos_of_word_begin == -1)
		return "";
	_pos_of_word_end = strlen(_str);
	for (_k = _pos_of_word_begin; _k < strlen(_str); _k++) {
		if (_arr[_k] == " ") {
			_pos_of_word_end = _k;
			break;
		}
	}
	_return = substr(_str, _pos_of_word_begin,
			_pos_of_word_end - _pos_of_word_begin);
	_str = substr(_str, _pos_of_word_end);
	return _return;
}
void trim_each(arr_ls &_arr_of_str) {
	//long _k;
	string _str;
	for (auto const& [_k, _str] : _arr_of_str)
		_arr_of_str[_k] = trim(_str);
}
arr_ls explode_then_trim(string _del, string _str) {
	arr_ls _return;
	_return = explode(_del, _str);
	trim_each(_return);
	return _return;
}
string regex_match_ta(string _str, string _regex) {
	string _result;
	_result = preg_match("/" + _regex + "/", _str);
	return _result;
}
//not used
string reconstruct_insert_query(string _table, arr_ls _cols, arr_ls _vals) {
	//long _k;
	string _val;
	for (auto const& [_k, _val] : _vals) {
		_vals[_k] = "'" + _val + "'";
	}
	return "insert into _table (" + implode(", ", _cols) + ") values ("
			+ implode(", ", _vals) + ")";
}
arr_ls get_columns_on_insert(string _query) {
	string _collumns_str;
	_collumns_str = str_i_between(_query, "(", ")");
	_collumns_str = str_ireplace("`", "", _collumns_str);
	_collumns_str = str_ireplace(" ", "", _collumns_str);

	return explode(",", _collumns_str);
}
string remove_quotes(string _str) {
	_str = str_ireplace("\\\"", "-|-double-quote-|-", _str);
	_str = str_ireplace("\"", "", _str);
	_str = str_ireplace("-|-double-quote-|-", "\\\"", _str);

	_str = str_ireplace("\\\'", "-|-single-quote-|-", _str);
	_str = str_ireplace("'", "", _str);
	_str = str_ireplace("-|-single-quote-|-", "\'", _str);
	return _str;
}
arr_ls get_values_on_insert(string _query) {
	string _collumns_str;
	_collumns_str = str_i_to_end(_query, "values");
	_collumns_str = str_i_between(_collumns_str, "(", ")");
	_collumns_str = str_ireplace("`", "", _collumns_str);
	_collumns_str = str_ireplace(" ", "", _collumns_str);

	_collumns_str = remove_quotes(_collumns_str);
	return explode(",", _collumns_str);
}
long qq_insert(string _query, string _org) {
	string _table_name;
	arr_ls _columns;
	arr_ls _values;
	arr_ll _array_keys;
	long _id;
	long _return;
	long _i;
	bool _check_index;
	//long _index_table_column;
	string _column_to_index;
	string _value_to_index;
	_table_name = get_1st_table_name_from_query(_query);
	_columns = get_columns_on_insert(_query);
	_values = get_values_on_insert(_query);
	if (!(_array_keys = array_keys(_columns, "id")).empty()) {
		_id = tl(_values[_array_keys[0]]);
		_return = dbqr(_org);
	} else {
		if (_dbc[_table_name].empty())
			_id = 0;
		else
			_id = _dbc[_table_name].last_key() + 1;
		_return = dbqr(_org);
	}
	if (_return == -1)
		return -1;
	_id = tl(dbsr("SELECT max(id) AS max_id from " + _table_name)[0]["max_id"]);
	array_push(_columns, "id");
	array_push(_values, ts(_id));
	for (_i = 0; _i < (long) (_columns.size()); _i++) {
		_dbc[_table_name][_id][_columns[_i]] = _values[_i];
	}
	// valuex calc;
	if (in_array(_table_name, VALUEX_TABLES))
		_dbc[_table_name][_id]["valuex"] = sqrt(
				td(_dbc[_table_name][_id]["weight"])
						* td(_dbc[_table_name][_id]["bore"]));
	// index create;
	_check_index = false;
	for (auto const& [_key_rtt, _index_table_column] : ALL_INDEXS) {
		if (_index_table_column.at(0) == _table_name) {
			_check_index = true;
			_column_to_index = _index_table_column.at(1);
			break;
		}
	}
	if (_check_index) {
		_value_to_index = _values[array_search(_column_to_index, _columns)];
		_dbi[_table_name][_column_to_index][_value_to_index] = _id;
	}
	return _return;
}
arr_lls get_column_value_pairs_on_update(string _query) {
	arr_lls _return;
	string _tmp_str;
	string _collumns_str;
	arr_ls _tmp_arr;
	string _tmp_ele;
	//long _k;
	string _v;
	_return.clear();
	_tmp_str = str_i_between(_query, " set ", " where");
	_tmp_str = str_ireplace("`", "", _tmp_str);
	// _collumns_str = str_ireplace ( " ", "", _collumns_str );
	_tmp_str = str_ireplace("'", "", _tmp_str);
	_tmp_str = str_ireplace("\"", "", _tmp_str);
	_tmp_arr = explode(",", _tmp_str);
	for (auto const& [_key_rtt, _tmp_ele] : _tmp_arr) {
		array_push(_return, explode_then_trim("=", _tmp_ele));
	}
	for (auto& [_k, _v] : _return) {
		_return[_k][1] = remove_quotes(_v[1]);
	}
	return _return;
}
string trim_str_1(string _str, string _char = "@") {
	string _return;
	long _strlen;
	_return = _str;
	_strlen = strlen(_return);
	//string _debug = substr(_return, _strlen - 1, 1);
	if (substr(_return, _strlen - 1, 1) == _char)
		_return = substr(_return, 0, _strlen - 1);
	if (substr(_return, 0, 1) == _char)
		_return = substr(_return, 1);
	return _return;
}
string trim_str(string _str, string _char = "@") {
	string _str1 = _str;
	string _str2 = trim_str_1(_str1);
	while (_str1 != _str2) {
		_str1 = _str2;
		_str2 = trim_str_1(_str2);
	}
	return _str1;
}
arr_lls parse_where(string _query) {
	arr_lls _return;
	string _tmp_str;
	arr_ls _tmp_arr;
	//long _k;
	string _tmp_ele;
	// echo "haha";
	_return.clear();
	// print_r ( _return );
	_tmp_str = str_i_between(_query, " where ", " order by ");
	if (_tmp_str == "")
		_tmp_str = str_i_between(_query, " where ", " limit ");
	if (_tmp_str == "")
		_tmp_str = str_i_between(_query, " where ", ";");
	if (_tmp_str == "")
		_tmp_str = str_i_to_end(_query, " where ");

	_tmp_arr = explode(" and ", _tmp_str);
	for (auto& [_k, _tmp_ele] : _tmp_arr) {
		if (strpos(_tmp_ele, " REGEXP_LIKE") > 0) {
			_tmp_ele = trim(str_ireplace(" REGEXP_LIKE", "", _tmp_ele));
			_tmp_ele = trim_str(_tmp_ele, "(");
			_tmp_ele = trim_str(_tmp_ele, ")");
			_return[_k] = explode_then_trim(" , ", _tmp_ele);
			_return[_k][2] = remove_quotes(_return[_k][1]);
			_return[_k][0] = trim(_return[_k][0]);
			_return[_k][1] = "r";
			continue;
		}
		if (strpos(_tmp_ele, " = ") > 0) {
			_return[_k] = explode_then_trim(" = ", _tmp_ele);
			_return[_k][2] = remove_quotes(_return[_k][1]);
			_return[_k][0] = trim(_return[_k][0]);
			_return[_k][1] = "=";
			continue;
		}
		if (strpos(_tmp_ele, " == ") > 0) {
			_return[_k] = explode_then_trim(" = ", _tmp_ele);
			_return[_k][2] = remove_quotes(_return[_k][1]);
			_return[_k][0] = trim(_return[_k][0]);
			_return[_k][1] = "=";
			continue;
		}
		if (strpos(_tmp_ele, " like@ ") > 0) {
			_return[_k] = explode_then_trim(" like@ ", _tmp_ele);
			_return[_k][2] = remove_quotes(_return[_k][1]);
			_return[_k][0] = trim(_return[_k][0]);
			_return[_k][1] = "~";
			continue;
		}
		if (strpos(_tmp_ele, " in ") > 0) {
			_return[_k] = explode_then_trim(" in ", _tmp_ele);
			_return[_k][2] = remove_quotes(_return[_k][1]);
			_tmp_ele = trim_str(_tmp_ele, "(");
			_tmp_ele = trim_str(_tmp_ele, ")");
			_return[_k][1] = "i";
			_return[_k][0] = trim(_return[_k][0]);
			continue;
		}
		echo("unsupported sql where format");
//		if (strpos(_query, "select") > -1)
//			return dbsr(_query);
//		else
//			dbqr(_query);
	}
	return _return;
}
bool match_where(arr_ss _row, arr_lls _where) {
	arr_ls _a_condition;
	string _column_to_check;
	string _operation;
	string _value_to_check;
	string _row_value_to_check;
	arr_ls _row_nodes;
	for (auto& [_key_rtt, _a_condition] : _where) {
		_column_to_check = _a_condition[0];
		_operation = _a_condition[1];
		_value_to_check = _a_condition[2];
		_row_value_to_check = _row[_column_to_check];
		if (_operation == "=" && _row_value_to_check != _value_to_check)
			return false;
		if (_operation == "~") {
			_row_nodes = explode("@", _row_value_to_check);
			if (!in_array(_value_to_check, _row_nodes))
				return false;
		}
		if (_a_condition[1] == "r"
				&& regex_match_ta(_row[_a_condition[0]], _a_condition[2]) != "")
			return false;
		if (_a_condition[1] == "i"
				&& !in_array(_row[_a_condition[0]],
						explode(",", _a_condition[2])))
			return false;
	}
	return true;
}
long get_update_id(string _query) {
	_query = (str_i_to_end(_query, " where id"));
	return tl(trim(str_i_to_end(_query, "=")));
}
long qq_update(string _query, string _org) {
	string _table_name;
	arr_lls _column_value_pairs;
	arr_lls _where;
	long _id_to_update;
	long _i;
	string _row;
	_table_name = get_1st_table_name_from_query(_query);
	_column_value_pairs = get_column_value_pairs_on_update(_query);
	_where = parse_where(_query);
	if ((_where.size()) == 1 && _where[0][0] == "id" && _where[0][1] == "=") {
		_id_to_update = tl(_where[0][2]);
		for (_i = 0; _i < (long) (_column_value_pairs.size()); _i++) {
			_dbc[_table_name][_id_to_update][_column_value_pairs[_i][0]] =
					_column_value_pairs[_i][1];
		}
		if (in_array(_table_name, VALUEX_TABLES))
			_dbc[_table_name][_id_to_update]["valuex"] =
					ts(
							sqrt(
									td(
											_dbc[_table_name][_id_to_update]["weight"])
											* td(
													_dbc[_table_name][_id_to_update]["bore"])));
		return dbqr(_org);
	}
	if ((_where.size()) == 1 && _where[0][1] == "=") {
		for (auto const& [_id_to_update, _row] : _dbc[_table_name].get_map()) {
			if (match_where(_row, _where)) {
				for (_i = 0; _i < (long) (_column_value_pairs.size()); _i++) {
					_dbc[_table_name][_id_to_update][_column_value_pairs[_i][0]] =
							_column_value_pairs[_i][1];
				}
				break;
			}
		}
		return dbqr(_org);
	}
	echo("unsupported update query.\n");
	return dbqr(_org);
}
long dbq(string _query, string _org = "") {
	string _command;
	if (_org == "")
		_org = _query;
	_query = trim(_query);
	_command = strtolower(str_i_from_begin(_query, " "));
	if (_command == "update") {
		return qq_update(_query, _org);
	} else if (_command == "insert") {
		return qq_insert(_query, _org);
	} else {
		return dbqr(_org);
	}
}
// ======================================================================================================
// ======================================================================================================
arr_lss array_top_by_column_no_keep_key(arr_lss _arr, long _start, long _stop,
		string _column) {
	arr_lss _return;
	long _j;
	long _tmp_k;
	double _tmp_v;
	//long _k;
	arr_ss _row;
	string _v;
	_return.clear();
	for (_j = 0; _j < _stop; _j++) {
		if (_arr.empty())
			break;
		_tmp_k = 0;
		_tmp_v = 0.0;
		for (auto& [_k, _row] : _arr) {
			if (_arr.empty())
				break;
			_v = _row[_column];
			if (td(_v) >= _tmp_v) {
				_tmp_k = _k;
				_tmp_v = td(_v);
			}
		}
		if (_j >= _start)
			array_push(_return, _arr[_tmp_k]);
		_arr.erase(_tmp_k);
	}
	return _return;
}
arr_lss array_bottom_by_column_no_keep_key(arr_lss _arr, long _start,
		long _stop, string _column) {
	arr_lss _return;
	long _j;
	long _tmp_k;
	double _tmp_v;
	//long _k;
	arr_ss _row;
	string _v;
	_return.clear();
	for (_j = 0; _j < _stop; _j++) {
		if (_arr.empty())
			break;
		_tmp_k = 0;
		_tmp_v = 0.0;
		for (auto& [_k, _row] : _arr) {
			if (_arr.empty())
				break;
			_v = _row[_column];
			if (td(_v) <= _tmp_v) {
				_tmp_k = _k;
				_tmp_v = td(_v);
			}
		}
		if (_j >= _start)
			array_push(_return, _arr[_tmp_k]);
		_arr.erase(_tmp_k);
	}
	return _return;
}
arr_ls parse_order_by(string _query) {
	string _tmp_str;
	arr_ls _return;
	_tmp_str = str_i_between(_query, " order by ", " limit ");
	if (_tmp_str == "")
		_tmp_str = str_i_to_end(_query, " order by ");
	if (_tmp_str == "")
		return arr_ls_zero;
	_return = { { 0, cut_and_get_1st_word(_tmp_str) }, { 1,
			cut_and_get_1st_word(_tmp_str) } };
	if (_return[1] == "")
		_return[1] = "DESC";
	return _return;
}
arr_ll parse_limit(string _query) {
	string _limit_str;
	arr_ls _explode;
	_limit_str = trim(str_i_to_end(_query, " limit "));
	if (_limit_str == "")
		// limit not found
		return arr_ll_zero;
	_limit_str = str_ireplace(" ", "", _limit_str);
	_limit_str = str_ireplace(";", "", _limit_str);
	_explode = explode(",", _limit_str);
	if ((_explode.size()) < 2) {
		// limit a ;
		if (_explode[0] == "1")
			return arr_ll_zero;
		return { {0,0},
			{	1,tl(_explode [0]
				)-1}};
	}
// limit a, b;
	if (_explode[0] == "0" && _explode[1] == "1")
		return arr_ll_zero;
	return { {0,tl(_explode [0])},
		{	1,tl(_explode [0]) + tl(_explode [1]
			)-1}};
}
arr_lss dbs(string _query, string _org = "") {
	if (_org == "")
		_org = _query;
	string _table_name;
	arr_ls _order_by;
	string _order_by_name;
	string _order_direction;
	arr_ll _limit;
	arr_lls _where;
	arr_lss _return;
	string _column_to_find;
	string _value_to_find;
	long _id;
//	long _k;
	arr_ss _row;
	long _j;
	_table_name = get_1st_table_name_from_query(_query);
	_order_by = parse_order_by(_query);
	_order_by_name = "";
	_order_direction = "";
	if (!_order_by.empty()) {
		_order_by_name = _order_by[0];
		_order_direction = _order_by[1];
	}
	_limit = parse_limit(_query);
	_where = parse_where(_query);
	if (_where.empty())
		return dbsr(_org);
	_return.clear();
	// select by id
	//echo("hihi\n");
	if (((_where).size() == 1) && (_where[0][0] == "id")
			&& (_where[0][1] == "=")) {
		//echo("hjhj\n");
		if (_dbc[_table_name].contains(tl(_where[0][2])))
			return { {0,_dbc [_table_name] [tl(_where [0] [2])]
				}};
		return arr_lss_zero;
	}
// select 1 row with opertin =;
	if (_limit == arr_ll_zero) {
		_column_to_find = _where[0][0];
		_value_to_find = _where[0][2];
		if (_where[0][1] == "=" && (_where.size()) == 1
				&& _dbi[_table_name].contains(_column_to_find)) {
			if (_dbi[_table_name][_column_to_find].contains(_value_to_find)) {
				_id = _dbi[_table_name][_column_to_find][_value_to_find];
				return { {0,_dbc [_table_name] [_id]
					}};
			}
			return arr_lss_zero;
		}
		for (auto const& [_k, _row] : _dbc[_table_name].get_map()) {
			if (match_where(_row, _where)) {
				array_push(_return, _row);
				break;
			}
		}
		return _return;
	}
	// select n rows order by id ASC;
	if (_order_by[0] == "" || _order_by[0] == "id") {
		_j = _limit[0];
		for (auto const& [_k, _row] : _dbc[_table_name].get_map()) {
			if (match_where(_row, _where)) {
				array_push(_return, _row);
				_j++;
				if (_j > _limit[1])
					break;
			}
		}
		return _return;
	}
	// select n rows order by something else DESC or ASC;
	if (_order_by_name != "" || _order_by_name != "id") {
		for (auto const& [_k, _row] : _dbc[_table_name].get_map()) {
			if (match_where(_row, _where)) {
				array_push(_return, _row);
			}
		}
		//if (_order_by) {
		if (_order_direction == "DESC")
			return array_top_by_column_no_keep_key(_return, _limit[0],
					_limit[1], _order_by_name);
		if (_order_direction == "ASC")
			return array_bottom_by_column_no_keep_key(_return, _limit[0],
					_limit[1], _order_by_name);
		//}
	}
	return _return;
}
#endif /* SRC_CORE_CONNECT_H_ */
