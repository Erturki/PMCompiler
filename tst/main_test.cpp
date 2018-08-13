#include "gtest/gtest.h"

int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv); // @suppress("Function cannot be resolved")
      return RUN_ALL_TESTS(); // @suppress("Function cannot be resolved")
}
