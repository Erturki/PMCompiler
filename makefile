BASE_DIR = .
SRC_DIR = $(BASE_DIR)/src
LIB_DIR = $(BASE_DIR)/lib
INCLUDE_DIR = $(BASE_DIR)/include

all: TerminalTable.o


include ./src/yacc/yacc.mk
include ./src/lex/lex.mk


TerminalTable.o: $(SRC_DIR)/TerminalTable.cpp
	g++ -c $^ -I $(INCLUDE_DIR)
	mv TerminalTable.o $(LIB_DIR)/TerminalTable.o

scanner:
	g++ -c src/lex.yy.cc src/PMCompiler.cpp -I$(INCLUDE_DIR) -L $(LIB_DIR)
	g++ lex.yy.o PMCompiler.o -o $@ -lfl

clean::
	rm -f $(OBJS)
	rm -f scanner.exe
	rm -f *.o *~

