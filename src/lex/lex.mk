LEX_SRC_FILE = $(SRC_DIR)/lex/lexer.l
LEX_OUT_FILE = lex.yy.c

#### Flex Build Options ####
# -d debug mode
# -w supress warning
# -+ generate C++ scanner
############################
LEX = flex
LEX_FLAGS = -d -+

ifeq (-+,$(findstring -+,$(LEX_FLAGS)))
	LEX_OUT_FILE = $(subst c,cc,lex.yy.c)	
endif

lexer: $(LEX_SRC_FILE) $(INCLUDE_DIR)/$(YACC_HEADER)
	$(LEX) $(LEX_FLAGS) -o$(SRC_DIR)/$(LEX_OUT_FILE) $<
		
clean:: 
	rm -f $(SRC_DIR)/lex.yy.*