/*
 * SymbolTableEntry.h
 *
 *  Created on: Sep 9, 2018
 *      Author: Erfan
 */

#ifndef SYMBOLTABLEENTRY_H_
#define SYMBOLTABLEENTRY_H_

#include "Types.h"
#include <string>
#include <iostream>
using namespace std;

class SymbolTableEntry {
public:
	SymbolTableEntry();
	SymbolTableEntry(const SymbolTableEntry& symbolTableEntry);
	virtual ~SymbolTableEntry();

	//incremental building setters
	SymbolTableEntry& withSymbolType(SymbolType symbolType);
	SymbolTableEntry& withStorageClass(StorageClass storageClass);
	SymbolTableEntry& withTypeSpecifier(TypeSpecifier typeSpecifier);
	SymbolTableEntry& withTypeQualifier(TypeQualifier typeQualifier);
	SymbolTableEntry& withName(string name);

	//getters
	SymbolType getSymbolType();
	StorageClass getStorageClass();
	TypeSpecifier getTypeSpecifier();
	TypeQualifier getTypeQualifier();
	string getName();

	friend ostream& operator<<(ostream& os, const SymbolTableEntry& ste);

private:
	SymbolType m_symbolType;
	StorageClass m_storageClass;
	TypeSpecifier m_typeSpecifier;
	TypeQualifier m_typeQualifier;
	string m_name;
};

#endif /* SYMBOLTABLEENTRY_H_ */
