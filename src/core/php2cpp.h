/*
 * php2cpp.h
 *
 *  Created on: May 2, 2021
 *      Author: qu
 */

#ifndef SRC_CORE_PHP2CPP_H_
#define SRC_CORE_PHP2CPP_H_

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <unordered_map>
#include <string>
#include <chrono>
#include <variant>
#include <algorithm>
#include <regex>
#include <boost/algorithm/string.hpp>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <csignal>
#include <boost/algorithm/string/replace.hpp>
#include <core/mp.h>
#include <core/mps.h>

using namespace std;
struct clause {
	string _0;
	double _1;
	double _2;
	long _3;
public:
	clause(string var0, double var1, double var2, long var3) {
		_0 = var0;
		_1 = var1;
		_2 = var2;
		_3 = var3;
	}
	clause(string var0, double var1, double var2) {
		_0 = var0;
		_1 = var1;
		_2 = var2;
		_3 = 0;
	}
	clause(string var0) {
		_0 = var0;
		_1 = 0.0;
		_2 = 0.0;
		_3 = 0;
	}
	clause() {
		_0 = "";
		_1 = 0.0;
		_2 = 0.0;
		_3 = 0;
	}
	bool operator ==(clause A) {
		return (_0 == A._0 && _1 == A._1 && _2 == A._2 && _3 == A._3);
	}
	bool operator !=(clause A) {
		return !(*this == A);
	}
};
struct dual {
	string _0;
	string _1;
	double _2;
	double _3;
	long _4;
public:
	dual(string var0, string var1, double var2, double var3, long var4) {
		_0 = var0;
		_1 = var1;
		_2 = var2;
		_3 = var3;
		_4 = var4;
	}
	dual(string var0, string var1, double var2, double var3) {
		_0 = var0;
		_1 = var1;
		_2 = var2;
		_3 = var3;
		_4 = 0;
	}
	dual(string var0, string var1) {
		_0 = var0;
		_1 = var1;
		_2 = 0.0;
		_3 = 0.0;
		_4 = 0;
	}
	dual() {
		_0 = "";
		_1 = "";
		_2 = -1.0;
		_3 = -1.0;
		_4 = -1;
	}
	bool operator ==(dual A) {
		return (_0 == A._0 && _1 == A._1 && _2 == A._2 && _3 == A._3
				&& _4 == A._4);
	}
	bool operator !=(dual A) {
		return !(*this == A);
	}
};
struct sublongA {
	map<long, long> _0;
	long _1;
public:
	sublongA(map<long, long> _i0, long _i1) {
		_0 = _i0;
		_1 = _i1;
	}
	sublongA() {
		map<long, long> _temp;
		_0 = _temp;
		_1 = -1;
	}
	bool operator ==(sublongA A) {
		return (_0 == A._0 && _1 == A._1);
	}
	bool operator !=(sublongA A) {
		return !(*this == A);
	}
};
struct sublongB {
	map<long, long> _0;
	long _1;
	long _2;
public:
	sublongB(map<long, long> _i0, long _i1, long _i2) {
		_0 = _i0;
		_1 = _i1;
		_2 = _i2;
	}
	sublongB() {
		map<long, long> _temp;
		_0 = _temp;
		_1 = -1;
		_2 = -1;
	}
	bool operator ==(sublongB A) {
		return (_0 == A._0 && _1 == A._1 && _2 == A._2);
	}
	bool operator !=(sublongB A) {
		return !(*this == A);
	}
};
struct substringC {
	map<long, string> _0;
	string _1;
public:
	substringC(map<long, string> _i0, string _i1) {
		_0 = _i0;
		_1 = _i1;
	}
	substringC() {
		map<long, string> _temp;
		_0 = _temp;
		_1 = "";
	}
	bool operator ==(substringC A) {
		return (_0 == A._0 && _1 == A._1);
	}
	bool operator !=(substringC A) {
		return !(*this == A);
	}
};

