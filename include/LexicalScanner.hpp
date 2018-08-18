#ifndef __LEXICAL_SCANNER_HPP__
#define __LEXICAL_SCANNER_HPP__

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "yacc.hpp"
#include "location.hh"

namespace yy{

class LexicalScanner : public yyFlexLexer {
	public:
		LexicalScanner(std::istream* arg_yyin = 0,
									 std::ostream* arg_yyout = 0 ) : yyFlexLexer(arg_yyin,arg_yyout) { set_debug(true); }
		using yyFlexLexer::yylex;
		virtual int yylex(yy::parser::semantic_type * const lval,
											yy::parser::location_type * loc );


	private:
		yy::parser::semantic_type* yylval = nullptr;
		yy::parser::location_type* location = nullptr;
};
}

#endif /* SCANNER_HPP_ */
