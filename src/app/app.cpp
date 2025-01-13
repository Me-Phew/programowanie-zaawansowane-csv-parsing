/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "app.hpp"
#include "../lineParser/lineData.hpp"
#include "../lineParser/lineValidation.hpp"
#include "../treeData/treeData.hpp"
#include "../logger/logger.hpp"

std::istream& operator>>(std::istream& iStream, MenuOption& menuOption) {
  int num;
  iStream >> num;
  menuOption = static_cast<MenuOption>(num);

  return iStream;
}

TreeData App::treeData;

int App::mainMenu() {
  while (true) {
    std::cout << "MENU:\n\n";

    std::cout << "1. Załaduj dane z pliku\n";
    std::cout << "2. Wyświetl strukturę drzewa\n";
    std::cout << "3. Pobierz dane w określonym przedziale czasowym\n";
    std::cout << "4. Oblicz sumy w określonym przedziale czasowym\n";
    std::cout << "5. Oblicz średnią wartość w określonym przedziale czasowym\n";
    std::cout << "6. Porównaj dane między dwoma zakresami czasowymi\n";
    std::cout << "7. Wyszukaj dane w określonym przedziale czasowym z tolerancją\n";
    std::cout << "8. Zapisz dane do pliku binarnego\n";
    std::cout << "9. Wczytaj dane z pliku binarnego\n";

    std::cout << "10. Wyjdź\n\n";

    std::cout << "Wybierz działanie: ";

    MenuOption selectedOption;

    std::cin >> selectedOption;

    if (selectedOption > EXIT) {
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n\n";
      continue;
    }

    std::cout << std::endl;

    switch (selectedOption) {
    case LOAD_DATA_FROM_FILE:
      handleLoadDataFromFile();
      break;
    case DISPLAY_TREE_STRUCTURE:
      handleDisplayTreeStructure();
      break;
    case GET_DATA_BETWEEN_DATES:
      handleGetDataBetweenDates();
      break;
    case CALCULATE_SUMS_BETWEEN_DATES:
      handleCalculateSumsBetweenDates();
      break;
    case CALCULATE_AVERAGES_BETWEEN_DATES:
      handleCalculateAveragesBetweenDates();
      break;
    case COMPARE_DATA_BETWEEN_DATES:
      handleCompareDataBetweenDates();
      break;
    case SEARCH_RECORDS_WITH_TOLERANCE:
      handleSearchRecordsWithTolerance();
      break;
    case SAVE_DATA_TO_BINARY_FILE:
      handleSaveDataToBinaryFile();
      break;
    case LOAD_DATA_FROM_BINARY_FILE:
      handleLoadDataFromBinaryFile();
      break;
    case EXIT: {
      return handleExit();
    }
    default:
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n";
    }

    std::cout << "\n";
  }
}


int App::run() {
#ifdef _WIN32
  // enable utf-8 printing on windows
  SetConsoleOutputCP(CP_UTF8);
#endif

  int exitCode = mainMenu();
  return exitCode;
}

int App::handleLoadDataFromFile() {
  std::ifstream file;

  file.open("Chart Export.csv");
  if (!file.is_open()) {
    std::cerr << "Podczas otwierania pliku wystąpił błąd" << std::endl;
    return -1;
  }

  vector<LineData> data; ///< Wektor przechowuj�cy dane wierszy z pliku.
  std::string line;

  while (std::getline(file, line)) {
    if (lineValidation(line)) {
      LineData ld(line);
      data.push_back(ld);
      treeData.addData(ld);
    }
  }

  file.close();
  cout << "Dane zostały załadowane pomyślnie." << endl;
  cout << "Loaded " << data.size() << " lines" << endl;
  cout << "Found " << loggerErrorCount << " faulty lines" << endl;
  cout << "Check log and log_error files for more details" << endl;

  return 0;
}

int App::handleDisplayTreeStructure() {
  TreeData treeData;
  treeData.print();

  return 0;
}

int App::handleGetDataBetweenDates() {
  std::string startDate, endDate;
  std::vector<LineData> filteredData;

  std::cout << "Enter start date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, startDate);
  std::cout << "Enter end date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, endDate);

  filteredData = treeData.getDataBetweenDates(startDate, endDate);
  std::cout << "Data between " << startDate << " and " << endDate << ":" << std::endl;
  for (const auto& ld : filteredData) {
    ld.print();
  }

  return 0;
}

