//============================================================================
// Name        : PMCompiler.cpp
// Author      : Erfan
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include <fstream>
#include "LiteralTable.h"
#include <FlexLexer.h>
#include "yacc.hpp"
using namespace std;

int main(int argc, char **argv) {
	cout << "Hello World" << endl; // prints Hello World
	LiteralTable *literalTable = LiteralTable::Instance();
	yy::parser* parser = new yy::parser;
	parser->parse();
	literalTable->printTable();

	return 0;
}
