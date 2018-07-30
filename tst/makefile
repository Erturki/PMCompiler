INCLUDE_DIR = ../include
LIB_DIR = ../lib
GOOGLE_INCLUDE = ../googletest/include
GOOGLE_LIB = ../googletest/make/libgtest.a
OBJS = main_test.o TerminalTable_Test.o  TerminalTable.o

all: $(OBJS)
	g++ $(OBJS) -o runtest -L. $(GOOGLE_LIB)

TerminalTable_Test.o: TerminalTable_Test.cpp
	g++ -c $^ -I $(GOOGLE_INCLUDE) -I $(INCLUDE_DIR)
	cp $(LIB_DIR)/TerminalTable.o TerminalTable.o

main_test.o: main_test.cpp
	g++ -c $^ -I $(GOOGLE_INCLUDE)

clean:
	rm -rf *~ *.o 
	rm -f runtest
run:
	./runtest
