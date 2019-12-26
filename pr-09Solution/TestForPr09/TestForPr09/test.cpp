#include <string>
#include <iostream>
#include "pch.h"
#include "../../pr-09/Calcule.h";
#include "../../pr-09/ReversePolish.h"

using namespace std;

TEST(Testing_Polish, FirstTest) {
  string str = "2+5*10";
  double result = CalculateReversePolish(ToReversePolish(str));
  EXPECT_EQ(52, result);
}
TEST(Testing_Polish, SecondTest) {
  string str = "(8+2*5)/(1+3*2-4)";
  double result = CalculateReversePolish(ToReversePolish(str));
  EXPECT_EQ(6, result);
}
TEST(Testing_Polish, ThirdTest) {
  string str = "(6+10-4)/(1+1*2)+1";
  double result = CalculateReversePolish(ToReversePolish(str));
  EXPECT_EQ(5, result);
}
TEST(Testing_Polish, FourthTest) {
  string str = "2+3*(8-7/2)";
  double result = CalculateReversePolish(ToReversePolish(str));
  EXPECT_EQ(15.5, result);
}
TEST(Testing_Form, FirstTest) {
  string str = "8|max(4,min(3,5))|(min(min(3,5),max(2,max(3,4)))";
  double result = CalculateForm(ToReversePolishForm(str));
  EXPECT_EQ(15, result);
}
TEST(Testing_Form, SecondTest) {
  string str = "4|max(4,8)|(min(3,max(5,max(3,4)))";
  double result = CalculateForm(ToReversePolishForm(str));
  EXPECT_EQ(15, result);
}
TEST(Testing_Form, ThirdTest) {
  string str = "4";
  double result = CalculateReversePolish(ToReversePolish(str));
  EXPECT_EQ(4, result);
}