struct corer_find_ele {
	string _0;
	double _1;
	double _2;
	bool _3;
	long _4;
public:
	corer_find_ele(string _i0, double _i1, double _i2, bool _i3, long _i4) {
		_0 = _i0;
		_1 = _i1;
		_2 = _i2;
		_3 = _i3;
		_4 = _i4;
	}
	corer_find_ele() {
		_0 = "";
		_1 = -1.0;
		_2 = -1.0;
		_3 = false;
		_4 = -1;
	}
};
typedef map<long, clause> core_find_type;
typedef map<long, string> arr_ls;
typedef map<long, long> arr_ll;
typedef map<long, double> arr_ld;
typedef map<long, map<long, long>> arr_lll;
typedef map<long, map<string, string>> arr_lss;
typedef map<string, string> arr_ss;
typedef map<string, long> arr_sl;
typedef map<long, clause> arr_lc;
typedef map<long, bool> arr_lb;
typedef map<long, map<long, bool>> arr_llb;
typedef map<long, dual> arr_l2;
typedef map<long, sublongA> arr_lA;
typedef map<long, sublongB> arr_lB;
typedef map<long, substringC> arr_lC;
typedef map<long, string> tmp_type;
typedef map<long, map<long, string>> arr_lls;
typedef map<long, map<long, map<long, long>>> arr_llll;
typedef map<long, map<long, double>> arr_lld;
typedef map<string, map<long, map<string, string>>> arr_slss;
typedef map<string, map<string, map<string, long>>> arr_sssl;

typedef mp<clause> core_find_type_ts;
typedef mp<string> arr_ls_ts;
typedef mp<long> arr_ll_ts;
typedef mp<double> arr_ld_ts;
typedef mp<map<long, long>> arr_lll_ts;
typedef mp<map<string, string>> arr_lss_ts;
typedef map<string, string> arr_ss_ts;
typedef map<string, long> arr_sl_ts;
typedef mp<clause> arr_lc_ts;
typedef mp<bool> arr_lb_ts;
typedef mp<map<long, bool>> arr_llb_ts;
typedef mp<dual> arr_l2_ts;
typedef mp<sublongA> arr_lA_ts;
typedef mp<sublongB> arr_lB_ts;
typedef mp<substringC> arr_lC_ts;
typedef mp<string> tmp_type_ts;
typedef mp<map<long, string>> arr_lls_ts;
typedef mp<map<long, map<long, long>>> arr_llll_ts;
typedef mp<map<long, double>> arr_lld_ts;
typedef map<string, mp<map<string, string>>> arr_slss_ts;
typedef map<string, map<string, mps<string, long>>> arr_sssl_ts;

typedef unordered_map<long, string> u_arr_ls;
typedef unordered_map<long, long> u_arr_ll;
typedef unordered_map<long, double> u_arr_ld;
typedef unordered_map<long, map<long, long>> u_arr_lll;
typedef unordered_map<long, map<string, string>> u_arr_lss;
typedef unordered_map<string, string> u_arr_ss;
typedef unordered_map<long, clause> u_arr_lc;

typedef unordered_map<long, bool> u_arr_lb;
typedef unordered_map<long, map<long, bool>> u_arr_llb;
typedef unordered_map<long, dual> u_arr_l2;
typedef unordered_map<long, sublongA> u_arr_lA;
typedef unordered_map<long, sublongB> u_arr_lB;
typedef unordered_map<long, string> u_tmp_type;
typedef unordered_map<long, map<long, string>> u_arr_lls;

clause clause_zero;
dual dual_zero;
sublongA sublongA_zero;
arr_ls arr_ls_zero;
arr_ll arr_ll_zero;
arr_ld arr_ld_zero;
arr_lll arr_lll_zero;
arr_lss arr_lss_zero;
arr_ss arr_ss_zero;
arr_lc arr_lc_zero;
arr_lb arr_lb_zero;
arr_llb arr_llb_zero;
arr_l2 arr_l2_zero;
arr_lA arr_lA_zero;
arr_lls arr_lls_zero;
u_arr_lll u_arr_lll_zero;
arr_lls arr_lls_true = { { 0, { { 0, "true" } }, } };
arr_lls arr_lls_false = { { 0, { { 0, "false" } }, } };

string ts(long _input) {
	return to_string(_input);
}
string ts(double _input) {
	return to_string(_input);
}
long tl(string _input) {
	try {
		return (long) stoi(_input);
	} catch (...) {
		return 0;
	}
}
double td(string _input) {
	return (double) atof(_input.c_str());
}
void clause_push(arr_lc &_map, clause _clause) {
	long inserted_key = 0;
	if (!_map.empty())
		inserted_key = _map.rbegin()->first + 1;
	_map.insert( { inserted_key, _clause });
}

