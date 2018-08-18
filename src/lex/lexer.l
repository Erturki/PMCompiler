%{
	#include <string>
	#include "LexicalScanner.hpp"
	#include "LiteralTable.h"
	using token = yy::parser::token;

	#undef YY_DECL
	#define YY_DECL int yy::LexicalScanner::yylex(yy::parser::semantic_type * const lval, yy::parser::location_type * loc )
	#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
	#define yyterminate() return(token::END)
	
	LiteralTable* literalTable = LiteralTable::Instance();
%}

/* Specify options to configure the Flex generated scanner */
%option yyclass="yy::LexicalScanner"
%option nomain noyywrap
%option c++ 
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

"auto"					{ return(token::AUTO); }
"break"					{ return(token::BREAK); }
"case"					{ return(token::CASE); }
"char"					{ return(token::CHAR); }
"const"					{ return(token::CONST); }
"continue"				{ return(token::CONTINUE); }
"default"				{ return(token::DEFAULT); }
"do"					{ return(token::DO); }
"double"				{ return(token::DOUBLE); }
"else"					{ return(token::ELSE); }
"enum"					{ return(token::ENUM); }
"extern"				{ return(token::EXTERN); }
"float"					{ return(token::FLOAT); }
"for"					{ return(token::FOR); }
"goto"					{ return(token::GOTO); }
"if"					{ return(token::IF); }
"int"					{ return(token::INT); }
"long"					{ return(token::LONG); }
"register"				{ return(token::REGISTER); }
"return"				{ return(token::RETURN); }
"short"					{ return(token::SHORT); }
"signed"				{ return(token::SIGNED); }
"sizeof"				{ return(token::SIZEOF); }
"static"				{ return(token::STATIC); }
"struct"				{ return(token::STRUCT); }
"switch"				{ return(token::SWITCH); }
"typedef"				{ return(token::TYPEDEF); }
"union"					{ return(token::UNION); }
"unsigned"				{ return(token::UNSIGNED); }
"void"					{ return(token::VOID); }
"volatile"				{ return(token::VOLATILE); }
"while"					{ return(token::WHILE); }

{L}{A}*						{ 
								return(token::IDENTIFIER); 
							}
							
{NZ}{D}*{IS}?				{ 
								literalTable->put(INT_LITERAL, YYText()); 
								return(token::I_CONSTANT);
							}
L?'(\\.|[^\\'])+'			{
								literalTable->put(CHAR_LITERAL, YYText());
								return(token::I_CONSTANT);
							}
{D}+{E}{FS}?				{ 
								literalTable->put(FLOAT_LITERAL, YYText()); 
								return(token::F_CONSTANT); 
							}
{D}*"."{D}+{E}?{FS}?		{ 
								literalTable->put(FLOAT_LITERAL, YYText()); 
								return(token::F_CONSTANT); 
							}
{D}+"."{D}*{E}?{FS}?		{ 
								literalTable->put(FLOAT_LITERAL, YYText()); 
								return(token::F_CONSTANT); 
							}
L?\"(\\.|[^\\"])*\"			{
								literalTable->put(CHAR_LITERAL, YYText());
								return(token::STRING_LITERAL);
							}

"..."					{ return(token::ELLIPSIS); }
">>="					{ return(token::RIGHT_ASSIGN); }
"<<="					{ return(token::LEFT_ASSIGN); }
"+="					{ return(token::ADD_ASSIGN); }
"-="					{ return(token::SUB_ASSIGN); }
"*="					{ return(token::MUL_ASSIGN); }
"/="					{ return(token::DIV_ASSIGN); }
"%="					{ return(token::MOD_ASSIGN); }
"&="					{ return(token::AND_ASSIGN); }
"^="					{ return(token::XOR_ASSIGN); }
"|="					{ return(token::OR_ASSIGN); }
">>"					{ return(token::RIGHT_OP); }
"<<"					{ return(token::LEFT_OP); }
"++"					{ return(token::INC_OP); }
"--"					{ return(token::DEC_OP); }
"->"					{ return(token::PTR_OP); }
"&&"					{ return(token::AND_OP); }
"||"					{ return(token::OR_OP); }
"<="					{ return(token::LE_OP); }
">="					{ return(token::GE_OP); }
"=="					{ return(token::EQ_OP); }
"!="					{ return(token::NE_OP); }
";"					{ return ';'; }
("{"|"<%")			{ return '{'; }
("}"|"%>")			{ return '}'; }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
("["|"<:")			{ return '['; }
("]"|":>")			{ return ']'; }
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
						 exit(1);
					}

%%