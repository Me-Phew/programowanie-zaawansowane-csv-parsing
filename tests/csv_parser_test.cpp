/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-14
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <gtest/gtest.h>

#include "lineData.hpp"
#include "lineData.cpp"
#include "treeData.hpp"
#include "treeData.cpp"
#include "logger.hpp"
#include "logger.cpp"
#include "lineValidation.hpp"

 // test lineData class
TEST(LineData, Constructor) {
  LineData lineData("2025-01-01 00:00:00,1,2,3,4,5");
  EXPECT_EQ("2025-01-01 00:00:00", lineData.getDate());
  EXPECT_EQ(1, lineData.getAutokonsumpcja());
  EXPECT_EQ(2, lineData.getEksport());
  EXPECT_EQ(3, lineData.getImport());
  EXPECT_EQ(4, lineData.getPobor());
  EXPECT_EQ(5, lineData.getProdukcja());
}

TEST(LineData, PrintString) {
  LineData lineData("2025-01-01 00:00:00,1,2,3,4,5");
  EXPECT_EQ("2025-01-01 00:00:00 1.000000 2.000000 3.000000 4.000000 5.000000", lineData.printString());
}

TEST(LineData, Serialize) {
  LineData lineData("2025-01-01 00:00:00,1,2,3,4,5");
  ofstream out("test.bin", ios::binary);
  lineData.serialize(out);
  out.close();
  ifstream in("test.bin", ios::binary);
  LineData lineData2(in);
  EXPECT_EQ("2025-01-01 00:00:00", lineData2.getDate());
  EXPECT_EQ(1, lineData2.getAutokonsumpcja());
  EXPECT_EQ(2, lineData2.getEksport());
  EXPECT_EQ(3, lineData2.getImport());
  EXPECT_EQ(4, lineData2.getPobor());
  EXPECT_EQ(5, lineData2.getProdukcja());
}

TEST(LineData, Deserialize) {
  LineData lineData("2025-01-01 00:00:00,1,2,3,4,5");
  ofstream out("test.bin", ios::binary);
  lineData.serialize(out);
  out.close();
  ifstream in("test.bin", ios::binary);
  LineData lineData2(in);
  EXPECT_EQ("2025-01-01 00:00:00", lineData2.getDate());
  EXPECT_EQ(1, lineData2.getAutokonsumpcja());
  EXPECT_EQ(2, lineData2.getEksport());
  EXPECT_EQ(3, lineData2.getImport());
  EXPECT_EQ(4, lineData2.getPobor());
  EXPECT_EQ(5, lineData2.getProdukcja());
}

TEST(LineValidationTest, HeaderLine) {
  string line = "Time,Autokonsumpcja (W),Eksport (W),Import (W),Pobor (W),Produkcja (W)";
  EXPECT_FALSE(lineValidation(line));
}

TEST(LineValidationTest, LineWithInvalidCharacters) {
  string line = "2025-01-14 10:00:00,X,200.5,300.5,400.5,500.5";
  EXPECT_FALSE(lineValidation(line));
}

TEST(TreeDataTest, AddData) {
  TreeData treeData;
  string line = "14.01.2025 10:00:00,50.5,100.5,200.5,500.5,300.5";
  LineData ld(line);
  treeData.addData(ld);

  vector<LineData> data = treeData.getDataBetweenDates("14.01.2025 00:00", "14.01.2025 23:59");
  ASSERT_EQ(data.size(), 1);
  EXPECT_EQ(data[0].getDate(), "14.01.2025 10:00:00");
  EXPECT_FLOAT_EQ(data[0].getAutokonsumpcja(), 50.5);
  EXPECT_FLOAT_EQ(data[0].getEksport(), 100.5);
  EXPECT_FLOAT_EQ(data[0].getImport(), 200.5);
  EXPECT_FLOAT_EQ(data[0].getPobor(), 500.5);
  EXPECT_FLOAT_EQ(data[0].getProdukcja(), 300.5);
}

TEST(TreeDataTest, CalculateSumsBetweenDates) {
  TreeData treeData;
  string line1 = "14.01.2025 10:00:00,50.5,100.5,200.5,500.5,300.5";
  string line2 = "14.01.2025 11:00:00,60.5,110.5,210.5,510.5,310.5";
  LineData ld1(line1);
  LineData ld2(line2);
  treeData.addData(ld1);
  treeData.addData(ld2);

  float autokonsumpcjaSum, eksportSum, importSum, poborSum, produkcjaSum;
  treeData.calculateSumsBetweenDates("14.01.2025 00:00", "14.01.2025 23:59", autokonsumpcjaSum, eksportSum, importSum, poborSum, produkcjaSum);
  EXPECT_FLOAT_EQ(autokonsumpcjaSum, 111.0);
  EXPECT_FLOAT_EQ(eksportSum, 211.0);
  EXPECT_FLOAT_EQ(importSum, 411.0);
  EXPECT_FLOAT_EQ(poborSum, 1011.0);
  EXPECT_FLOAT_EQ(produkcjaSum, 611.0);
}