//void array_push(arr_lc &_arr, clause _ele) {
//	long _max_key = 1;
//	if (!_arr.empty())
//		_max_key = (--_arr.end())->first;
//	_arr.insert(pair<long, clause>(_max_key, _ele));
//}
//void array_push(arr_ll &_arr, long _ele) {
//	long _max_key = 1;
//	if (!_arr.empty())
//		_max_key = (--_arr.end())->first;
//	_arr.insert(pair<long, long>(_max_key, _ele));
//}
void array_push(arr_ls &_arr, string _ele) {
	///long _max_key;
	if (_arr.empty()) {
		_arr[0] = _ele;
		return;
	}
	long _max_key = (_arr.rbegin()->first);
	_arr[_max_key + 1] = _ele;
}
//void array_push(arr_ss &_arr, string _key, string _value) {
////	long _max_key = 1;
////	if (!_arr.empty())
////		_max_key = (--_arr.end())->first;
//	_arr.insert(pair<string, string>(_key, _value));
//}
//void array_push(arr_lss &_arr, map<string, string> _ele) {
//	long _max_key = 1;
//	if (!_arr.empty())
//		_max_key = (--_arr.end())->first;
//	_arr.insert(pair<long, map<string, string>>(_max_key + 1, _ele));
//}
//void array_push(arr_l2 &_arr, dual _ele) {
//	long _max_key = 1;
//	if (!_arr.empty())
//		_max_key = (--_arr.end())->first;
//	_arr.insert(pair<long, dual>(_max_key + 1, _ele));
//}
//void array_push(arr_lls &_arr, arr_ls _ele) {
//	long _max_key = 1;
//	if (!_arr.empty())
//		_max_key = (--_arr.end())->first;
//	_arr.insert(pair<long, arr_ls>(_max_key + 1, _ele));
//}
//void array_push(arr_lll &_arr, arr_ll _ele) {
//	long _max_key = 1;
//	if (!_arr.empty())
//		_max_key = (--_arr.end())->first;
//	_arr.insert(pair<long, arr_ll>(_max_key + 1, _ele));
//}
template<typename V>
void array_push(map<long, V> &_arr, V _ele) {
	if (_arr.size() == 0) {
		_arr[0] = _ele;
		return;
	}
	long _max_key = (_arr.rbegin()->first);
	_arr[_max_key + 1] = _ele;
}
template<class V>
void array_push(unordered_map<long, V> &_arr, V _ele) {
	long _max_key = 0;
	for (auto const& [_k, _v] : _arr) {
		if (_k > _max_key)
			_max_key = _k;
	}
	_arr[_max_key + 1] = _ele;
}
template<class V>
void array_push(mp<V> &_arr, V _ele) {
	_arr.push(_ele);
}
arr_ls explode(string _del, string _str) {
	arr_ls _tokens;
	size_t _prev = 0, _pos = 0;
//	if (_str == "")
//		return arr_ls_zero;
	if (_del == "") {
		throw 43;
	}
	do {
		_pos = _str.find(_del, _prev);
		if (_pos == string::npos)
			_pos = _str.length();
		string _token = _str.substr(_prev, _pos - _prev);
		if (!_token.empty())
			array_push(_tokens, _token);
		_prev = _pos + _del.length();
	} while (_pos < _str.length() && _prev < _str.length());
	return _tokens;
}
void print_r(arr_ls _vector_input) {
	cout << "[" << endl;
	for (unsigned long _i = 0; _i < _vector_input.size(); _i++)
		cout << "\t" << _i << " => \"" << _vector_input[_i] << "\"," << endl;
	cout << "]" << endl;
}

void print_r(arr_ll _vector_input) {
	cout << "[" << endl;
	for (unsigned long _i = 0; _i < _vector_input.size(); _i++)
		cout << "\t" << _i << " => " << _vector_input[_i] << "," << endl;
	cout << "]" << endl;
}

