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
//#include "LexicalScanner.hpp"
#include <FlexLexer.h>
using namespace std;

int main(int argc, char **argv) {
	cout << "Hello World" << endl; // prints Hello World
	LiteralTable *literalTable = LiteralTable::Instance();
	FlexLexer* yylex = new yyFlexLexer;
	yylex->set_debug(true);
	while(yylex->yylex() != 0) {
		cout << yylex->YYText() << endl;
	}
	/*yy::LexicalScanner* yylex = new yy::LexicalScanner;
	yy::parser* parser = new yy::parser;
	parser->parse();

	std::ofstream os("flex.dbg");
	std::streambuf *cerrbuf = std::cerr.rdbuf();
	std::cerr.rdbuf(os.rdbuf());


	while(yylex->yylex() != 0) {
		cout << yylex->YYText() << endl;
	}

	std::cerr.rdbuf(cerrbuf);
	 */
	literalTable->printTable();

	return 0;
}
