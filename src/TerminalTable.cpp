/*
 * TerminalTable.cpp
 *
 *  Created on: Jul 29, 2018
 *      Author: Erfan
 */

#include "TerminalTable.h"
#include <stddef.h>  // defines NULL
#include <iostream>

// Global static pointer used to ensure a single instance of the class.
TerminalTable* TerminalTable::m_instance = 0;

TerminalTable* TerminalTable::Instance() {
	if(!m_instance)
		m_instance = new TerminalTable();
	return m_instance;
}

void TerminalTable::free() {
	delete m_instance;
	m_instance = nullptr;
}

bool TerminalTable::isKeyword(string keyword) {
	TerminalTable::Terminal* terminal = find(keyword);
	if(terminal != NULL && std::get<0>(*terminal).compare(keyword) == 0)
		return true;
	return false;
}

bool TerminalTable::isSupported(string keyword) {
	TerminalTable::Terminal* terminal = find(keyword);
	if(terminal != NULL && std::get<1>(*terminal))
		return true;
	return false;
}

/*
 * TerminalTable::find
 * binary search keyword array to find a match
 */
TerminalTable::Terminal* TerminalTable::find(string keyword) {
	int begin = 0, middle, end = size-1;
	while(begin <= end) {
		middle = (begin+end)/2;
		string TerminalValue = std::get<0>(c_keywords[middle]);
		if(keyword.compare(TerminalValue) < 0) {
			end = middle - 1;
		}
		else if (keyword.compare(TerminalValue) > 0) {
			begin = middle + 1;
		}
		else {
			return &(c_keywords[middle]);
		}
	}
	return nullptr;
}

/* Checks if the c_keywords array is in lexicographic order
 * ONLY USED BY UNIT TEST
 * */
bool TerminalTable::isInOrder() {
	for(int i = 0; i < size-1; i++) {
		if(std::get<0>(c_keywords[i]).compare(std::get<0>(c_keywords[i+1])) >= 0) {
			return false;
		}
	}
	return true;
}

/* This keyword lookup table must be a ordered list.
 * find() method which binary search keyword list assume
 * the table is in order
 */
TerminalTable::Terminal TerminalTable::c_keywords[] = {
		make_tuple("_Bool",0),
		make_tuple("_Complex",0),
		make_tuple("_Imaginary",0),
		make_tuple("auto",0),
		make_tuple("break",0),
		make_tuple("case",0),
		make_tuple("char",0),
		make_tuple("const",0),
		make_tuple("continue",0),
		make_tuple("default",0),
		make_tuple("do",0),
		make_tuple("double",0),
		make_tuple("else",0),
		make_tuple("enum",0),
		make_tuple("extern",0),
		make_tuple("float",0),
		make_tuple("for",0),
		make_tuple("goto",0),
		make_tuple("if",0),
		make_tuple("inline",0),
		make_tuple("int",0),
		make_tuple("long",0),
		make_tuple("register",0),
		make_tuple("restrict",0),
		make_tuple("return",0),
		make_tuple("short",0),
		make_tuple("signed",0),
		make_tuple("sizeof",0),
		make_tuple("static",0),
		make_tuple("struct",0),
		make_tuple("switch",0),
		make_tuple("typedef",0),
		make_tuple("union",0),
		make_tuple("unsigned",0),
		make_tuple("void",0),
		make_tuple("volatile",0),
		make_tuple("while",0),

};