void print_r(arr_lss _input) {
	cout << "[" << endl;
	for (auto const& [_key0, _val0] : _input) {
		cout << "\t[" << endl;
		for (auto const& [_key, _val] : _val0)
			cout << "\t\t" << _key << " => \"" << _val << "\"," << endl;
		cout << "\t]," << endl;
	}
	cout << "]" << endl;
}
template<typename T>
map<long, T> sort_arr(map<long, T> _input_arr) {
	map<long, T> _arr1 = _input_arr;
	map<long, T> _res;
	for (long _i = 0; _i < _input_arr.size(); _i++) {
		long _tmp_key = 0;
		double _tmp_value = -8888.88;
		for (auto const& [_k, _v] : _arr1) {
			if (_v >= _tmp_value) {
				_tmp_key = _k;
				_tmp_value = _v;
			}
		}
		_res.insert(pair<long, T>(_tmp_key, _tmp_value));
		_arr1.erase(_tmp_key);
	}
	return _res;
}
arr_lc sort_arr_lc_by_valuex_desc(arr_lc _input_arr) {
	arr_lc _arr1 = _input_arr;
	arr_lc _res;
	for (long _i = 0; _i < (long) _input_arr.size(); _i++) {
		long _tmp_key = 0;
		double _tmp_value = -8888.88;
		for (auto const& [_k, _v] : _arr1) {
			if ((_v._1 * _v._2) >= _tmp_value) {
				_tmp_key = _k;
				_tmp_value = (_v._1 * _v._2);
			}
		}
		_res.insert(pair<long, clause>(_tmp_key, _arr1[_tmp_key]));
		_arr1.erase(_tmp_key);
	}
	return _res;
}
void print_r(arr_lc _input) {
	cout << "[" << endl;
	for (auto const& [_key0, _val0] : _input) {
		cout << "\t[" << _key0 << ": " << _val0._0 << "      " << _val0._1
				<< " - " << _val0._2 << "  |  " << _val0._3;
		cout << "\t]," << endl;
	}
	cout << "]" << endl;
}
void print_r(arr_ss _input) {
	cout << "[" << endl;
	for (auto const& [_key0, _val0] : _input) {
		cout << "\t" << _key0 << " => " << _val0;
		cout << "\t," << endl;
	}
	cout << "]" << endl;
}
void print_r(arr_sl _input) {
	cout << "[" << endl;
	for (auto const& [_key0, _val0] : _input) {
		cout << "\t" << _key0 << " => " << _val0;
		cout << "\t," << endl;
	}
	cout << "]" << endl;
}
void print_r(arr_ld _input) {
	cout << "[" << endl;
	for (auto const& [_key0, _val0] : _input) {
		cout << "\t" << _key0 << " => " << _val0;
		cout << "\t," << endl;
	}
	cout << "]" << endl;
}
void print_r(arr_lll _input) {
	cout << "[" << endl;
	for (auto const& [_key0, _val0] : _input) {
		cout << "\t" << _key0 << " => " "\n";
		for (auto const& [_key1, _val1] : _val0) {
			cout << "\t\t" << _key1 << " => " << _val1 << "\n";
		}
		cout << "\t," << endl;
	}
	cout << "]" << endl;
}
bool file_overwrite(string _file, string _str) {
	try {
		ofstream out(_file);
		out << _str;
		out.close();
		return true;
	} catch (...) {
		return false;
	}
}
bool file_append(string _file, string _str) {
	try {
		ofstream out(_file, ios_base::app);
		out << _str;
		out.close();
		return true;
	} catch (...) {
		return false;
	}
}
arr_ll array_keys_with_value(arr_ls _arr, string _find_after) {
	arr_ll _res = { };
	for (unsigned long _i = 0; _i < _arr.size(); _i++) {
		if (_find_after == _arr[_i])
			array_push(_res, (long) _i);
	}
	return _res;
}
template<typename T>
unordered_map<long, T> array_slice(unordered_map<long, T> _arr, long _start,
		long _len, bool klklikkkk = true) {
	unordered_map<long, T> _return;
	long _i = -1;
	for (auto const& [_k, _v] : _arr) {
		_i++;
		if (_i < _start)
			continue;
		if (_i > (_start + _len))
			break;
		_return[_k] = _v;
	}
	return _return;
}
unordered_map<long, string> array_slice(unordered_map<long, string> _arr,
		long _start, long _len, bool klklikkkk = true) {
	unordered_map<long, string> _return;
	long _i = -1;
	for (auto const& [_k, _v] : _arr) {
		_i++;
		if (_i < _start)
			continue;
		if (_i > (_start + _len))
			break;
		_return[_k] = _v;
	}
	return _return;
}
template<typename T>
map<long, T> array_slice(map<long, T> _arr, long _start, long _len,
		bool klklikkkk = true) {
	map<long, T> _return;
	long _i = -1;
	for (auto const& [_k, _v] : _arr) {
		_i++;
		if (_i < _start)
			continue;
		if (_i > (_start + _len))
			break;
		_return[_k] = _v;
	}
	return _return;
}
map<long, string> array_slice(map<long, string> _arr, long _start, long _len,
		bool klklikkkk = true) {
	map<long, string> _return;
	long _i = -1;
	for (auto const& [_k, _v] : _arr) {
		_i++;
		if (_i < _start)
			continue;
		if (_i > (_start + _len))
			break;
		_return[_k] = _v;
	}
	return _return;
}
double microtime(bool i = true) {
	using namespace std::chrono;
	long long _d = duration_cast<nanoseconds>(
			system_clock::now().time_since_epoch()).count();
	double _res = (double) _d / 1000000000.f;
	return _res;
}
long time_php() {
	return (long) floor(microtime());
}
void echo(int _input) {
	cout.precision(17);
	cout << _input;
}
void echo(long _input) {
	cout.precision(17);
	cout << _input;
}
void echo(double _input) {
	cout.precision(17);
	cout << _input;
}
void echo(string _input) {
	cout.precision(17);
	cout << _input;
}
void echo(char _input) {
	cout << _input;
}
//void echo(bool _input) {
//	if (_input)
//		cout << "true";
//	else
//		cout << "false";
//}
long count(arr_lc _arr) {
	return _arr.size();
}
long count(arr_ll _arr) {
	return _arr.size();
}
long count(arr_ls _arr) {
	return _arr.size();
}
long count(arr_lss _arr) {
	return _arr.size();
}
long count(arr_ss _arr) {
	return _arr.size();
}
long count(arr_l2 _arr) {
	return _arr.size();
}
string implode(string _glue, arr_ls _arr) {
	if (_arr.empty())
		return "";
	string _res = "";
	long _max_k = _arr.size() - 1;
	long _k = 0;
	for (auto const& [_i, _v] : _arr) {
		if (_k < _max_k)
			_res += _v + _glue;
		_k++;
	}
	_res += _arr.rbegin()->second;
	return _res;
}
string implode(string _glue, arr_ll _arr) {
	if (_arr.empty())
		return "";
	string _res = "";
	for (unsigned long _i = 0; _i < (_arr.size() - 1); _i++) {
		_res += ts(_arr[_i]) + _glue;
	}
	//TODO: use rbegin;
	_res += ts(_arr[_arr.size() - 1]);
	return _res;
}
string rtrim(string _str, string _sub) {
	arr_ls _tmp = explode(_sub, _str);
	for (long _i = 0; _i < (long) _tmp.size(); _i++) {
		if (_tmp[_i] != "")
			break;
		_tmp.erase(_i);
	}
	return implode(_sub, _tmp);
}
string ltrim(string _str, string _sub) {
	arr_ls _tmp = explode(_sub, _str);
	for (long _i = _tmp.size() - 1; _i >= 0; _i--) {
		if (_tmp[_i] != "")
			break;
		_tmp.erase(_i);
	}
	return implode(_sub, _tmp);
}
string trim(string _str, string _sub) {
	return rtrim(ltrim(_str, _sub), _sub);
}
string rtrim(string _str) {
	boost::trim_right(_str);
	return _str;
}
string ltrim(string _str) {
	boost::trim_left(_str);
	return _str;
}
string trim(string _str) {
	boost::trim(_str);
	return _str;
}
string strtolower(string _str) {
	boost::to_lower(_str);
	return _str;
}
bool str_contains(string _haystack, string _needle) {
	if (_haystack.find(_needle) != string::npos) {
		//.. found.
		return true;
	}
	return false;
}
long strpos(string _haystack, string _needle) {
	size_t _pos = _haystack.find(_needle);
	if (_pos == string::npos)
		return -1;
	else
		return (long) _pos;
}
long stripos(string _haystack, string _needle) {
	return strpos(strtolower(_haystack), strtolower(_needle));
}
template<typename T>
arr_ll array_keys(map<long, T> _arr) {
	arr_ll _res;
	for (auto const& [_key0, _val0] : _arr) {
		_res[_res.size()] = _key0;
	}
	return _res;
}
arr_ll array_keys(arr_ls _arr, string _str = "") {
	arr_ll _res;
	for (auto const& [_key0, _val0] : _arr) {
		if (_str == "" || _val0 == _str)
			_res[_res.size()] = _key0;
	}
	return _res;
}
//arr_ll array_keys(arr_lc _arr) {
//	arr_ll _res;
//	for (auto const& [_key0, _val0] : _arr) {
//		array_push(_res, _key0);
//	}
//	return _res;
//}
arr_ls array_keys(arr_ss _arr) {
	arr_ls _res;
	for (auto const& [_key0, _val0] : _arr) {
		array_push(_res, _key0);
	}
	return _res;
}
//arr_ls array_values(arr_ss _arr) {
//	arr_ls _res;
//	for (auto const& [_key0, _val0] : _arr) {
//		array_push(_res, _val0);
//	}
//	return _res;
//}
arr_ls array_reverse(arr_ls _arr) {
	if (_arr.size() < 2)
		return _arr;
	arr_ls _tmp = _arr;
	arr_ls _res;
	map<long, string>::const_iterator _forwardIt = _tmp.begin();
	map<long, string>::const_reverse_iterator _reverseIt = _tmp.rbegin();
	for (; _forwardIt != _tmp.end(); ++_forwardIt, ++_reverseIt) {
		_res[_forwardIt->first] = _reverseIt->second;
	}
	return _res;
}
bool is_numeric(string const _str) {
	try {
		stol(_str);
		return true;
	} catch (...) {
		;
	}
	try {
		stod(_str);
		return true;
	} catch (...) {
		;
	}
	return false;
}
//long ceil(double _num) {
//	return (long) ceil(_num);
//}
//long floor(double _num) {
//	return (long) floor(_num);
//}
long strlen(string _str) {
	return _str.length();
}
string str_replace(string _search, string _replace, string _input) {
	string _output = _input;
	boost::replace_all(_output, _search, _replace);
	return _output;
}
long substr_count(string _haystack1, string _needle) {
	long _occurrences = 0;
	string _haystack = _haystack1;
	string::size_type _pos = 0;
	while ((_pos = _haystack.find(_needle, _pos)) != string::npos) {
		++_occurrences;
		_pos += _needle.length();
	}
	return _occurrences;
}
string str_replace(string _search, string _replace, string _input,
		long &_count) {
	_count = substr_count(_input, _search);
	return regex_replace(_input, regex(_search), _replace);
}
string str_ireplace(string _search, string _replace, string _input) {
	string _input1 = _input;
	boost::ireplace_all(_input1, _search, _replace);
	return _input1;
}
string add0(string _str) {
	if (_str.length() < 2)
		return "0" + _str;
	return _str;
}
string date(const string _format = "d-m-Y H:i:s") {
	string _str = _format;

	time_t t = time(NULL);
	tm *timePtr = localtime(&t);

	long _seconds = timePtr->tm_sec;
	long _minutes = timePtr->tm_min;
	long _hours = timePtr->tm_hour;
	long _day_of_month = timePtr->tm_mday;
	long _month_of_year = timePtr->tm_mon;
	long _year = timePtr->tm_year + 1900;
//	long _weekday = timePtr->tm_wday;
//	long _day_of_year = timePtr->tm_yday;
//	long daylight_savings = timePtr->tm_isdst;
	_str = str_replace("d", add0(to_string(_day_of_month)), _str);
	_str = str_replace("m", add0(to_string(_month_of_year)), _str);
	_str = str_replace("Y", to_string(_year), _str);
	_str = str_replace("H", add0(to_string(_hours)), _str);
	_str = str_replace("i", add0(to_string(_minutes)), _str);
	_str = str_replace("s", add0(to_string(_seconds)), _str);
	return _str;
}
bool mkdir(string _path) {
	filesystem::path _path1 = (filesystem::path) _path;
	return filesystem::create_directory(_path1);
}
string get_env(string _name) {
	char *pPath;
	char name[_name.length() + 1];
	strcpy(name, _name.c_str());
	pPath = getenv(name);
	if (pPath != NULL) {
		string _str(pPath);
		return _str;
	}
	return "";
}
string substr(string _str, long _start, long _length = 0) {
	if ((_start) > ((long) _str.length() - 1)
			|| (_start + _length) > ((long) _str.length() - 1))
		return "";
	if (_length == 0)
		_length = _str.length();
	return _str.substr(_start, _length);
}
arr_ls str_split(string _str, long _num = 1) {
	arr_ls _return;
	long _len = strlen(_str) - 1;
	string _tmp_str;
	long _i = 0;
	while (_i < _len) {
		_tmp_str = substr(_str, _i, _num);
		array_push(_return, _tmp_str);
		_i += strlen(_tmp_str);
	}
	return _return;
}
long array_last_key(arr_lc _arr) {
	long _largest = 0;
	for (auto const& [_key, _value] : _arr) {
		if (_key > _largest)
			_largest = _key;
	}
	return _largest;
}

