%{
	#include <iostream>
	#include <FlexLexer.h>
	using namespace std;
	
	extern "C" int yylex();
	extern "C" void yyerror(char *s);
%}

%token INT

%% 

int : INT;

%% 

int main() {
	yyFlexLexer yylexer;
	yylexer.yylex();
}

