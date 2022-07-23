/*
 * mp.h
 *
 *  Created on: Jun 2, 2021
 *      Author: qu
 */

#ifndef MPS_H_
#define MPS_H_
#include <map>
#include <mutex>
using namespace std;

template<class K, class T>
class mps {
private:
	map<K, T> _map;
	shared_mutex _nock;
public:
	mps(map<K, T> _map1) {
		this->_map = _map1;
	}
	mps() {
	}
	mps(const mps &_old) {
		_map = _old._map;
	}
	virtual ~mps() {
	}
	map<K, T> get_map() {
		shared_lock<shared_mutex> _l(_nock);
		map<K, T> _return = this->_map;
		return _return;
	}
	void set_map(map<K, T> _arr) {
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
	bool contains(K _find) {
		shared_lock<shared_mutex> _l(_nock);
		return _map.contains(_find);
	}
	K last_key() {
		K _return = NULL;
		shared_lock<shared_mutex> _l(_nock);
		if (!_map.empty())
			_return = _map.rbegin()->first;
		return _return;
	}
	K first_key() {
		long _return = NULL;
		shared_lock<shared_mutex> _l(_nock);
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

//	void re_assoc() {
//		this->_map = array_values(this->_map);
//	}
	bool erase(K _k) {
		unique_lock<shared_mutex> _l(_nock);
		if (_map.contains(_k)) {
			_map.erase(_k);
			return true;
		}
		return false;
	}
	T& operator[](const K &_key) {
		unique_lock<shared_mutex> _l(_nock);
		T &_return = _map[_key];
		return _return;
	}
//	T& operator()(const long &_key) {
//		_nock.trylock();
//		return _map.at(_key);
//		_nock.unlock();
//	}
	T at(const K &_key) {
		return _map.at(_key);
	}
//	K push(const T &_element) {
//		lock_guard<mutex> _l(_nock);
//		K _k();
//		if (!this->_map.empty())
//			_k = this->_map.rbegin()->first + 1;
//		_map[_k] = _element;
//		return _k;
//	}
};

#endif /* MP_H_ */
