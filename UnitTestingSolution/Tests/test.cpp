#include "pch.h"
#include "Header.h"
#include "gtest/gtest.h"

using namespace std;

TEST(RationalNumberTest, DivisionTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(1, 2);
  RationalNumber<int> exception(1, 1);
  RationalNumber<int> actual = first / second;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, DivisionTest2) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(3, 2);
  RationalNumber<int> exception(1, 3);
  RationalNumber<int> actual = first / second;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, DivisionTest3) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(0, 2);
  RationalNumber<int> exception(0, 0);
  RationalNumber<int> actual = first / second;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, SumTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(3, 1);
  RationalNumber<int> exception(7, 2);
  RationalNumber<int> actual = first + second;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, ResTest) {
  RationalNumber<int> first(5, 2);
  RationalNumber<int> second(1, 4);
  RationalNumber<int> exception(9, 4);
  RationalNumber<int> actual = first - second;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, MultTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(3, 1);
  RationalNumber<int> exception(3, 2);
  RationalNumber<int> actual = first * second;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, IncrTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> exception(3, 2);
  RationalNumber<int> actual = ++first;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, DectTest) {
  RationalNumber<int> first(5, 2);
  RationalNumber<int> exception(3, 2);
  RationalNumber<int> actual = --first;
  EXPECT_TRUE(actual == exception);
}
TEST(RationalNumberTest, MinTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(3, 1);
  EXPECT_TRUE(first < second);
}
TEST(RationalNumberTest, MaxTest) {
  RationalNumber<int> first(8, 2);
  RationalNumber<int> second(3, 1);
  EXPECT_TRUE(first > second);
}
TEST(RationalNumberTest, MinEqualTest) {
  RationalNumber<int> first(3, 1);
  RationalNumber<int> second(3, 1);
  EXPECT_TRUE(first <= second);
}
TEST(RationalNumberTest, MaxEqualTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(1, 2);
  EXPECT_TRUE(first >= second);
}
TEST(RationalNumberTest, SumEqualTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(3, 1);
  RationalNumber<int> exception(7, 2);
  first += second;
  EXPECT_TRUE(first == exception);
}
TEST(RationalNumberTest, RelEqualTest) {
  RationalNumber<int> first(7, 2);
  RationalNumber<int> second(3, 1);
  RationalNumber<int> exception(1, 2);
  first -= second;
  EXPECT_TRUE(first == exception);
}
TEST(RationalNumberTest, MultEqualTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(3, 1);
  RationalNumber<int> exception(3, 2);
  first *= second;
  EXPECT_TRUE(first == exception);
}
TEST(RationalNumberTest, DivEqualTest) {
  RationalNumber<int> first(1, 2);
  RationalNumber<int> second(3, 1);
  RationalNumber<int> exception(1, 6);
  first /= second;
  EXPECT_TRUE(first == exception);
}