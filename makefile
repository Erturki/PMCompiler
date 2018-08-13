BASE_DIR = .
SRC_DIR = $(BASE_DIR)/src
LIB_DIR = $(BASE_DIR)/lib
INCLUDE_DIR = $(BASE_DIR)/include

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
SRC_FILES += $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(LIB_DIR)/%.o,$(SRC_FILES))


CXXFLAGS += -MMD

all:  lexer PMCompiler.exe Test_PMCompiler.exe
	
include ./src/yacc/yacc.mk
include ./src/lex/lex.mk
include ./tst/test.mk

PMCompiler.exe: $(OBJ_FILES) 
	g++ -o $@ $^

$(LIB_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) -std=c++0x -c -o $@ $< -I $(INCLUDE_DIR)
	@echo $(SRC_FILES)
	@echo $(OBJ_FILES)


-include $(OBJ_FILES:.o=.d)

clean::
	rm -f $(OBJ_FILES)
	rm -f PMCompiler.exe
	rm -rf *~	
