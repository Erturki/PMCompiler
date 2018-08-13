GOOGLE_INCLUDE = $(BASE_DIR)/googletest/include
GOOGLE_LIB = $(BASE_DIR)/googletest/make/libgtest.a
TEST_DIR = $(BASE_DIR)/tst

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(LIB_DIR)/%.o,$(TEST_FILES))

Test_PMCompiler.exe: $(TEST_OBJ_FILES) $(filter-out $(LIB_DIR)/PMCompiler.o, $(OBJ_FILES))
	g++ -o $@ $^ -L. $(GOOGLE_LIB)

$(LIB_DIR)/%.o: $(TEST_DIR)/%.cpp
	g++ -c -o $@ $< -I $(GOOGLE_INCLUDE) -I $(INCLUDE_DIR)

test:
	./Test_PMCompiler.exe 2>/dev/null
	
clean::
	rm -f $(TEST_OBJ_FILES)
	rm -f PMCompiler_Test.exe
