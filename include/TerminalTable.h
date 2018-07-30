/*
 * TerminalTable.h
 *
 *  Created on: Jul 29, 2018
 *      Author: Erfan
 */

#ifndef TERMINALTABLE_H_
#define TERMINALTABLE_H_

#include <string>
#include <tuple>
using namespace std;

class TerminalTable {

	typedef tuple<string,bool> Terminal;

public:
	static TerminalTable* Instance();
	bool isKeyword(string keyword);
	bool isSupported(string keyword);

private:
	TerminalTable() {};
	TerminalTable(TerminalTable const&) {};
	TerminalTable& operator=(TerminalTable const&) {};
	virtual ~TerminalTable() {};
	Terminal* find(string keyword);
	static TerminalTable* m_instance;
	static TerminalTable::Terminal c_keywords[];
	const int size = 36; //size of c_keywords array. must update
};

#endif /* TERMINALTABLE_H_ */
