/*
 * SymbolTableEntry.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: AiTG145
 */
#include "SymbolTableEntry.h"

SymbolTableEntry::SymbolTableEntry() {
	m_symbolType = static_cast<SymbolType>(0);
	m_storageClass = static_cast<StorageClass>(0);
	m_typeSpecifier = static_cast<TypeSpecifier>(0);
	m_typeQualifier = static_cast<TypeQualifier>(0);
	m_name.clear();
}

SymbolTableEntry::SymbolTableEntry(const SymbolTableEntry& symbolTableEntry) {
	this->m_name = symbolTableEntry.m_name;
	this->m_storageClass = symbolTableEntry.m_storageClass;
	this->m_symbolType = symbolTableEntry.m_symbolType;
	this->m_typeQualifier = symbolTableEntry.m_typeQualifier;
	this->m_typeSpecifier = symbolTableEntry.m_typeSpecifier;
}

SymbolTableEntry::~SymbolTableEntry() {
}

SymbolTableEntry& SymbolTableEntry::withSymbolType(SymbolType symbolType) {
	m_symbolType = symbolType;
	return *this;
}

SymbolTableEntry& SymbolTableEntry::withStorageClass(StorageClass storageClass) {
	m_storageClass = storageClass;
	return *this;
}

SymbolTableEntry& SymbolTableEntry::withTypeSpecifier(TypeSpecifier typeSpecifier) {
	m_typeSpecifier = typeSpecifier;
	return *this;
}

SymbolTableEntry& SymbolTableEntry::withTypeQualifier(TypeQualifier typeQualifier) {
	m_typeQualifier = typeQualifier;
	return *this;
}

SymbolTableEntry& SymbolTableEntry::withName(string name) {
	m_name = name;
	return *this;
}

SymbolType SymbolTableEntry::getSymbolType() {
	return this->m_symbolType;
}

StorageClass SymbolTableEntry::getStorageClass() {
	return this->m_storageClass;
}

TypeSpecifier SymbolTableEntry::getTypeSpecifier() {
	return this->m_typeSpecifier;
}

TypeQualifier SymbolTableEntry::getTypeQualifier() {
	return this->m_typeQualifier;
}

string SymbolTableEntry::getName() {
	return this->m_name;
}

ostream& operator<<(ostream& os, const SymbolTableEntry& ste) {
	os << ste.m_typeQualifier << " | " << ste.m_storageClass << " | " << ste.m_typeSpecifier << " | " << ste.m_name << " | " << ste.m_symbolType;
}

















