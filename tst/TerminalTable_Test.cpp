#include "gtest/gtest.h"
#include "TerminalTable.h"

TEST(TerminalTable, Instance) {
	TerminalTable* instance1 = TerminalTable::Instance();
	TerminalTable* instance2 = TerminalTable::Instance();
	EXPECT_EQ(instance1,instance2);
}

TEST(TerminalTable, isKeyword) {
	TerminalTable* instance = TerminalTable::Instance();
	ASSERT_TRUE(instance->isKeyword("if"));
	ASSERT_FALSE(instance->isKeyword("num"));
}

TEST(TerminalTable, isSupported) {
	TerminalTable* instance = TerminalTable::Instance();
	ASSERT_FALSE(instance->isSupported("int"));
	ASSERT_FALSE(instance->isSupported("num"));
}
