/*
 * mp.h
 *
 *  Created on: Jun 2, 2021
 *      Author: qu
 */

#ifndef MP_H_
#define MP_H_
#include <map>
#include <shared_mutex>
using namespace std;

//long lo = 0;
//long lc = 0;
template<class T>
class mp {
private:
	map<long, T> _map;
	shared_mutex _nock;
public:
	mp(map<long, T> _map1) {
		this->_map = _map1;
	}
	mp() {
	}
	mp(const mp &_old) {
		_map = _old._map;
	}
	virtual ~mp() {
	}
	map<long, T> get_map() {
		//map<long, T> _return = this->_map;
		shared_lock<shared_mutex> _l(_nock);
		return this->_map;
	}
	void set_map(map<long, T> _arr) {
		unique_lock<shared_mutex> _l(_nock);
		this->_map = _arr;
	}
	//override cast
	operator map<long, T>() const {
//		if(is_same<T, mp>){
//			;
//		}
		return _map;
	}
	long size() {
		return _map.size();
	}
	bool empty() {
		return _map.empty();
	}
	bool contains(long _find) {
		shared_lock<shared_mutex> _l(_nock);
		return _map.contains(_find);
	}
	long last_key() {
		shared_lock<shared_mutex> _l(_nock);
		long _return = -1;
		if (!_map.empty())
			_return = _map.rbegin()->first;
		return _return;
	}
	long first_key() {
		shared_lock<shared_mutex> _l(_nock);
		long _return = -1;
		if (!_map.empty())
			_return = _map.begin()->first;
		return _return;
	}
	void clear() {
		unique_lock<shared_mutex> _l(_nock);
		this->_map.clear();
	}
//	bool operator=(const map<long, T> &x) {
//		this->_map = x;
//		return true;
//	}
//	bool operator=(const mp<T> &x) {
//		this->_map = x.get_map();
//		return true;
//	}

	void re_assoc() {
		unique_lock<shared_mutex> _l(_nock);
		this->_map = array_values(this->_map);
	}
	bool erase(long _k) {
		unique_lock<shared_mutex> _l(_nock);
		if (_map.contains(_k)) {
			_map.erase(_k);
			return true;
		}
		return false;
	}
	T& operator[](const long &_key) {
		unique_lock<shared_mutex> _l(_nock);
		T &_return = _map[_key];
		return _return;
	}
//	T& operator()(const long &_key) {
//		_nock.trylock();
//		return _map.at(_key);
//		_nock.unlock();
//	}
	T at(const long &_key) {
		shared_lock<shared_mutex> _l(_nock);
		if (_map.contains(_key))
			return _map.at(_key);
		else
			throw 42;
	}
	long push(const T &_element) {
		unique_lock<shared_mutex> _l(_nock);
		long _k = 0;
		if (!this->_map.empty())
			_k = this->_map.rbegin()->first + 1;
		_map[_k] = _element;
		return _k;
	}
};

#endif /* MP_H_ */
