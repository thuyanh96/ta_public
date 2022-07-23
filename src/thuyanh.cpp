//============================================================================
// Name        : thuyanh.cpp
// Author      : Ngan Nguyen
// Version     :
// Copyright   : GNU
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//#include <map>
//#include <stdlib.h>
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include <php2cpp.h>
//#include <connect.h>
double _dbt = 0.0;
#include <core/one_cycle.h>

using namespace std;

int main() {
	int _j = 0;
	clause _c;
	_c._0 = "29@4234@149@134508@134509@134510@134502@150";
	_c._1 = 1;
	_c._2 = 1;
	_c._3 = time_php();
	_core.set_map(( arr_lc ) { { 0, _c } });
	//pre_exec();
	prepare();
	for (long _i = 0; _i < 20000; _i++) {
		_j++;
		one_cycle();
	}
//	;;
//	_corer_find.set_map((arr_lc ) { { 0, { ._0 = "x1@2@3", ._1 = 1, ._2 = 1,
//					._3 = 8888888888 } } });
//	_rules.set_map((arr_lc ) { { 0, { ._0 = "$1@4@5@c@$1@2@3", ._1 = 1, ._2 = 1,
//					._3 = 8888888888 } } });
//	_core_l.set_map((arr_lc ) { { 0, { ._0 = "l@54@1@2@3", ._1 = 1, ._2 = 1,
//					._3 = 0 } } });
//	_prove_num = "54";
//	substringC _ttt = { ._0 = { { 0, "1@4@5" } }, ._1 = "1@2@3" };
//	_r_logic.set_map((arr_lC ) { { 0,
//					{ ._0 = { { 0, "1@4@5" } }, ._1 = "1@2@3" } } });
//	_cache.set_map((arr_lc ) { { 0,
//					{ ._0 = "222@4@5", ._1 = 1, ._2 = 1, ._3 = 0 } } });
//	_next_core_key = 1;
//	_next_corer_find_key = 1;
//	simple_find_x();
//	echo(1);
//

}
