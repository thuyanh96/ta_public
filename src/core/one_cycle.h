/*
 * one_cycle.h
 *
 *  Created on: May 8, 2021
 *      Author: qu
 */

#ifndef SRC_CORE_ONE_CYCLE_H_
#define SRC_CORE_ONE_CYCLE_H_

#include<core/php2cpp.h>
#include<pthread.h>
const string _db_prefix = "beta_";
#include<core/connect.h>
//#include<libs.h>
const double INCREMENT_FOR_NEW = 0.75;
const double DESCREASEMENT_FOR_NEW = 0.75;
const long MAX_CORE_SIZE = 220;
const long MAX_corer_prove_SIZE = 5;
const long MAX_corer_find_SIZE = 5;
const long MAX_R_LOGIC_SIZE = 15;
const long MAX_CACHE_SIZE = 300;
const long MAX_LOCAL_BORED = 10000;
const long MAX_CONNECTION = 100;
const long MAX_LOGIC = 400;
// const long DEFAULT_CORE_DENIED_LV=0.1;
const double CORE_SYNC_FACTOR = 1.05;
const double MIN_UNACCEPTABLE_XCLAUSE_VALUE = 0.4;
const long DEFAULT_RULE_VALUE_FACTOR = 1;
const long MAX_RULES_COUNT = 25;
const long MAX_RELS_COUNT = 20;
const double DEFAULT_OUT_CORE_VALUE_FACTOR = 0.03;
const double DEFAULT_OUT_CACHE_VALUE_FACTOR = 0.1;
const double CORE_DENIED_LV_DEFAULT = 0.15;
const double CORE_DENIED_LV_R_DEFAULT = 0.65;
const double ACTION_DENIED_LV_DEFAULT = 0.5;
const string core = "core";
const string cache = "cache";
const string rules = "rules";
const string br = "<br>";
// =======================================
// =======================================

arr_llb_ts _may_match;
double _denied_value = CORE_DENIED_LV_DEFAULT;
long _cycle_count = 0;
long _time = 0;
long _next_core_key = 0;
long _next_corer_prove_key = 0;
long _next_corer_find_key = 0;
long _next_r_logic_key = 0;
long _max_cache_key = 0;
long _max_node = 0;
long _max_rule = 0;
long _log_lv = 4;
long _word_index = 0;
arr_lc_ts _core;
arr_lc_ts _corer_prove;
arr_lc_ts _corer_find;
arr_lC_ts _r_logic;
arr_lc_ts _core_gi;
arr_lc_ts _core_go;
arr_lc_ts _core_t;
arr_lc_ts _core_d;
arr_lc_ts _core_l;
arr_lc_ts _core_others;
arr_l2_ts _rels;
arr_lc_ts _cache;
arr_lc_ts _rules;
arr_llll_ts _passed;
arr_lA_ts _steps_passed;
arr_lB_ts _logic;
arr_lls_ts _delimiters_arr = (arr_lls ) { { 0, { { 0, "\n" }, { 1, "\r\n" } } },
				{ 1, { { 0, "." }, { 1, "?" }, { 2, "!" } } }, { 2,
						{ { 0, ";" } } }, { 3, { { 0, "," } } } };

arr_ls_ts _all_new_vocal_id;
arr_lc_ts _max_important_rules;
arr_lc_ts _max_important_x_clauses;
arr_lc_ts _max_important_clauses;
arr_lc_ts _boss;

string _prove_num;

//#include<libs1.h>
//#include<libs2.h>
#include<libs/libs.h>

const string _mode = "st";
//#include<libs.h>

