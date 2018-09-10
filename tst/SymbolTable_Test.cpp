#include "gtest/gtest.h"
#include "SymbolTable.h"

TEST(SymbolTable, Constructor) {
	string alphanum =
			"01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	SymbolTable* symbolTable = new SymbolTable();
	EXPECT_NE(symbolTable->getScope(),alphanum);
	EXPECT_EQ(symbolTable->getAncestor(),nullptr);
}

TEST(SymbolTable, CopyConstructor) {
	SymbolTable* parentSymbolTable = new SymbolTable();
	SymbolTable* symbolTable = new SymbolTable(*parentSymbolTable);
	EXPECT_EQ(symbolTable->getAncestor(),parentSymbolTable);
}

TEST(SymbolTable, InsertAndSearch) {
	//set up
	SymbolTableEntry entry1, entry2, entry3;
	entry1 = SymbolTableEntry()
							.withSymbolType(VAR).withName("variable1").withTypeSpecifier(INT);
	entry2 = SymbolTableEntry()
							.withSymbolType(FUNC).withName("function2").withTypeSpecifier(VOID);
	entry3 = SymbolTableEntry()
							.withSymbolType(LABEL).withName("label3").withTypeSpecifier(VOID);

	SymbolTable* symbolTable = new SymbolTable();

	symbolTable->insert(entry1);
	symbolTable->insert(entry2);
	symbolTable->insert(entry3);

	SymbolTableEntry* value1 = symbolTable->search("variable1");
	EXPECT_EQ(value1->getSymbolType(),VAR);
	SymbolTableEntry* value2 = symbolTable->search("variable2");
	EXPECT_EQ(value2,nullptr);
	SymbolTableEntry* value3 = symbolTable->search("label3");
	EXPECT_EQ(value3->getTypeSpecifier(),VOID);

	//symbolTable->printTable();
}



