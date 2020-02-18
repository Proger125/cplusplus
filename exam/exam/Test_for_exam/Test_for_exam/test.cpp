#include "pch.h"
#include "../../NumberStream.h"
#include "../../SimpleStream.h"
TEST(SImpleSteramTest, SImpleSteramTest_Sample_Test) {
  std::string a = "abssfgasjhasgfajhf";
  SimpleStream testing;
  for (int i = 0; i < a.size(); i++) {
    testing.put(a[i]);
  }
  for (int i = 0; i < a.size(); i++) {
    EXPECT_EQ(a[i], testing.get());
  }
}

TEST(NumberStreamTest, NumberStreamTest_SampleTest) {
  std::string a = "ab12345 6578 9876 agah";
  NumberStream testing;
  for (int i = 0; i < a.size(); i++) {
    testing.put(a[i]);
  }
  testing.setPosition(0);
  EXPECT_NE(12345, testing.read());
  EXPECT_NE(12345, testing.read());
  EXPECT_EQ(12345, testing.read());
  EXPECT_NE(6578, testing.read());
  EXPECT_EQ(6578, testing.read());
  testing.write(12345);
  testing.setPosition(9);
  EXPECT_EQ(657812345, testing.read());
}