void* one_cycle_part1(void *_void_pointer) {
	try {
		long _key = (long) _void_pointer;
		clause _clause = _core.at(_key);

		mem_push_relative_rels(_key, _clause);
		mem_push_relative_rules(_key, _clause);
// mem_push_relative_rules_tmp ( _key, _clause );
		mem_push_relative_gi(_key, _clause);
		mem_push_relative_go(_key, _clause);
		question_processing(_key, _clause);
// equal_processing ( _key, _clause );
		conflict_in_lang(_key, _clause);
// seperators_processing ( _clause );
// check_negative_pair_clauses ();
// shrink_cache ();

		process_long_all_kinds_of_clause(_clause);
		read_a_word_type_of_clause(_clause);
// create_new_nodes ();

		pthread_exit(NULL);
	} catch (int a) {
		pthread_exit(NULL);
	}
}
void* one_cycle_part4(void *_void_pointer) {
	try {
		long _key = (long) _void_pointer;
		clause _clause = _core.at(_key);

		replace_long_phrases_single(_key, _clause);
		resolve_conflict_single(_key, _clause);
		reduce_x_node_clause_weight_single(_key, _clause);
		inscrease_bore_core_single(_key, _clause);

		pthread_exit(NULL);
	} catch (int a) {
		pthread_exit(NULL);
	}
}
bool one_cycle() {
//	long _countdbq;
	_cycle_count++;
	_dbt = 0.0;
	double _time0;
//	double _core_denied_lv;
	long _key_tmp;
	clause _clause;
	double _time1;
	double _time2;
	double _time3;
	double _time4;
	double _time5;
	long _thread_id;
// _countdbq = _countdbq;
// _func = [
// [ ],
// [ ]
// ];
// _gI_push_core = 0;
	_time0 = microtime(true);
// time_push ( _time0 );
	explain_core();
	line();
//	 explain_corer_find ();
//	 explain_corer_prove ();
	// echo array_reconstruct ( _core );
	// echoa ( _rules );
//	_core_denied_lv = _denied_value;
	// echo _global_read_clause_index + " : " + _core_denied_lv + "\r\n";
	// similars_finder ();
	//time_push();
	arr_lc _core_tmp = _core;
	map<long, pthread_t> _all_step_1_threads;
	_thread_id = 0;
	void *_thread_status;
	for (auto const& [_key, _clause] : _core_tmp) {
		_key_tmp = _key;
		pthread_create(&_all_step_1_threads[_thread_id], NULL, one_cycle_part1,
				(void*) _key_tmp);
		_thread_id++;
	}
	for (auto const& [_key, _tmp_pthread_t] : _all_step_1_threads) {
		pthread_join(_tmp_pthread_t, &_thread_status);
	}
	_time1 = microtime(true);
	// echo (_time1 - _time0) + n ();
// rule_based
	map<long, pthread_t> _all_step_2_threads;
	_thread_id = 0;
	for (auto& [_k, _clauseK] : _core_others.get_map()) {
		_key_tmp = _k;
		pthread_create(&_all_step_2_threads[_thread_id], NULL, one_cycle_part2,
				(void*) _key_tmp);
		_thread_id++;
	}
	for (auto const& [_key, _tmp_pthread_t] : _all_step_2_threads) {
		pthread_join(_tmp_pthread_t, &_thread_status);
	}

	_time2 = microtime(true);
	// echo (_time2 - _time1) + n ();

	map<long, pthread_t> _all_step_3_threads;
	_thread_id = 0;
	arr_lc _data = find_related_rules();
	for (auto& [_k, _clauseK] : _data) {
		_key_tmp = _k;
		pthread_create(&_all_step_3_threads[_thread_id], NULL, one_cycle_part3,
				(void*) _key_tmp);
		_thread_id++;
	}
	for (auto const& [_key, _tmp_pthread_t] : _all_step_3_threads) {
		pthread_join(_tmp_pthread_t, &_thread_status);
	}; // very important;

	_time3 = microtime(true);
	// echo (_time3 - _time2) + n ();

	map<long, pthread_t> _all_step_4_threads;
	_thread_id = 0;
	for (auto& [_k, _clauseK] : _core_others.get_map()) {
		_key_tmp = _k;
		pthread_create(&_all_step_4_threads[_thread_id], NULL, one_cycle_part4,
				(void*) _key_tmp);
		_thread_id++;
	}
	for (auto const& [_key, _tmp_pthread_t] : _all_step_4_threads) {
		pthread_join(_tmp_pthread_t, &_thread_status);
	}

	_time2 = microtime(true);
	shrink_core_and_cache();
	//attach_driver();

	_time4 = microtime(true);
	// echo (_time4 - _time3) + n ();

	arr_lc _top_rules = find_max_important_rules(5);
	map<long, pthread_t> _all_step_5_threads;
	_thread_id = 0;
	for (auto& [_k, _clauseK] : _top_rules) {
		_key_tmp = _k;
		pthread_create(&_all_step_5_threads[_thread_id], NULL, one_cycle_part5,
				(void*) _key_tmp);
		_thread_id++;
	}
	for (auto const& [_key, _tmp_pthread_t] : _all_step_5_threads) {
		pthread_join(_tmp_pthread_t, &_thread_status);
	}

	//revert_processing();

	//_top_rules = get_top_rules();
	find_corer_in_corel();
	map<long, pthread_t> _all_step_6_threads;
	_thread_id = 0;
	for (auto& [_k, _clauseK] : _corer_prove.get_map()) {
		_key_tmp = _k;
		pthread_create(&_all_step_6_threads[_thread_id], NULL, one_cycle_part6,
				(void*) _key_tmp);
		_thread_id++;
	}
	for (auto const& [_key, _tmp_pthread_t] : _all_step_6_threads) {
		pthread_join(_tmp_pthread_t, &_thread_status);
	}

	match_2_core();
	add_core_to_corer_find();

	map<long, pthread_t> _all_step_7_threads;
	_thread_id = 0;
	for (auto& [_k, _clauseK] : _corer_find.get_map()) {
		_key_tmp = _k;
		pthread_create(&_all_step_7_threads[_thread_id], NULL, one_cycle_part7,
				(void*) _key_tmp);
		_thread_id++;
	}
	for (auto const& [_key, _tmp_pthread_t] : _all_step_7_threads) {
		pthread_join(_tmp_pthread_t, &_thread_status);
	}
	//simple_find_x();
	// task_processing();
	_time5 = microtime(true);
	// echo (_time5 - _time4) + n ();
	// echo "countdbq: " + (_countdbq - _countdbq) + n ();
	// echo _dbq_time + "/" + (_time5 - _time0) + "=" + (_dbq_time / (_time5 - _time0)) + n ();
	// print_r ( _func );
//	dbq(
//			"update settings set valuex = " + ts(_max_node)
//					+ " where keyx = 'max_node'");
	if (check_negative_pair_clauses() && (!find_x_node_unsolved().empty())) {
		// echo n () + (microtime ( true ) - _time0);
		//echo(ts(_time0) + "\n");
//		echo(ts(_time1 - _time0) + "\n");
//		echo(ts(_time2 - _time1) + "\n");
//		echo(ts(_time3 - _time2) + "\n");
//		echo(ts(_time4 - _time3) + "\n");
//		echo(ts(_time5 - _time4) + "\n");
//		echo(
//				"Total:" + ts(microtime(true) - _time0) + +" | cycle: "
//						+ ts(_cycle_count) + "\n");
		return false;
	} else {
		//echo(ts(_time0) + "\n");
//		echo(ts(_time1 - _time0) + "\n");
//		echo(ts(_time2 - _time1) + "\n");
//		echo(ts(_time3 - _time2) + "\n");
//		echo(ts(_time4 - _time3) + "\n");
//		echo(ts(_time5 - _time4) + "\n");
		// TODO: What do I do now
		// core_push ( [
		// "l@talk@108747@29800@48239@29800",
		// 1,
		// 1
		// ] );
//		echo(
//				"Total:" + ts(microtime(true) - _time0) + +" | cycle: "
//						+ ts(_cycle_count) + "\n");
		return true;
	}
	return true;
}
#endif /* SRC_CORE_ONE_CYCLE_H_ */
