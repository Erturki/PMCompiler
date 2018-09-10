/*
 * SymbolTable.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: AiTG145
 */

#include "SymbolTable.h"
#include <algorithm>
#include <iostream>
#include <stdlib.h>

SymbolTable::SymbolTable() {
	static string alphanum =
			"01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(alphanum.begin(),alphanum.end());
	m_scope = alphanum;
	m_ancestor = NULL;
}

SymbolTable::SymbolTable(SymbolTable& ancestor) : SymbolTable() {
	m_ancestor = &ancestor;
}

SymbolTable::~SymbolTable() {
	delete m_ancestor;
	m_ancestor = NULL;
	map<string,SymbolTableEntry*>::iterator it;
	for(it=m_symbolTable.begin();it!=m_symbolTable.end();it++) {
		SymbolTableEntry* ste = it->second;
		delete ste;
		ste = NULL;
	}
}

void SymbolTable::insert(SymbolTableEntry symbolTableEntry) {
	string key = symbolTableEntry.getName();
	SymbolTableEntry* foundSymbol = search(key);
	if (foundSymbol == NULL) {
		m_symbolTable[key] = new SymbolTableEntry(symbolTableEntry);
	} else {
		std::cerr << "Duplicate insertion of " << key << " into the symbol table." << std::endl;
		exit(1);
	}
}

SymbolTableEntry* SymbolTable::search(string key) {
	map<string,SymbolTableEntry*>::iterator it;
	it = m_symbolTable.find(key);
	if (it == m_symbolTable.end()) {
		return NULL;
	}
	return it->second;
}

SymbolTable* SymbolTable::getAncestor() {
	return m_ancestor;
}

string SymbolTable::getScope() {
	return m_scope;
}

void SymbolTable::printTable() {
	map<string,SymbolTableEntry*>::iterator it;
	std::cout << "Printing symbol table with scope: " << this->m_scope << std::endl;
	std::cout << "TypeQualifier | StorageClass | TypeSpecifier | Name | SymbolType" << std::endl;
	for(it = m_symbolTable.begin(); it != m_symbolTable.end(); it++) {
		std::cout << *(it->second) << std::endl;
	}
}











