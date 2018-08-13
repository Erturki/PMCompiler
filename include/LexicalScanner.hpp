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
		LexicalScanner() : yyFlexLexer() { set_debug(false); }
		using FlexLexer::yylex;
		virtual int yylex(parser::semantic_type* const lval, parser::location_type* loc);

	private:
		parser::semantic_type* yylval = nullptr;
		parser::location_type* location = nullptr;
};
}

#endif /* SCANNER_HPP_ */
