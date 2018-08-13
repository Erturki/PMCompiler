/*
 * LiteralTable.cpp
 *
 *  Created on: Jul 30, 2018
 *      Author: Erfan
 */

#include "LiteralTable.h"
#include <iostream>
#include <stdexcept>

// Global static pointer used to ensure a single instance of the class.
LiteralTable* LiteralTable::m_instance = 0;

LiteralTable* LiteralTable::Instance() {
	if(!m_instance)
		m_instance = new LiteralTable();
	return m_instance;
}

void LiteralTable::free() {
	delete m_instance;
	m_instance = nullptr;
}

int LiteralTable::put(LITERAL_TYPE type, string value) {
	static int index = 0;
	m_table.push_back(std::make_tuple(index,type,value));
	return index++;
}

string LiteralTable::get(int index) {
	string value;
	try {
		value = std::get<2>(m_table.at(index));
	} catch (const std::out_of_range& e) {
		cerr << "LiteralTable::get() Out of Range Access: " << e.what() << endl;
		exit(1);
	}
	return value;
}


LITERAL_TYPE LiteralTable::getType(int index) {
	LITERAL_TYPE type;
		try {
			type = std::get<1>(m_table.at(index));
		} catch (const std::out_of_range& e) {
			cerr << "LiteralTable::getType() Out of Range Access: " << e.what() << endl;
			exit(1);
		}
		return type;
}

void LiteralTable::printTable() {
	std::cout << "Printing Literal Table" << endl;
	for(vector<Literal>::iterator it = m_table.begin(); it != m_table.end(); it++) {
		std::cout << std::get<0>(*it) << "\t" << std::get<1>(*it) << "\t" << std::get<2>(*it) << endl;
	}
}

