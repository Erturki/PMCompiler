YACC_SRC = $(SRC_DIR)/yacc/parser.yy
YACC_PREFIX = yacc
YACC_HEADER = $(YACC_PREFIX).hpp

#### Bison Build Options ####
# -d build definition files
# -o specify output file
############################
YACC = bison 

parser: $(YACC_SRC)
	$(YACC) -o$(SRC_DIR)/$(YACC_PREFIX).cpp -d $<
	-@mv $(SRC_DIR)/$(YACC_HEADER) $(INCLUDE_DIR)
	-@mv $(SRC_DIR)/*.hh $(INCLUDE_DIR)
	
clean::
	rm -f $(SRC_DIR)/$(YACC_PREFIX).*
	rm -f $(INCLUDE_DIR)/$(YACC_PREFIX).* 
	rm -f $(INCLUDE_DIR)/*.hh
