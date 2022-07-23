/*
 * libs1.h
 *
 *  Created on: May 15, 2021
 *      Author: qu
 */

#ifndef SRC_LIBS_LIBS1_H_
#define SRC_LIBS_LIBS1_H_
//#include<php2cpp.h>
//#include<connect.h>
//#include<one_cycle.h>

void l1(string _str, long _lv = 3) {
	/*
	 * Error: 0
	 * Warning: 1
	 * Info: 2
	 * Debug: 3
	 */
	string _log_lv_str;
	string _file = "local.log";
	if (_log_lv > _lv) {

		switch (_lv) {
		case 0:
			_log_lv_str = "ERROR";
			break;
		case 1:
			_log_lv_str = "WARNING";
			break;
		case 2:
			_log_lv_str = "INFO";
			break;
		case 3:
			_log_lv_str = "DEBUG";
			break;
		}
		file_append(_file,
				date("d-m-Y H:i:s") + " [" + _log_lv_str + "] " + _str + "\n");
	}
}
string n() {
	return "\n";
}
template<typename T>
void echoa(T _arr, long _level = 0) {
	echo("echoa is not used");
}
void echo_n_tabs(long _n) {
	for (long _i = 0; _i < _n; _i++) {
		echo("\t");
	}
}
string array_reconstruct(arr_lc _arr, long _level = 0) {
	string _tab = "";
	arr_ls _arr1;
	for (long _i = 0; _i < _level; _i++)
		_tab += "\t";
	for (auto const& [_k1, _e1] : _arr) {
		_arr1[_k1] = _tab + "\"" + ts(_k1) + "\" => \"" + _e1._0 + "\"";
	}

	return "[" + n() + implode("," + n(), _arr1) + n() + "]";
}
template<typename T>
void ech(T _n) {
	if (_n == true) {
		echo("TRUE");
		return;
	}

	if (_n == false) {
		echo("FALSE");
		return;
	}
	try {
		print_r((arr_ls) _n);
		return;
	} catch (...) {
	}
	try {
		print_r((arr_lc) _n);
		return;
	} catch (...) {
	}
	try {
		print_r((arr_ld) _n);
		return;
	} catch (...) {
	}
	try {
		print_r((arr_ls) _n);
		return;
	} catch (...) {
	}
	try {
		print_r((arr_lll) _n);
		return;
	} catch (...) {
	}
	try {
		print_r((arr_lss) _n);
		return;
	} catch (...) {
	}
	try {
		print_r((arr_ss) _n);
		return;
	} catch (...) {
	}
	echo((string) _n);
	return;
}
double geo_avg(double _1, double _2) {
	return sqrt(_1 * _2);
}
double geo_avg(double _1, double _2, double _3) {
	return pow(_1 * _2 * _3, 1 / 3);
}
double geo_avg(double _1, double _2, double _3, double _4) {
	return pow(_1 * _2 * _3 * _4, 1 / 4);
}
double geo_avg(double _1, double _2, double _3, double _4, double _5, double _6,
		double _7) {
	return pow(_1 * _2 * _3 * _4 * _5 * _6 * _7, 1 / 7);
}
void readc(string &_var) {
	cin >> _var;
}
string new_node_num() {
	lock_guard < mutex > _l(_lock);
	_max_node++;
	return ts(_max_node);
}
long new_rule_num() {
	long _current_max_num = 0;
	arr_lss _data = dbs("select valuex from settings where keyx = 'max_rule'");
	_current_max_num = tl(_data[0]["valuex"]);
	dbq(
			"update settings set valuex = " + ts(_current_max_num + 1)
					+ " where keyx = 'max_rule'");
	return _current_max_num + 1;
}
bool in_core(string _clause_find) {
	for (auto const& [_k, _clause] : _core.get_map()) {
		if (_clause._0 == _clause_find) {
			return true;
		}
	}
	return false;
}
long find_core(string _clause_find) {
	for (auto const& [_k, _clause] : _core.get_map()) {
		if (_clause._0 == _clause_find) {
			return _k;
		}
	}
	return -1;
}
long find_corer_prove(string _clause_find) {
	for (auto const& [_k, _clause] : _corer_prove.get_map()) {
		if (_clause._0 == _clause_find) {
			return _k;
		}
	}
	return -1;
}
long find_corer_find(string _clause_find) {
	for (auto const& [_k, _clause] : _corer_find.get_map()) {
		if (_clause._0 == _clause_find) {
			return _k;
		}
	}
	return -1;
}
arr_ll find_r_logic(substringC _substringC_find) {
	arr_ll _return;
	for (auto const& [_k, _substringC] : _r_logic.get_map()) {
		if (_substringC_find == _substringC) {
			array_push(_return, _k);
		}
	}
	return _return;
}
long find_cache(string _clause_find) {
	for (auto const& [_k, _clause] : _cache.get_map()) {
		if (_clause._0 == _clause_find) {
			return _k;
		}
	}
	return -1;
}
long find_rule(string _clause_find) {
	for (auto const& [_k, _clause] : _rules.get_map()) {
		if (_clause._0 == _clause_find) {
			return _k;
		}
	}
	return -1;
}
long find_rel(string _c1, string _c2) {
	for (auto const& [_k, _clause] : _rels.get_map()) {
		if ((_clause._0 == _c1 && _clause._1 == _c2)
				|| (_clause._0 == _c2 && _clause._1 == _c1)) {
			return _k;
		}
	}
	return -1;
}
bool in_cache(string _clause_pattern) {
	for (auto const& [_k, _clause] : _cache.get_map()) {
		if (strpos(_clause._0, _clause_pattern) > -1)
			return true;
	}
	return false;
}
string in_db(string _clause_pattern) {
	arr_lss _dbq = dbs(
			"SELECT word_id FROM new_defi WHERE defi = \"" + _clause_pattern
					+ "\"");
	if (_dbq.size() == 0)
		return _dbq[0]["word_id"];
	_dbq = dbs(
			"SELECT id FROM gi_f WHERE c = \"" + _clause_pattern
					+ "\" limit 1");
	if (_dbq.size() == 0)
		_dbq = dbs(
				"SELECT id FROM gi WHERE c = \"" + _clause_pattern
						+ "\" limit 1");
	if (_dbq.size() != 0)
		return _dbq[0]["id"];
	return "";
}
long find_core_cache(string _clause_pattern) {
	long _tmp;
	if ((_tmp = find_core(_clause_pattern)) >= 0)
		return _tmp;
	if ((_tmp = find_cache(_clause_pattern)) >= 0)
		return _tmp;
	return -1;
}
long find_describer_key(long _node) {
	for (auto const& [_key, _clause] : _core.get_map()) {
		if (strpos(ts(_node) + "@", _clause._0) == 0)
			return _key;
	}
	for (auto const& [_key, _clause] : _core.get_map()) {
		if (strpos(ts(_node) + "@", _clause._0) == 0)
			return _key;
	}
	return -1;
}
string node_replace(string _search, string _replace, string _subject) {
	try {
		string _return = str_replace("@" + _search + "@", "@" + _replace + "@",
				_subject);
		if (strpos(_return, _search + "@") == 0)
// head
			_return = _replace + substr(_subject, strlen(_search));
		long _pos_of_tail = strpos(_return, "@" + _search);
		long _tmp_compare = strlen(_return) - strlen(_search) - 1;
		if (_pos_of_tail == _tmp_compare) /* 1 for the @ */
// bot
			_return = substr(_return, 0, _pos_of_tail) + "@" + _replace;
		return _return;
	} catch (...) {
		return _subject;
	}
}
string node_replace_multi(string _search, string _replace,
		string _multi_clause) {
	arr_ls _multi_clause_arr = explode("&", _multi_clause);
	arr_ls _tmp_clause;
	for (auto const& [_k, _clause] : _multi_clause_arr) {
		array_push(_tmp_clause, node_replace(_search, _replace, _clause));
	}
	return implode("&", _tmp_clause);
}
void l(string _str, long _lv = 2) {
	string _file;
	string _log_lv_str;
	ofstream _my_file("filename.txt");
	if (_log_lv > _lv) {
		switch (_lv) {
		case 0:
			_log_lv_str = "ERROR";
			break;
		case 1:
			_log_lv_str = "WARNING";
			break;
		case 2:
			_log_lv_str = "INFO";
			break;
		case 3:
			_log_lv_str = "DEBUG";
			break;
		}
		_my_file
				<< date("d-m-Y H:i:s") + " [" + _log_lv_str + "] " + _str
						+ "\n";
	}
}
arr_ls explode_multi(arr_ls _delimiters, string _string) {
	string _delimiter;
	arr_ls _launch;
	if (_delimiters.empty()) {
		throw 45;
		//return { {0, _string}};
	}
	for (auto const& [_key_rtt, _delimiter] : _delimiters)
		_string = str_replace(_delimiter, _delimiters[0], _string);
	_launch = explode(_delimiters[0], _string);
	return _launch;

}
void core_update_wb(long _num, long _key, double _new) {
	if (_key == 1)
		_core[_num]._1 = _new;
	else if (_key == 2)
		_core[_num]._2 = _new;
//	if (_mode == "mt")
//		_return["core_update"][_num] = _core[_num];
}
void corer_find_update_wb(long _num, long _key, double _new) {
	if (_key == 1)
		_corer_find[_num]._1 = _new;
	else if (_key == 2)
		_corer_find[_num]._2 = _new;
//	if (_mode == "mt")
//		_return["core_update"][_num] = _core[_num];
}
void corer_prove_update_wb(long _num, long _key, double _new) {
	if (_key == 1)
		_corer_prove[_num]._1 = _new;
	else if (_key == 2)
		_corer_prove[_num]._2 = _new;
//	if (_mode == "mt")
//		_return["core_update"][_num] = _core[_num];
}
void precision_control(long _k) {
	core_update_wb(_k, 1, _core[_k]._1 > 1 ? 1 : _core[_k]._1);
	core_update_wb(_k, 2, _core[_k]._2 > 1 ? 1 : _core[_k]._2);
	core_update_wb(_k, 1, _core[_k]._1 < 0.03 ? 0.03 : _core[_k]._1);
	core_update_wb(_k, 2, _core[_k]._2 < 0.03 ? 0.03 : _core[_k]._2);
}
bool can_match(string _rule, string _clause) {
	arr_ls _rule_arr;
	arr_ls _clause_arr;
//	long _key;
	string _rule_node;
	_rule_arr = explode("@", _rule);
	_clause_arr = explode("@", _clause);
	if (_rule_arr.size() != _clause_arr.size())
		return false;
	for (auto const& [_key, _rule_node] : _rule_arr) {
		if (strpos(_rule_node, "$") != 0 && _rule_node != _clause_arr[_key])
			return false;
	}
	return true;
}
bool can_match_multi_clause_rule(string _multiC_rule, string _singleC_clause) {
	arr_ls _rule_clause_arr = explode("&", _multiC_rule);
	for (auto const& [_k, _rule_clause] : _rule_clause_arr) {
		if (can_match(_rule_clause, _singleC_clause))
			return true;
	}
	return false;
}
void test_match_core(long _core_key) {
	clause _clause;
//	long _rk;
	clause _rule;
	_clause = _core[_core_key];
	for (auto const& [_rk, _rule] : _rules.get_map()) {
		if (can_match_multi_clause_rule(_rule._0, _clause._0))
			_may_match[_core_key][_rk] = true;
		else
			_may_match[_core_key].erase(_rk);
	}
}
void core_push_arr(clause _clause, long _key = -1) {
	long _pushed_core_key;
//	if (_mode == "mt")
//		array_push(_return["core"], _clause);
	if (_clause._0 == "")
		echo(4);
	lock_guard < mutex > _l(_lock);
	if (_key == -1) {
		_core[_next_core_key] = _clause;
		_pushed_core_key = _next_core_key;
		_next_core_key++;
	} else {
		_pushed_core_key = _key;
		_core[_key] = _clause;
		if (_key > _next_core_key)
			_next_core_key = _key + 1;
	}
	if (strpos(_clause._0, "@g@i@") > 0)
		_core_gi[_pushed_core_key] = _clause;
	else if (strpos(_clause._0, "@g@o@") > 0)
		_core_go[_pushed_core_key] = _clause;
	else if (strpos(_clause._0, "t") >= 0)
		_core_t[_pushed_core_key] = _clause;
	else if (strpos(_clause._0, "d") == 0)
		_core_d[_pushed_core_key] = _clause;
	else if (strpos(_clause._0, "l") == 0)
		_core_l[_pushed_core_key] = _clause;
	else
		_core_others[_pushed_core_key] = _clause;
	test_match_core(_pushed_core_key);
}
long find_in_array_lv2_0(string _ele, arr_lc _arr) {
//	long _key;
	clause _ele_tmp;
	for (auto const& [_key, _ele_tmp] : _arr) {
		if (_ele == _ele_tmp._0)
			return _key;
	}
	return -1;
}
long core_find(string _clause) {
	return find_in_array_lv2_0(_clause, _core.get_map());
}
bool cache_push_core(long _index1, double _bore = -1.0) {
	clause _clause;
	try {
		_clause = _cache.at(_index1);
	} catch (...) {
		return false;
	}
	if (core_find(_clause._0) > -1) {
		_cache.erase(_index1);
		return false;
	}
	core_push_arr(_cache[_index1], _index1);
	_cache.erase(_index1);
	return true;
}
long find_node_in_clause(string _node, string _clause_str, arr_ll _skipped_pos =
		arr_ll_zero) {
	arr_ls _nodes_arr;
//	long _k;
	string _node1;
	_nodes_arr = explode("@", _clause_str);
	for (auto const& [_k, _node1] : _nodes_arr) {
		if (_node == _node1 && !in_array(_k, _skipped_pos))
			return _k;
	}
	return -1;
}
bool check_if_clause_is_a_word_type_go_word_clause_and_no_new_vocal_entry_of_word_clause(
		clause _clause) {
	arr_ll _word_type_nums;
//	long _num;
	arr_ls _nodes_arr;
	string _last;

	array_push(_word_type_nums, 51230l);
	array_push(_word_type_nums, 51l);
	array_push(_word_type_nums, 259l);
	array_push(_word_type_nums, 52230l);
	array_push(_word_type_nums, 52l);
	array_push(_word_type_nums, 256l);
	array_push(_word_type_nums, 255l);
	array_push(_word_type_nums, 257l);
	array_push(_word_type_nums, 52400l);
	array_push(_word_type_nums, 274554l);
	array_push(_word_type_nums, 258l);
	array_push(_word_type_nums, 88693l);
	array_push(_word_type_nums, 77206l);
	array_push(_word_type_nums, 97592l);
	array_push(_word_type_nums, 229l);
	array_push(_word_type_nums, 230l);
	array_push(_word_type_nums, 64851l);
	array_push(_word_type_nums, 246l);
	for (auto const& [_key_rtt, _num] : _word_type_nums) {
		if (strpos(_clause._0, ts(_num) + "@") == 0) {
			_nodes_arr = explode("@", _clause._0);
			_last = _nodes_arr[_nodes_arr.size() - 1];
			if (in_array(_last, _all_new_vocal_id))
				return true;
		}
	}
	return false;
}
bool db_push(clause _clause) {
	string _clause0;
	string _num;
	string _after_gi;
	arr_lss _result;
	string _after_go;
	if (_clause._0 != "")
		return true;
	_clause0 = _clause._0;
	if (strpos(_clause0, "d") > -1)
		return true;
	if (strpos(_clause0, "l") > -1)
		return true;
	if (strpos(_clause0, "g@I") > -1)
		return true;
	if (find_node_in_clause("254", _clause0) > -1)
		return true;
	if (strpos(_clause0, "@g@i@") > -1) {
		_num = explode("@g@i@", _clause0)[0];
		_after_gi = explode("@g@i@", _clause0)[1];
		_result = dbs("select * from gi_f where c = '" + _clause0 + "'");
		if (_result.size() == 0) {
			_result = dbs("select * from gi where c = '" + _clause0 + "'");
		}
		if (_result.size() == 0) {
			dbq(
					"insert into gi (id, c, weight, bore) values (" + _num
							+ ", '" + _after_gi + "', " + ts(_clause._1) + ", "
							+ ts(_clause._2) + ")");
		} else {
			dbq(
					"update gi set weight = "
							+ ts(
									(td(_result[0]["weight"])
											+ 0.05 * _clause._1) / 1.05)
							+ ",  bore = "
							+ ts(
									(td(_result[0]["bore"]) + 0.05 * _clause._2)
											/ 1.05) + " where id = "
							+ _result[0]["id"]);
		}
		return true;
	}
	if (strpos(_clause0, "@g@o@") > -1) {
		if (_clause._1 < 0 + 7
				|| check_if_clause_is_a_word_type_go_word_clause_and_no_new_vocal_entry_of_word_clause(
						_clause))
			return true;
		_num = explode("@g@o@", _clause0)[0];
		_after_go = explode("@g@o@", _clause0)[1];
		_result = dbs(
				"select *  from go_f where c2 = " + _after_go + " and c1 = "
						+ _num);
		if (_result.size() == 0) {
			_result = dbs(
					"select * from go where c2 = " + _after_go + " and c1 = "
							+ _num);
		}
		if (_result.size() == 0) {
			dbq(
					"insert into go ( c1, c2, weight, bore) values (" + _num
							+ ", " + _after_go + ", " + ts(_clause._1) + ", "
							+ ts(_clause._2) + ")");
		} else {
			dbq(
					"update go set weight = "
							+ ts(
									(td(_result[0]["weight"])
											+ 0.05 * _clause._1) / 1.05)
							+ ",  bore = "
							+ ts(
									(td(_result[0]["bore"]) + 0.05 * _clause._2)
											/ 1.05) + " where id = "
							+ _result[0]["id"]);
		}
		return true;
	}
	_result = dbs("select * from rules_tmp_f where c = '" + _clause0 + "'");
	if (_result.size() == 0) {
		_result = dbs("select * from rules_tmp where c = '" + _clause0 + "'");
	}
	if (_result.size() == 0) {
		dbq(
				"insert into rules_tmp (c, weight, bore) values ('" + _clause._0
						+ "', " + ts(_clause._1) + ", " + ts(_clause._2) + ")");
	} else {
		dbq(
				"update rules_tmp set weight = '"
						+ ts(
								(td(_result.begin()->second["weight"]) + 0
										+ 0.5 * _clause._1) / 1 + 0.5)
						+ "'  bore = '"
						+ ts(
								(td(_result.begin()->second["bore"]) + 0
										+ 0.5 * _clause._2) / 1 + 0.5)
						+ " where id = '" + _result.begin()->second["id"]
						+ "'");
	}
	return true;
}
void shrink_cache() {
	long _index_to_eliminated;
	long _i;
	double _tmp_effective;
//	long _key;
	clause _clause;
	double _effective_index;
	long _key_to_remove;
	arr_lll _passed_arr;
//	long _j;
	string _clause_num;
	_index_to_eliminated = _cache.size() - MAX_CACHE_SIZE;
	for (_i = 0; _i < _index_to_eliminated; _i++) {
		_tmp_effective = 1;
		for (auto const& [_key, _clause] : _cache.get_map()) {
			_effective_index = _clause._1 - _clause._2;
			if (_effective_index <= _tmp_effective) {
				_key_to_remove = _key;
				_tmp_effective = _effective_index;
			}
		}
		if (_cache[_key_to_remove]._1
				> geo_avg(DEFAULT_OUT_CACHE_VALUE_FACTOR, _denied_value))
			db_push (_cache[_key_to_remove]);
		_cache.erase(_key_to_remove);
		arr_llll _tmp = _passed.get_map();
		for (auto const& [_i, _passed_arr] : _tmp) {
			for (auto const& [_j, _passedx] : _passed_arr) {
				for (auto const& [_j1, _clause_num] : _passedx) {
					if (_clause_num == _key_to_remove)
						_passed[_i].erase(_j);
				}
			}
		}
	}
}
long cache_push(clause _clause, long _key = -1) {
// TODO: find_represent ();
//if (_mode == "mt")
//	array_push(_return["cache"], _clause);
	long _return;
	_clause._1 = _clause._1 == 0.0 ? _clause._1 : 0.3;
	_clause._2 = _clause._2 == 0.0 ? _clause._2 : 0.02;
	_clause._3 = _clause._3 != 0 ? _clause._3 : time_php();
	if (_key == -1) {
		array_push(_cache, _clause);
		_return = _cache.last_key();
	} else {
		_cache[_key] = _clause;
		_return = _key;
	}
//if (_key > _max_cache_key)
//   _max_cache_key = _key + 1;
	shrink_cache();
	return _return;
}
void shrink_core() {
	long _index_to_eliminated;
	long _i;
	double _tmp_effective;
//	long _key;
	arr_lc _core_tmp;
	string _clause;
	double _effective_index;
	long _key_to_remove;
	long _current_time;
	_index_to_eliminated = _core.size() - MAX_CORE_SIZE;
	for (_i = 0; _i < _index_to_eliminated; _i++) {
		_tmp_effective = 1;
		for (auto const& [_key, _clause] : _core.get_map()) {
			_effective_index = sqrt(_clause._1 * _clause._2);
			if (_effective_index <= _tmp_effective) {
				_key_to_remove = _key;
				_tmp_effective = _effective_index;

			}

		}
		if (_core[_key_to_remove]._1
				> geo_avg(DEFAULT_OUT_CORE_VALUE_FACTOR, _denied_value))
			cache_push(_core[_key_to_remove], _key_to_remove);
		_core.erase(_key_to_remove);
		_may_match.erase(_key_to_remove);
		_core_gi.erase(_key_to_remove);
		_core_go.erase(_key_to_remove);
		_core_t.erase(_key_to_remove);
		_core_d.erase(_key_to_remove);
		_core_l.erase(_key_to_remove);
		_core_others.erase(_key_to_remove);
	}
	_current_time = time_php();
	_core_tmp = _core;
	for (auto const& [_key, _clause] : _core_tmp) {
		if ((_current_time - _clause._3) > 18000) {
			_key_to_remove = _key;
			if (_core[_key]._1 > 0.2) {
				cache_push(_core[_key_to_remove], _key_to_remove);
			}
			_core.erase(_key_to_remove);
			_may_match.erase(_key_to_remove);
			_core_gi.erase(_key_to_remove);
			_core_go.erase(_key_to_remove);
			_core_t.erase(_key_to_remove);
			_core_d.erase(_key_to_remove);
			_core_l.erase(_key_to_remove);
			_core_others.erase(_key_to_remove);
		}
	}
}
long core_push(clause _clause, bool _return = false, bool _add_weight = false,
		bool _shrink = true) {
	clause _false_clause;
	arr_ls _node_arr;
	string _after;
	arr_lss _data;
	long _index;
	long _index1;
	if (_clause._1 == 0)
		_clause._1 = 0.4;
	if (_clause._2 == 0)
		_clause._2 = 0.98;
	if (_clause._3 == 0)
		_clause._3 = time_php();
	_node_arr = explode("@", _clause._0);
	if (_node_arr.size() == 3 && _node_arr[1] == "0"
			&& _node_arr[0] == _node_arr[2])
		return false;
	if (strpos(_clause._0, "@g@i@") > -1) {
		_after = explode("@g@i@", _clause._0)[1];
		_data = dbs("select * from gi_f where c = '" + _after + "' limit 1");
		if (_data.empty()) {
			_data = dbs("select * from gi where c = '" + _after + "' limit 1");
		}
		if (!_data.empty()) {
			_clause._0 = _data.begin()->second["id"] + "@g@i@" + _data[0]["c"];
			_clause._1 = geo_avg(td(_data.begin()->second["weight"]),
					_clause._1);
			_clause._2 = geo_avg(td(_data.begin()->second["bore"]), _clause._2);
		}
	}

	if ((_index = find_core(_clause._0)) >= 0) {
		if (_add_weight) {
			_core[_index]._1 = sqrt(pow(_core[_index]._1, 2) * 1.15);
			_core[_index]._2 = sqrt(pow(_core[_index]._2, 2) * 0.8);
			precision_control(_index);
			_core[_index]._3 = time_php();
		}
		return -1;
	}
	if ((_index1 = find_cache(_clause._0)) >= 0) {
		cache_push_core(_index1, _clause._2);
		return -1;
	}
	core_push_arr(_clause);
	//_mode != "mt" && _shrink && shrink_core();
	if (!_return)
		return 0;
	return _core.last_key();
}
bool core_push_each(arr_lc _multi_clauses, bool _first, bool _second) {
	string _clause;
	for (auto const& [_key_rtt, _clause] : _multi_clauses) {
		core_push(_clause, _first, _second);
	}
	return true;
}
void precision_control_r(long _k) {
	corer_prove_update_wb(_k, 1, _core[_k]._1 > 1 ? 1 : _core[_k]._1);
	corer_prove_update_wb(_k, 2, _core[_k]._2 > 1 ? 1 : _core[_k]._2);
	corer_prove_update_wb(_k, 1, _core[_k]._1 < 0.03 ? 0.03 : _core[_k]._1);
	corer_prove_update_wb(_k, 2, _core[_k]._2 < 0.03 ? 0.03 : _core[_k]._2);
	corer_find_update_wb(_k, 1, _core[_k]._1 > 1 ? 1 : _core[_k]._1);
	corer_find_update_wb(_k, 2, _core[_k]._2 > 1 ? 1 : _core[_k]._2);
	corer_find_update_wb(_k, 1, _core[_k]._1 < 0.03 ? 0.03 : _core[_k]._1);
	corer_find_update_wb(_k, 2, _core[_k]._2 < 0.03 ? 0.03 : _core[_k]._2);
}
long core_push_no_shrink(clause _clause, bool _return = false,
		bool _add_weight = false) {
	return core_push(_clause, _return, _add_weight, false);
}
void test_match_rule(long _rule_key) {
//	long _rc;
	clause _clause;
	for (auto const& [_rc, _clause] : _core.get_map()) {
		if (can_match(_rules[_rule_key]._0, _clause._0))
			_may_match[_rc][_rule_key] = true;
		else
			_may_match[_rc].erase(_rule_key);
	}
}
void rule_push_arr(long _key, clause _clause) {
	if (_key > -1)
		_rules[_key] = _clause;
	else {
		array_push(_rules, _clause);
		_key = array_last_key(_rules);
	}
	//if (_mode == "gt")
	test_match_rule(_key);
//	else
//		_return["rules"][_key] = _clause;
}
bool shrink_rules() {
	long _count;
	arr_ld _tmp_arr;
//	long _key;
	clause _rule;
	long _i;
//	long _k;
	arr_lb _match_rules_arr;
	if ((_count = count(_rules)) <= MAX_RULES_COUNT)
		return false;
	for (auto const& [_key, _rule] : _rules.get_map()) {
		_tmp_arr[_key] = 1.0 - geo_avg(_rule._1, _rule._2);
	}
	_i = _count - MAX_RULES_COUNT;
	_tmp_arr = array_top(_tmp_arr, _i);
	for (auto const& [_key, _tmp_value] : _tmp_arr) {
// db_push ( _rules [_key] );
		_rules.erase(_key);
		for (auto const& [_k, _match_rules_arr] : _may_match.get_map()) {
			_may_match[_k].erase(_key);
		}
		//if (_mode == 'mt')
		_passed.erase(_key);
	}
	return true;
}
bool rule_push(long _key, clause _clause) {
	long _index;
	if ((_index = find_rule(_clause._0)) >= 0) {
		_rules[_index]._1 = sqrt(_clause._1 * 1.0);
		_rules[_index]._3 = time_php();
		return false;
	}
	//if (is_array(_clause)) {
	_clause._3 = time_php();
	rule_push_arr(_key, _clause);
//	} else {
//	rule_push_arr ( _key, [
//			_clause,
//			0+3,
//			0+02,
//			time ()
//			] );
//}
	shrink_rules();
	return true;
}
bool rule_push_each(arr_lc _arr) {
//	long _k;
	clause _ele;
	for (auto const& [_k, _ele] : _arr) {
		rule_push(_k, _ele);
	}
	return true;
}
bool shrink_rels() {
	long _count;
	arr_ld _tmp_arr;
//	long _key;
	dual _rel;
	long _count_will_be_removed;
	arr_ll _keys_to_be_removed;
	if ((_count = _rels.size()) <= MAX_RELS_COUNT)
		return false;
	//_tmp_arr = _rels;
	_count_will_be_removed = _rels.size() - MAX_RELS_COUNT;
	for (auto const& [_key, _rel] : _rels.get_map()) {
		_tmp_arr[_key] = geo_avg(_rel._2, _rel._3);
	}
	for (long _i = 0; _i < _count_will_be_removed; _i++) {
		long _key_to_remove = -1;
		double _tmp = 0.0;
		for (auto const& [_k, _value] : _tmp_arr) {
			if (_value > _tmp)
				_key_to_remove = _k;
		}
		if (_key_to_remove > -1)
			_rels.erase(_key_to_remove);
	}
	return true;
}
bool rel_push(string _c1, string _c2, double _weight = 0.5,
		double _bore = 0.5) {
	long _index;
	if ((_index = find_rel(_c1, _c2)) > -1) {
		_rels[_index]._2 = sqrt(_weight * _rels[_index]._2);
		_rels[_index]._3 = sqrt(_bore * _rels[_index]._3);
		_rels[_index]._4 = time_php();
		return false;
	}
	dual _tmp;
	_tmp._0 = _c1;
	_tmp._1 = _c2;
	_tmp._2 = _weight;
	_tmp._3 = _bore;
	_tmp._4 = time_php();
	array_push(_rels, _tmp);

	shrink_rels();
	return true;
}
clause corer_prove_push(clause _clause, bool _return = false, bool _add_weight =
		true) {
	arr_ls _node_arr;
	long _index;
	_clause._3 = time_php();
	if (_clause._1 == 0)
		_clause._1 = 0.4;
	if (_clause._2 == 0)
		_clause._2 = 0.98;
	if ((_index = find_corer_prove(_clause._0)) < 0)
		array_push(_corer_prove, _clause);
	else {
		if (_add_weight) {
			_corer_prove[_index]._1 = sqrt(
					pow(_corer_prove[_index]._1, 2) * 1.15);
			_corer_prove[_index]._2 = sqrt(
					pow(_corer_prove[_index]._2, 2) * 0.8);
			precision_control_r(_index);
		};
	}
	if (_return)
		return _clause;
	clause _zero;
	return _zero;
}
clause corer_find_push(clause _clause, bool _return = false, bool _add_weight =
		true) {
	arr_ls _node_arr;
	long _index;
	_clause._3 = time_php();
	if (_clause._1 == 0)
		_clause._1 = 0.4;
	if (_clause._2 == 0)
		_clause._2 = 0.98;
	if ((_index = find_corer_find(_clause._0)) < 0)
		array_push(_corer_find, _clause);
	else {
		if (_add_weight) {
			_corer_find[_index]._1 = sqrt(
					pow(_corer_find[_index]._1, 2) * 1.15);
			_corer_find[_index]._2 = sqrt(pow(_corer_find[_index]._2, 2) * 0.8);
			precision_control_r(_index);
		};
	}
	if (_return)
		return _clause;
	clause _zero;
	return _zero;
}
void corer_prove_push_arr(clause _clause, long _key) {
	if (_key == -1) {
		array_push(_corer_prove, _clause);
// return 1;
	} else {
		_corer_prove[_key] = _clause;
// }
	}
}
void corer_find_push_arr(clause _clause, long _key) {
	if (_key == -1) {
		array_push(_corer_find, _clause);
		// return 1;
	} else {
		_corer_find[_key] = _clause;
		// }
	}
}
long r_logic_push(substringC _substringC, bool _return = false,
		bool _add_weight = true) {
	arr_ls _node_arr;
	arr_ll _index;
	if (!(_index = find_r_logic(_substringC)).empty())
		//array_push(_r_logic, _substringC);
		return -1;
	else {
		array_push(_r_logic, _substringC);
	}
	if (_return && _r_logic.size() > 1)
		return _r_logic.last_key();
	return -1;
}
void r_logic_push_arr(arr_ls _gt, string _kl, long _key = -1) {
	if (_key == -1) {
		array_push(_r_logic, substringC(_gt, _kl));
		// return 1;
	} else {
		_r_logic[_key] = substringC(_gt, _kl);
		// }
	}
}
bool in_array_lv2_0(string _ele, arr_lc _arr) {
	string _array;
	clause _ele_tmp;
	/*
	 * check if _ele is one of _array[i]._0;
	 * return true or false;
	 */
	for (auto const& [_key_rtt, _ele_tmp] : _arr) {
		if (_ele == _ele_tmp._0)
			return true;
	}
	return false;
}
//not used
arr_lc all_match_array_lv2_0(string _pattern, arr_lc _arr) {
	clause _ele;
	arr_lc _array;
	arr_lc _return;
//	long _key;
	clause _ele_tmp;
	/*
	 * check if _ele on eles of _array[i]._0;
	 * return array or false;
	 */
	for (auto const& [_key, _ele_tmp] : _arr) {
		if (preg_match(_pattern, _ele_tmp._0))
			_return[_key] = _ele_tmp;
	}
	return _return;
}
long array_search_lv2_0(string _ele, arr_lc _arr) {
//	long _k;
	clause _ele_tmp;
	/*
	 * check if _ele is one of _array[i]._0;
	 * return key or false;
	 */
	for (auto const& [_k, _ele_tmp] : _arr) {
		if (_ele == _ele_tmp._0)
			return _k;
	}
	return -1;
}
long array_search_lv2_0(string _ele, arr_lls _arr) {
//	long _k;
	arr_ls _ele_tmp;
	/*
	 * check if _ele is one of _array[i]._0;
	 * return key or false;
	 */
	for (auto const& [_k, _ele_tmp] : _arr) {
		if (_ele == _ele_tmp.begin()->second)
			return _k;
	}
	return -1;
}
long find_in_array_lv2_0_contain(string _ele, arr_lc _arr) {
//	long _key;
	clause _ele_tmp;
	for (auto const& [_key, _ele_tmp] : _arr) {
		if (strpos(_ele_tmp._0, _ele) > -1)
			return _key;
	}

	return -1;
}
long find_in_array_lv2_0_at_end(string _ele, arr_lc _arr, long _start = 0) {
//	long _sizeof;
//	long _key;
	clause _ele_tmp;
	_ele = str_replace("(", "\\(", _ele);
	_ele = str_replace(")", "\\)", _ele);
	_ele = str_replace("$", "\\$", _ele);
// _sizeof = sizeof ( _arr );
	for (auto const& [_key, _ele_tmp] : _arr) {
		if (preg_match("/" + _ele + "$/", _ele_tmp._0))
			return _key;
	}
	return -1;
}
arr_ll find_all_in_array_lv2_0_at_end(string _ele, arr_lc _arr,
		long _start = 0) {
//	long _sizeof;
	arr_ll _return;
//	long _key;
	clause _ele_tmp;
	_ele = str_replace("(", "\\(", _ele);
	_ele = str_replace(")", "\\)", _ele);
	_ele = str_replace("$", "\\$", _ele);
// _sizeof = sizeof ( _arr );
	for (auto const& [_key, _ele_tmp] : _arr) {
		if (preg_match("/" + _ele + "$/", _ele_tmp._0))
			array_push(_return, _key);
	}
	return _return;
}
long find_in_array_lv2_0_at_start(string _ele, arr_lc _arr, long _start = 0) {
	long _sizeof;
	long _key;
	clause _ele_tmp;
	_ele = str_replace("(", "\\(", _ele);
	_ele = str_replace(")", "\\)", _ele);
	_ele = str_replace("$", "\\$", _ele);
	_sizeof = _arr.size();
	for (_key = _start; _key < _sizeof; _key++) {
		_ele_tmp = _arr[_key];
		if (preg_match("/^" + _ele + "/", _ele_tmp._0))
			return _key;
	}
	return -1;
}
long cache_find(string _clause) {
	return find_in_array_lv2_0(_clause, _cache.get_map());
}
long cache_find_contain(string _clause) {
	return find_in_array_lv2_0_contain(_clause, _cache.get_map());
}
long cache_find_at_end(string _clause) {
	return find_in_array_lv2_0_at_end(_clause, _cache.get_map());
}
long core_find_contain(string _clause) {
	return find_in_array_lv2_0_contain(_clause, _core.get_map());
}
long core_find_at_end(string _clause) {
	return find_in_array_lv2_0_at_end(_clause, _core.get_map());
}
arr_lc array_add(arr_lc _1, arr_lc _2) {
	arr_lc _return = _1;
	for (auto const& [_k, _v] : _2)
		array_push(_return, _v);
	return _return;
}
arr_ll array_add(arr_ll _1, arr_ll _2) {
	arr_ll _return = _1;
	for (auto const& [_k, _v] : _2)
		array_push(_return, _v);
	return _return;
}
arr_ll core_cache_find_all_at_end(string _clause) {
	return array_add(find_all_in_array_lv2_0_at_end(_clause, _core.get_map()),
			find_all_in_array_lv2_0_at_end(_clause, _cache.get_map()));
}
long core_find_at_start(string _clause) {
	return find_in_array_lv2_0_at_start(_clause, _core.get_map());
}
string find_represent(string _clause) {
	long _index;
	string _result;
	/*
	 * return a full clause;
	 */
	try {
		if ((_index = in_core("@g@i@_clause"))) {
			return explode("@", _core[_index]._0)[0];
		} else if ((_index = in_cache("@g@i@_clause")) != false) {
			return explode("@", _cache[_index]._0)[0];
		} else if (tl(_result = in_db(_clause)) > -1) {
			return _result;
		}
	} catch (...) {
		l("could not found: " + _clause);
		return "";
	}
	return "";
}
string get_num(string _word) {
	arr_lss _return;
	_return = dbs(
			"select id from new_vocal where vocal_str = \"" + _word + "\"");
	if (!_return.empty())
		return _return.begin()->second["id"];
	return "";
}
string word_type_update(string _type_x) {
	arr_lls _arr;
	string _ele;
	arr_ls _tmpa;
	_tmpa[0] = "pron";
	_tmpa[1] = "pronoun";
	array_push(_arr, _tmpa);

	_tmpa[0] = "n";
	_tmpa[1] = "noun";
	array_push(_arr, _tmpa);

	_tmpa[0] = "adv";
	_tmpa[1] = "adverb";
	array_push(_arr, _tmpa);

	_tmpa[0] = "v";
	_tmpa[1] = "verb";
	array_push(_arr, _tmpa);

	_tmpa[0] = "a";
	_tmpa[1] = "adjective";
	array_push(_arr, _tmpa);

	_tmpa[0] = "prep";
	_tmpa[1] = "preposition";
	array_push(_arr, _tmpa);

	_tmpa[0] = "conj";
	_tmpa[1] = "conjunction";
	array_push(_arr, _tmpa);

	_tmpa[0] = "interj";
	_tmpa[1] = "interjection";
	array_push(_arr, _tmpa);

	_tmpa[0] = "pp";
	_tmpa[1] = "past-participle";
	array_push(_arr, _tmpa);

	_tmpa[0] = "pl";
	_tmpa[1] = "plural";
	array_push(_arr, _tmpa);

	_tmpa[0] = "sep";
	_tmpa[1] = "separator";
	array_push(_arr, _tmpa);

	_tmpa[0] = "pref";
	_tmpa[1] = "prefix";
	array_push(_arr, _tmpa);

	_tmpa[0] = "sym";
	_tmpa[1] = "symbol";
	array_push(_arr, _tmpa);

	_tmpa[0] = "be";
	_tmpa[1] = "to-be";
	array_push(_arr, _tmpa);

	for (auto& [_key_rtt, _ele] : _arr) {
		if (_ele[0] == _type_x)
			return _ele[1];
	}
	return "";
}
string code_2_lang(string input) {
	return "error code2lang placeholder";
}
string create_find_represent_force(string _clause, bool _table_f = false) {
	string _return;
	string _new_node_num;
	arr_lss _dbq;
	string _table;
	string _types;
	arr_ls _type_arr;
	string _type;
	string _type_num;
// return the smallest node id that is unused
	if (_clause == "" || strpos(_clause, "@") == 0)
		return "";
	_return = find_represent(_clause);
	if (_return != "")
		return _return;

//	_current_maxid = _max_node;
//	_max_node++;
//	_current_maxid++;
	_dbq = dbs("select id from gi_f where c ='_clause'");
	if (_dbq.empty()) {
		_dbq = dbs("select id from gi where c ='_clause'");
	}
	if (!_dbq.empty()) {
		return _dbq.begin()->second["id"];
	}
	_table = _table_f ? "gi_f" : "gi";
	_new_node_num = new_node_num();
	core_push(clause(_new_node_num + "@g@i@_clause", 0.5, 0.5));
	dbq(
			"insert into _table (id, c, weight, bore) values(_current_maxid, '_clause', 1,1)");
	if (_table_f) {
		echo("What is type of " + code_2_lang(_clause));
		cin >> _types;
		_type_arr = explode(",", _types);
		for (auto const& [_key_rtt, _type] : _type_arr) {
			_type_num = get_num(word_type_update(_type));
			dbq(
					"insert into go_f (c1, c2, weight, bore) values( _type_num, _current_maxid, 1,1)");
		}
	}
	return _new_node_num;
}
string create_find_represent(string _clause, bool _table_f = false) {
	string _return;
	string _new_node_num;
	arr_lss _dbq;
	string _table;
	string _types;
	arr_ls _type_arr;
	string _type;
	string _type_num;
// return the smallest node id that is unused
	if (_clause == "" || strpos(_clause, "@") < 0)
		return "";
	if (strpos(_clause, "g@i") > -1)
		return "";
	if (find_node_in_clause("254", _clause) > -1)
		return "";
	_return = find_represent(_clause);
	if (_return != "")
		return _return;

//	_current_maxid = _max_node;
//	_max_node++;
//	_current_maxid++;
	_dbq = dbs("select id from gi_f where c ='_clause' ");
	if (_dbq.empty()) {
		_dbq = dbs("select id from gi where c ='_clause'");
	}
	if (!_dbq.empty()) {
		return _dbq[0]["id"];
	}
	_table = _table_f ? "gi_f" : "gi";
	_new_node_num = new_node_num();
	core_push(clause(_new_node_num + "@g@i@" + _clause, 0.5, 0.5));
	dbq(
			"insert into " + _table + " (id, c, weight, bore) values("
					+ _new_node_num + ", '" + _clause + "', 1,1)");
	if (_table_f) {
		echo("What is type of " + code_2_lang(_clause));
		cin >> _types;
		_type_arr = explode(",", _types);
		for (auto const& [_key_rtt, _type] : _type_arr) {
			_type_num = get_num(word_type_update(_type));
			dbq(
					"insert into go_f (c1, c2, weight, bore) values( "
							+ _type_num + ", " + _new_node_num + ", 1,1)");
		}
	}
	return _new_node_num;
}
bool cache_push_each(arr_lc _multi_clauses) {
	clause _clause;
	for (auto const& [_key_rtt, _clause] : _multi_clauses) {
		cache_push(_clause);
	}
	return true;
}
bool db_push_each(arr_lc _multi_clauses) {
	clause _clause;
	for (auto const& [_key_rtt, _clause] : _multi_clauses) {
		db_push(_clause);
	}
	return true;
}
bool multi_clause_match(string _multi_clause1, string _multi_clause2) {
	bool _check;
	arr_ls _multi_clause1_arr;
	arr_ls _multi_clause2_arr;
	string _clause1;
	string _clause2;
// find if @multiclause1 has all multi_clause2 ele
	_multi_clause1_arr = explode("&", _multi_clause1);
	_multi_clause2_arr = explode("&", _multi_clause2);
	for (auto const& [_key_rtt, _clause1] : _multi_clause1_arr) {
		_check = false;
		for (auto const& [_key_rtt, _clause2] : _multi_clause2_arr) {
			if (_clause1 == _clause2) {
				_check = true;
				break;
			}
		}
		if (_check)
			continue;
		else
			return false;
	}
	return true;
}
string implode2(arr_lls _arr, string _delimiter1 = "&",
		string _delimiter2 = "@") {
	arr_ls _tmp_arr;
	string _line;
	string _return;
	try {
		for (auto const& [_key_rtt, _line] : _arr) {
			array_push(_tmp_arr, implode(_delimiter2, _line));
		}
		_return = implode(_delimiter1, _tmp_arr);
		return _return;
	} catch (...) {
		return "";
	}
}
arr_lls explode2(string _str, string _delimiter1 = "&",
		string _delimiter2 = "@") {
	arr_lls _return;
	arr_ls _explode1;
	string _line;
	_explode1 = explode(_delimiter1, _str);
	for (auto const& [_key_rtt, _line] : _explode1) {
		array_push(_return, explode(_delimiter2, _line));
	}
	return _return;
}
arr_ls explode2_to_0(string _str, string _delimiter1 = "&", string _delimiter2 =
		"@") {
	arr_ls _return;
	arr_ls _explode1;
	arr_ls _line;
	arr_ls _explode2;
	string _ele;
	_explode1 = explode(_delimiter1, _str);
	for (auto const& [_key_rtt, _line] : _explode1) {
		_explode2 = explode(_delimiter2, _line);
		for (auto const& [_key_rtt, _ele] : _explode2) {
			array_push(_return, _ele);
		}
	}
	return _return;
}
arr_ls explode3(string _str, string _delimiter0 = "c", string _delimiter1 = "&",
		string _delimiter2 = "@") {
	arr_ls _return;
	arr_ls _explode0;
	string _line0;
	arr_ls _explode1;
	string _line1;
	arr_ls _explode2;
	string _line2;
	_explode0 = explode(_delimiter0, _str);
	for (auto const& [_key_rtt, _line0] : _explode0) {
		_explode1 = explode(_delimiter1, _line0);
		for (auto const& [_key_rtt, _line1] : _explode1) {
			_explode2 = explode(_delimiter2, _line1);
			for (auto const& [_key_rtt, _line2] : _explode2) {
				array_push(_return, _line2);
			};
		}
	}
	return _return;
}
arr_ls cut_head(clause _clause) {
	arr_ls _node_arr;
	string _cutted_node;
	arr_ls _return;
	_node_arr = explode("@", _clause._0);
	_cutted_node = array_shift(_node_arr);
	_return[0] = implode("@", _node_arr);
	_return[1] = _cutted_node;
	return _return;
}
arr_ls cut_tail(clause _clause) {
	arr_ls _node_arr;
	string _cutted_node;
	arr_ls _return;
	_node_arr = explode("@", _clause._0);
	_cutted_node = _node_arr.rbegin()->second;
	_node_arr.erase(_node_arr.rbegin()->first);
	_return[0] = implode("@", _node_arr);
	_return[1] = _cutted_node;
	return _return;
}
long node_count(string _str) {
	return (long) explode("@", _str).size();
}
string node_replace_with_index(string _find_ele, string _replace_ele,
		string _pure_clause, long _index_of_replace_ele_in_clause) {
	arr_ls _ele;
	_ele = explode("@", _pure_clause);
	_ele[_index_of_replace_ele_in_clause - 1] = _replace_ele;
	return implode("@", _ele);
}
bool array_equal(arr_ls _arr1, arr_ls _arr2) {
	string _ele1;
	long _key;
	if ((_arr1.size()) != (_arr2.size()))
		return false;
	for (auto const& [_key_rtt, _ele1] : _arr1) {
		if ((_key = array_search(_ele1, _arr2)) == false)
			return false;
		else
			_arr2.erase(_key);
	}
	return true;
}
void increase_weight(long _core_key) {
	double _tmp;
	_tmp = pow(_core[_core_key]._1, 1 / 3);
	core_update_wb(_core_key, 1, _tmp);
}
long in_array_table(string _find, arr_lls _arr, long _row) {
	string _k;
	string _smaller_arr;
// find if _find is in _arr[*][_row];
	for (auto& [_k, _smaller_arr] : _arr) {
		if (_find == _smaller_arr[_row])
			return _k;
	}
	return -1;
}
bool contain_in_array_lv2_0(string _ele, arr_lc _arr) {
	clause _ele_tmp;
	for (auto const& [_key_rtt, _ele_tmp] : _arr) {
		if (strpos(_ele_tmp._0, _ele) > -1)
			return true;
	}
	return false;
}
bool core_find_pattern(string _pattern) {
	clause _clause;
	string _str;
	_pattern = '^' + _pattern + '_';
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		_str = _clause._0;
		if (preg_match(_pattern, _str)) {
			return true;
		}
	}
	return false;
}
//not used
long group_count(string _group) {
	long _count;
	clause _clause;
	_count = 0;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		if (strpos(_group + "@g@o@", _clause._0) >= 1)
			_count++;
	}
	return _count;
}
string find_word(string _num) {
	arr_lss _return;
	_return = dbs("select vocal_str from new_vocal where id = " + _num);
	try {
		return _return.begin()->second["vocal_str"];
	} catch (...) {
		return "";
	}
}
double weight_a_clause(clause _clause) {
	return sqrt(_clause._1 * _clause._2);
}
string find_create_num(string _word) {
	arr_lss _data;
	string _new_node_num;
	string _return;
	_data = dbs(
			"select id from new_vocal where vocal_str = '" + _word
					+ "' limit 1");
	if (_data.empty()) {
		_new_node_num = new_node_num();
		dbq(
				"insert into new_vocal (id, vocal_str) values (" + _new_node_num
						+ ", '" + _word + "')");
		return _new_node_num;
	}
	_return = _data.begin()->second["id"];
	return _return;
}
string read_to_num(string _str) {
	string _definition;
	arr_ls _words;
//	long _key;
	string _word;
	arr_lss _result;
	string _replace_num;
	string _sentence;
	_definition = trim(_str);
	_definition = str_replace("\r\n", " ", _definition);
	_definition = str_replace("\n", " ", _definition);
	_definition = str_replace(",", " ,", _definition);
	_definition = str_replace(".", " .", _definition);
	_definition = str_replace(";", " ;", _definition);
	_definition = str_replace("--", " -", _definition);
	_definition = str_replace("(", "( ", _definition);
	_definition = str_replace(")", " )", _definition);
	_definition = str_replace("[", "( ", _definition);
	_definition = str_replace("]", " )", _definition);
	_definition = str_replace("'s ", " 's ", _definition);
	_definition = str_replace("'s;", " 's ;", _definition);
	_definition = str_replace("'s.", " 's .", _definition);
	_definition = str_replace("'s,", " 's ,", _definition);
	_definition = str_replace("\"", " \\\" ", _definition);
	_definition = str_replace("/", " / ", _definition);
	_definition = str_replace(":", " :", _definition);
	_definition = str_replace("?", " ?", _definition);
	_definition = str_replace("&", " &", _definition);
	_definition = str_replace("!", " !", _definition);
	_words = explode(" ", _definition);
	for (auto& [_key, _word] : _words) {
		_word = strtolower(trim(_word));
		if (_word == "")
			continue;
		_result = dbs(
				"select id from new_vocal where word = '" + _word
						+ "' limit 1");
		try {
			if (is_numeric(_word))
				_words[_key] = "z_word";
			else {
				l("Error: " + _word + ":" + _word + "\n", 3);
				continue;
			}
		} catch (...) {
			_replace_num = _result.begin()->second["id"];
			_words[_key] = _replace_num;
		}
	}
	_sentence = implode("@", _words);
	return _sentence;
}
bool find_if_there_is_one_ele_of_arr1_in_arr2(arr_ls _arr1, arr_ls _arr2) {
	string _ele1;
	string _ele2;
	for (auto const& [_key_rtt, _ele1] : _arr1) {
		for (auto const& [_key_rtt, _ele2] : _arr2) {
			if (_ele1 == _ele2)
				return true;
		}
	}
	return false;
}
string get_word(string _id) {
	arr_lss _data;
	_data = dbs("select vocal_str from new_vocal where id = " + _id);
	try {
		return _data[0]["vocal_str"];
	} catch (...) {
		return "";
	}
}
string explain(string _str) {
	arr_ls _arr;
//	long _k;
	string _ele;
	_arr = explode("@", _str);
	for (auto const& [_k, _ele] : _arr) {
		_arr[_k] = get_word(_ele);
	}
	return implode(" ", _arr);
}
//not used
arr_ls find_duplicated_core() {
	arr_ls _return;
//	long _k;
	clause _clause0;
//	long _j;
	clause _clause1;
	for (auto const& [_k, _clause0] : _core.get_map()) {
		for (auto const& [_j, _clause1] : _core.get_map()) {
			if (_k == _j)
				continue;
			if (_clause0._0 == _clause1._0) {
				array_push(_return, _clause0._0);
			}
		}
	}
	return (_return);
}
long count_num(arr_ls _arr) {
	long _count;
	string _ele;
	_count = 0;
	for (auto const& [_key_rtt, _ele] : _arr) {
		try {
			long _tmp = tl(_ele);
			if (_tmp < 0 || _tmp >= 0)
				_count++;
		} catch (...) {
		}
	}
	return _count;
}
string general_processing(string _input) {
	string _return;
	arr_ls _arr;
	string _ele;
	_return = _input;
	array_push(_arr, (string) "\r\n");
	array_push(_arr, (string) "\n");
	array_push(_arr, (string) " ");
	array_push(_arr, (string) "\t");
	for (auto const& [_key_rtt, _ele] : _arr) {
		_return = str_replace(_ele, "", _return);
	}
	_return = trim_str(_return, "&");
	_return = trim(trim_str(_return));
	return _return;
}
arr_ls general_processing(arr_ls _input) {
	arr_ls _return;
	for (auto const& [_key_rtt, _ele] : _input) {
		if (_ele != "") {
			array_push(_return, _ele);
		}
	}
	return _return;
}
bool is_var(string _str) {
	if (strpos(_str, "$") == 0)
		return true;
	return false;
}
bool is_x(string _str) {
	if (strpos(_str, "x") == 0)
		return true;
	return false;
}
arr_lll array_mix(arr_lll _arr) {
	arr_lll _return;
	string _ele;
	arr_lll _tmp_arr;
	arr_ll _first_line;
	arr_lll _lower_array_mix;
	arr_ll _lower_result;
	string _tmp_lower_result;
	if (_arr.size() == 0) {
		return arr_lll_zero;
	}
	if (_arr.size() == 1) {
		for (auto const& [_key_rtt, _ele] : _arr.begin()->second) {
			arr_ll _tmp_arr1 = { { 1, _ele } };
			array_push(_return, _tmp_arr1);
		}
		return _return;
	}
	_tmp_arr = _arr;
	_first_line = _tmp_arr.begin()->second;
	_tmp_arr.erase(_tmp_arr.begin()->first);
	_lower_array_mix = array_mix(_tmp_arr);
	arr_ll _first_line_tmp = _first_line;
	for (auto& [_key_rtt, _ele] : _first_line_tmp) {
		for (auto& [_key_rtt, _lower_result] : _lower_array_mix) {
			if (in_array(_ele, _lower_result) && _ele != -1) {
				continue;
			}
			arr_ll _lower_result_tmp = _lower_result;
			array_unshift(_ele, _lower_result_tmp);
			array_push(_return, _lower_result_tmp);
		}
	}
	return _return;
}
//arr_llb array_mix(arr_llb _arr) {
//	arr_llb _return;
//	string _ele;
//	arr_llb _tmp_arr;
//	arr_lb _first_line;
//	arr_llb _lower_array_mix;
//	arr_lb _lower_result;
//	string _tmp_lower_result;
//	if (_arr.size() == 0) {
//		return arr_llb_zero;
//	}
//	if (_arr.size() == 1) {
//		for (auto const& [_key_rtt, _ele] : _arr[0]) {
//			arr_lb _tmp_arr1 = { { 1, _ele } };
//			array_push(_return, _tmp_arr1);
//		}
//		return _return;
//	}
//	_tmp_arr = _arr;
//	_first_line = _tmp_arr.begin()->second;
//	_tmp_arr.erase(_tmp_arr.begin()->first);
//	_lower_array_mix = array_mix(_tmp_arr);
//	for (auto const& [_key_rtt, _ele] : _first_line) {
//		for (auto const& [_key_rtt, _lower_result] : _lower_array_mix) {
//			if (in_array(_ele, _lower_result)) {
//				continue;
//			}
//			array_unshift(_ele, _lower_result);
//			array_push(_return, _lower_result);
//		}
//	}
//	return _return;
//}
arr_lll array_mix_limited(arr_lll _arr, long _limited = 5) {
	arr_lll _all_mix = array_mix(_arr);
	arr_lll _return;
//arr_ld _values_of_mixes;
	for (long _i = 0; _i < _limited; _i++) {
		if (_all_mix.empty())
			break;
		long _max_key = 0;
		double _max_tmp_value = 0;
		for (auto const& [_k, _ll] : _all_mix) {
			double _tmp_value = 0;
			for (auto const& [_k1, _v1] : _ll) {
				if (_v1 == -1)
					_tmp_value += 0;
				else if (_core.contains(_v1))
					_tmp_value += _core[_v1]._1 * _core[_v1]._2;
				else if (_cache.contains(_v1))
					_tmp_value += _cache[_v1]._1 * _cache[_v1]._2;
			}
			_tmp_value = _tmp_value / _ll.size();
			if (_tmp_value >= _max_tmp_value) {
				_max_tmp_value = _tmp_value;
				_max_key = _k;
			}
		}
		array_push(_return, _all_mix[_max_key]);
		_all_mix.erase(_max_key);
	}
	return _return;
}
//arr_llb array_mix_limited(arr_llb _arr, long _limited = 5) {
//	arr_llb _all_mix = array_mix(_arr);
//	arr_llb _return;
////arr_ld _values_of_mixes;
//	for (long _i = 0; _i < _limited; _i++) {
//		long _max_key = 0;
//		double _max_tmp_value = 0;
//		for (auto const& [_k, _ll] : _all_mix) {
//			double _tmp_value = 1;
//			for (auto const& [_k1, _v1] : _ll) {
//				_tmp_value = _tmp_value * _core[_v1]._1 * _core[_v1]._2;
//			}
//			_tmp_value = pow(_tmp_value, (2.0 / _ll.size()));
//			if (_tmp_value > _max_tmp_value) {
//				_max_tmp_value = _tmp_value;
//				_max_key = _k;
//			}
//		}
//		array_push(_return, _all_mix[_max_key]);
//	}
//	return _return;
//}
double geo_avg_arr(arr_ld _arr) {
	double _return;
//	double _ele;
	_return = 1;
	for (auto const& [_key_rtt, _ele] : _arr) {
		if (_ele != 0.0)
			_return *= _ele;

	}
	return pow(_return, 1.0 / (double) _arr.size());
}
bool is_node_or_z_or_x(string _str) {
	try {
		td(_str);
		return true;
	} catch (...) {
	}
	if (preg_match("\\$xz[0-9] {1,}", _str))
		return true;
	return false;
}
void shrink_core_r() {
	long _index_to_eliminated;
	long _i;
	double _tmp_effective;
//	long _key;
	clause _clause;
	double _effective_index;
	long _key_to_remove = 0;
	//corer_find_type _core_tmp;
//	long _k;
	//arr_lc _tmp_clause;
	_index_to_eliminated = count(_corer_prove) - MAX_corer_prove_SIZE;
	for (_i = 0; _i <= _index_to_eliminated; _i++) {
		_tmp_effective = 1;
		for (auto const& [_key, _clause] : _corer_prove.get_map()) {
			_effective_index = _clause._1 + _clause._2;
			if (_effective_index <= _tmp_effective) {
				_key_to_remove = _key;
			}
		}
		_corer_prove.erase(_key_to_remove);
		// cache_push ( _corer_prove [_key_to_remove] );
	}
	_corer_prove.re_assoc();
//	for (auto const& [_k, _clause] : _corer_prove) {
//		for (auto const& [_key_rtt, _tmp_clause] : _core_tmp) {
//			if (_tmp_clause._0 == _clause._0) {
//				_corer_prove.erase(_k);
//				continue;
//			}
//		}
//		array_push(_core_tmp, _clause);
//	}
	_index_to_eliminated = _corer_find.size() - MAX_corer_find_SIZE;
//	for (_i = 0; _i <= _index_to_eliminated; _i++) {
//		_tmp_effective = 1;
//		for (auto const& [_key, _clause] : _corer_find) {
//			_effective_index = _clause._1 + _clause._2;
//			if (_effective_index <= _tmp_effective) {
//				_key_to_remove = _key;
//				_corer_find.erase(_key_to_remove);
//			}
//		}
//// cache_push ( _corer_find [_key_to_remove] );
//	}
	for (_i = 0; _i <= _index_to_eliminated; _i++) {
		_tmp_effective = 1;
		for (auto const& [_key, _clause] : _corer_find.get_map()) {
			_effective_index = _clause._1 + _clause._2;
			if (_effective_index <= _tmp_effective) {
				_key_to_remove = _key;
			}
		}
		_corer_find.erase(_key_to_remove);
		// cache_push ( _corer_prove [_key_to_remove] );
	}
	_corer_find.set_map(array_values(_corer_find.get_map()));
}
void shrink_r_logic() {
	long _index_to_eliminated;
	long _i;
//	double _tmp_effective;
//	long _key;
	clause _clause;
//	double _effective_index;
//	long _key_to_remove;
//	double _need_to_removed_bored;
	arr_lc _core_tmp;
//	long _k;
	arr_lc _tmp_clause;
	_index_to_eliminated = (_r_logic.size()) - MAX_R_LOGIC_SIZE;
	for (_i = 0; _i <= _index_to_eliminated; _i++) {
		_r_logic.erase(_r_logic.first_key());
	}
	_r_logic.re_assoc();
// if (count ( (_need_to_removed_bored = _GLOBALS ["local_bored" - MAX_LOCAL_BORED]) ) > 0) {
// for(_i = 0; _i <= _need_to_removed_bored; _i ++) {
// array_shift ( _local_bored );
// }
// }
//	for (auto const& [_k, _clause] : _r_logic) {
//		for (auto const& [_key_rtt, _tmp_clause] : _core_tmp) {
//			if (_tmp_clause._0 == _clause._0) {
//				_r_logic.erase(_k);
//				continue;
//			}
//		}
//		array_push(_core_tmp, _clause);
//	}
}
void core_remove_each(arr_ll _arr) {
	string _num;
// if(_mode=="mt");
	for (auto const& [_key_rtt, _num] : _arr) {
		_core.erase(_num);
		_may_match.erase(_num);
		_core_gi.erase(_num);
		_core_go.erase(_num);
		_core_t.erase(_num);
		_core_d.erase(_num);
		_core_l.erase(_num);
		_core_others.erase(_num);
	}
}
void core_update(long _i, string _new_clause) {
	_core[_i]._0 = _new_clause;
	clause _full_clause = _core[_i];
	_core_gi.erase(_i);
	_core_go.erase(_i);
	_core_t.erase(_i);
	_core_d.erase(_i);
	_core_l.erase(_i);
	_core_others.erase(_i);
	if (strpos(_new_clause, "@g@i@") > -1)
		_core_gi[_i] = _full_clause;
	else if (strpos(_new_clause, "@g@o@") > -1)
		_core_go[_i] = _full_clause;
	else if (strpos(_new_clause, "t") > -1)
		_core_t[_i] = _full_clause;
	else if (strpos(_new_clause, "d") == 0)
		_core_d[_i] = _full_clause;
	else if (strpos(_new_clause, "l") == 0)
		_core_l[_i] = _full_clause;
	else {
		_core_others[_i] = _full_clause;
	}
//	if (_mode == "gt")
//		test_match_core(_i);
//	else
//		_return["core_update"][_i] = _new_clause;
}
void core_update_each(arr_lc _arr) {
//	long _k;
	clause _ele;
	for (auto const& [_k, _ele] : _arr) {
		core_update(_k, _ele._0);
	}
}
//void core_update_wb(long _num, long _key, double _new) {
//	if (_key == 1)
//		_core[_num]._1 = _new;
//	else if (_key == 2)
//		_core[_num]._2 = _new;
////	if (_mode == "mt")
////		_return["core_update"][_num] = _core[_num];
//}
void core_update_arr(long _i, clause _new_clause) {
//	if (_mode == "mt")
//		_core_update[_i] = _new_clause;
	_core[_i] = _new_clause;
	test_match_core(_i);
}
bool reduce_rels(string _obj1, string _obj2) {
	arr_ss _data;
	long _id;
	double _new_weight;
	double _new_bore;
	arr_lss _data1 = dbs(
			"SELECT * FROM rels WHERE (c1 = \"" + _obj1 + "\" AND c2 = \""
					+ _obj2 + "\") OR (c1 = \"" + _obj2 + "\" AND c2 = \""
					+ _obj1 + "\") limit 1");
	if (_data1.size() > 0) {
		_data = _data1.begin()->second;
		_id = tl(_data["id"]);
		_new_weight = pow(td(_data["weight"]), 1.04);
		_new_bore = pow(td(_data["bore"]), 1.04);
		if (_new_weight <= 0)
			_new_weight = 0.005;
		if (_new_bore <= 0)
			_new_bore = 0.005;
		dbq(
				"UPDATE rels SET weight = " + ts(_new_weight) + ", bore = "
						+ ts(_new_bore) + " WHERE id = " + ts(_id));
		return true;
	}
// dbq ( "INSERT INTO rels (c1, c2, weight, bore) VALUES ('_obj1','_obj2', 0.04, 0,04)" );
	rel_push(_obj1, _obj2, 0.15, 0.15);
	return true;
}
void reduce_rels_word_2_str_rule_1(string _multi_clause_str, long _rel_id) {
	arr_ls _arr;
	string _ele;
	string _ele_str;
	_arr = explode2_to_0(_multi_clause_str);
	for (auto const& [_key_rtt, _ele] : _arr) {
		_ele_str = "w" + _ele;
		reduce_rels(_ele_str, "r" + _rel_id);
	}
}
bool make_rels(string _obj1, string _obj2) {
	arr_lss _data1;
	arr_ss _data;
	long _id;
	double _new_weight = 0;
	double _new_bore = 0;
// database
	_data1 = dbs(
			"SELECT * FROM rels WHERE (c1 = \"" + _obj1 + "\" AND c2 = \""
					+ _obj2 + "\") OR (c1 = \"" + _obj2 + "\" AND c2 = \""
					+ _obj1 + "\") limit 1");
	if (_data.size() > 0) {
		_data = _data1.begin()->second;
		_id = tl(_data["id"]);
		if (td(_data["weight"]) > 0)
			_new_weight = pow(td(_data["weight"]) * td(_data["weight"]) * 1.07,
					0.5);
		if (td(_data["bore"]) > 0)
			_new_bore = pow(td(_data["bore"]) * td(_data["bore"]) * 1.07, 0.5);
		if (_new_weight <= 0.005)
			_new_weight = 0.005;
		if (_new_bore <= 0.005)
			_new_bore = 0.05;
		if (_new_weight >= 0.995)
			_new_weight = 0.995;
		if (_new_bore >= 0.995)
			_new_bore = 0.995;
		dbq(
				"UPDATE rels SET weight = " + ts(_new_weight) + ", bore = "
						+ ts(_new_bore) + " WHERE id = " + ts(_id));
	} else {
		dbq(
				"INSERT INTO rels (c1, c2, weight, bore) VALUES (\"" + _obj1
						+ "\",\"" + _obj2 + "\", \"0.04\", \"0.04\")");
	}
// memory
	rel_push(_obj1, _obj2, 0.85, 0.85);
	return true;
}
void make_rels_word_2_str_rule_1(string _multi_clause_str, long _rel_id) {
	arr_ls _arr;
	arr_ls _ele;
	string _ele_str;
	_arr = explode2_to_0(_multi_clause_str);
	for (auto const& [_key_rtt, _ele] : _arr) {
		try {
			td(_ele);
			continue;
		} catch (...) {
		}
		_ele_str = "w" + _ele;
		make_rels(_ele_str, "r" + _rel_id);
	}
}
double core_weight_avg() {
	long _count;
	double _weight_total;
	clause _clause;
	_count = _core.size();
	_weight_total = 0;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		_weight_total += _clause._1;
	}
	return _weight_total / _count;
}
double core_bore_avg() {
	long _count;
	double _bore_total;
	clause _clause;
	_count = count(_core.get_map());
	_bore_total = 0;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		_bore_total += _clause._2;
	}
	return _bore_total / _count;
}
string find_clause_between_brackets(string _str,
		long _pos_of_open_bracket = 0) {
	long _len;
	long _pos_of_close_bracket;
	long _index;
	long _i;
	string _char;
	_len = strlen(_str);
	_pos_of_close_bracket = _len;
	_index = 0;
	for (_i = _pos_of_open_bracket; _i < _len; _i++) {
		_char = _str[_i];
		if (_char == "(")
			_index++;
		else if (_char == ")") {
			_index--;
			if (_index <= 0) {
				_pos_of_close_bracket = _i;
				break;
			}
		}
	}
	return substr(_str, _pos_of_open_bracket + 1,
			_pos_of_close_bracket - 1 - _pos_of_open_bracket);
}
string find_first_gi_right_clause(string _gi_str) {
	string _right_clause;
	_right_clause = explode("@g@i@", _gi_str)[1];
	return find_clause_between_brackets(_right_clause, 0);
}
long find_explain_key(string _num) {
//	long _k;
	string _c;
	for (auto const& [_k, _c] : _core.get_map()) {
		if (strpos(_num + "@g@i@", _c._0) == 0)
			return _k;
	}
	return -1;
}
#endif /* SRC_LIBS_LIBS1_H_ */
