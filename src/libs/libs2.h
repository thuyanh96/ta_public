/*
 * libs2.h
 *
 *  Created on: May 18, 2021
 *      Author: qu
 */

#ifndef SRC_LIBS_LIBS2_H_
#define SRC_LIBS_LIBS2_H_
//#include<php2cpp.h>
//#include<connect.h>
//#include<one_cycle.h>
void make_rels_word_1_word_1(string _result_str) {
	arr_ls _result_arr;
	string _group_clause;
	string _result_clause;
	string _right_clause;
	string _first_node;
	string _second_node;
	_result_arr = explode("&", _result_str);
	_group_clause = "";
	for (auto const& [_key_rtt, _result_clause] : _result_arr) {
		if (strpos("@g@i@", _result_clause) > -1) {
			_group_clause = _result_clause;
// break;
			_right_clause = find_first_gi_right_clause(_group_clause);
			_first_node = explode("@", _right_clause)[0];
			_second_node = explode("@", _right_clause)[1];
			make_rels(_first_node, _second_node);
		}
	}
}
long array_search_pair_no_order(arr_l2 _arr, string _ele1, string _ele2) {
//	long _key;
	dual _ele;
	for (auto const& [_key, _ele] : _arr) {
		if ((_ele._0 == _ele1 && _ele._1 == _ele2)
				|| (_ele._1 == _ele1 && _ele._0 == _ele2))
			return _key;
	}
	return -1;
}
double avg_offset(arr_ld _arr, double _base_num) {
	double _return;
//	double _ele;
	if (_arr.size() < 1)
		return 0.0;
	_return = 0;
	for (auto const& [_key_rtt, _ele] : _arr) {
		_return += _ele - _base_num;
	}
	return _return / (_arr.size()) + _base_num;
}
string revert_c(string _c) {
	arr_ls _arr;
	_arr = explode("@c@", _c);
	return _arr[1] + "@c@" + _arr[0];
}
bool has_duplicated(arr_ls _arr) {
	return (count(array_unique(_arr)) < count(_arr) ? true : false);
}
arr_lls single_pair_match(string _clause, string _gt) {
	arr_ls _clause_arr;
	arr_ls _clause_tmp;
	arr_ls _gt_arr;
	arr_ls _gt_tmp;
	string _gt1;
	string _k;
	string _gt_node;
	string _var;
	arr_lls _return;
	_clause_arr = explode("@", _clause);
	_gt_arr = explode("@", _gt);
	_gt1 = _gt;
	for (auto const& [_k, _gt_node] : _gt_arr) {
		if (is_var(_gt_node) && !in_array(_gt_node, _gt_tmp)) {
			array_push(_gt_tmp, _gt_node);
			array_push(_clause_tmp, _clause_arr[_k]);
		}
	}
	if (has_duplicated(_clause_tmp))
		return arr_lls_zero;
	for (auto const& [_k, _var] : _gt_tmp) {
		_gt1 = node_replace(_var, _clause_tmp[_k], _gt1);
	}
	if (_clause != _gt1)
		return arr_lls_zero;
	array_push(_return, _gt_tmp);
	array_push(_return, _clause_tmp);
	return _return;
}
long core_find_advanced(string _clause_str) {
//	long _k;
	clause _core_clause;
	if (strpos(_clause_str, "x") > -1) {
		for (auto const& [_k, _core_clause] : _core.get_map()) {
			if (!single_pair_match(_core_clause._0, _clause_str).empty())
				return _k;
		}
		return false;
	}
	return true;
}
struct scan_new_node_type {
	string _0;
	arr_lls _1;
};
scan_new_node_type scan_new_node(string _clause_str, arr_lls _maps) {
	arr_ls _map0;
	arr_ls _map1;
	arr_ls _arr;
//	long _k;
	string _ele;
	string _x_node;
	long _i;
	string _new_node;
	string _star_node;
	scan_new_node_type _return;
	if (strpos(_clause_str, "$") == -1) {
		_return._0 = _clause_str;
		_return._1 = _maps;
		return _return;
	}
	_map0 = _maps[0];
	_map1 = _maps[1];
	_arr = explode("@", _clause_str);
	for (auto const& [_k, _ele] : _arr) {
		if (strpos(_ele, "$*") > -1) {
			_x_node = str_replace("$*", "", _ele);
			if ((_i = array_search(_x_node, _map0)) != false) {
				_arr[_k] = _map1[_i];
				continue;
			}
			_new_node = new_node_num();
			array_push(_map1, "x" + _new_node);
			array_push(_map0, _x_node);
			_arr[_k] = "x" + _new_node;
		} else if (strpos(_ele, "$") > -1) {
			_star_node = str_replace("$", "", _ele);
			if ((_i = array_search(_star_node, _map0)) > -1) {
				_arr[_k] = _map1[_i];
				continue;
			}
			_new_node = new_node_num();
			array_push(_map1, _new_node);
			array_push(_map0, _star_node);
			_arr[_k] = _new_node;
		}
	}
	_return._0 = implode("@", _arr);
	_return._1[0] = _map0;
	_return._1[1] = _map1;
	return _return;
}
bool find_logic(arr_ll _posibility_match, long _rule_num, clause _clause) {
	sublongA _logicl;
	// return false;
	for (auto const& [_key_rtt, _logicl] : _logic.get_map()) {
		if (_logicl._1 == _rule_num && _posibility_match == _logicl._0)
			return true;
	}
	return false;
}
string explain_to_lang(string _str, long _lv = 0) {
	arr_ls _arr;
//	long _k;
	string _ele;
	arr_lss _q;
	if (_lv > 50)
		return _str;
	_arr = explode("@", _str);
	for (auto const& [_k, _ele] : _arr) {
		_q = dbs("select * from new_vocal where id = " + _ele);
		if (_q.size() > 0) {
			_arr[_k] = _q.begin()->second["vocal_str"];
		} else {
			_q = dbs("select * from gi_f where id = " + _ele);
			if (_q.size() == 0) {
				_q = dbs("select * from gi where id = " + _ele);
			}
			if (_q.size() > 0)
				_arr[_k] = explain_to_lang(_q.begin()->second["c"], _lv + 1);
			else {
				_arr[_k] = "?" + _ele;
			}
		}
	}
	return implode(" ", _arr);
}
arr_lc find_max_important_rules(long _count) {
	arr_ld _tmp_arr;
	arr_lc _return;
//	long _key;
	clause _rule;
	clause _ignored;
	for (auto const& [_key, _rule] : _rules.get_map()) {
		_tmp_arr[_key] = 1 - geo_avg(_rule._2, _rule._1);
	}
	_tmp_arr = array_top(_tmp_arr, _count);
	for (auto const& [_key, _ignored] : _tmp_arr) {
		_return[_key] = _rules[_key];
	}
	_max_important_rules.set_map(_return);
	return _return;
}
arr_lc find_max_important_x_clauses(long _count) {
	arr_ld _tmp_arr;
	arr_lc _return;
//	long _key;
	clause _clause;
	arr_lc _ignored;
	for (auto const& [_key, _clause] : _core.get_map()) {
		if (strpos(_clause._0, "x") > -1)
			_tmp_arr[_key] = 1 - geo_avg(_clause._2, _clause._1);
	}
	_tmp_arr = array_top(_tmp_arr, _count);
	for (auto const& [_key, _ignored] : _tmp_arr) {
		_return[_key] = _core[_key];
	}
	_max_important_rules.set_map(_return);
	return _return;
}
arr_lc find_max_important_clauses(long _count) {
	arr_ld _tmp_arr;
	arr_lc _return;
//	long _key;
	clause _clause;
//	double _ignored;
	for (auto const& [_key, _clause] : _core.get_map()) {
		_tmp_arr[_key] = 1 - geo_avg(_clause._2, _clause._1);
	}
	_tmp_arr = array_top(_tmp_arr, _count);
	for (auto const& [_key, _ignored] : _tmp_arr) {
		_return[_key] = _core[_key];
	}
	_max_important_rules.set_map(_return);
	return _return;
}
bool single_pair_matchable(string _clause, string _gt) {
	arr_ls _clause_arr;
	arr_ls _gt_arr;
//	double _k;
	string _v;
	_clause_arr = explode("@", _clause);
	_gt_arr = explode("@", _gt);
	if (count(_clause_arr) != count(_gt_arr))
		return false;
	for (auto const& [_k, _v] : _gt_arr) {
		if (!is_var(_v) && _v != _clause_arr[_k])
			return false;
	}
	return true;
}
string remove_from_str(string _str, string _ele) {
	arr_ls _return;
	arr_ls _arr;
//	long _k;
	string _v;
	_arr = explode("&", _str);
	for (auto const& [_k, _v] : _arr) {
		if (_ele == _v)
			_return[_k] = "";
		_return[_k] = _v;
	}
	return implode("&", _return);
}
bool has_duplicated(string _str) {
	return has_duplicated(explode("@", _str));
}
string multi_nodes_replace_on_multi_clauses(arr_lls _transform_table,
		string _multi_clause) {
	long _count;
	long _i;
	_count = _transform_table[0].size();
	for (_i = 0; _i < _count; _i++) {
		_multi_clause = node_replace_multi(_transform_table[0][_i],
				_transform_table[1][_i], _multi_clause);
	}
	return _multi_clause;
}
template<typename K, typename V>
map<K, V> remove_from_arr(map<K, V> _arr, V _ele) {
	map<K, V> _return;
	K _k;
	V _v;
	for (auto const& [_k, _v] : _arr) {
		if (_ele == _v)
			continue;
		_return[_k] = _v;
	}
	return _return;
}
long count_node(string _str) {
	return substr_count(_str, "@") + 1;
}
long calculate_posibilities(arr_lls _arr) {
	long _return;
	bool _element_empty;
	arr_ls _row;
	if (_arr.empty())
		return 0;
	_return = 1;
	_element_empty = true;
	for (auto const& [_key_rtt, _row] : _arr) {
		if (tl(_row.begin()->second) == -1)
			continue;
		_return = _return * _row.size();
		_element_empty = false;
	}
	if (_element_empty)
		return false;
	return _return;
}
//bool find_top_match_single(string _skipped) {
//	bool _return;
//	string _clause;
//	string _rule;
//	bool _match_one;
//	// _return = "";
//	// while ( true ) {
//	for (auto const& [_key_rtt, _clause] : _max_important_clauses) {
//		for (auto const& [_key_rtt, _rule] : _max_important_rules) {
//			_match_one = match_one(_clause, _rule, _skipped);
//			return _match_one;
//		}
//	}
//	// }
//	return false;
//}
//void find_top_matches(long _count) {
//	arr_ls _skipped;
//	long _i;
//	bool _result;
//	for (_i = 0; _i < _count; _i++) {
//		_result = find_top_match_single();
//		if (!_result)
//			break;
//	}
//}
void line() {
	long _i;
	echo (n());for
(	_i = 0; _i < 3; _i++)
	echo(
	"===================================================================================="
	+ n());
}
void reduce_weight_of_max_important_rule_and_clause() {
//	long _k;
	clause _v;
	for (auto const& [_k, _v] : _max_important_clauses.get_map()) {
		_core[_k]._1 = sqrt(_core[_k]._1 * 0.7 * _core[_k]._1);
		_core[_k]._2 = sqrt(_core[_k]._2 * 0.7 * _core[_k]._2);
	}
	for (auto const& [_k, _v] : _max_important_rules.get_map()) {
		_rules[_k]._1 = sqrt(_rules[_k]._1 * 0.7 * _rules[_k]._1);
		_rules[_k]._2 = sqrt(_rules[_k]._2 * 0.7 * _rules[_k]._2);
	}
}
double calculate_important(arr_ll _clauses_result_1_line, clause _clause =
		clause_zero, clause _rule = clause_zero) {
	arr_ld _tmp_arr;
//	long _k;
	double _tmp;
	for (auto const& [_key_rtt, _k] : _clauses_result_1_line) {
		if (_k > 0)
			array_push(_tmp_arr, 0.85);
		else
			array_push(_tmp_arr, 0.15);
	}
	_tmp = geo_avg_arr(_tmp_arr);
	if ((_clause == clause_zero) && (_rule == clause_zero))
		return geo_avg(_tmp, _tmp, _tmp, _clause._1, _clause._2, _rule._1,
				_rule._2);
	return _tmp;
}
void set_max_node(long _num) {
	dbq(
			"update beta_settings set valuex = " + ts(_num)
					+ " where keyx = 'max_node'");
}
string process_brackets(string _str, long _pos_of_open_bracket) {
	long _len;
	long _i;
	string _char;
	long _current_open = 0;
	long _current_close;
	string _g_i_str;
	string _new_g_i;
	if (strpos(_str, ")") > -1)
		return _str;
	while (strpos(_str, ")") > -1) {
		_len = strlen(_str);
		for (_i = 0; _i < _len; _i++) {
			_char = _str[_i];
			if (_char == "(")
				_current_open = _i;
			else if (_char == ")") {
				_current_close = _i;
				_g_i_str = substr(_str, _current_open + 1,
						_current_close - 1 - _current_open);
				_new_g_i = create_find_represent(trim_str(_g_i_str), true);
				_str = str_replace("(_g_i_str)", _new_g_i, _str);
				break;
			}
		}
	}
	return _str;
}
string normalize(string _sen) {
	string _result_clause;
	long _count;
	_result_clause = _sen;
	_count = 1;
	while (_count) {
		_result_clause = str_replace("@@", "@", _result_clause, _count);
	}
	_result_clause = str_replace("@&", "&", _result_clause);
	_result_clause = str_replace("&@", "&", _result_clause);
	_count = 1;
	while (_count) {
		_result_clause = str_replace("&&", "&", _result_clause, _count);
	}
	_result_clause = trim_str(_result_clause, "@");
	return _result_clause;
	_result_clause = str_replace("&c", "c", _result_clause);
	_result_clause = str_replace("c&", "c", _result_clause);
	_result_clause = str_replace("c", "@c@", _result_clause);
}
string find_create_gi(string _clause, string _max_node, bool _table_f = false) {
	arr_lss _data;
	string _table;
	string _types;
	arr_ls _type_arr;
	string _type;
	string _type_num;
	_clause = normalize(_clause);
	_data = dbs("select * from gi_f where c = '" + _clause + "' limit 1");
	if (_data.size() == 0) {
		_data = dbs("select * from gi where c = '" + _clause + "' limit 1");
	}
	if (_table_f)
		_table = "gi_f";
	else
		_table = "gi";
	if (_data.empty()) {
		dbq(
				"insert into _table (id, c, weight, bore ) values ( "
						+ _max_node + ", '" + _clause + "', 1, 1 )");
		_max_node = ts(tl(_max_node) + 1);
		set_max_node(tl(_max_node));
		return _max_node;
	}
	if (_table_f) {
		echo("what is type of _clause");
		readc(_types);
		_type_arr = explode(",", _types);
		for (auto const& [_key_rtt, _type] : _type_arr) {
			_type_num = get_num(_type);
			dbq(
					"insert into go_f (id, c1, c2, weight, bore) values( "
							+ _type_num + ", " + _max_node + ", 1,1)");
		}
	}
	return _data.begin()->second["id"];
}
string natural_str_to_num_clause(string _sen) {
	arr_ls _return;
	arr_ls _word_arr;
	string _word;
	string _skip_arr;
	arr_lss _data;
	string _num;
	string _return_type;
	string _result_clause;
	long _count;
	if (strpos(_sen, "@") > -1 && strpos(_sen, " ") == -1)
		return _sen;
	_sen = trim(_sen);
	_sen = str_replace(" => ", " c ", _sen);
	_sen = str_replace("=> ", " c ", _sen);
	_sen = str_replace("(", " ( ", _sen);
	_sen = str_replace(")", " ) ", _sen);
	_sen = str_replace(" =>", " c ", _sen);
	_sen = str_replace("=>", " c ", _sen);
	_sen = str_replace("\r\n", " & ", _sen);
	_sen = str_replace("\n", " & ", _sen);
	_word_arr = explode(" ", _sen);
	for (auto const& [_key_rtt, _word] : _word_arr) {
		if (_word == "")
			continue;
		if ((strpos(_word, "$") == 0) || _word == "c" || _word == "&"
				|| _word == "(" || _word == ")") {
			array_push(_return, _word);
			continue;
		}
		if (_word == "g.o") {
			array_push(_return, "g@o");
			continue;
		}
		if (_word == "g.i") {
			array_push(_return, "g@i");
			continue;
		}
		if (_word == "d") {
			array_push(_return, "d");
			continue;
		}
// if (in_array ( _word, _skip_arr )) {
// array_push ( _return, _word );
// continue;
// }
		try {
			_data = dbs(
					"select id from new_vocal where vocal_str = \"" + _word
							+ "\" limit 1");
			try {
				auto _tmpx = _data.begin()->second["id"];
			} catch (...) {
				continue;
			}
			_num = _data.begin()->second["id"];
			if (_num != "")
				array_push(_return, _num);
			else
				throw 46;
		} catch (...) {
			string _new_node_num = new_node_num();
			dbq(
					"insert into new_vocal (id, vocal_str) values ( "
							+ _new_node_num + ", '" + _word + "')");
			array_push(_return, _new_node_num);
			set_max_node(tl(_new_node_num));
		}
	}
	// if (_return_type == "arr")
	// return _return;
	_result_clause = implode("@", _return);
	// while ( _count ) {
	// _result_clause = str_replace ( "@@", "@", _result_clause, _count );
	// }
	_result_clause = str_replace("@&", "&", _result_clause);
	_result_clause = str_replace("&@", "&", _result_clause);
	_count = 1;
	while (_count) {
		_result_clause = str_replace("&&", "&", _result_clause, _count);
	}
	_result_clause = str_replace("&(", "(", _result_clause);
	_result_clause = str_replace("&)", ")", _result_clause);
	_result_clause = str_replace("(&", "(", _result_clause);
	_result_clause = str_replace(")&", ")", _result_clause);
	_result_clause = str_replace("&c", "c", _result_clause);
	_result_clause = str_replace("0c&", "c", _result_clause);
	_result_clause = str_replace("c", "@c@", _result_clause);
	_count = 1;
	_result_clause = process_brackets(_result_clause, false);
	_result_clause = normalize(_result_clause);
	return _result_clause;
}
bool remove_from_core(string _pattern) {
//	long _key;
	string _clause;
	arr_lc _core_tmp = _core;
	for (auto const& [_key, _clause] : _core_tmp) {
		if (strpos(_clause._0, _pattern) > -1) {
			//_mode == "mt" && array_push ( _return [core_remove], _key );
			_core.erase(_key);
			_may_match.erase(_key);
			_core_gi.erase(_key);
			_core_go.erase(_key);
			_core_t.erase(_key);
			_core_d.erase(_key);
			_core_l.erase(_key);
			_core_others.erase(_key);
		}
	}
	return true;
}
string what_2_x_convert(string _str) {
	arr_ls _nodes_arr;
//	long _k;
	string _node;
	_nodes_arr = explode("@", _str);
	for (auto const& [_k, _node] : _nodes_arr) {
		if (_node == "80") {
			_nodes_arr[_k] = "x" + new_node_num();
		}
	}
	return implode("@", _nodes_arr);
}
string what_2_var_convert(string _str) {
	arr_ls _nodes_arr;
//	long _k;
	string _node;
	_nodes_arr = explode("@", _str);
	for (auto const& [_k, _node] : _nodes_arr) {
		if (_node == "80") {
			_nodes_arr[_k] = "$" + new_node_num();
		}
	}
	return implode("@", _nodes_arr);
}
void process_sentence(string _current_sentence, string _mode) {
	string _clause;
	string _clause_org;
	string _clause_with_var;
	clause _clause_tmp;
	remove_from_core("254@g@i@");
	_clause = _current_sentence;
	if (_mode != "")
		_clause = natural_str_to_num_clause(_clause);
	if (find_node_in_clause("80", _clause) != false) {
		_clause_org = _clause;
		_clause = what_2_x_convert(_clause);
		_clause_with_var = what_2_var_convert(_clause_org);
		_clause_tmp = clause(_clause_with_var, 1, 1, time_php());
		corer_find_push(_clause_tmp);
	}
	core_push(clause("254@g@i@" + _clause, 1, 1));
	core_push(clause(_clause, 1, 1));
// handler
}
bool read_a_word_type(string _word_id) {
	arr_ls _arr1;
	arr_ls _tmpa;
	arr_lls _arr;
//	long _k;
	arr_lss _data;
	arr_ss _word_db;
	arr_ls _word_types_arr;
	double _base_weight;
	double _base_bore;
	string _word_type;
	string _type_tmp;
	string _x;
	string _newnode1;
	string _newnode2;
	string _x1;
	string _word;
	long _index_of_word_type_in_arr;
	array_push(_arr1, "51230");
	array_push(_arr1, "51");
	array_push(_arr1, "259");
	array_push(_arr1, "52230");
	array_push(_arr1, "52");
	array_push(_arr1, "256");
	array_push(_arr1, "255");
	array_push(_arr1, "257");
	array_push(_arr1, "52400");
	array_push(_arr1, "274554");
	array_push(_arr1, "258");
	array_push(_arr1, "88693");
	array_push(_arr1, "77206");
	array_push(_arr1, "97592");
	array_push(_arr1, "229");
	array_push(_arr1, "230");
	array_push(_arr1, "64851");
	array_push(_arr1, "246");
	if (in_array((_word_id), _arr1))
		return true;
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
	array_push(_arr, _tmpa);// if(_k=core_find_at_end("@g@o@"+_word_id))return false;
	if (!is_numeric(_word_id))
		return false;
	_data = dbs("select * from new_vocal where id = " + _word_id);
	if (_data.size() == 0)
		return false;
	_word_db = _data.begin()->second;
	if (_word_db.size() > 0 && _word_db["type"] != "") {
		_word_types_arr = explode(",", _word_db["type"]);
		_base_weight = 0.85;
		_base_bore = 0.85;
		for (auto const& [_key_rtt, _word_type] : _word_types_arr) {
			_index_of_word_type_in_arr = array_search_lv2_0(_word_type, _arr);
			if (_index_of_word_type_in_arr == -1)
				_type_tmp = _word_type;
			else
				_type_tmp = _arr[_index_of_word_type_in_arr][1];
			string _num = get_num(_type_tmp);
			if (_num != "")
				core_push(_num + "@g@o@" + _word_id, _base_weight, _base_bore);
			// article processing
			// if (_word_type == "art") {
			// core_push ( _word_id+"@1@\_x" + (_newnode1 = new_node_num ()) );
			// core_push ( "\_x_newnode1@250@\_x" + (_newnode2 = new_node_num ()) ); // right be4
			// core_push ( "227@g@o@\_x" + _newnode2 ); // is noun
			// core_push ( "\_x_newnode2@g@o@\_x" + _newnode1 );
			// // TODO: validate: core_push ( "u@g@o@\_x1" );
			// }
			return true;
		}
	}
	_data =
			dbs(
					"select * from go_f where c2 = " + _word_id
							+ " and c1 in (51230,51,259,52230,52,256,255,257,52400,274554,258,88693,77206,97592,229,230,64851,246) union select * from go where c2 = "
							+ _word_id
							+ " and c1 in (51230,51,259,52230,52,256,255,257,52400,274554,258,88693,77206,97592,229,230,64851,246)");
	if (_data.size() > 0) {
		for (auto& [_key_rtt, _word] : _data) {
			core_push(
					clause(_word["c1"] + "@g@o@+" + _word_id,
							td(_word["weight"]), td(_word["bore"])));
		}
	}
	return false;
}
void process_word(string _current_word) {
	arr_lss _data;
	string _type;
	string _new_node_num;
// _current_word = strtolower ( _current_word );
	_data = dbs(
			"select * from new_vocal where vocal_str = '" + _current_word
					+ "' limit 1");
	if (_data.size() == 0) {
		echo(_current_word + ": no index\n");
		_type = readline("Enter type: ");
		_new_node_num = new_node_num();
		dbq(
				"insert into new_vocal (id, vocal_str, type) values ("
						+ _new_node_num + ", '" + _current_word + ", '" + _type
						+ " )");
	} else if (_data.begin()->second["type"] != "") {
		echo(_current_word + ": no type\n");
		_type = readline("Enter type: ");
		dbq(
				"update new_vocal set type ='" + _type + "' where id = "
						+ _data.begin()->second["id"]);
	}
	read_a_word_type(_data.begin()->second["id"]);

// remove_from_core ( "253@0@" );
// core_push ( [
// "253@0@" + find_create_num ( _current_word ),
// 1,
// 1
// ] );
}
bool all_understand() {
	double _max_value;
	string _clause;
	double _value;
	_max_value = 0;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		if (strpos(_clause._0, "x") > -1
				&& (_value = geo_avg(_clause._1, _clause._2)) > _max_value) {
			_max_value = _value;
		}
	}
	for (auto const& [_key_rtt, _clause] : _cache.get_map()) {
		if (strpos(_clause._0, "x") > -1
				&& (_value = geo_avg(_clause._1, _clause._2)) > _max_value) {
			_max_value = _value;
		}
	}
	if (_max_value > MIN_UNACCEPTABLE_XCLAUSE_VALUE)
		return false;
	return true;
}
bool is_sentence_understood(string _current_sentence) {
	long _count;
	if (_current_sentence != "")
		_count = 0;
	else
		_count = count(explode("@", _current_sentence));
	if ((_word_index >= _count) && all_understand())
		return true;
	return false;
}