long random_int(long _start, long _end) {
	srand(time(NULL));
	long _minus = _end - _start + 1;
	return (rand() % _minus + _start);
}
string shell_exec(string _cmd) {
	array<char, 128> buffer;
	int _n = _cmd.length();
	char _char_array[_n + 1];
	strcpy(_char_array, _cmd.c_str());
	string result;
	unique_ptr<FILE, decltype(&pclose)> pipe(popen(_char_array, "r"), pclose);
	if (!pipe) {
		throw runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}
template<typename T>
bool in_array(T _find, map<long, T> _arr) {
	for (auto const& [_i, _v] : _arr) {
		if (_find == _v)
			return true;
	}
	return false;
}
template<typename T>
bool in_array(T _find, mp<T> _arr1) {
	map<long, T> _arr = _arr1.get_map();
	for (auto const& [_i, _v] : _arr) {
		if (_find == _v)
			return true;
	}
	return false;
}
bool in_array(string _find, arr_ls _arr) {
	for (auto const& [_i, _v] : _arr) {
		if (_v == _find)
			return true;
	}
	return false;
}
bool in_array(string _find, arr_ls_ts _arr) {
	return in_array(_find, _arr.get_map());
}
long array_search(long _find, arr_ll _arr) {
	for (auto const& [_i, _v] : _arr) {
		if (_v == _find)
			return true;
	}
	return false;
}
long array_search(arr_ll _find, arr_lll _arr) {
	for (auto const& [_i, _v] : _arr) {
		if (_v == _find)
			return true;
	}
	return false;
}
long array_search(string _find, arr_ls _arr) {
	for (auto const& [_i, _v] : _arr) {
		if (_v == _find)
			return _i;
	}
	return -1;
}
string array_search(string _find, arr_ss _arr) {
	for (auto const& [_i, _v] : _arr) {
		if (_v == _find)
			return _i;
	}
	return "";
}
template<typename T>
map<long, T> array_values(map<long, T> _arr) {
	map<long, T> _return_arr;
	//_return_arr[0] = 1;
	for (auto const& [_k, _v] : _arr)
		_return_arr[_return_arr.size()] = _v;
	return _return_arr;
}
void array_unshift(long _ele, arr_ll &_arr) {
	long _key = _arr.begin()->first;
	_arr[_key - 1] = _ele;
	_arr = array_values(_arr);
}
template<typename K, typename V>
void array_shift(map<K, V> &_arr) {
	_arr.erase(_arr.begin()->first);
}
string array_shift(arr_ls &_arr) {
	if (_arr.empty())
		return "";
	string _return = _arr.begin()->second;
	_arr.erase(_arr.begin()->first);
	return _return;
}
string array_shift(arr_ss &_arr) {
	if (_arr.empty())
		return "";
	string _return = _arr.begin()->second;
	_arr.erase(_arr.begin()->first);
	return _return;
}
arr_ss array_shift(arr_lss &_arr) {
	if (_arr.empty())
		return arr_ss_zero;
	arr_ss _return = _arr.begin()->second;
	_arr.erase(_arr.begin()->first);
	return _return;
}
//void array_shift(arr_lc &_arr) {
//	_arr.erase(_arr.begin());
//}
string file_get_contents(string _file) {
//	int _n = _file.length();
//	char _char_array[_n + 1];
//	strcpy(_char_array, _file.c_str());
	ifstream _ifs(_file);
	string _content((istreambuf_iterator<char>(_ifs)),
			(istreambuf_iterator<char>()));
	return _content;
}
bool preg_match(string _pattern, string _subject) {
	//echo(substr(_subject, 1, _subject.size() - 2));
	return regex_search(_subject,
			regex(substr(_pattern, 1, _pattern.size() - 2)));
}
long max(long _1, long _2, long _3, long _4, long _5) {
	return max(max(max(_1, _2), max(_3, _4)), _5);
}
arr_ll array_top(arr_ll _arr, long _count) {
	arr_ll _arr1 = _arr;
	arr_ll _res;
	if ((long) _arr.size() <= _count)
		return _arr;
	for (long _i = 0; _i < _count; _i++) {
		long _tmp_key = 0;
		long _tmp_value = -2147483648;
		for (auto const& [_k, _v] : _arr1) {
			if (_v >= _tmp_value) {
				_tmp_key = _k;
				_tmp_value = _v;
			}
		}
		_res[_tmp_key] = _tmp_value;
		_arr1.erase(_tmp_key);

	}
	return _res;
}
arr_ld array_top(arr_ld _arr, long _count) {
	arr_ld _arr1 = _arr;
	arr_ld _res;
	if ((long) _arr.size() <= _count)
		return _arr;
	for (long _i = 0; _i < _count; _i++) {
		long _tmp_key = 0;
		double _tmp_value = -8888.88;
		for (auto const& [_k, _v] : _arr1) {
			if (_v > _tmp_value) {
				_tmp_key = _k;
				_tmp_value = _v;
			}
		}
		_res[_tmp_key] = _tmp_value;
		_arr1.erase(_tmp_key);

	}
	return _res;
}
arr_ll array_tail(arr_ll _arr, long _count) {
	arr_ll _arr1 = _arr;
	arr_ll _res;
	for (long _i = 0; _i < _count; _i++) {
		for (auto const& [_k, _v] : _arr1) {
			long _tmp_key = 0;
			long _tmp_value = 2147483647;
			if (_v <= _tmp_value) {
				_tmp_key = _k;
				_tmp_value = _v;
			}
			_res.insert(pair<long, long>(_tmp_key, _tmp_value));
			_arr1.erase(_tmp_key);
		}
	}
	return _res;
}
arr_ld array_tail(arr_ld _arr, long _count) {
	arr_ld _arr1 = _arr;
	arr_ld _res;
	for (long _i = 0; _i < _count; _i++) {
		for (auto const& [_k, _v] : _arr1) {
			long _tmp_key = 0;
			double _tmp_value = 88888.88;
			if (_v <= _tmp_value) {
				_tmp_key = _k;
				_tmp_value = _v;
			}
			_res.insert(pair<long, double>(_tmp_key, _tmp_value));
			_arr1.erase(_tmp_key);
		}
	}
	return _res;
}
arr_lll array_chunk(arr_ll _arr, long _num) {
	arr_lll _res;
	long _i = 0;
	for (auto const& [_k, _v] : _arr) {
		_res[_i / _num][_i % _num] = _v;
		_i++;
	}
	return _res;
}
arr_ll array_unique(arr_ll _arr) {
	arr_ll _res;
	for (auto const& [_k, _v] : _arr) {
		if (!in_array(_v, _res))
			array_push(_res, _v);
	};
	return _res;
}
arr_ls array_unique(arr_ls _arr) {
	arr_ls _res;
	for (auto const& [_k, _v] : _arr) {
		if (!in_array(_v, _res))
			array_push(_res, _v);
	};
	return _res;
}
arr_ls array_unique(arr_ss _arr) {
	arr_ls _res;
	for (auto const& [_k, _v] : _arr) {
		if (!in_array(_v, _res))
			array_push(_res, _v);
	};
	return _res;
}
string readline(string _message = "") {
	echo(_message);
	string _to;
	cin >> _to;
	return _to;
}
void signal_handler(int _signal_num) {
	cout << "Signal (" << _signal_num << ").\n";
	// end;
	throw _signal_num;
	//terminate();
}
#endif /* SRC_CORE_PHP2CPP_H_ */
