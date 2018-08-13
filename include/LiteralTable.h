/*
 * LiteralTable.h
 *
 *  Created on: Jul 30, 2018
 *      Author: Erfan
 */

#ifndef LITERALTABLE_H_
#define LITERALTABLE_H_

#include <vector>
#include <tuple>
#include <string>
#include "Types.h"
using namespace std;

class LiteralTable {

	typedef tuple<int,LITERAL_TYPE,string> Literal;

public:
		static LiteralTable* Instance();
		void free();
		int put(LITERAL_TYPE type, string value);
		string get(int index);
		LITERAL_TYPE getType(int index);

		void printTable();

private:
	LiteralTable() {};
	virtual ~LiteralTable() {};
	LiteralTable(LiteralTable const&) {};
	LiteralTable& operator=(LiteralTable const&) {};
	static LiteralTable* m_instance;
	vector<Literal> m_table;

};

#endif /* LITERALTABLE_H_ */
