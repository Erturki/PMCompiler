#include "gtest/gtest.h"
#include "SymbolTableEntry.h"

TEST(SymbolTableEntry, Constructor) {
	SymbolTableEntry entry = SymbolTableEntry();
	EXPECT_EQ(entry.getSymbolType(),0);
	EXPECT_EQ(entry.getStorageClass(),0);
	EXPECT_EQ(entry.getTypeSpecifier(),0);
	EXPECT_EQ(entry.getTypeQualifier(),0);
	EXPECT_EQ(entry.getName(),"");
}

TEST(SymbolTableEntry, CopyConstructor) {
	SymbolTableEntry entry = SymbolTableEntry()
			.withName("variable1")
			;
	SymbolTableEntry* copyEntry = new SymbolTableEntry(entry);
	EXPECT_EQ(copyEntry->getName(),"variable1");
}

TEST(SymbolTableEntry, Builder) {
	SymbolTableEntry entry = SymbolTableEntry()
			.withSymbolType(VAR)
			.withName("variable1")
			.withTypeSpecifier(INT)
			;

	EXPECT_EQ(entry.getSymbolType(),VAR);
	EXPECT_NE(entry.getSymbolType(),0);
	EXPECT_EQ(entry.getName(),"variable1");
	EXPECT_EQ(entry.getTypeSpecifier(),INT);
}

TEST(SymbolTableEntry, Print) {
	SymbolTableEntry entry = SymbolTableEntry()
			.withSymbolType(VAR)
			.withName("variable1")
			.withTypeSpecifier(INT)
			.withTypeQualifier(CONST)
			.withStorageClass(AUTO)
			;
	//std::cout << entry;
}



