#include "gtest/gtest.h"
#include "pch.h"
#include "Header.h"

using namespace std;

struct RationalNumberTestFixture : public ::testing::Test {
 public:
  RationalNumber<int> first;
  RationalNumber<int> second;
  RationalNumber<int> zero;
  void SetUp() {
    first = {1, 2};
    second = {1, 2};
    zero = {0, 1};
  }
  void TearDown() {
    // Something
  }
};
TEST_F(RationalNumberTestFixture, DivisionTest) {
  RationalNumber<int> exception(1, 1);
  EXPECT_TRUE(first / second == exception);
}
TEST_F(RationalNumberTestFixture, DivisionTest2) {
  RationalNumber<int> exception(0, 0);
  EXPECT_TRUE(first / zero == exception);
}
TEST_F(RationalNumberTestFixture, SumTest) {
  RationalNumber<int> exception(1, 1);
  EXPECT_TRUE(first + second == exception);
}
TEST_F(RationalNumberTestFixture, ResTest) {
  RationalNumber<int> exception(0, 1);
  EXPECT_TRUE(first - second == exception);
}
TEST_F(RationalNumberTestFixture, MultTest) {
  RationalNumber<int> exception(1, 4);
  EXPECT_TRUE(first * second == exception);
}
TEST_F(RationalNumberTestFixture, IncrTest) {
  RationalNumber<int> exception(3,2);
  EXPECT_TRUE(++first == exception);
}
TEST_F(RationalNumberTestFixture, DectTest) {
  RationalNumber<int> exception(-1, 2);
  EXPECT_TRUE(--first == exception);
}
TEST_F(RationalNumberTestFixture, EqualTest) {
  EXPECT_TRUE(first == second);
}
TEST_F(RationalNumberTestFixture, MinEqualTest) {
  EXPECT_TRUE(first <= second);
}
TEST_F(RationalNumberTestFixture, MaxEqualTest) {
  EXPECT_TRUE(first >= second);
}
TEST_F(RationalNumberTestFixture, SumEqualTest) {
  RationalNumber<int> exception(1, 1);
  first += second;
  EXPECT_TRUE(first == exception);
}
TEST_F(RationalNumberTestFixture, RelEqualTest) {
  RationalNumber<int> exception(0, 1);
  first -= second;
  EXPECT_TRUE(first == exception);
}
TEST_F(RationalNumberTestFixture, MultEqualTest) {
  RationalNumber<int> exception(1, 4);
  first *= second;
  EXPECT_TRUE(first == exception);
}
TEST_F(RationalNumberTestFixture, DivEqualTest) {
  RationalNumber<int> exception(1, 1);
  first /= second;
  EXPECT_TRUE(first == exception);
}