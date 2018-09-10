/*
 * SymbolTable.h
 *
 *  Created on: Sep 9, 2018
 *      Author: Erfan
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <map>
#include <string>
#include <iostream>
#include "SymbolTableEntry.h"
using namespace std;

class SymbolTable {
public:
	SymbolTable();
	SymbolTable(SymbolTable& ancestor);
	virtual ~SymbolTable();
	void insert(SymbolTableEntry symbolTableEntry);
	SymbolTableEntry* search(string key);

	SymbolTable* getAncestor();
	string getScope();

	void printTable();

private:
	map<string,SymbolTableEntry*> m_symbolTable;
	string m_scope;
	SymbolTable* m_ancestor;
};

#endif /* SYMBOLTABLE_H_ */