// ===================================================
string find_create_gi_no_save(string _clause) {
	_clause = normalize(_clause);
	long _key = core_find_at_end("@g@i@" + _clause);
	if (_key > -1)
		return explode("@g@i@", _core[_key]._0)[0];
	_key = core_find_at_end("@g@I@" + _clause);
	if (_key > -1)
		return explode("@g@I@", _core[_key]._0)[0];
	_key = cache_find_at_end("@g@i@" + _clause);
	if (_key > -1)
		return explode("@g@i@", _cache[_key]._0)[0];
	arr_lss _data = dbs(
			"select * from gi_f where c = '" + _clause + "' limit 1");
	if (!_data.empty()) {
		return _data.begin()->second["id"];
	}
	_data = dbs("select * from gi where c = '" + _clause + "' limit 1");
	if (!_data.empty()) {
		return _data.begin()->second["id"];
	}
	return new_node_num();
}
clause find_gi_db(string _clause) {
	arr_lss _data;
	_clause = normalize(_clause);
	_data = dbs("select * from gi_f where c = '" + _clause + "' limit 1");
	if (_data.size() == 0) {
		_data = dbs("select * from gi where c = '" + _clause + "' limit 1");
	}
	if (_data.size() == 0) {
		return clause_zero;
	}
	return clause((string) _data[0]["id"] + "@g@i@" + (string) _data[0]["c"],
			td((string) _data[0]["weight"]), td((string) _data[0]["bore"]));
}
template<typename T>
void array_push_each(map<long, T> &_arr, map<long, T> _arr1) {
	string _ele;
	for (auto const& [_key_rtt, _ele] : _arr1) {
		array_push(_arr, _ele);
	}
}
template<typename T>
map<long, T> array_add(map<long, T> &_arr1, map<long, T> _arr2) {
	if (_arr1.size() == 0 && _arr2.size() == 0) {
		return _arr1;
	}
	if (_arr1.size() == 0) {
		_arr1 = _arr2;
		return _arr1;
	}
	if (_arr2.size() == 0)
		return _arr1;
	array_push_each(_arr1, _arr2);
	_arr1 = array_values(_arr1);
	return _arr1;
}
//template<typename T>
void array_push_each(map<long, string> &_arr, map<long, string> _arr1) {
	string _ele;
	for (auto const& [_key_rtt, _ele] : _arr1) {
		array_push(_arr, _ele);
	}
}
//template<typename T>
map<long, string> array_add(map<long, string> &_arr1, map<long, string> _arr2) {
	if (_arr1.size() == 0 && _arr2.size() == 0) {
		return _arr1;
	}
	if (_arr1.size() == 0) {
		_arr1 = _arr2;
		return _arr1;
	}
	if (_arr2.size() == 0)
		return _arr1;
	array_push_each(_arr1, _arr2);
	_arr1 = array_values(_arr1);
	return _arr1;
}
string node_replace_at_pos(string _subject, string _replace, long _pos) {
	arr_ls _nodes_arr;
	_nodes_arr = explode("@", _subject);
	_nodes_arr[_pos] = _replace;
	return implode("@", _nodes_arr);
}
void replace_them_all_1_time(arr_lls _arr, string _str) {
	string _return;
//	long _count;
	arr_ls _pair;
//	long _count_tmp;
// may loop forever;
	_return = _str;
// _count = 1;
// while ( _count ) {
// _count = 0;
	for (auto& [_key_rtt, _pair] : _arr) {
// _count_tmp = 0;
		_return = str_replace(_pair[0], _pair[1], _return);
// _count = _count > _count_tmp ? _count : _count_tmp;
	}
// }
	_str = _return;
}
void semi_process(string &_str) {
	_str = str_replace("I", "i", _str);
}
arr_lc merge_cc() {
	arr_lc _return;
//	long _k;
	clause _clause;
	for (auto const& [_k, _clause] : _core.get_map()) {
		_return[_k] = _clause;
	}
	for (auto const& [_k, _clause] : _cache.get_map()) {
		_return[_k] = _clause;
	}
	return _return;
}
u_arr_lll core_cache_may_match_rules(arr_ls _multi_clauses_rule) {
	arr_lc _mcc;
	u_arr_lll _return;
//	long _i;
	string _rule_clause;
	bool _matched;
	arr_ll _tmp_arr;
//	long _k;
	clause _core_clause;
	// TODO: improve, limit number;
	// find all sets of clauses in core that may match _multi_clauses_rule, return those index in an array;
	if (_multi_clauses_rule.size() == 0)
		return u_arr_lll_zero;
	_mcc = merge_cc();
	// _core;
	for (auto& [_i, _rule_clause] : _multi_clauses_rule) {
		semi_process(_rule_clause);
		_matched = false;
		for (auto& [_k, _core_clause] : _mcc) {
			semi_process(_core_clause._0);
			if (single_pair_matchable(_core_clause._0, _rule_clause)) {
				array_push(_tmp_arr, _k);
				_matched = true;
			}
		}
		if (!_matched)
			return u_arr_lll_zero;
		_return[_i] = _tmp_arr;
	}
	return _return;
}
arr_ll core_cache_find_matches(string _rule_gt_transformed, long _max,
		bool _include_false = true) {
	arr_ls _core_may_match_rules;
	arr_ls _cache_may_match_rules;
	u_arr_lll _core_cache_may_match_rules1;
	arr_ll _core_cache_may_match_rules;
// _core_may_match_rules = core_may_match_rules ( _rule_gt_transformed ) ._0;
// _cache_may_match_rules = cache_may_match_rules ( _rule_gt_transformed ) ._0;
	arr_ll _return_zero = { { 0, -1 } };

	arr_ls _tmp_gt;
	array_push(_tmp_gt, _rule_gt_transformed);
	_core_cache_may_match_rules1 = core_cache_may_match_rules(_tmp_gt);
	if (_core_cache_may_match_rules1.size() == 0) {

		return _return_zero;
	}
	_core_cache_may_match_rules = _core_cache_may_match_rules1.begin()->second;
	//TODO:may have different meaning to php
	if ((_core_cache_may_match_rules.size()) > 3)
		_core_cache_may_match_rules = array_slice(_core_cache_may_match_rules,
				0, 3, true);
	array_push(_core_cache_may_match_rules, -1l);
	return (!_core_cache_may_match_rules.empty()) ?
			_core_cache_may_match_rules : _return_zero;
}
arr_lls find_transform_table(string _target_kl, string _target) {
	arr_ls _kl_arr;
	arr_ls _target_arr;
	arr_lls _return;
	string _k;
	string _kl_node;
	_kl_arr = explode("@", _target_kl);
	_target_arr = explode("@", _target);
	for (auto const& [_k, _kl_node] : _kl_arr) {
		if (_target_arr[_k] != _kl_node)
			_return[_k][0] = _target_arr[_k];
		_return[_k][1] = _kl_node;
	}
	return array_values(_return);
}
string use_transform_table(string _rule_gt_multi, arr_lls _transform_table) {
	arr_ls _pair;
	for (auto& [_key_rtt, _pair] : _transform_table) {
		_rule_gt_multi = node_replace_multi(_pair[0], _pair[1], _rule_gt_multi);
	}
	return _rule_gt_multi;
}
struct find_all_distinct_vars_in_multi_rules_element {
	string _0;
	long _1;
	long _2;
public:
	find_all_distinct_vars_in_multi_rules_element(string _i0, long _i1,
			long _i2) {
		_0 = _i0;
		_1 = _i1;
		_2 = _i2;
	}
	find_all_distinct_vars_in_multi_rules_element() {
		_0 = "";
		_1 = -1;
		_2 = -1;
	}
};
typedef map<long, find_all_distinct_vars_in_multi_rules_element> find_all_distinct_vars_in_multi_rules_type;
find_all_distinct_vars_in_multi_rules_element find_all_distinct_vars_in_multi_rules_element_zero;
long array_search_lv2_0(string _ele,
		find_all_distinct_vars_in_multi_rules_type _arr) {
//	long _k;
	arr_ls _ele_tmp;
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
find_all_distinct_vars_in_multi_rules_type find_all_distinct_vars_in_multi_rules(
		string _multi_rules1) {
	arr_ls _multi_rules;
	string _x;
	string _1;
	string _2;
	string _5;
	string _rule;
	string _1111;
	find_all_distinct_vars_in_multi_rules_type _return;
	string _i;
	arr_ls _nodes_arr;
//	long _j;
	string _node;
	string _;
//	long _key;
	/*
	 * find all _x (_1, _2, _5,...) from _rule, _1@3@_1@_2@4@_2&_1111@2222&_5 return in a array [[_1,0,0],[_2,0,2],[_5,2,2]], the second is index of single clause, third is the first occurent of _x.
	 */
	_multi_rules = explode("&", _multi_rules1);
	for (auto const& [_i, _rule] : _multi_rules) {
		_nodes_arr = explode("@", _rule);
		for (auto const& [_j, _node] : _nodes_arr) {
			if (strpos(_node, "$") == 0) {
				if (array_search_lv2_0(_node, _return) == -1) {
					array_push(_return,
							find_all_distinct_vars_in_multi_rules_element(_node,
									_i, _j));
				} else {
					// array_push ( _return [find_in_array_lv2_0 ( _node, _return )] ._1, _key );
					continue;
				}
			}
		}
	}
	return _return;
}
string node_replace_skip_nodes_multi_lines(string _search_node,
		string _replace_node, string _subjects, string _refs,
		arr_ls _skip_node) {
	string _ref_clause;
	string _search;
	string _pos;
	string _replace;
	string _subject;
	arr_lls _ref_arr;
	arr_lls _subject_arr;
//	long _k;
	arr_ls _subject_line;
//	long _j;
	string _subject_node;
	arr_lls _output_arr;
	/*
	 * replace all _search at _pos by _replace in _subject. If a _ref_arr[_pos] is in _skip_node, return false.
	 */
	try {
		_subject_arr = explode2(_subjects);
		_ref_arr = explode2(_refs);
		for (auto const& [_k, _subject_line] : _subject_arr) {
			for (auto const& [_j, _subject_node] : _subject_line) {
				if (_subject_node == _search_node) {
					if (in_array((string) _subject_node, _skip_node))
						return _subjects;
					else {
						_subject_arr[_k][_j] = _replace_node;
						// array_push ( _skip_node, _ref_arr [_k] [_j] );
					}
				}
			}
		}
		_output_arr.clear();
		for (auto const& [_key_rtt, _subject_line] : _subject_arr) {
			array_push(_output_arr, (arr_ls) _subject_line);
		}
		return implode2(_output_arr);
	} catch (...) {
		return _subjects;
	}
}
arr_lls multi_var_process(string _multi_clauses_str, string _multi_rules_str) {
	string _core;
	string _1;
	string _2;
	string _3;
	arr_lls _nodes_clause_arr;
	string _transformed_result;
	arr_lls _return;
	arr_ls _skipped_nodes;
	find_all_distinct_vars_in_multi_rules_type _all_distinct_vars_in_rule;
	arr_ls _distinct_var_in_rule;
	string _coresponding_rule_node;
	string _coresponding_clause_node;
	/*
	 * try to check if multi clause match multi rules
	 * must match in order _multi_clauses_str[0] must match _multi_rules_str[0]
	 * used to check if _core matched a rule
	 * example multi_var_process("1001@g@i@1002@1003&1001@160&78427@g@o@1002&66493@g@o@1003", "$1@g@i@_2@_3&_1@160&78427@g@o@_2&66493@g@o@_3")
	 * => Array
	 * (
	 * [0] => Array
	 * (
	 * [0] => _1
	 * [1] => 1001
	 * )
	 *
	 * [1] => Array
	 * (
	 * [0] => _2
	 * [1] => 1002
	 * )
	 *
	 * [2] => Array
	 * (
	 * [0] => _3
	 * [1] => 1003
	 * )
	 * )
	 *
	 */
	semi_process(_multi_clauses_str);
	semi_process(_multi_rules_str);
	_nodes_clause_arr = explode2(_multi_clauses_str);
	_transformed_result = _multi_rules_str;
	// Check if 2 multi_clause are already equal.

	if (multi_clause_match(_multi_clauses_str, _multi_rules_str))
		return arr_lls_true;
	// replace var in 2 multi_clauses
	_all_distinct_vars_in_rule = find_all_distinct_vars_in_multi_rules(
			_multi_rules_str);
	for (auto const& [_key_rtt, _distinct_var_in_rule] : _all_distinct_vars_in_rule) {
		_coresponding_rule_node = _distinct_var_in_rule._0;
		// find clause has same position respectively;
		try {
			_nodes_clause_arr[_distinct_var_in_rule._1][_distinct_var_in_rule._2];
		} catch (...) {
			continue;
		}
		_coresponding_clause_node =
				_nodes_clause_arr[_distinct_var_in_rule._1][_distinct_var_in_rule._2];
		_transformed_result = node_replace_skip_nodes_multi_lines(
				_coresponding_rule_node, _coresponding_clause_node,
				_transformed_result, _multi_clauses_str, _skipped_nodes);
		if (_transformed_result == "")
			return arr_lls_false;
		arr_ls _return_1;
		_return_1[0] = _coresponding_rule_node;
		_return_1[1] = _coresponding_clause_node;
		array_push(_return, _return_1);
		array_push(_skipped_nodes, _coresponding_clause_node);
	}

	if (_transformed_result != _multi_clauses_str)
		return arr_lls_zero;
	return _return;
}
arr_lll core_may_match_rules(arr_ls _multi_clauses_rule) {
	arr_lll _return;
//	long _i;
	string _rule_clause;
	bool _matched;
	arr_ll _tmp_arr;
//	long _k;
	clause _core_clause;
	string _core_clause0;
	// TODO: improve, limit number;
	// find all sets of clauses in core that may match _multi_clauses_rule, return those index in an array;
	// _core;
	for (auto& [_i, _rule_clause] : _multi_clauses_rule) {
		semi_process(_rule_clause);
		_matched = false;
		_tmp_arr.clear();
		for (auto const& [_k, _core_clause] : _core.get_map()) {
			_core_clause0 = _core_clause._0;
			semi_process(_core_clause0);
			if (single_pair_matchable(_core_clause0, _rule_clause)) {
				array_push(_tmp_arr, _k);
				_matched = true;
			}
		}
		if (!_matched)
			return arr_lll_zero;
		_return[_i] = _tmp_arr;
	}
	return _return;
}
arr_lll cache_may_match_rules(arr_ls _multi_clauses_rule) {
	arr_lll _return;
//	long _i;
	string _rule_clause;
	bool _matched;
	arr_ll _tmp_arr;
//	long _k;
	clause _cache_clause;
	string _cache_clause0;
	// TODO: improve, limit number;
	// find all sets of clauses in core that may match _multi_clauses_rule, return those index in an array;
	// _core;
	for (auto& [_i, _rule_clause] : _multi_clauses_rule) {
		semi_process(_rule_clause);
		_matched = false;
		_tmp_arr.clear();
		for (auto const& [_k, _cache_clause] : _core.get_map()) {
			_cache_clause0 = _cache_clause._0;
			semi_process(_cache_clause0);
			if (single_pair_matchable(_cache_clause0, _rule_clause)) {
				array_push(_tmp_arr, _k);
				_matched = true;
			}
		}
		if (!_matched)
			return arr_lll_zero;
		_return[_i] = _tmp_arr;
	}
	return _return;
}
long process_matchable_arr(arr_ll _matchable_arr, string _gt_str,
		double _rule_weight, double _rule_bore, string _target,
		long _kl_index) {
	string _prove;
	arr_lls _transform_table;
	arr_ls _gt_arr;
//	long _key;
	//long _match;
	arr_lls _match_table;
	long _core_push;
	arr_ld _tmp_weight;
	arr_ld _tmp_bore;
	scan_new_node_type _gt_rs;
	string _gt;
	string _gt_transform_table;
	arr_ls _arr_gt;
	arr_lll _re0;
	arr_lll _re1;
	_prove = get_num("prove");
	_gt_arr = explode("&", _gt_str);
	for (auto const& [_key, _match] : _matchable_arr) {
		if (_match == 0) {
			_match_table = multi_var_process(
					merge_cc()[(long) _matchable_arr[_key]]._0, _gt_arr[_key]);
			if (_match_table == arr_lls_false)
				return -1;
			if (_match_table == arr_lls_zero || _match_table.size() == 0)
				continue;
			_match_table = array_add(_match_table, _transform_table);
			_gt_arr = explode("&", use_transform_table(_gt_str, _match_table));
		}
	}
	_core_push = -1;
	for (auto const& [_key, _match] : _matchable_arr) {
		if (_match == false)
			array_push(_tmp_weight, 0.1);
		else
			array_push(_tmp_weight, merge_cc()[_matchable_arr[_key]]._1);
		if (_match == false)
			array_push(_tmp_bore, 0.1);
		else
			array_push(_tmp_bore, merge_cc()[_matchable_arr[_key]]._2);
	}
	for (auto const& [_key, _match] : _matchable_arr) {
		if (_match == -1) {
			arr_lls _temp;
			_temp[0] = arr_ls_zero;
			_temp[1] = arr_ls_zero;
			_gt_rs = scan_new_node(_gt_arr[_key], _temp);
			_gt = _gt_rs._0;
// _gt_transform_table = _gt_rs ._1;
			_arr_gt.clear();
			_arr_gt[0] = _gt;
			_re0 = core_may_match_rules(_arr_gt);
			_re1 = core_may_match_rules(_arr_gt);
			if ((_re0.size() > 0 && _re0.begin()->second.size() > 0)
					|| (_re1.size() > 0 && _re1.begin()->second.size() > 0))
				continue;
			if (_target == "")
				_core_push = core_push(
						clause("d@" + _prove + "@" + _gt,
								geo_avg(geo_avg_arr(_tmp_weight), _rule_weight,
										0.65),
								geo_avg(geo_avg_arr(_tmp_bore), _rule_bore,
										1)));
			else
				_core_push = core_push(
						clause(_gt + "@C@" + _target,
								geo_avg(geo_avg_arr(_tmp_weight), _rule_weight,
										0.65),
								geo_avg(geo_avg_arr(_tmp_bore), _rule_bore, 1)),
						new_rule_num());
		}
	}
	return _core_push;
}
bool new_revert_processing(string _rule, double _rule_weight, double _rule_bore,
		string _target = "", long _kl_index = 0) {
	string _rule_str;
	arr_ls _rule_arr;
	string _rule_gt_str;
	string _rule_kl_str;
	arr_ls _rule_gt_arr;
	arr_ls _rule_kl_arr;
	string _target_kl;
	arr_lls _transform_table;
	arr_lll _matchables_arr_arr;
	string _rule_gt;
	string _rule_gt_transformed;
	arr_ll _core_matches;
	arr_lll _mixed_matchables_arr_arr;
	arr_ll _matchable_arr;
	_rule_str = _rule;
	_rule_arr = explode("@c@", _rule_str);
	_rule_gt_str = _rule_arr[0];
	_rule_kl_str = _rule_arr[1];
	_rule_gt_arr = explode("&", _rule_gt_str);
	_rule_kl_arr = explode("&", _rule_kl_str);
	_target_kl = _rule_kl_arr[_kl_index];
	if (_target != "")
		_transform_table = find_transform_table(_target_kl, _target);
	else
		_transform_table.clear();
	for (auto const& [_key_rtt, _rule_gt] : _rule_gt_arr) {
		_rule_gt_transformed = use_transform_table(_rule_gt, _transform_table);
		_core_matches = core_cache_find_matches(_rule_gt_transformed, 3, true);
		array_push(_matchables_arr_arr, _core_matches);
	}
	_mixed_matchables_arr_arr = array_mix_limited(_matchables_arr_arr);
	for (auto const& [_key_rtt, _matchable_arr] : _mixed_matchables_arr_arr) {
		if (process_matchable_arr(_matchable_arr, implode("&", _rule_gt_arr),
				_rule_weight, _rule_bore, _target, _kl_index))
			return true;
	}
	return false;
}
bool may_match(string _clause1, string _clause2) {
	arr_ls _arr1;
	arr_ls _arr2;
//	long _k;
	string _node1;
	string _node2;
	_arr1 = explode("@", _clause1);
	_arr2 = explode("@", _clause2);
	for (auto const& [_k, _node1] : _arr1) {
		_node2 = _arr2[_k];
		if ((!(is_var(_node1) || is_var(_node2)) || _node1 == _node2))
			return true;
	}
	return false;
}
bool passed_find(long _rule_i, arr_ll _core_keys) {
	try {
		_passed[_rule_i];
	} catch (...) {
		return false;
	}
	if (array_search(_core_keys, _passed.at(_rule_i)) == false)
		return false;
	return true;
}
void passed_push(long _rule_i, arr_ll _core_keys, bool _check_matches) {
	try {
		_passed[_rule_i];
		if (array_search(_core_keys, _passed.at(_rule_i)) == -1) {
			array_push(_passed[_rule_i], _core_keys);
		}
	} catch (...) {
		arr_lll _temp;
		_temp[0] = _core_keys;
		_passed[_rule_i] = _temp;
	}
//	if (_mode == "mt") {
//	if (! _return ["passed"] [_rule_i])
//	_return ["passed"] [_rule_i] = [
//	_core_keys
//	];
//	else if (array_search ( _core_keys, _return ["passed"] [_rule_i] ) == false) {
//		array_push ( _return ["passed"] [_rule_i], _core_keys );
//	}
//}
}
void remove_core(long _core_key) {
	_core.erase(_core_key);
}
void prove(long _i, string _clause) {
	arr_ss _found;
	arr_ls _arr;
	string _first;
	string _second;
	arr_lss _q;
	if (core_find(_clause)) {
		remove_core(_i);
		return;
	}
	if ((_i = cache_find(_clause)) > -1) {
		cache_push_core(_i, 0.8);
		return;
	}
	_found = arr_ss_zero;
	if (strpos(_clause, "g@i") > -1) {
		_arr = explode("@g@i@", _clause);
		_first = _arr[0];
		_second = _arr[1];
		_q = dbs(
				"select id from gi_f where c = '" + _second + "' and id = "
						+ _first + " limit 1");
		if (_q.size() == 0) {
			_q = dbs(
					"select id from gi_f where c = '" + _second + "' and id = "
							+ _first + " limit 1");
		}
		if (_q.size() > 0) {
			_found = _q[0];
		}
	} else if (strpos(_clause, "g@o") > -1) {
		_arr = explode("@g@i@", _clause);
		_first = _arr[0];
		_second = _arr[1];
		_q = dbs(
				"select id from go_f wher c2 = '" + _second + "' and c1 = "
						+ _first + " limit 1");
		if (_q.empty()) {
			_q = dbs(
					"select id from go where c2 = '" + _second + "' and c1 = "
							+ _first + " limit 1");
		}
		if (_q.size() == 0)
			_found = _q[0];
	} else {
		_q = dbs(
				"select id from rules_tmp_f where c = '" + _clause
						+ "' limit 1");
		if (_q.empty()) {
			_q = dbs(
					"select id from rules_tmp where c = '" + _clause
							+ "' limit 1");
		}
		if (_q.size() == 0)
			_found = _q[0];
	}
	if (!_found.empty()) {
		core_push(
				clause(_found["c"], td(_found["weight"]), td(_found["bore"])));
	}
	//return _found;
}
void find(long _i, string _clause) {
	arr_ss _found;
	arr_ls _arr;
	string _first;
	string _second;
	arr_lss _q;
	if (core_find(_clause)) {
		remove_core(_i);
		return;
	}
	if ((_i = cache_find(_clause)) > -1) {
		cache_push_core(_i, 0.8);
		return;
	}
	_found = arr_ss_zero;
	if (strpos(_clause, "g@i") > -1) {
		_arr = explode("@g@i@", _clause);
		_first = _arr[0];
		_second = _arr[1];
		_q = dbs(
				"select id from gi_f where c = '" + _second + "' and id = "
						+ _first + " limit 1");
		if (_q.size() == 0) {
			_q = dbs(
					"select id from gi_f where c = '" + _second + "' and id = "
							+ _first + " limit 1");
		}
		if (_q.size() > 0) {
			_found = _q[0];
		}
	} else if (strpos(_clause, "g@o") > -1) {
		_arr = explode("@g@i@", _clause);
		_first = _arr[0];
		_second = _arr[1];
		_q = dbs(
				"select id from go_f wher c2 = '" + _second + "' and c1 = "
						+ _first + " limit 1");
		if (_q.empty()) {
			_q = dbs(
					"select id from go where c2 = '" + _second + "' and c1 = "
							+ _first + " limit 1");
		}
		if (_q.size() == 0)
			_found = _q[0];
	} else {
		_q = dbs(
				"select id from rules_tmp_f where c = '" + _clause
						+ "' limit 1");
		if (_q.empty()) {
			_q = dbs(
					"select id from rules_tmp where c = '" + _clause
							+ "' limit 1");
		}
		if (_q.size() == 0)
			_found = _q[0];
	}
	if (!_found.empty()) {
		core_push(
				clause(_found["c"], td(_found["weight"]), td(_found["bore"])));
	}
	//return _found;
}
void read_a_word_type_of_clause(clause _clause) {
	arr_ls _words;
	string _word;
	_words = explode("@", _clause._0);
	for (auto const& [_key_rtt, _word] : _words) {
		read_a_word_type(_word);
	}
}
arr_lc find_related_rules() {
	arr_lc _return;
//	long _kc;
	clause _clause;
//	long _rk;
//	bool _true;
	for (auto const& [_kc, _clause] : _core.get_map()) {
		for (auto const& [_rk, _true] : _may_match[_kc]) {
			if (!_return.contains(_rk))
				_return[_rk] = _rules[_rk];
		}
	}
	return _return;
}
arr_ls vars_replacement(arr_lls _multi_var_process_result,
		string _multi_clauses_rule_str_right) {
	string _result;
	arr_ls _pair;
	_result = _multi_clauses_rule_str_right;
	for (auto& [_key_rtt, _pair] : _multi_var_process_result) {
		_result = node_replace_multi(_pair[0], _pair[1], _result);
	}
	return explode("&", _result);
}
void shrink_core_and_cache() {
	shrink_core();
	shrink_cache();
}
bool check_negative_pair_clauses() {
	if (contain_in_array_lv2_0("q@", _core.get_map()))
		return true;
	return false;
}
struct find_trust_lv_ele {
	long _0;
	double _1;
public:
	find_trust_lv_ele(long _i0, double _i1) {
		_0 = _i0;
		_1 = _i1;
	}
	find_trust_lv_ele() {
		_0 = -1;
		_1 = -1.0;
	}
};
find_trust_lv_ele find_trst_lv_ele_zero;
find_trust_lv_ele find_trust_lv(string _node_num) {
	long _clause_num;
	double _impo;
	find_trust_lv_ele _return;
	try {
		_clause_num = core_find_at_start(_node_num + "@g@i@");
		_impo = _core[_clause_num]._1;
		return find_trust_lv_ele(_clause_num, _impo);
	} catch (...) {
		return find_trst_lv_ele_zero;
	}
}
long resolve_conflict() {
	clause _clause;
	arr_ls _clause_arr;
	string _node_clause1;
	string _node_clause2;
	find_trust_lv_ele _trust1;
	find_trust_lv_ele _trust2;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		if (strpos(_clause._0, "q@") == 0) {
			_clause_arr = explode("@", _clause._0);
			_node_clause1 = _clause_arr[1];
			_node_clause2 = _clause_arr[2];
			_trust1 = find_trust_lv(_node_clause1);
			_trust2 = find_trust_lv(_node_clause2);
			if (_trust1._1 == 1 && _trust2._1 == 1) {
				core_update_wb(_trust1._0, 1, 0.7);
				core_update_wb(_trust2._0, 1, 0.7);
				return 1;
			} else if (_trust1._1 == 1) {
				core_update_wb(_trust2._0, 1, 0);
				return 2;
			} else if (_trust2._1 == 1) {
				core_update_wb(_trust1._0, 1, 0);
				return 3;
			} else if (_trust1._1 > _trust2._1 * 1.3) {
				core_update_wb(_trust2._0, 1, _trust2._1 - 0.05);
				return 4;
			} else if (_trust1._1 * 1.3 < _trust2._1) {
				core_update_wb(_trust1._0, 1, _trust1._1 - 0.05);
				return 5;
			}
		}
	}
	return -1;
}
long resolve_conflict_single(long _key_rtt, clause _clause) {
	//clause _clause;
	arr_ls _clause_arr;
	string _node_clause1;
	string _node_clause2;
	find_trust_lv_ele _trust1;
	find_trust_lv_ele _trust2;
//	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
	if (strpos(_clause._0, "q@") == 0) {
		_clause_arr = explode("@", _clause._0);
		_node_clause1 = _clause_arr[1];
		_node_clause2 = _clause_arr[2];
		_trust1 = find_trust_lv(_node_clause1);
		_trust2 = find_trust_lv(_node_clause2);
		if (_trust1._1 == 1 && _trust2._1 == 1) {
			core_update_wb(_trust1._0, 1, 0.7);
			core_update_wb(_trust2._0, 1, 0.7);
			return 1;
		} else if (_trust1._1 == 1) {
			core_update_wb(_trust2._0, 1, 0);
			return 2;
		} else if (_trust2._1 == 1) {
			core_update_wb(_trust1._0, 1, 0);
			return 3;
		} else if (_trust1._1 > _trust2._1 * 1.3) {
			core_update_wb(_trust2._0, 1, _trust2._1 - 0.05);
			return 4;
		} else if (_trust1._1 * 1.3 < _trust2._1) {
			core_update_wb(_trust1._0, 1, _trust1._1 - 0.05);
			return 5;
		}
	}
//	}
	return -1;
}
void replace_long_phrases() {
//	long _k1;
	clause _clause0;
//	long _k2;
	clause _clause1;
	clause _long_clause;
	clause _short_clause;
	arr_ls _tmp_arr;
	string _short_clause_left;
	string _short_clause_right;
	arr_lc _core_tmp = _core;
	arr_lc _core_gi_tmp = _core_gi;
	for (auto const& [_k1, _clause0] : _core_tmp) {
		for (auto const& [_k2, _clause1] : _core_gi_tmp) {
// identify long clause;
			if (_k2 == _k1)
				continue;
			if (node_count(_clause0._0) >= node_count(_clause1._0)) {
				continue;
			} else {
				_long_clause = _clause0;
				_short_clause = _clause1;
			}
// checking short clause;
// if (strpos ( _short_clause ._0, "@g@i@" ) ==-1)
// continue;
// if (stripos ( _long_clause ._0, "@g@i@" ) != false)
// continue;
			_tmp_arr = explode("@g@i@", _short_clause._0);
			_short_clause_left = _tmp_arr[0];
			_short_clause_right = _tmp_arr[1];
// replacing;
			if ((_long_clause._0 != "") && (_short_clause_right != "")
					&& strpos(_long_clause._0, _short_clause_right) > -1)
				core_push(
						clause(
								node_replace(_short_clause_right,
										_short_clause_left, _long_clause._0),
								pow(_long_clause._1 * _short_clause._1, 1 / 2),
								pow(_long_clause._2 * _short_clause._2,
										1 / 2)));
		}
	}
}
void replace_long_phrases_single(long _k1, clause _clause0) {
//	long _k1;
	//clause _clause0;
//	long _k2;
	clause _clause1;
	clause _long_clause;
	clause _short_clause;
	arr_ls _tmp_arr;
	string _short_clause_left;
	string _short_clause_right;
	arr_lc _core_tmp = _core;
	arr_lc _core_gi_tmp = _core_gi;
//	for (auto const& [_k1, _clause0] : _core_tmp) {
	for (auto const& [_k2, _clause1] : _core_gi_tmp) {
// identify long clause;
		if (_k2 == _k1)
			continue;
		if (node_count(_clause0._0) >= node_count(_clause1._0)) {
			continue;
		} else {
			_long_clause = _clause0;
			_short_clause = _clause1;
		}
// checking short clause;
// if (strpos ( _short_clause ._0, "@g@i@" ) ==-1)
// continue;
// if (stripos ( _long_clause ._0, "@g@i@" ) != false)
// continue;
		_tmp_arr = explode("@g@i@", _short_clause._0);
		_short_clause_left = _tmp_arr[0];
		_short_clause_right = _tmp_arr[1];
// replacing;
		if ((_long_clause._0 != "") && (_short_clause_right != "")
				&& strpos(_long_clause._0, _short_clause_right) > -1)
			core_push(
					clause(
							node_replace(_short_clause_right,
									_short_clause_left, _long_clause._0),
							pow(_long_clause._1 * _short_clause._1, 1 / 2),
							pow(_long_clause._2 * _short_clause._2, 1 / 2)));
	}
//	}
}
void inscrease_bore_core() {
//	long _k;
	clause _clause;
	for (auto const& [_k, _clause] : _core.get_map()) {
// _core [_k] ._1 = _core [_k] ._1 > 1 ? 1 : _core [_k] ._1;
// _core [_k] ._2 = _clause ._2 > 1 ? 1 : _clause ._2;
// _core [_k] ._1 = _core [_k] ._1 < 0.03 ? 0.03 : _core [_k] ._1;
// _core [_k] ._2 = _clause ._2 < 0.03 ? 0.03 : _clause ._2;
		core_update_wb(_k, 2, sqrt(pow(_clause._2, 2) * 0.8));
		precision_control(_k);
	}
}
void inscrease_bore_core_single(long _k, clause _clause) {
//	long _k;
	//clause _clause;
//	for (auto const& [_k, _clause] : _core.get_map()) {
// _core [_k] ._1 = _core [_k] ._1 > 1 ? 1 : _core [_k] ._1;
// _core [_k] ._2 = _clause ._2 > 1 ? 1 : _clause ._2;
// _core [_k] ._1 = _core [_k] ._1 < 0.03 ? 0.03 : _core [_k] ._1;
// _core [_k] ._2 = _clause ._2 < 0.03 ? 0.03 : _clause ._2;
	core_update_wb(_k, 2, sqrt(pow(_clause._2, 2) * 0.8));
	precision_control(_k);
//	}
}
arr_lc find_node_relative_rels(string _node) {
	arr_lc _tmp_arr;
	arr_lss _data;
	arr_ss _rel;
//	long _a;
//	long _b;
	_data =
			dbs(
					"select * from (select c2 as c2, weight as weight, bore as bore, (weight - bore) as point from rels where c1 = 'w"
							+ _node + "') as tmp order by point desc limit 0, "
							+ ts(MAX_CONNECTION));
	if (!_data.empty())
	//return arr_lc_zero;
	{
		for (auto& [_key_rtt, _rel] : _data) {
			array_push(_tmp_arr,
					clause(_rel["c2"], td(_rel["weight"]), td(_rel["bore"])));
		}
	}
//	usort ( _tmp_arr, function (_a, _b) {
//				return _a ['valuex'] <=> _b ['valuex'];
//			});
	// reverted;
	_data =
			dbs(
					"select * from (select c1 as c2, weight as weight, bore as bore, (weight - bore) as point from rels where c2 = 'w"
							+ _node + "') as tmp order by point desc limit 0, "
							+ ts(MAX_CONNECTION));
	if (!_data.empty())
	//return arr_lc_zero;
	{
		for (auto& [_key_rtt, _rel] : _data) {
			array_push(_tmp_arr,
					clause(_rel["c2"], td(_rel["weight"]), td(_rel["bore"])));
		}
	}
	_tmp_arr = sort_arr_lc_by_valuex_desc(_tmp_arr);
	return _tmp_arr;
}
arr_lc find_explaination(string _node_root, arr_lc _node_relative_object) {
	arr_ss _table_map;
	arr_ss _main_map;
	string _object_type;
	string _object_num;
	double _object_weight;
	double _object_bore;
	arr_lss _data1;
	arr_ss _data;
	string _tmp_clause;
	double _tmp_weight;
	double _tmp_bore;
	double _result_weight;
	double _result_bore;
	arr_lc _return;
	string _new_clause_num;
	_table_map["w"] = "new_vocal";
	_table_map["d"] = "new_defi";
	_table_map["r"] = "rules";
	_main_map["w"] = "id";
	_main_map["d"] = "defi";
	_main_map["r"] = "c";
	_object_type = substr(_node_relative_object[0]._0, 0, 1);
	_object_num = ltrim(_node_relative_object[0]._0, _object_type);
	_object_weight = _node_relative_object[0]._1;
	_object_bore = _node_relative_object[0]._2;
	_data1 = dbs(
			"SELECT * FROM " + _table_map[_object_type] + " WHERE id = "
					+ _object_num);
	if (_data1.empty())
		return arr_lc_zero;
	_data = _data1[0];
	_tmp_clause = _data[_main_map[_object_type]];
	_tmp_weight = (_data.contains("weight")) ? td(_data["weight"]) : 1.0;
	_tmp_bore = (_data.contains("bore")) ? td(_data["bore"]) : 1.0;
	_result_weight = sqrt(_object_weight * _tmp_weight);
	_result_bore = sqrt(_object_bore * _tmp_bore);
	if (_object_type == "w") {
// 2 word next by;
		array_push(_return,
				clause(
						(_new_clause_num = create_find_represent(
								_node_root + "@" + _tmp_clause)) + "@g@i@"
								+ _node_root + "@" + _tmp_clause,
						_result_weight, _result_bore));
		array_push(_return,
				clause(_new_clause_num + "@g@190", _result_weight,
						_result_bore));
	} else if (_object_type == "d") {
// create definition;
		_tmp_clause = _object_num + "@g@i@" + _tmp_clause;
		array_push(_return, clause(_tmp_clause, _result_weight, _result_bore));
	} else if (_object_type == "r") {
// just push the rules to core;
		array_push(_return, clause(_tmp_clause, _result_weight, _result_bore));
	}
	return _return;
}
void mem_push_relative_rels(long _key, clause _clause) {
	arr_ls _nodes_arr;
	arr_ls _nodes_passed;
	string _node;
	arr_lc _node_relative_rels;
	//clause _node_relative_rel;
	_nodes_arr = explode("@", _clause._0);
	for (auto const& [_key_rtt, _node] : _nodes_arr) {
		if (in_array(_node, _nodes_passed))
			continue;
		_node_relative_rels = find_node_relative_rels(_node);
		if (_node_relative_rels.size() > 0)
			//for (auto const& [_key_rtt, _node_relative_rel] : _node_relative_rels) {
			core_push_each(find_explaination(_node, _node_relative_rels), false,
					false);
		//}
		array_push(_nodes_passed, _node);
	}
}
arr_ll all_already_in_core(arr_ls _multi_clauses) {
//	long _key;
	string _clause;
	arr_ll _return;
	for (auto const& [_key, _clause] : _multi_clauses) {
		if (!in_core(_clause))
			return arr_ll_zero;
		else
			array_push(_return, _key);
	}
	return _return;
}
arr_ll all_already_in_cache(arr_ls _multi_clauses) {
//	long _key;
	string _clause;
	arr_ll _return;
	for (auto const& [_key, _clause] : _multi_clauses) {
		if (!in_cache(_clause))
			return arr_ll_zero;
		else
			array_push(_return, _key);
	}
	return _return;
}
string minimize_xs(string _x_clause_str) {
	arr_ls _x_clause_arr;
	arr_ls _real_x_arr;
//	long _i;
	string _x_node;
	_x_clause_arr = explode("@", _x_clause_str);
	for (auto const& [_i, _x_node] : _x_clause_arr) {
		if (strpos(_x_node, "x") > -1 && !in_array(_x_node, _real_x_arr)) {
			array_push(_real_x_arr, _x_node);
			_x_clause_arr[_i] = array_search(_x_node, _real_x_arr);
		}
	}
	return implode("@", _x_clause_arr);
}
void x_solved(arr_ll _clause_i_arr, long _rule_i) {
//	long _clause_i;
	string _minimized_x_clause;
	for (auto const& [_key_rtt, _clause_i] : _clause_i_arr) {
		if (strpos(_core[_clause_i]._0, "x") > -1) {
			_minimized_x_clause = minimize_xs(_core[_clause_i]._0);
			make_rels("w" + find_represent(_minimized_x_clause), "r" + _rule_i);
		}
	}
}
arr_ls find_all_x_node() {
	clause _clause;
	arr_ls _return;
	arr_ls _x_node_arr;
	string _ele;
	string _tmp_str;
	//long _x_pos;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		_x_node_arr = explode("@", _clause._0);
		for (auto const& [_key_rtt, _ele] : _x_node_arr) {
			if (strpos(_ele, "x") > -1) {
				//_x_pos = strpos(_ele, "x");
				//_tmp_str = substr(_ele, _x_pos, strlen(_ele) - _x_pos);
				if (!in_array(_ele, _return))
					array_push(_return, _ele);
			}
		}
	}
	if (count(_return) == 0)
		return arr_ls_zero;
	return _return;
}
arr_ls find_all_x_node_in_clause(clause _clause) {
	arr_ls _return;
	arr_ls _x_node_arr;
	string _ele;
	string _x;
	_return.clear();
	_x_node_arr = explode("@", _clause._0);
	for (auto const& [_key_rtt, _ele] : _x_node_arr) {
		if (strpos(_ele, "$x") > -1) {
			array_push(_return, _ele);
		}
	}
	if (_return.empty())
		return arr_ls_zero;
	return _return;
}
arr_ls find_x_node_unsolved() {
	arr_ls _return;
	arr_ls _all_x_nodes;
	string _x_node;
	clause _clause;
	bool _break = false;
	_return.clear();
	_all_x_nodes = find_all_x_node();
	if (_all_x_nodes.size() == 0)
		return arr_ls_zero;
	for (auto const& [_key_rtt, _x_node] : _all_x_nodes) {
		_break = false;
		for (auto const& [_key_rtt, _clause] : _core.get_map()) {
//			long _tmp = strpos(_clause._0, _x_node + "@0@");
//			long _tmp1 = strpos(_clause._0, "@0@" + _x_node);
			if (strpos(_clause._0, _x_node + "@0@") == 0
					|| strpos(_clause._0, "@0@" + _x_node) > 0) {
				_break = true;
				break;
			}
		}
		if (_break)
			continue;
		array_push(_return, _x_node);
	}
	return _return.empty() ? arr_ls_zero : _return;
}
void reduce_x_node_clause_weight() {
//	long _key;
	clause _clause;
	arr_ls _x_nodes_arr;
	bool _check;
	string _x_node;
	// reduce clause have x_nodes
	arr_lc _core_tmp = _core;
	for (auto const& [_key, _clause] : _core_tmp) {
		_x_nodes_arr = find_all_x_node_in_clause(_clause);
		_check = false;
		if (_x_nodes_arr.empty())
			return;
		for (auto const& [_key_rtt, _x_node] : _x_nodes_arr) {
			if (core_find_at_start(_x_node + "@0@") == -1) {
				_check = true;
			}
		}
		if (_check) {
			core_update_wb(_key, 1, geo_avg(0.05, _core[_key]._1));
		}
	}
}
void reduce_x_node_clause_weight_single(long _key, clause _clause) {
//	long _key;
	//clause _clause;
	arr_ls _x_nodes_arr;
	bool _check;
	string _x_node;
	// reduce clause have x_nodes
	//arr_lc _core_tmp = _core;
	//for (auto const& [_key, _clause] : _core_tmp) {
	_x_nodes_arr = find_all_x_node_in_clause(_clause);
	_check = false;
	if (_x_nodes_arr.empty())
		return;
	for (auto const& [_key_rtt, _x_node] : _x_nodes_arr) {
		if (core_find_at_start(_x_node + "@0@") == -1) {
			_check = true;
		}
	}
	if (_check) {
		core_update_wb(_key, 1, geo_avg(0.05, _core[_key]._1));
	}
	//}
}
arr_lc super_core() {
	arr_lc _return;
	clause _clause;
	arr_ls _nodes_arr;
	string _node;
	long _break = false;
	_return.clear();
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		_break = false;
		_nodes_arr = explode("@", _clause._0);
		for (auto const& [_key_rtt, _node] : _nodes_arr) {
			if (!preg_match("/^[0-9zxgo] {1,}$/", _node)) {
				_break = true;
				break;
			}
		}
		if (_break)
			continue;
		array_push(_return, _clause);
	}
	return _return;
}
arr_ls super_core_diff() {
	arr_ls _return;
	arr_lc _super_core;
	arr_lc _super_core_new;
	clause _clause_new;
	clause _clause;
	_return.clear();
	_super_core_new = super_core();
	_super_core = _super_core_new;
	for (auto const& [_key_rtt, _clause_new] : _super_core_new) {
		bool _continue = false;
		for (auto const& [_key_rtt, _clause] : _super_core) {
			if (_clause_new._0 == _clause._0)
				_continue = true;
		}
		if (_continue)
			continue;
		array_push(_return, _clause_new._0);
	}
	return _return;
}
void exit_all() {
	clause _clause;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		if (_clause._1 >= 0.1)
			db_push(_clause);
	}
	for (auto const& [_key_rtt, _clause] : _cache.get_map()) {
		if (_clause._1 >= 0.1)
			db_push(_clause);
	}
	_core.clear();
	_cache.clear();
	_steps_passed.clear();
}
void load_table(const string _table_name) {
	_dbc[_table_name].set_map(
			dbsr("select * from " + _table_name, false, false));
}
void calc_valuex(const string _table_name) {
	//long _id;
	arr_ss _row;
	for (auto& [_id, _row] : _dbc[_table_name].get_map())
		_dbc[_table_name][_id]["valuex"] = ts(
				sqrt(td(_row["weight"]) * td(_row["bore"])));
}
void load_table_index(const string _table, const string _column) {
	arr_lss _tmp_arr;
	arr_ss _tmp_ele;
// echo $table + $column;
// echo "\nselect id, $column from $table\n";
	_dbi[_table][_column];
	_tmp_arr = dbsr("select id, " + _column + " from " + _table, false, false);
	for (auto& [_key_rtt, _tmp_ele] : _tmp_arr) {
		_dbi[_table][_column][_tmp_ele[_column]] = tl(_tmp_ele["id"]);
	}
}
void prepare() {
	arr_lss _dbq;
	string _1;
	arr_ss _rule;
	string _type;
	string _clause;
//	long _i;
	arr_ls _delimiters;
//	long _j;
	string _delimiter;
	signal(SIGABRT, signal_handler);
	signal(SIGFPE, signal_handler);
	signal(SIGILL, signal_handler);
	signal(SIGSEGV, signal_handler);
	echo("loading all datas...\n");
	for (auto const& [_k, _table] : ALL_TABLES) {
		load_table(_table);
	}
	echo("calculating...\n");
	for (auto const& [_k, _table] : VALUEX_TABLES) {
		calc_valuex(_table);
	}
	echo("creating indexes...\n");
	for (auto const& [_k, _pair] : ALL_INDEXS) {
		load_table_index(_pair.at(0), _pair.at(1));
	}
	echo("starting...\n");
// load rules;
	_dbq = dbs("select * from settings where keyx = 'max_node'");
	_max_node = tl(_dbq[0]["valuex"]);

	_dbq = dbs("select * from rules where alway_load = 1 limit 1000");
// _dbq = [
// [
// 'id' => 1,
// 'c' => "$1@c@2",
// 'type' => 1,
// 'weight' => 1,
// 'bore' => 1
// ]
// ];
	for (auto& [_key_rtt, _rule] : _dbq) {
		_type = _rule["type"];
		if (strpos((string) _rule["c"], "c") == -1)
			continue;
		rule_push(tl(_rule["id"]),
				clause(general_processing((string) _rule["c"]),
						td((string) _rule["weight"]),
						td((string) _rule["bore"])));
		if (_type == "1")
			rule_push(0 - td(_rule["id"]),
					clause(
							(string) general_processing(
									revert_c((string) _rule["c"])),
							td((string) _rule["weight"]),
							td((string) _rule["bore"])));
		;
	}
// for( auto const& [_key_rtt, _clause ]: _core.get_map()) {
// process_rule ( _clause );
// }
// translater delimiter to num
	for (auto const& [_i, _delimiters] : _delimiters_arr.get_map()) {
		for (auto const& [_j, _delimiter] : _delimiters) {
			_delimiters_arr[_i][_j] = get_num(_delimiter);
		}
	}
// translater delimiter to num
	for (auto const& [_i, _delimiters] : _delimiters_arr.get_map()) {
		for (auto const& [_j, _delimiter] : _delimiters) {
			_delimiters_arr[_i][_j] = get_num(_delimiter);
		}
	}
	_prove_num = get_num("prove");
}
//void exec1() {
//	while (true) {
//		one_cycle();
//	}
//}
#endif /* SRC_LIBS_LIBS2_H_ */
