#ifndef SRC_LIB_LIBS_H_
#define SRC_LIB_LIBS_H_

//#include<php2cpp.h>
//#include<connect.h>
//#include<one_cycle.h>
#include<libs/libs1.h>
#include<libs/libs2.h>
bool mem_push_relative_rules(long _index, clause _clause) {
	arr_ls _nodes_arr;
	string _node;
	long _count;
	long _start;
	arr_lss _data;
	arr_ss _rule;
	string _type;
	long _rule_push;
	long _rule_push1;
	bool _break = false;
	_nodes_arr = explode("@", _clause._0);
	for (auto const& [_key_rtt, _node] : _nodes_arr) {
		_break = false;
		_count = 0;
		_start = 0;
		while (true) {
			if (!is_numeric(_node)) {
				_break = true;
				break;
			}
			string _tmp_str =
					"select id, c, weight, bore, (weight + bore) as valuex, type from rules where (c = '"
							+ _node + "' or c like '%@" + _node
							+ "' or c like '" + _node + "@%' or c like '%@"
							+ _node + "@%') order by valuex limit " + ts(_start)
							+ ", 10";
			_data = dbs(_tmp_str);
			if (_data.size() == 0) {
				_break = true;
				break;
			}
			for (auto& [_key_rtt, _rule] : _data) {
				_type = _rule["type"];
				_rule_push = rule_push(tl(_rule["id"]),
						clause(
								(string) general_processing(
										revert_c((string) _rule["c"])),
								td((string) _rule["weight"]),
								td((string) _rule["bore"])));
				_rule_push1 = false;
				if (_type == "1")
					_rule_push1 = rule_push(0 - tl(_rule["id"]),
							clause(
									(string) general_processing(
											revert_c((string) _rule["c"])),
									td((string) _rule["weight"]),
									td((string) _rule["bore"])));

				if (_rule_push)
					_count++;
				if (_rule_push1)
					_count++;
			}
			if (_count > 4) {
				_break = true;
				break;
			}
			_start += 10;
		}
		if (_break)
			continue;
	}
	return true;
}
bool mem_push_relative_gi(long _index, clause _clause) {
	arr_ls _nodes_arr;
	arr_ls _rules_evolve_arr;
	arr_lld _node_bend_to_rule_strength_arr;
	arr_ls _rules_evolve_value_arr;
	string _node;
	arr_lss _data;
	arr_ss _go;
	arr_lls _node_bend_to_rule_strength;
	arr_ls _node_bend_to_rule_strength_arr1;
	clause _rule;
//	long _rule_index;
//	long _key;
	arr_ld _sub_arr;
	arr_lc _strongest_rules_to_node;
	_nodes_arr = explode("@", _clause._0);
	_rules_evolve_arr.clear();
	_node_bend_to_rule_strength_arr.clear();
	_rules_evolve_value_arr.clear();
	for (auto const& [_key_rtt, _node] : _nodes_arr) {
		if (!is_numeric(_node))
			continue;
		_data =
				dbs(
						"select id, c, (weight + bore) as valuez, weight, bore from gi_f where (id = "
								+ _node + " or c = '" + _node + "' or c like '%"
								+ _node + "' or c like '" + _node
								+ "%' or c like '%" + _node
								+ "%') union all select id, c, (weight + bore) as valuez, weight, bore from gi where (id = "
								+ _node + " or c = '" + _node + "' or c like '%"
								+ _node + "' or c like '" + _node
								+ "%' or c like '%" + _node
								+ "%') order by valuez limit 5");
		if (_data.size() == 0)
			return false;
		for (auto& [_key_rtt, _go] : _data) {
// _node_bend_to_rule_strength = find_node_bend_to_rule_strength ( _node, _rule ["id"] );
// if ((_rule_index = array_search ( _rules_evolve_arr, _rule ["id"] )) == false) {
// array_push ( _rules_evolve_arr, _rule ["id"] );
// array_push ( _rules_evolve_value_arr, _rule ["value"] );
// array_push ( _node_bend_to_rule_strength_arr, [
// _node_bend_to_rule_strength
// ] );
// } else {
// array_push ( _node_bend_to_rule_strength_arr [_rule_index], _node_bend_to_rule_strength );
// }
			core_push(
					clause(_go["id"] + "@g@i@" + _go["c"], td(_go["weight"]),
							td(_go["bore"])));
		}
	}
//	for (auto const& [_key, _sub_arr] : _node_bend_to_rule_strength_arr) {
//		_node_bend_to_rule_strength_arr1[_key] = sqrt(
//				avg_offset(_sub_arr, 0.5) * _rules_evolve_value_arr[_key]);
//	}
//	_node_bend_to_rule_strength_arr1 = sort_arr(
//			_node_bend_to_rule_strength_arr1);
//	for (auto const& [_key, _strongest_rules_to_node] : _node_bend_to_rule_strength_arr) {
//		core_push(_rules_evolve_arr[_key]);
//	}
	return true;
}
bool mem_push_relative_go(long _index, clause _clause) {
	arr_ls _nodes_arr;
	arr_ls _rules_evolve_arr;
	arr_lld _node_bend_to_rule_strength_arr;
	arr_ld _node_bend_to_rule_strength_arr1;
	arr_ls _rules_evolve_value_arr;
	string _node;
	arr_lss _data;
	string _node_bend_to_rule_strength;
	clause _rule;
//	long _rule_index;
	string _go;
//	long _key;
	arr_ld _sub_arr;
	arr_lc _strongest_rules_to_node;
	_nodes_arr = explode("@", _clause._0);
	_rules_evolve_arr.clear();
	_node_bend_to_rule_strength_arr.clear();
	_rules_evolve_value_arr.clear();
	for (auto const& [_key_rtt, _node] : _nodes_arr) {
		if (!is_numeric(_node))
			continue;
		_data =
				dbs(
						"select id, c1, c2, weight, bore, (weight + bore) as value from go_f where (c2 = '"
								+ _node + "' or c1 = '" + _node
								+ "') union select id, c1, c2, weight, bore, (weight + bore) as value from go where (c2 = '"
								+ _node + "' or c1 = '" + _node
								+ "') order by value limit 5");
		if (_data.size() == 0)
			return false;
// _node_bend_to_rule_strength = find_node_bend_to_rule_strength ( _node, _rule ["id"] );
// if ((_rule_index = array_search ( _rules_evolve_arr, _rule ["id"] )) == false) {
// array_push ( _rules_evolve_arr, _rule ["id"] );
// array_push ( _rules_evolve_value_arr, _rule ["value"] );
// array_push ( _node_bend_to_rule_strength_arr, [
// _node_bend_to_rule_strength
// ] );
// } else {
// array_push ( _node_bend_to_rule_strength_arr [_rule_index], _node_bend_to_rule_strength );
// }
		for (auto& [_key_rtt, _go] : _data) {
			core_push(
					clause((string) _go["c1"] + "@g@o@" + (string) _go["c2"],
							tl((string) _go["weight"]),
							tl((string) _go["bore"])));
		}
	}
//	for (auto const& [_key, _sub_arr] : _node_bend_to_rule_strength_arr)
//		_node_bend_to_rule_strength_arr1[_key] = sqrt(
//				avg_offset(_sub_arr, 0.5) * _rules_evolve_value_arr[_key]);
//	sort_arr(_node_bend_to_rule_strength_arr1);
//	for (auto const& [_key, _strongest_rules_to_node] : _node_bend_to_rule_strength_arr1)
//		core_push(_rules_evolve_arr[_key]);
	return true;
}
double find_node_bend_to_rule_strength(string _node, long _rule_id) {
	long _search;
	arr_lss _data;
	_search = array_search_pair_no_order(_rels, _node, "r" + _rule_id);
	if (_search >= 0)
		return _rels[_search]._2 + _rels[_search]._3;
	_data = dbs(
			"SELECT * FROM rels WHERE c1 = '" + _node + "'  AND c2 = 'r"
					+ ts(_rule_id) + "' OR  c2 = '" + _node + "'  AND c1 = 'r"
					+ ts(_rule_id) + "' ");
	if (_data.size() != 0)
		return td(_data.begin()->second["weight"])
				+ td(_data.begin()->second["bore"]);
	return 0.5;
}
void revert_processing() {
	arr_lc _top_rules;
	clause _top_rule;
	try {
// _top_x_clause = find_max_important_x_clauses ( 1 ) ._0;
		_top_rules = find_max_important_rules(5);
		for (auto const& [_key_rtt, _top_rule] : _top_rules)
			new_revert_processing(_top_rule._0, _top_rule._1, _top_rule._2);
	} catch (...) {
		;
	}
}
void* one_cycle_part5(void *_void_pointer) {
	try { //	arr_lc _top_rules;
//	clause _top_rule;
		long _key_rtt = (long) _void_pointer;
		clause _top_rule = _rules[_key_rtt];
//	try {
// _top_x_clause = find_max_important_x_clauses ( 1 ) ._0;
//		_top_rules = find_max_important_rules(5);
//		for (auto const& [_key_rtt, _top_rule] : _top_rules)
		new_revert_processing(_top_rule._0, _top_rule._1, _top_rule._2);
		pthread_exit (NULL);
//	} catch (...) {
//		pthread_exit (NULL);
//	}
	} catch (int a) {
		pthread_exit (NULL);
	}
}
arr_ls vars_x_replacement(arr_ls _clauses_arr) {
	arr_ls _return;
	bool _check;
	string _clause;
	string _x;
	arr_ls _x_nodes_arr;
	arr_ls _replacement_nodes_arr;
	arr_ls _nodes_arr;
	string _node;
	string _x_node;
	string _tmp_clause;
//	long _k;
	string _replacement_node;
	_return.clear();
	_check = false;
	for (auto const& [_key_rtt, _clause] : _clauses_arr) {
		if (strpos(_clause, "$x") > -1) {
			_check = true;
			break;
		}
	}
// if no _x in all of _clauses_arr
	if (!_check)
		return _clauses_arr;
// =============================

	_x_nodes_arr.clear();
	_replacement_nodes_arr.clear();
	for (auto const& [_key_rtt, _clause] : _clauses_arr)
		_nodes_arr = explode("@", _clause);
	for (auto const& [_key_rtt, _node] : _nodes_arr) {
		if (strpos(_node, "$x") == 0
				&& array_search(_node, _x_nodes_arr) == false) {
			array_push(_x_nodes_arr, _node);
		}
	}
	for (long _o = 0; _o < (long) _x_nodes_arr.size(); _o++) {
		array_push(_replacement_nodes_arr, new_node_num());
	}
	for (auto const& [_key_rtt, _clause] : _clauses_arr) {
		if (!core_find_advanced(_clause)) {
			_tmp_clause = _clause;
			for (auto const& [_k, _x_node] : _x_nodes_arr) {
				_replacement_node = _replacement_nodes_arr[_k];
				_tmp_clause = node_replace(_x_node, _replacement_node,
						_tmp_clause);
			}
			array_push(_return, _tmp_clause);
		}
	}
	return _return;
}
void question_processing(long _key, clause _clause) {
	arr_ls _nodes_arr;
	long _check;
	arr_ls _pattern_arr;
//	long _k;
	string _node;
	string _pattern;
	string _x_clause;
	string _boss_tmp;
	clause _clause_tmp;
	string _;
// convert what to x(unique-num)
	_nodes_arr = explode("@", _clause._0);
	_check = false;
	_pattern_arr = _nodes_arr;
	for (auto const& [_k, _node] : _nodes_arr) {
		if (_node == "80") {
			_check = true;
			_pattern_arr[_k] = "x[0-9] {1,}";
		}
	}
	_pattern = implode("@", _pattern_arr);
	if (_check && !core_find_pattern(_pattern)) {
		_x_clause = what_2_x_convert(_clause._0);
		core_push(clause(_x_clause, _clause._1, _clause._2));
// _boss_tmp = (core_find ( "254@g@i@_clause" ) != false);
		_clause_tmp = clause(str_replace("x", "$", _x_clause), _clause._1,
				_clause._2, time_php());
		corer_find_push(_clause_tmp);
	}
}
void explain_core() {
	print_r(_core.get_map());
}
bool equal_processing(long _k, clause _clause) {
	arr_ls _node_arr;
//	long _k1;
	clause _clause1;
	tmp_type _equaled_nodes;
	string _equaled_node0;
	string _equaled_node2;
	arr_ll _skipped;
	long _find;
	string _tmp_clause;
	if (find_node_in_clause("0", _clause._0) != 1)
		return false;
	if (find_node_in_clause("80", _clause._0) != false)
		return false;
	_node_arr = explode("@", _clause._0);
	if (_node_arr[0] == _node_arr[2])
		return false;
	for (auto const& [_k1, _clause1] : _core.get_map())
		if (_k == _k1)
			return false;
	_equaled_nodes = explode("@", _clause._0);
	_equaled_node0 = _equaled_nodes[0];
	_equaled_node2 = _equaled_nodes[2];
	_skipped.clear();
	while (true) {
		if ((_find = find_node_in_clause(_equaled_node0, _clause1._0, _skipped))
				!= false) {
			if (!in_core(
					(_tmp_clause = node_replace_at_pos(_clause1._0,
							_equaled_node2, _find)))) {
				core_push(
						clause(_tmp_clause,
								geo_avg(_clause._1, _clause1._1, 0.8),
								geo_avg(_clause._2, _clause1._2, 0.8)));
				break;
			} else {
				array_push(_skipped, _find);
			}
			echo("\nQ: " + code_2_lang(_clause1._0) + " \n\tA: " + _clause._0);
		} else
			break;
	}
// opposite direction
	_skipped.clear();
	while (true) {
		if ((_find = find_node_in_clause(_equaled_node2, _clause1._0, _skipped))
				!= false) {
			if (!in_core(
					_tmp_clause = node_replace_at_pos(_clause1._0,
							_equaled_node0, _find))) {
				core_push(
						clause(_tmp_clause,
								geo_avg(_clause._1, _clause1._1, 0.8),
								geo_avg(_clause._2, _clause1._2, 0.8)));
				break;
			} else {
				array_push(_skipped, _find);
			}
			echo("\nQ: " + code_2_lang(_clause1._0) + " \n\tA: " + _clause._0);
		} else
			break;
	}
	return true;
}
long may_match_core_cache(string _clause_str1) {
//	long _k;
	clause _clause2;
	for (auto const& [_k, _clause2] : _core.get_map()) {
		if (single_pair_matchable(_clause2._0, _clause_str1))
			return _k;
	}
	for (auto const& [_k, _clause2] : _cache.get_map()) {
		if (single_pair_matchable(_clause2._0, _clause_str1))
			return _k;
	}
	return -1;
}
long logic_push(arr_ll _con_arr, long _rule_i, string _result_str,
		long _result_i) {
	string _con_str;
	// _con_str = implode ( "@", _con_arr );
	array_push(_logic, sublongB(_con_arr, _result_i, _rule_i));
//	if (_mode == "mt")
//	array_push ( _return ["logic"], [
//			_con_arr,
//			_result_i,
//			_rule_i
//			] );
//	else
	if (_logic.size() > MAX_LOGIC) {
		_logic.erase(_logic.first_key());
		_logic.erase(_logic.first_key());
	}
	return _logic.last_key();
}
bool find_relative_clauses(double _core_denied_lv) {
	arr_lc _data;
//	long _i;
	clause _multi_clauses_rule;
	string _multi_clauses_rule_str;
	double _rule_weight;
	double _rule_bore;
	string _multi_clauses_rule_str_left;
	string _multi_clauses_rule_str_right;
	arr_ls _multi_clauses_rule_arr_left;
	arr_lll _core_may_match_rule;
	arr_lll _posibility_matches;
	long _limit_mix;
	arr_ll _posibility_match;
	bool _check_matched;
	tmp_type _tmp_arr;
	arr_ld _tmp_weight;
	arr_ld _tmp_bore;
//	long _index_of_core_clause;
	double _weight;
	double _bore;
	double _point;
	string _core_clause_str;
	arr_lls _multi_var_process_result;
	arr_ls _results_arr;
	arr_ll _indexs_of_cache;
	string _result;
	long _core_push_up;
	long _core_push_down;
	arr_lls _maps;
	scan_new_node_type _scan_new_node;
	string _result1;
	long _core_push;
	_data = find_related_rules();
	if (_data.size() == 0)
		return false;
	for (auto const& [_i, _multi_clauses_rule] : _data) {
// _multi_clauses_rule ["0"] = str_replace ( "I", 'i', _multi_clauses_rule ["0"] );
		_multi_clauses_rule_str = general_processing(_multi_clauses_rule._0);
		_rule_weight = _multi_clauses_rule._1;
		_rule_bore = _multi_clauses_rule._2;
		_multi_clauses_rule_str_left =
				explode("@c@", _multi_clauses_rule_str)[0];
		_multi_clauses_rule_str_right =
				explode("@c@", _multi_clauses_rule_str)[1];
		if (_i == (22 - 1)) {
			_multi_clauses_rule_str_left = str_replace("C", "c",
					_multi_clauses_rule_str_left);
			_multi_clauses_rule_str_right = str_replace("C", "c",
					_multi_clauses_rule_str_right);
		}
		_multi_clauses_rule_arr_left = explode("&",
				_multi_clauses_rule_str_left);
		_core_may_match_rule = core_may_match_rules(
				_multi_clauses_rule_arr_left);
		if ((_posibility_matches = array_mix_limited(_core_may_match_rule)).size()
				== 0)
			continue;
// only match 30 first cases
		_limit_mix = 9999930;
		for (auto const& [_key_rtt, _posibility_match] : _posibility_matches) {
			if (passed_find(_i, _posibility_match))
// we tried this before;
				continue;
			_check_matched = false;
// if (logic_check_1 ( _posibility_match, _i ))
// continue;
			_tmp_arr.clear();
			_tmp_weight.clear();
			_tmp_bore.clear();
			for (auto const& [_key_rtt, _index_of_core_clause] : _posibility_match) {
				array_push(_tmp_arr, _core[_index_of_core_clause]._0);
				array_push(_tmp_weight, _core[_index_of_core_clause]._1);
				array_push(_tmp_bore, _core[_index_of_core_clause]._2);
			}
			_weight = geo_avg_arr(_tmp_weight);
			_bore = geo_avg_arr(_tmp_bore);
			_point = geo_avg(_weight, _bore);
			if (_point < _core_denied_lv)
				continue;
// if (_point >= geo_avg ( DEFAULT_RULE_VALUE_FACTOR, _core_denied_lv ))
// process_rule ( _multi_clauses_rule );
			if (in_array(sublongA(_posibility_match, _i), _steps_passed))
				continue;
			if (_limit_mix <= 0)
				break;
			_limit_mix--;
			array_push(_steps_passed, sublongA(_posibility_match, _i));
			_core_clause_str = implode("&", _tmp_arr);
			_multi_var_process_result = multi_var_process(_core_clause_str,
					_multi_clauses_rule_str_left);
			if (_multi_var_process_result.size() > 0) {
// if matched;
				_check_matched = true;
				for (auto const& [_key_rtt, _index_of_core_clause] : _posibility_match) {
// refresh timer
					_core[_index_of_core_clause]._3 = time_php();
				}
// if (find_in_core_vars_replacement ( _multi_var_process_result, _multi_clauses_rule_str_right ))
// continue;
				array_push(_tmp_weight, _rule_weight);
				array_push(_tmp_bore, _rule_bore);
				_results_arr = vars_replacement(_multi_var_process_result,
						_multi_clauses_rule_str_right);
				_results_arr = vars_x_replacement(_results_arr);
// repeated
				arr_ls _tmp0;
				_tmp0[0] = _multi_clauses_rule_str_right;
				if (all_already_in_core(_tmp0).size() > 0) {
					continue;
				}
				if ((_indexs_of_cache = all_already_in_cache(_tmp0)).size()
						> 0) {
					for (auto const& [_i, _result] : _results_arr) {
						cache_push_core(_indexs_of_cache[_i], _bore);
					}
					continue;
				}
// to adjust bore of clauses and rule;
				_core_push_up = 0;
				_core_push_down = 0;
// end;
				_maps.clear();
				_maps[0] = arr_ls_zero;
				_maps[1] = arr_ls_zero;
				for (auto const& [_key_rtt, _result] : _results_arr) {
					_scan_new_node = scan_new_node(_result, _maps);
					_result1 = _scan_new_node._0;
					_maps = _scan_new_node._1;
					if (may_match_core_cache(_result) > -1
							&& find_logic(_posibility_match, _i, _result))
						continue;
					/*
					 * ===============================
					 * ===============================
					 * CORE PUSH
					 * ===============================
					 * ===============================
					 */
					_core_push = core_push_no_shrink(
							clause(_result1, _weight, _bore), true, true);
					/*
					 * ===============================
					 * ===============================
					 * CORE PUSH
					 * ===============================
					 * ===============================
					 */
					if (_core_push >= 0) {
						_core_push_up++;
					} else {
						_core_push_down++;
					}
					logic_push(_posibility_match, _i, _result1,
							_core.empty() ? 0 : _core.last_key());
// logic_push_to_core ( [
// _core_clause_str,
// _core [_index_of_core_clause] ._1,
// _core [_index_of_core_clause] ._2
// ], [
// _result1,
// _weight,
// _bore
// ] );
// echo "tt";
				}
				for (auto const& [_key_rtt, _index_of_core_clause] : _posibility_match) {
// refresh bore;
					core_update_wb(_index_of_core_clause, 2,
							pow(0.95, _core_push_down)
									* pow(1.05, _core_push_up));
				}
// add relation between node and rule;
				make_rels_word_2_str_rule_1(_core_clause_str, _i);
// refresh timeer of rules
// _GLOBALS ['core'] [_i] ._3 = time ();
				x_solved(_posibility_match, _i);
			} else {
// if not matched;
				reduce_rels_word_2_str_rule_1(_core_clause_str, _i);
			}
			passed_push(_i, _posibility_match, _check_matched);
		}
		arr_ll _tmp1;
		_tmp1[0] = 14;
		_tmp1[1] = 15;
		_tmp1[2] = 16;
		_tmp1[3] = 17;
		_tmp1[4] = 18;
		_tmp1[5] = 19;
		if (in_array(_i, _tmp1))
			make_rels_word_1_word_1(_result);
	}
	return false;
}