int App::handleCalculateSumsBetweenDates() {
  std::string startDate, endDate;
  float autokonsumpcjaSum, eksportSum, importSum, poborSum, produkcjaSum;

  std::cout << "Enter start date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, startDate);
  std::cout << "Enter end date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, endDate);

  treeData.calculateSumsBetweenDates(startDate, endDate, autokonsumpcjaSum, eksportSum, importSum, poborSum, produkcjaSum);
  std::cout << "Sums between " << startDate << " and " << endDate << ":" << std::endl;
  std::cout << "Autokonsumpcja: " << autokonsumpcjaSum << std::endl;
  std::cout << "Eksport: " << eksportSum << std::endl;
  std::cout << "Import: " << importSum << std::endl;
  std::cout << "Pobór: " << poborSum << std::endl;
  std::cout << "Produkcja: " << produkcjaSum << std::endl;

  return 0;
}

int App::handleCalculateAveragesBetweenDates() {
  std::string startDate, endDate;
  float autokonsumpcjaSum, eksportSum, importSum, poborSum, produkcjaSum;

  std::cout << "Enter start date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, startDate);
  std::cout << "Enter end date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, endDate);

  treeData.calculateAveragesBetweenDates(startDate, endDate, autokonsumpcjaSum, eksportSum, importSum, poborSum, produkcjaSum);
  std::cout << "Averages between " << startDate << " and " << endDate << ":" << std::endl;
  std::cout << "Autokonsumpcja: " << autokonsumpcjaSum << std::endl;
  std::cout << "Eksport: " << eksportSum << std::endl;
  std::cout << "Import: " << importSum << std::endl;
  std::cout << "Pobór: " << poborSum << std::endl;
  std::cout << "Produkcja: " << produkcjaSum << std::endl;

  return 0;
}

int App::handleCompareDataBetweenDates() {
  std::string startDate1, endDate1, startDate2, endDate2;
  float autokonsumpcjaDiff, eksportDiff, importDiff, poborDiff, produkcjaDiff;

  std::cout << "Enter first start date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, startDate1);
  std::cout << "Enter first end date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, endDate1);
  std::cout << "Enter second start date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, startDate2);
  std::cout << "Enter second end date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, endDate2);

  treeData.compareDataBetweenDates(startDate1, endDate1, startDate2, endDate2, autokonsumpcjaDiff, eksportDiff, importDiff, poborDiff, produkcjaDiff);
  std::cout << "Differences between " << startDate1 << " and " << endDate1 << " and " << startDate2 << " and " << endDate2 << ":" << std::endl;
  std::cout << "Autokonsumpcja: " << autokonsumpcjaDiff << std::endl;
  std::cout << "Eksport: " << eksportDiff << std::endl;
  std::cout << "Import: " << importDiff << std::endl;
  std::cout << "Pobór: " << poborDiff << std::endl;
  std::cout << "Produkcja: " << produkcjaDiff << std::endl;

  return 0;
}

int App::handleSearchRecordsWithTolerance() {
  std::string startDate, endDate;
  float searchValue, tolerance;
  std::vector<LineData> recordsWithTolerance;

  std::cout << "Enter start date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, startDate);
  std::cout << "Enter end date (dd.mm.yyyy hh:mm): ";
  std::getline(std::cin, endDate);
  std::cout << "Enter search value: ";
  std::cin >> searchValue;
  std::cout << "Enter tolerance: ";
  std::cin >> tolerance;

  recordsWithTolerance = treeData.searchRecordsWithTolerance(startDate, endDate, searchValue, tolerance);
  std::cout << "Records within tolerance:" << std::endl;
  for (const auto& ld : recordsWithTolerance) {
    ld.print();
  }

  return 0;
}

int App::handleSaveDataToBinaryFile() {
  std::ofstream file;
  file.open("data.bin", std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return -1;
  }

  treeData.serialize(file);
  file.close();
  std::cout << "Data saved successfully." << std::endl;

  return 0;
}

int App::handleLoadDataFromBinaryFile() {
  std::ifstream file;
  file.open("data.bin", std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return -1;
  }

  while (file.peek() != EOF) {
    LineData ld(file);
  }

  file.close();
  std::cout << "Data loaded successfully." << std::endl;

  return 0;
}

int App::handleExit() {
  std::cout << "Dziękujemy za korzystanie z programu\n";

  return 0;
}
