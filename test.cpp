#include "pch.h"
#include "../Project1/functions.h"
#include "../Project1/functions.cpp"

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

TEST(TestCaseName1, checkConstructor) {
	duomenys pirmas({0,0,0},3,4,6,"jonas","jonaitis");
	ASSERT_EQ(pirmas.vardas(), "jonas");
}
TEST(TestCaseName2, CheckSetterAndAssignment) {
	duomenys pirmas, antras;
	pirmas.setEgz(3);
	antras = pirmas;
	ASSERT_EQ(pirmas.egz(), antras.egz());
}
TEST(TestCaseName3, CheckMarksQuantity) {
	duomenys pirmas;
	pirmas.setPaz(3);
	pirmas.setPaz(4);
	pirmas.setPaz(5);
	ASSERT_EQ(3, pirmas.kiekPaz());
}
