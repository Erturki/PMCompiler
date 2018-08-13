%{
	#include <string>
	#include "yacc.hpp"
	#include "LiteralTable.h"
	/*
	#undef YY_DECL
	#define YY_DECL int yy::LexicalScanner::yylex(yy::parser::semantic_type* const lval, yy::parser::location_type* loc)
	#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
	#define yyterminate() return yy::parser::token::END
	%option yyclass = "yy:LexicalScanner"
	*/
	LiteralTable* literalTable = LiteralTable::Instance();
%}

/* Specify options to configure the Flex generated scanner */
%option nomain noyywrap
%option 8bit c++ 
%option yylineno
%pointer

D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
E   ([Ee][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
WS  [ \t\v\n\f\r]

%%

%{
						//yylval = lval;
%}

"/*"                  	{   /* consume C style /*-comment */   
							int c;
							while((c = yyinput()) != 0) {
								if(c == '*') {
									if((c = yyinput()) == '/')
										break;
									else
										unput(c);
								}
							}
						}
"//"[^\n]*              { /* consume //-comment */ }

"auto"					{ return(yy::parser::token::AUTO); }
"break"					{ return(yy::parser::token::BREAK); }
"case"					{ return(yy::parser::token::CASE); }
"char"					{ return(yy::parser::token::CHAR); }
"const"					{ return(yy::parser::token::CONST); }
"continue"				{ return(yy::parser::token::CONTINUE); }
"default"				{ return(yy::parser::token::DEFAULT); }
"do"					{ return(yy::parser::token::DO); }
"double"				{ return(yy::parser::token::DOUBLE); }
"else"					{ return(yy::parser::token::ELSE); }
"enum"					{ return(yy::parser::token::ENUM); }
"extern"				{ return(yy::parser::token::EXTERN); }
"float"					{ return(yy::parser::token::FLOAT); }
"for"					{ return(yy::parser::token::FOR); }
"goto"					{ return(yy::parser::token::GOTO); }
"if"					{ return(yy::parser::token::IF); }
"int"					{ return(yy::parser::token::INT); }
"long"					{ return(yy::parser::token::LONG); }
"register"				{ return(yy::parser::token::REGISTER); }
"return"				{ return(yy::parser::token::RETURN); }
"short"					{ return(yy::parser::token::SHORT); }
"signed"				{ return(yy::parser::token::SIGNED); }
"sizeof"				{ return(yy::parser::token::SIZEOF); }
"static"				{ return(yy::parser::token::STATIC); }
"struct"				{ return(yy::parser::token::STRUCT); }
"switch"				{ return(yy::parser::token::SWITCH); }
"typedef"				{ return(yy::parser::token::TYPEDEF); }
"union"					{ return(yy::parser::token::UNION); }
"unsigned"				{ return(yy::parser::token::UNSIGNED); }
"void"					{ return(yy::parser::token::VOID); }
"volatile"				{ return(yy::parser::token::VOLATILE); }
"while"					{ return(yy::parser::token::WHILE); }

"inline"				{ return(yy::parser::token::INLINE); }
"restrict"				{ return(yy::parser::token::RESTRICT); }
"_Bool"                 { return(yy::parser::token::BOOL); }
"_Complex"              { return(yy::parser::token::COMPLEX); }
"_Imaginary"            { return(yy::parser::token::IMAGINARY); }

{L}{A}*						{ 
								/* create a symbol
								 * make an entry in symbol table
								 * /
								return(yy::parser::token::IDENTIFIER); 
							}
							
{NZ}{D}*{IS}?				{ 
								literalTable->put(INT_LITERAL, YYText()); 
								return(yy::parser::token::I_CONSTANT); 
							}

{D}+{E}{FS}?				{ 
								literalTable->put(FLOAT_LITERAL, YYText()); 
								return(yy::parser::token::F_CONSTANT); 
							}
{D}*"."{D}+{E}?{FS}?		{ 
								literalTable->put(FLOAT_LITERAL, YYText()); 
								return(yy::parser::token::F_CONSTANT); 
							}
{D}+"."{E}?{FS}?			{ 
								literalTable->put(FLOAT_LITERAL, YYText()); 
								return(yy::parser::token::F_CONSTANT); 
							}
L?'(\\.|]^\\'\n])+'			{ 
								literalTable->put(CHAR_LITERAL, YYText()); 
								return(yy::parser::token::I_CONSTANT); 
							}
L?\"(\\.|[^\\"\n)*\"		{
								literalTable->put(CHAR_LITERAL, YYText());
								return(yy::parser::token::STRING_LITERAL);
							}

"..."					{ return(yy::parser::token::ELLIPSIS); }
">>="					{ return(yy::parser::token::RIGHT_ASSIGN); }
"<<="					{ return(yy::parser::token::LEFT_ASSIGN); }
"+="					{ return(yy::parser::token::ADD_ASSIGN); }
"-="					{ return(yy::parser::token::SUB_ASSIGN); }
"*="					{ return(yy::parser::token::MUL_ASSIGN); }
"/="					{ return(yy::parser::token::DIV_ASSIGN); }
"%="					{ return(yy::parser::token::MOD_ASSIGN); }
"&="					{ return(yy::parser::token::AND_ASSIGN); }
"^="					{ return(yy::parser::token::XOR_ASSIGN); }
"|="					{ return(yy::parser::token::OR_ASSIGN); }
">>"					{ return(yy::parser::token::RIGHT_OP); }
"<<"					{ return(yy::parser::token::LEFT_OP); }
"++"					{ return(yy::parser::token::INC_OP); }
"--"					{ return(yy::parser::token::DEC_OP); }
"->"					{ return(yy::parser::token::PTR_OP); }
"&&"					{ return(yy::parser::token::AND_OP); }
"||"					{ return(yy::parser::token::OR_OP); }
"<="					{ return(yy::parser::token::LE_OP); }
">="					{ return(yy::parser::token::GE_OP); }
"=="					{ return(yy::parser::token::EQ_OP); }
"!="					{ return(yy::parser::token::NE_OP); }
";"					{ return ';'; }
("{"|"<%")				{ return '{'; }
("}"|"%>")				{ return '}'; }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."					{ return '.'; }
"&"					{ return '&'; }
"!"					{ return '!'; }
"~"					{ return '~'; }
"-"					{ return '-'; }
"+"					{ return '+'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"<"					{ return '<'; }
">"					{ return '>'; }
"^"					{ return '^'; }
"|"					{ return '|'; }
"?"					{ return '?'; }

{WS}+				{ /* whitespace separates tokens */ }
.					{ /* warn and abort bad characters */
						 std::cout << "Error: unrecognized character \"" << YYText()
						 		   << "\" at line: " << lineno() << endl;
						 //exit(1);
					}

%%