void* one_cycle_part3(void *_void_pointer) {
	try {
		long _i = (long) _void_pointer;
		clause _multi_clauses_rule = _rules[_i];
		double _core_denied_lv = _denied_value;
		arr_lc _data;
//	long _i;
		//clause _multi_clauses_rule;
		string _multi_clauses_rule_str;
		double _rule_weight;
		double _rule_bore;
		string _multi_clauses_rule_str_left;
		string _multi_clauses_rule_str_right;
		arr_ls _multi_clauses_rule_arr_left;
		arr_lll _core_may_match_rule;
		arr_lll _posibility_matches;
		long _limit_mix;
		arr_ll _posibility_match;
		bool _check_matched;
		tmp_type _tmp_arr;
		arr_ld _tmp_weight;
		arr_ld _tmp_bore;
//	long _index_of_core_clause;
		double _weight;
		double _bore;
		double _point;
		string _core_clause_str;
		arr_lls _multi_var_process_result;
		arr_ls _results_arr;
		arr_ll _indexs_of_cache;
		string _result;
		long _core_push_up;
		long _core_push_down;
		arr_lls _maps;
		scan_new_node_type _scan_new_node;
		string _result1;
		long _core_push;
//	_data = find_related_rules();
//	if (_data.size() == 0)
//		return false;
//	for (auto const& [_i, _multi_clauses_rule] : _data) {
// _multi_clauses_rule ["0"] = str_replace ( "I", 'i', _multi_clauses_rule ["0"] );
		_multi_clauses_rule_str = general_processing(_multi_clauses_rule._0);
		_rule_weight = _multi_clauses_rule._1;
		_rule_bore = _multi_clauses_rule._2;
		_multi_clauses_rule_str_left =
				explode("@c@", _multi_clauses_rule_str)[0];
		_multi_clauses_rule_str_right =
				explode("@c@", _multi_clauses_rule_str)[1];
		if (_i == (22 - 1)) {
			_multi_clauses_rule_str_left = str_replace("C", "c",
					_multi_clauses_rule_str_left);
			_multi_clauses_rule_str_right = str_replace("C", "c",
					_multi_clauses_rule_str_right);
		}
		_multi_clauses_rule_arr_left = explode("&",
				_multi_clauses_rule_str_left);
		_core_may_match_rule = core_may_match_rules(
				_multi_clauses_rule_arr_left);
		if ((_posibility_matches = array_mix_limited(_core_may_match_rule)).size()
				== 0)
			pthread_exit (NULL);
// only match 30 first cases
		_limit_mix = 9999930;
		for (auto const& [_key_rtt, _posibility_match] : _posibility_matches) {
			if (passed_find(_i, _posibility_match))
// we tried this before;
				continue;
			_check_matched = false;
// if (logic_check_1 ( _posibility_match, _i ))
// continue;
			_tmp_arr.clear();
			_tmp_weight.clear();
			_tmp_bore.clear();
			for (auto const& [_key_rtt, _index_of_core_clause] : _posibility_match) {
				array_push(_tmp_arr, _core[_index_of_core_clause]._0);
				array_push(_tmp_weight, _core[_index_of_core_clause]._1);
				array_push(_tmp_bore, _core[_index_of_core_clause]._2);
			}
			_weight = geo_avg_arr(_tmp_weight);
			_bore = geo_avg_arr(_tmp_bore);
			_point = geo_avg(_weight, _bore);
			if (_point < _core_denied_lv)
				continue;
// if (_point >= geo_avg ( DEFAULT_RULE_VALUE_FACTOR, _core_denied_lv ))
// process_rule ( _multi_clauses_rule );
			if (in_array(sublongA(_posibility_match, _i), _steps_passed))
				continue;
			if (_limit_mix <= 0)
				break;
			_limit_mix--;
			array_push(_steps_passed, sublongA(_posibility_match, _i));
			_core_clause_str = implode("&", _tmp_arr);
			_multi_var_process_result = multi_var_process(_core_clause_str,
					_multi_clauses_rule_str_left);
			if (_multi_var_process_result.size() > 0) {
// if matched;
				_check_matched = true;
				for (auto const& [_key_rtt, _index_of_core_clause] : _posibility_match) {
// refresh timer
					_core[_index_of_core_clause]._3 = time_php();
				}
// if (find_in_core_vars_replacement ( _multi_var_process_result, _multi_clauses_rule_str_right ))
// continue;
				array_push(_tmp_weight, _rule_weight);
				array_push(_tmp_bore, _rule_bore);
				_results_arr = vars_replacement(_multi_var_process_result,
						_multi_clauses_rule_str_right);
				_results_arr = vars_x_replacement(_results_arr);
// repeated
				arr_ls _tmp0;
				_tmp0[0] = _multi_clauses_rule_str_right;
				if (all_already_in_core(_tmp0).size() > 0) {
					continue;
				}
				if ((_indexs_of_cache = all_already_in_cache(_tmp0)).size()
						> 0) {
					for (auto const& [_i, _result] : _results_arr) {
						cache_push_core(_indexs_of_cache[_i], _bore);
					}
					continue;
				}
// to adjust bore of clauses and rule;
				_core_push_up = 0;
				_core_push_down = 0;
// end;
				_maps.clear();
				_maps[0] = arr_ls_zero;
				_maps[1] = arr_ls_zero;
				for (auto const& [_key_rtt, _result] : _results_arr) {
					_scan_new_node = scan_new_node(_result, _maps);
					_result1 = _scan_new_node._0;
					_maps = _scan_new_node._1;
					if (may_match_core_cache(_result) > -1
							&& find_logic(_posibility_match, _i, _result))
						continue;
					/*
					 * ===============================
					 * ===============================
					 * CORE PUSH
					 * ===============================
					 * ===============================
					 */
					_core_push = core_push_no_shrink(
							clause(_result1, _weight, _bore), true, true);
					/*
					 * ===============================
					 * ===============================
					 * CORE PUSH
					 * ===============================
					 * ===============================
					 */
					if (_core_push >= 0) {
						_core_push_up++;
					} else {
						_core_push_down++;
					}
					logic_push(_posibility_match, _i, _result1,
							_core.empty() ? 0 : _core.last_key());
// logic_push_to_core ( [
// _core_clause_str,
// _core [_index_of_core_clause] ._1,
// _core [_index_of_core_clause] ._2
// ], [
// _result1,
// _weight,
// _bore
// ] );
// echo "tt";
				}
				for (auto const& [_key_rtt, _index_of_core_clause] : _posibility_match) {
// refresh bore;
					core_update_wb(_index_of_core_clause, 2,
							pow(0.95, _core_push_down)
									* pow(1.05, _core_push_up));
				}
// add relation between node and rule;
				make_rels_word_2_str_rule_1(_core_clause_str, _i);
// refresh timeer of rules
// _GLOBALS ['core'] [_i] ._3 = time ();
				x_solved(_posibility_match, _i);
			} else {
// if not matched;
				reduce_rels_word_2_str_rule_1(_core_clause_str, _i);
			}
			passed_push(_i, _posibility_match, _check_matched);
		}
		arr_ll _tmp1;
		_tmp1[0] = 14;
		_tmp1[1] = 15;
		_tmp1[2] = 16;
		_tmp1[3] = 17;
		_tmp1[4] = 18;
		_tmp1[5] = 19;
		if (in_array(_i, _tmp1))
			make_rels_word_1_word_1(_result);
//	}
		pthread_exit (NULL);
	} catch (int a) {
		pthread_exit (NULL);
	}
}
void conflict_in_lang(long _key, clause _clause) {
	;
}
bool find_relative_clauses_for_r(arr_ls _arr_clauses) {
	arr_lll _core_may_match_rule;
	arr_lll _posibility_matches;
	long _limit_mix;
	arr_ll _posibility_match;
	arr_ls _tmp_arr;
	arr_ld _tmp_weight;
	arr_ld _tmp_bore;
//	long _index_of_core_clause;
	string _core_clause_str;
	arr_lls _multi_var_process_result;
	_core_may_match_rule = core_may_match_rules(_arr_clauses);
	if ((_posibility_matches = array_mix_limited(_core_may_match_rule)).size()
			== 0)
		return false;
	// only match 30 first cases
	_limit_mix = 9999930;
	for (auto const& [_key_rtt, _posibility_match] : _posibility_matches) {
		_tmp_arr.clear();
		_tmp_weight.clear();
		_tmp_bore.clear();
		for (auto const& [_key_rtt, _index_of_core_clause] : _posibility_match) {
			array_push(_tmp_arr, _core[_index_of_core_clause]._0);
			array_push(_tmp_weight, _core[_index_of_core_clause]._1);
			array_push(_tmp_bore, _core[_index_of_core_clause]._2);
		}
		if (_limit_mix <= 0)
			break;
		_limit_mix--;
		_core_clause_str = implode("&", _tmp_arr);
		_multi_var_process_result = multi_var_process(_core_clause_str,
				implode("&", _arr_clauses));
		if (!_multi_var_process_result.empty()) {
			// if matched;
			continue;
		} else {
			// if not matched;
			return false;
		}
	}
	return true;
}
arr_lc get_top_rules(long _count = 3) {
	arr_ld _tmp_value;
//	long _k;
	arr_lc _return;
	string _key;
	string _st;
	_tmp_value.clear();
	for (auto const& [_k, _rule] : _rules.get_map()) {
		_tmp_value[_k] = geo_avg(_rule._1, _rule._2);
	}
	_tmp_value = array_top(_tmp_value, _count);
	for (auto const& [_key, _st] : _tmp_value) {
		_return[_key] = _rules[_key];
	}
	return _return;
}
tmp_type corer_prove() {
	tmp_type _return;
	string _prove;
//	long _i;
	clause _clause;
	arr_lc _top_rules;
	clause _rule;
	arr_ls _rule_arr;
	string _rule_left;
	string _rule_right;
	arr_ls _rule_left_arr;
	arr_ls _rule_right_arr;
	string _rule_right_ele;
	arr_lls _multi_var_process_result;
	arr_ls _results_arr;
	string _suggested_clause;
	_return.clear();
	_prove = _prove_num;
	for (auto const& [_i, _clause] : _core_l.get_map()) {
		clause _tmp = _clause;
		if (strpos(_clause._0, "l@" + _prove + "@") == 0) {
			_tmp._0 = str_replace("l@" + _prove + "@", "", _clause._0);
			corer_prove_push(_tmp);
		}
	}
	// if (! _corer_prove) {
	// _corer_prove = _core_l;
	// return 0;
	// }
	_top_rules = get_top_rules();
	for (auto const& [_key_rtt, _clause] : _corer_prove.get_map()) {
		for (auto const& [_key_rtt, _rule] : _top_rules) {
			_rule_arr = explode("@c@", _rule._0);
			_rule_left = _rule_arr[0];
			_rule_right = _rule_arr[1];
			// _rule_left_arr = explode ( "&", _rule_left );
			_rule_right_arr = explode("&", _rule_right);
			for (auto const& [_key_rtt, _rule_right_ele] : _rule_right_arr) {
				if ((_multi_var_process_result = multi_var_process(_clause._0,
						_rule_right_ele)).size() > 0) {
					if (_multi_var_process_result == arr_lls_true)
						_multi_var_process_result.clear();
					_results_arr = vars_replacement(_multi_var_process_result,
							_rule_left);
					r_logic_push(substringC(_results_arr, _clause._0));
					for (auto const& [_key_rtt, _suggested_clause] : _results_arr) {
						corer_prove_push(clause(_suggested_clause, 0.65, 0.65));
					}
				}
			}
		}
	}
	return _return;
}
void find_corer_in_corel() {
	for (auto const& [_i, _clause] : _core_l.get_map()) {
		clause _tmp = _clause;
		if (strpos(_clause._0, "l@" + _prove_num + "@") == 0) {
			_tmp._0 = str_replace("l@" + _prove_num + "@", "", _clause._0);
			corer_prove_push(_tmp);
		}
	}
}
void* one_cycle_part6(void *_void_pointer) {
	try {
		long _key_r = (long) _void_pointer;
		clause _clause = _corer_prove[_key_r];
		tmp_type _return;
		string _prove;
//	long _i;
		//clause _clause;
		arr_lc _top_rules;
		clause _rule;
		arr_ls _rule_arr;
		string _rule_left;
		string _rule_right;
		arr_ls _rule_left_arr;
		arr_ls _rule_right_arr;
		string _rule_right_ele;
		arr_lls _multi_var_process_result;
		arr_ls _results_arr;
		string _suggested_clause;
		_return.clear();
//	_prove = _prove_num;
//	for (auto const& [_i, _clause] : _core_l.get_map()) {
//		clause _tmp = _clause;
//		if (strpos(_clause._0, "l@" + _prove + "@") == 0) {
//			_tmp._0 = str_replace("l@" + _prove + "@", "", _clause._0);
//			corer_prove_push(_tmp);
//		}
//	}
		// if (! _corer_prove) {
		// _corer_prove = _core_l;
		// return 0;
		// }
		_top_rules = get_top_rules();
//	for (auto const& [_key_rtt, _clause] : _corer_prove.get_map()) {
		for (auto const& [_key_rtt, _rule] : _top_rules) {
			_rule_arr = explode("@c@", _rule._0);
			_rule_left = _rule_arr[0];
			_rule_right = _rule_arr[1];
			// _rule_left_arr = explode ( "&", _rule_left );
			_rule_right_arr = explode("&", _rule_right);
			for (auto const& [_key_rtt, _rule_right_ele] : _rule_right_arr) {
				if ((_multi_var_process_result = multi_var_process(_clause._0,
						_rule_right_ele)).size() > 0) {
					if (_multi_var_process_result == arr_lls_true)
						_multi_var_process_result.clear();
					_results_arr = vars_replacement(_multi_var_process_result,
							_rule_left);
					r_logic_push(substringC(_results_arr, _clause._0));
					for (auto const& [_key_rtt, _suggested_clause] : _results_arr) {
						corer_prove_push(clause(_suggested_clause, 0.65, 0.65));
					}
				}
			}
		}
//	}
		pthread_exit (NULL);
	} catch (int e) {
		pthread_exit (NULL);
	};
}
void add_core_to_corer_find() {
	clause _clause;
	clause _clause_tmp;
	for (auto const& [_key_rtt, _clause] : _core.get_map()) {
		if (strpos(_clause._0, "x") > -1) {
			_clause_tmp = clause(str_replace("x", "$", _clause._0), _clause._1,
					_clause._2, 0);
			corer_find_push(_clause_tmp);
		}
	}
}
void advanced_corer_find(clause _clause) {
	//string _return;
	string _find;
//	long _i;
	arr_lc _top_rules;
	clause _rule;
	arr_ls _rule_arr;
	string _rule_left;
	string _rule_right;
	arr_ls _rule_left_arr;
	arr_ls _rule_right_arr;
	arr_ls _rule_right_ele;
	arr_lls _multi_var_process_result;
	arr_ls _results_arr;
	string _suggested_clause;
// _return .clear();
// _find = get_num ( "find" );
// for( auto const& [_i, _clause]: _core_l) {
// if (strpos ( _clause ._0, "d@_find@" ) == 0) {
// _clause ._0 = str_replace ( "d@_find@", '', _clause ._0 );
// corer_find_push ( _clause );
// }
// }
// if (! _corer_find) {
// _corer_find = _core_l;
// return 0;
// }
	_top_rules = get_top_rules();
// for( auto const& [_key_rtt, _clause ]: _corer_find) {
	for (auto const& [_key_rtt, _rule] : _top_rules) {
		_rule_arr = explode("@c@", _rule._0);
		_rule_left = _rule_arr[0];
		_rule_right = _rule_arr[1];
// _rule_left_arr = explode ( "&", _rule_left );
		_rule_right_arr = explode("&", _rule_right);
		for (auto const& [_key_rtt, _rule_right_ele] : _rule_right_arr) {
			if ((_multi_var_process_result = multi_var_process(_clause._0,
					_rule_right_ele)).size() > 0) {
				_results_arr = vars_replacement(_multi_var_process_result,
						_rule_left);
				r_logic_push(substringC(_results_arr, _clause._0));
				for (auto const& [_key_rtt, _suggested_clause] : _results_arr) {
					corer_find_push(
							clause(_suggested_clause, 0.65, 0.65, time_php()));
				}
			}
		}
	}
// }
}
bool simple_find_x() {
	clause _clause0;
	string _find;
	clause _clause;
//	long _k;
	clause _clause1;
	arr_ls _node_arr;
//	long _key;
	string _node;
	string _pattern;
	arr_lss _q;
	arr_lss _q1;
// basic find
	for (auto const& [_key_rtt, _clause0] : _corer_find.get_map()) {
		// if (! node_in_clause ( _find, _clause ))
		// continue;
		for (auto const& [_k, _clause1] : _cache.get_map()) {
			if (may_match(_clause0._0, _clause1._0)) {
				cache_push_core(_k);
				if (find_in_array_lv2_0(_clause0._0, _boss.get_map())) {
					echo("found in cache: " + _clause1._0);
					continue;
				}
			}
		}
		_node_arr = explode("@", _clause0._0);
		for (auto const& [_key, _node] : _node_arr) {
			if (is_var(_node))
				_node_arr[_key] = "[0-9]*";
		}
		_pattern = implode("@", _node_arr);
		_q = dbsr(
				"select * from rules_tmp_f where REGEXP_LIKE (c, '" + _pattern
						+ "')");
		_q = array_add(_q,
				dbsr(
						"select * from rules_tmp where REGEXP_LIKE (c, '"
								+ _pattern + "')"));
		if (!_q.empty()) {
			for (auto& [_key_rtt, _q1] : _q) {
				core_push(
						clause((string) _q1["c"], td((string) _q1["weight"]),
								td((string) _q1["bore"])));
				if (_clause0._3) {
					echo("found in db: " + explain_to_lang((string) _q1["c"]));
					continue;
				}
			}
		}
		if (_clause0._1 >= 0.7)
			advanced_corer_find(_clause0);
	}
	return true;
// end basic find end;
}
void* one_cycle_part7(void *_void_pointer) {
	try {
		long _key = (long) _void_pointer;
		clause _clause0 = _corer_find[_key];
		string _find;
		clause _clause;
//	long _k;
		clause _clause1;
		arr_ls _node_arr;
//	long _key;
		string _node;
		string _pattern;
		arr_lss _q;
		arr_lss _q1;
// basic find
		//for (auto const& [_key_rtt, _clause0] : _corer_find.get_map()) {
		// if (! node_in_clause ( _find, _clause ))
		// continue;
		for (auto const& [_k, _clause1] : _cache.get_map()) {
			if (may_match(_clause0._0, _clause1._0)) {
				cache_push_core(_k);
				if (find_in_array_lv2_0(_clause0._0, _boss.get_map())) {
					echo("found in cache: " + _clause1._0);
					continue;
				}
			}
			//		}
			_node_arr = explode("@", _clause0._0);
			for (auto const& [_key, _node] : _node_arr) {
				if (is_var(_node))
					_node_arr[_key] = "[0-9]*";
			}
			_pattern = implode("@", _node_arr);
			_q = dbsr(
					"select * from rules_tmp_f where REGEXP_LIKE (c, '"
							+ _pattern + "')");
			_q = array_add(_q,
					dbsr(
							"select * from rules_tmp where REGEXP_LIKE (c, '"
									+ _pattern + "')"));
			if (!_q.empty()) {
				for (auto& [_key_rtt, _q1] : _q) {
					core_push(
							clause((string) _q1["c"],
									td((string) _q1["weight"]),
									td((string) _q1["bore"])));
					if (_clause0._3) {
						echo(
								"found in db: "
										+ explain_to_lang((string) _q1["c"]));
						continue;
					}
				}
			}
			if (_clause0._1 >= 0.7)
				advanced_corer_find(_clause0);
		}
		pthread_exit (NULL);
	} catch (int e) {
		pthread_exit (NULL);
	};
// end basic find end;
}
void time_push(long _timestamp = time_php()) {
	core_push(clause("30@0@z" + ts(_timestamp), 1, 1));
}
void match_2_core() {
//	long _i;
	arr_lC _r_logic_1;
// match core and core_r;
	for (auto const& [_i, _r_logic_1] : _r_logic.get_map()) {
		if (find_relative_clauses_for_r(_r_logic_1._0))
			core_push(clause(_r_logic_1._1, 1, 1));
	}
}
bool make_vertical_group_2_clauses(clause _clauseK, clause _clauseJ) {
	string _1;
	string _2;
	string _3;
	string _4;
	string _;
	arr_ls _clauseJ_cutted;
	arr_ls _clauseK_cutted;
	string _group;
	string _13;
// test if 2 clause are type g clauses;
// _1 _2 _3 vs _4 _2 _3 is in same group _* _2 _3;
	if (strpos(_clauseJ._0, "g@o@") > -1 || strpos(_clauseK._0, "@g@o@") > -1)
		return false;
// case 1st element;
	_clauseJ_cutted = cut_head(_clauseJ);
	_clauseK_cutted = cut_head(_clauseK);
	if (_clauseJ_cutted[0] == _clauseK_cutted[0]
			&& (core_find_contain("@gt@" + _clauseJ_cutted[0]) == -1)) {
		core_push((_group = new_node_num()) + "@g@o@" + _clauseK_cutted[1]);
		core_push(_group + "@g@o@" + _clauseJ_cutted[1]);
		core_push(_group + "@gt@" + _clauseJ_cutted[0]);
		return true;
	}
// case last element;
// _1 _2 _3 vs _1 _2 _13 is in same group _1 _2 _*;
	_clauseJ_cutted = cut_tail(_clauseJ);
	_clauseK_cutted = cut_tail(_clauseK);
	if (_clauseJ_cutted[0] == _clauseK_cutted[0]
			&& core_find_contain(_clauseJ_cutted[0] + "@tg@") == -1) {
		core_push(_group = new_node_num() + "@g@o@" + _clauseK_cutted[1]);
		core_push(_group + "@g@o@" + _clauseJ_cutted[1]);
		core_push(_clauseJ_cutted[0] + "@tg@" + _group);
		return true;
	}
	return false;
}
bool make_vertical_group_1_group_1_clause(clause _clauseK, clause _clauseJ) {
	clause _t_clause;
	clause _other_clause;
// test if clause K is type g clauses;
// if ((strpos ( _clauseK ._0, "t" ) || strpos ( _clauseJ ._0, "t" )) && (! strpos ( _clauseK ._0, "t" ) || (! strpos ( _clauseJ ._0, "t" ))))
// return false;
// case 1st element;
// if (strpos ( _clauseK ._0, "t" )) {
	_t_clause = _clauseK;
	_other_clause = _clauseJ;
// } else {
// _t_clause = _clauseJ;
// _other_clause = _clauseK;
// }
	if (strpos(_t_clause._0, "gt") > -1) {
// left group
//		string _j = cut_head(_t_clause)[0];
//		string _g = "gt@" + cut_head(_other_clause)[0];
		if (cut_head(_t_clause)[0] == "gt@" + cut_head(_other_clause)[0]) {
			core_push(
					cut_head(_t_clause)[1] + "@g@o"
							+ cut_head(_other_clause)[1]);
			return true;
		}
//		_j = cut_tail(_t_clause)[0];
//		_g = cut_tail(_other_clause)[0] + "@gt";
		if (cut_tail(_t_clause)[0] == cut_tail(_other_clause)[0] + "@gt") {
			core_push(
					cut_tail(_t_clause)[1] + "@g@o"
							+ cut_tail(_other_clause)[1]);
			return true;
		}
	}
	return false;
}
bool group_processing() {
	bool _return;
	string _k;
	clause _clauseK;
//	long _j;
	clause _clauseJ;
	/*
	 * make vertical core of _core;
	 * return none;
	 */
	_return = false;

//	arr_lc _core_others_tmp = _core_others;
//	arr_lc _core_t_tmp = _core_t;
	for (auto& [_k, _clauseK] : _core_others.get_map()) {
// if (replace_duplicated_group ( _k, _clauseK ))
// _return = true;
		for (auto& [_j, _clauseJ] : _core_others.get_map()) {
			if (_k == _j || _clauseJ == _clauseK)
				continue;
			if (make_vertical_group_2_clauses(_clauseK, _clauseJ))
// if (make_vertical_group_2_clauses ( _clauseK, _clauseJ ))
				return true;
		}
		for (auto& [_j, _clauseJ] : _core_t.get_map()) {
// if (replace_duplicated_group ( _k, _clauseK ))
// _return = true;
			if (_k == _j || _clauseJ == _clauseK)
				continue;
			if (make_vertical_group_1_group_1_clause(_clauseJ, _clauseK))
// if (make_vertical_group_2_clauses ( _clauseK, _clauseJ ))
				return true;
		}
	}

	return _return;
}
void* one_cycle_part2(void *_void_pointer) {
	try {
		long _k = (long) _void_pointer;
		clause _clauseK = _core_others[_k];
//	long _j;
		/*
		 * make vertical core of _core;
		 * return none;
		 */

//	arr_lc _core_others_tmp = _core_others;
//	arr_lc _core_t_tmp = _core_t;
//	for (auto& [_k, _clauseK] : _core_others_tmp) {
// if (replace_duplicated_group ( _k, _clauseK ))
// _return = true;
		for (auto& [_j, _clauseJ] : _core_others.get_map()) {
			if (_k == _j || _clauseJ == _clauseK)
				continue;
			make_vertical_group_2_clauses(_clauseK, _clauseJ);
// if (make_vertical_group_2_clauses ( _clauseK, _clauseJ ))
			//return true;
		}
		for (auto& [_j, _clauseJ] : _core_t.get_map()) {
// if (replace_duplicated_group ( _k, _clauseK ))
// _return = true;
			if (_k == _j || _clauseJ == _clauseK)
				continue;
			make_vertical_group_1_group_1_clause(_clauseJ, _clauseK);
// if (make_vertical_group_2_clauses ( _clauseK, _clauseJ ))
			//return true;
		}
//	}

		pthread_exit (NULL);
	} catch (int a) {
		pthread_exit (NULL);
	}
}
bool is_num_only_clause(string _clause_str) {
	return preg_match("/^[0-9\\$@]{1,}$/", _clause_str) ? true : false;
}
bool gI_push_core(string _tmp_clause, double _long_clause_weight,
		double _long_clause_bore, arr_ll _pos_arr, string _main_node) {
	bool _return;
	long _index;
	clause _db;
	string _pos_str;
	long _k;
	string _new_node_num;
	_return = false;
	if ((_index = cache_find_at_end('-' + _tmp_clause)) != false) {
		cache_push_core(_index);
		return false;
	}
	if ((_db = find_gi_db(_tmp_clause)) != clause_zero) {
		core_push(_db);
		return false;
	}
	_pos_str = implode(":", _pos_arr);
	if ((_k = core_find_at_end("-" + _tmp_clause) == false)) {
		_return = true;
		core_push(
				clause(
						(_new_node_num = new_node_num()) + "@g@I@" + _main_node
								+ "-" + _pos_str + "-" + _tmp_clause,
						sqrt(0.8 * _long_clause_weight * _long_clause_weight),
						sqrt(0.8 * _long_clause_bore * _long_clause_bore)));
	}
// else {
// _return = true && core_push ( [
// node_replace ( "i", "I", _core [_k] ._0 ),
// sqrt ( 0.8 * _long_clause_weight * _long_clause_weight ),
// sqrt ( 0.8 * _long_clause_bore * _long_clause_bore )
// ] );
// }
	return _return;
}
bool process_long_simple_clause(string _long_clause, double _long_clause_weight,
		double _long_clause_bore) {
	bool _return;
	string _;
	arr_ls _tmp_arr;
	string _head_start;
	arr_ls _long_clause_arr;
	long _i;
	string _tmp_clause;
	string _new_node_num;
	string _long_clause_current;
//	long _tmp_k;
	string _tmp_node;
	_return = false;
	if (strpos(_long_clause, "g@I") > -1 || strpos(_long_clause, "g@o") > -1)
		return false;
// if (! preg_match ( "^[0-9\_@n]{1,}_", _long_clause ))
// return false;
// 2 nodes group
	_tmp_arr = explode("@g@i@", _long_clause);
	_head_start = _tmp_arr[0];
	_long_clause = _tmp_arr[count(_tmp_arr) - 1];
	_long_clause_arr = explode("@", _long_clause);
	for (_i = 0; _i < (count(_long_clause_arr) - 1); _i++) {
//		if (!is_node_or_z_or_x(_long_clause_arr[_i])
//				|| !is_node_or_z_or_x(_long_clause_arr[_i + 1]))
//			continue;
		_tmp_clause = _long_clause_arr[_i] + "@" + _long_clause_arr[_i + 1];
		core_push(
				clause(
						find_create_gi_no_save(_tmp_clause) + "@g@I@"
								+ _tmp_clause, 0.5, 0.5));
	}

// 3 nodes group;
	for (_i = 0; _i < count(_long_clause_arr) - 2; _i++) {
		_tmp_clause = _long_clause_arr[_i] + "@" + _long_clause_arr[_i + 1]
				+ "@" + _long_clause_arr[_i + 2];
		core_push(
				clause(
						find_create_gi_no_save(_tmp_clause) + "@g@I@"
								+ _tmp_clause, 0.5, 0.5));
// && core_push ( _new_node_num + "@160" );
// _long_clause_current = replace_evaquilent ( _long_clause, _new_node_num, _tmp_clause );
// ! core_find ( _long_clause_current ) && core_push ( [
// _long_clause_current,
// 0.8,
// 0.8
// ] );

// for( auto const& [_tmp_k, ]: explode ( "@", _tmp_clause )) {
// core_push ( _tmp_node + "@a@" + _new_node_num );
// core_push ( _tmp_node + "@p_tmp_k@" + _new_node_num );
// }
	}
// 4 nodes group;
	for (_i = 0; _i < count(_long_clause_arr) - 3; _i++) {
		_tmp_clause = _long_clause_arr[_i] + "@" + _long_clause_arr[_i + 1]
				+ "@" + _long_clause_arr[_i + 2] + "@"
				+ _long_clause_arr[_i + 3];
		core_push(
				clause(
						find_create_gi_no_save(_tmp_clause) + "@g@I@"
								+ _tmp_clause, 0.5, 0.5));
	}
	return _return;
}
void process_long_clause1(string _long_pure_clause, double _long_clause_weight,
		double _long_clause_bore) {
	arr_ls _delimiters_lv;
//	long _k;
	string _delimiter;
	arr_ls _single_long_clauses;
	string _single_clause;
	clause _clause;
	arr_ls _clause_separators;
	arr_ls _smaller_clauses;
	string _clause_separator;
	string _smaller_clause;
	string _trimed_smaller_clause;
	string _driver_log;
//arr_lls _delimiters_arr_tmp = _delimiters_arr.get_map();
	arr_ls _flattened_delimiters_arr;
	for (auto const& [_key_rtt, _delimiters_lv] : _delimiters_arr.get_map()) {
		for (auto const& [_k, _delimiter] : _delimiters_lv) {
			array_push(_flattened_delimiters_arr, "@" + _delimiter + "@");
		}
	}
	_single_long_clauses = explode_multi(_flattened_delimiters_arr,
			_long_pure_clause);
	for (auto const& [_key_rtt, _single_clause] : _single_long_clauses) {
		process_long_simple_clause(_single_clause, _long_clause_weight,
				_long_clause_bore);
	}
}
bool process_long_all_kinds_of_clause(clause _clause) {
	arr_ls _smaller_clauses;
	arr_ls _clause_separators;
	string _clause_separator;
	string _trimed_smaller_clause;
	if (preg_match("/@190$/", _clause._0))
		return false;
	if (strpos(_clause._0, "d") > -1 || strpos(_clause._0, "l") > -1)
		return false;
	if (strpos(_clause._0, "p") > -1 || strpos(_clause._0, "a") > -1)
		return false;
	if (strpos(_clause._0, "@191@") > -1 || strpos(_clause._0, "@192@") > -1)
		return false;
	if (strpos(_clause._0, "C") > -1 || strpos(_clause._0, "@192@") > -1)
		return false;
// process unmanaged rule clause
	if (strpos(_clause._0, "@c@") > -1) {
// && ! preg_match ( '/^[0-9]{1,}@g@i@/', _clause ._0 )) {
// process_rule ( _clause );
		return false;
	}
	_clause_separators[0] = "@c@";
	_clause_separators[1] = "@C@";
	_clause_separators[2] = "g@i";
	_clause_separators[3] = "g@I";
	_clause_separators[4] = "g@o";
	_clause_separators[5] = "r";
	_clause_separators[6] = "y";
	_clause_separators[7] = "s";
	_clause_separators[8] = "b";
	_clause_separators[9] = "e";
	_clause_separators[10] = "a";
	_smaller_clauses.clear();
	for (auto const& [_key_rtt, _clause_separator] : _clause_separators) {
		if (strpos(_clause._0, _clause_separator) > -1) {
			_smaller_clauses = explode("@" + _clause_separator + "@",
					_clause._0);
			break;
		}
	}

	if (_smaller_clauses.size() == 0) {
// make array with 1 element
		_smaller_clauses.clear();
		_smaller_clauses[0] = _clause._0;
	}
	for (auto const& [_key_rtt, _smaller_clause] : _smaller_clauses) {
		if (substr_count(_smaller_clause, "@") < 1)
			continue;
		if (_smaller_clause == "")
			continue;
		// trim @
		_trimed_smaller_clause = trim_str(_smaller_clause);
		process_long_clause1(_trimed_smaller_clause, _clause._1, _clause._2);
	}
	return true;
}
// TO DO action in real world, to interact with real world
void driver_talk(string _str) {
	echo("Thuy Anh: " + _str + n());
}
string driver_compare(string _num1, string _num2) {
	if (td(_num1) > td(_num2))
		return "greater";
	if (td(_num1) == td(_num2))
		return "equal";
	return "smaller";
}
void driver_corepush(string _clause) {
	core_push(_clause);
}
bool driver_write(string _file, string _text) {
	bool _res = file_append(_file, _text);
	if (!_res) {
		driver_talk("Cannot open file _file");
		return false;
	}
	return true;
}
string driver_access(string _url) {
	return file_get_contents(_url);
}
string driver_read(string _file) {
	return driver_access(_file);
}
string driver_listen() {
	try {
		return readline();
	} catch (...) {
		driver_talk("Cannot listen");
		return "";
	}
	return "";
}
string act_process(string _command_str) {
	arr_ls _arr;
	arr_ls _command_arr;
	string _node;
	_arr.clear();
	_command_arr = explode("@", _command_str);
	for (auto const& [_key_rtt, _node] : _command_arr) {
		if (strpos(_node, "z") > -1)
			array_push(_arr, str_ireplace("z", "", _node));
		else {
			array_push(_arr, find_word(_node));
		}
	}
	return implode(" ", _arr);
}

