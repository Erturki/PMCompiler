#include "gtest/gtest.h"
#include "LiteralTable.h"

TEST(LiteralTable, Instance) {
	LiteralTable* instance1 = LiteralTable::Instance();
	LiteralTable* instance2 = LiteralTable::Instance();
	EXPECT_EQ(instance1,instance2);
}

TEST(LiteralTable, MethodsNormal) {
	LiteralTable* instance = LiteralTable::Instance();
	int index = instance->put(INT_LITERAL,"100");
	ASSERT_TRUE(instance->get(index).compare("100") == 0);
	index = instance->put(CHAR_LITERAL, "z");
	ASSERT_TRUE(instance->getType(index) == CHAR_LITERAL);
}

TEST(LiteralTable, GetMethodsOutOfBound) {
	LiteralTable* instance = LiteralTable::Instance();
	ASSERT_EXIT(instance->get(100),::testing::ExitedWithCode(1), ".*");
}

TEST(LiteralTable, GetTypeMethodsOutOfBound) {
	LiteralTable* instance = LiteralTable::Instance();
	ASSERT_EXIT(instance->getType(200),::testing::ExitedWithCode(1), ".*");
}

