YACC_SRC_FILE = $(SRC_DIR)/yacc/parser.yy
YACC_OUT_FILE_PREFIX = yacc.tab
YACC_HEADER = $(YACC_OUT_FILE_PREFIX).hh

#### Bison Build Options ####
# -d build definition files
# -o specify output file
############################
YACC = bison 

parser: $(YACC_SRC_FILE)
	$(YACC) -o$(SRC_DIR)/$(YACC_OUT_FILE_PREFIX).cc -d $<
	-@mv $(SRC_DIR)/$(YACC_HEADER) $(INCLUDE_DIR)/$(YACC_HEADER)
	
clean::
	rm -f $(SRC_DIR)/$(YACC_OUT_FILE_PREFIX).*