bool isOperand(char c) {
	return (c >= '0' && c <= '9');
}

// utility function to find value of and operand
int value(char c) {
	return (c - '0');
}
long eval_math(string _input) {
// Base Case: Given expression is empty
	const char *exp = _input.c_str();
	if (*exp == '\0')
		return -1;

// The first character must be an operand, find its value
	int res = value(exp[0]);

// Traverse the remaining characters in pairs
	for (int i = 1; exp[i]; i += 2) {
		// The next character must be an operator, and
		// next to next an operand
		char opr = exp[i], opd = exp[i + 1];

		// If next to next character is not an operand
		if (!isOperand(opd))
			return -1;

		// Update result according to the operator
		if (opr == '+')
			res += value(opd);
		else if (opr == '-')
			res -= value(opd);
		else if (opr == '*')
			res *= value(opd);
		else if (opr == '/')
			res /= value(opd);

		// If not a valid operator
		else
			return -1;
	}
	return res;
}
string driver_math(string _input) {
	long _result;
	string _pre;
	string _expression;
	arr_ls _arr;
	string _str;
	string _ele;
	_result = false;
	_pre = explode("@l@", _input)[0];
	_expression = explode("@l@", _input)[1];
	_arr = explode("@", _expression);
	_str = "";
	for (auto const& [_key_rtt, _ele] : _arr) {
		if (strpos(_ele, "z") == 0)
			_str += str_replace("z", "", _ele);
		else
			_str += find_word(_ele);
	}
	_result = eval_math(_str);
	return _pre + "@z" + ts(_result);
}
arr_lls _driver_log;
void driver_log_push(arr_ls _arr) {
	arr_ls _temp;
	_temp[0] = ts(microtime(true));
	_temp[1] = _arr[0];
	_temp[2] = _arr[1];
	array_push(_driver_log, _temp);
	if (count(_arr) > 100)
		array_shift(_driver_log);
}
long attach_driver() {
//	long _key;
	clause _clause;
	string _str;
	string _params_str;
	arr_ls _params_arr;
	string _cmd_num;
	arr_lss _data;
	string _cmd;
	string _evr;
	for (auto const& [_key, _clause] : _core_d.get_map()) {
// if (strpos ( _clause ._0, "d@" ) == 0) {
		if (_clause._1 > ACTION_DENIED_LV_DEFAULT) {
			core_update(_key, "l" + substr(_clause._0, 1));
		}
// }}
		for (auto const& [_key, _clause] : _core_l.get_map()) {
			// if (substr ( _clause ._0, 0, 1 ) == "l") {

// act_process ( _str );
			arr_ls _temp;
			_temp[0] = _clause._0;
			_temp[1] = "0";
			driver_log_push(_temp);
			_params_str = substr(_clause._0, 2);
			_params_arr = explode("@", _params_str);
			_cmd_num = array_shift(_params_arr);
			_data = dbs("select * from cmds where num =" + _cmd_num);
			if (_data.size() == 0) {
				driver_talk("Sorry, driver #" + _cmd_num + " not found!");
				return 1;
			}
			_cmd = _data.begin()->second["func_name"];

			if (_params_arr.size() == 0) {
				driver_talk("Sorry, cannot done!");
				return 1;
			}
			_params_str = '"' + implode("@", _params_arr) + '"';
			try {
				echo("\\_evr=driver__cmd(_params_str);");
				echo("after__cmd(_key, '" + _evr + "');");
			} catch (...) {
				l("error");
			}
		}
// }
	}
	return 0;
}
bool replace_from_core(string _pattern, string _replace = "") {
	remove_from_core("254@g@i@");
	return true;
}
void after_talk(long _id, string _evr) {
	;

}
void after_write(long _id, string _evr) {
	;

}
void after_read(long _id, string _evr) {
	core_update(_id, read_to_num(_evr));
}
void after_listen(long _id, string _evr) {
	core_update(_id, read_to_num(_evr));
}
void after_access(long _id, string _evr) {
	core_update(_id, read_to_num(_evr));
}
void after_compare(long _id, string _evr) {
	string _compare = find_create_num(_evr);
	clause _clause = _core[_id];
	arr_ls _clause_arr = explode("@", _clause._0);
	_clause._0 = _clause_arr[2] + "@" + _compare + "@" + _clause_arr[3];
	_core[_id] = _clause;
}
void after_corepush(long _id, string _evr) {
	;
}
void after_math(long _core_key, string _evr) {
// _clause = _GLOBALS ["core"] [_core_key] [0];
// _clause_arr = explode ( "@", _clause );
// _first_node = _clause_arr [0];
	core_update(_core_key, _evr);
// unset ( _GLOBALS ['evr'] );
}
double driver_weight(string _represent_node) {
	long _explain_key;
	_explain_key = find_explain_key(_represent_node);
	if (_explain_key == false)
		return -1.0;
	return _core[_explain_key]._1;
}
bool after_weight(long _id, string _evr) {
	arr_ls _arr;
	string _node_to_weight;
	if (_evr == "")
		return false;
	_arr = explode("@", _core[_id]._0);
	_node_to_weight = _arr[count(_arr) - 1];
	core_push(clause(_node_to_weight + "@220@_evr", 1, 1));
	return true;
}
double driver_bore(string _represent_node) {
	long _explain_key;
	_explain_key = find_explain_key(_represent_node);
	if (_explain_key == false)
		return -1.0;
	return _core[_explain_key]._2;
}
bool after_bore(long _id, string _evr) {
	arr_ls _arr;
	string _node_to_weight;
	if (_evr == "")
		return false;
	_arr = explode("@", _core[_id]._0);
	_node_to_weight = _arr[count(_arr) - 1];
	core_push(clause(_node_to_weight + "@221@" + _evr, 1, 1));
	return true;
}
double driver_value(string _represent_node) {
	long _explain_key;
	_explain_key = find_explain_key(_represent_node);
	if (_explain_key == false)
		return false;
	return geo_avg(_core[_explain_key]._1, _core[_explain_key]._2);
}
bool after_value(long _id, string _evr) {
	arr_ls _arr;
	string _node_to_weight;
	if (_evr == "")
		return false;
	_arr = explode("@", _core[_id]._0);
	_node_to_weight = _arr[count(_arr) - 1];
	core_push(clause(_node_to_weight + "@222@_evr", 1, 1));
	return true;
}
long driver_length() {
//TODO: add	;
	return 0;
}
void after_length(string _id, string _evr) {
//TODO: add	;
	;
}
//=========================================================================
//=========================================================================
//=========================================================================
#endif
