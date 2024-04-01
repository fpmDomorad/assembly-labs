#include "pch.h"
#include "D:\BSU\Arifm\task4\function.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(AdditionTest, SumTest) {
	uint16_t a1 = 0x0000;
	uint16_t a2 = 0x0000;
	uint16_t a3 = 0x0000;
	uint16_t b1 = 0x0000;
	uint16_t b2 = 0x0000;
	uint16_t b3 = 0x0000;
	std::vector<uint16_t> expectedRes = { 0x0000,  0x0000,  0x0000,  0x0000 };
	std::vector<uint16_t> realRes = sumNumbers(a1, a2, a3, b1, b2, b3);

	for (size_t i = 0; i < realRes.size(); ++i) {
		EXPECT_EQ(realRes[i], expectedRes[i]);
	}
}
	//TODO Test case 2 and other
	TEST(AdditionTest, SumTest3) {
		uint16_t a1 = 0xFFFF;
		uint16_t a2 = 0xFFFF;
		uint16_t a3 = 0x0000;
		uint16_t b1 = 0xFFFF;
		uint16_t b2 = 0xFFFF;
		uint16_t b3 = 0xFFFF;
		std::vector<uint16_t> expectedRes = { 0xFFFF,  0xFFFF,  0xFFFF,  0x0001 };
		std::vector<uint16_t> realRes = sumNumbers(a1, a2, a3, b1, b2, b3);

		for (size_t i = 0; i < realRes.size(); ++i) {
			EXPECT_EQ(realRes[i], expectedRes[i]);
		}
}