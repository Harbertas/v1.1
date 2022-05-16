#include "pch.h"
#include "../Project1/functions.h"
#include "../Project1/functions.cpp"

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

TEST(TestCaseName1, CheckAssignemntAndResult) {
	duomenys pirmas({10, 5, 10}, 5, 3, 5, "jonas", "jonaitis");
	duomenys antras = pirmas;
	ASSERT_EQ(pirmas.egz(), antras.egz());
}

TEST(TestCaseName2, CheckNames) {
	duomenys pirmas, antras;
	pirmas.setVardas("Pilypas");
	antras.setVardas(pirmas.vardas());
	ASSERT_EQ(pirmas.vardas(), antras.vardas());
}

TEST(TestCaseName3, CheckMarks) {
	duomenys pirmas;
	pirmas.setPaz(3);
	pirmas.setPaz(4);
	pirmas.setPaz(5);
	ASSERT_EQ(3, pirmas.kiekPaz());
}
