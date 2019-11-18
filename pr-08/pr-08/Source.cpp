#include "Header.h"
#include "gtest/gtest.h"
class RationalNumberTest : public ::testing::Test {};
TEST(RationalNumberTest, DivisionTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(1, 2);
  RationalNumber<int> exception(1, 1);
  RationalNumber<int> actual = first / second;
  ASSERT_TRUE(actual == exception);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}