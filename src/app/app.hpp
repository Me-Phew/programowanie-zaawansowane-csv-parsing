/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <vector>

#include "../treeData/treeData.hpp"

 /// @brief Wyliczenie opcji dostępnych w menu.
 /// Definiuje różne operacje, które użytkownik może wybrać w aplikacji.
enum MenuOption {
  LOAD_DATA_FROM_FILE = 1,
  DISPLAY_TREE_STRUCTURE,
  GET_DATA_BETWEEN_DATES,
  CALCULATE_SUMS_BETWEEN_DATES,
  CALCULATE_AVERAGES_BETWEEN_DATES,
  COMPARE_DATA_BETWEEN_DATES,
  SEARCH_RECORDS_WITH_TOLERANCE,
  SAVE_DATA_TO_BINARY_FILE,
  LOAD_DATA_FROM_BINARY_FILE,
  EXIT                         ///< Zakończenie działania aplikacji.
};

/// @brief Przeciążenie operatora >> do wyboru opcji menu.
/// @param iStream Strumień wejściowy.
/// @param menuOption Opcja menu, którą należy ustawić.
/// @return Referencja do strumienia wejściowego.
std::istream& operator>>(std::istream& iStream, MenuOption& menuOption);

class App {
private:
  static TreeData treeData; ///< Struktura drzewa do przechowywania danych.

  /// @brief Konstruktor usunięty, ponieważ klasa zawiera wyłącznie statyczne metody.
  App() = delete;

  /// @brief Usunięty konstruktor kopiujący.
  App(const App&) = delete;

  /// @brief Usunięty operator przypisania.
  App& operator=(const App&) = delete;

  /// @brief Wyświetla główne menu aplikacji i zwraca wybraną opcję.
  /// @return Wybrana opcja menu jako liczba całkowita.
  static int mainMenu();

  static int handleLoadDataFromFile();

  static int handleDisplayTreeStructure();

  static int handleGetDataBetweenDates();

  static int handleCalculateSumsBetweenDates();

  static int handleCalculateAveragesBetweenDates();

  static int handleCompareDataBetweenDates();

  static int handleSearchRecordsWithTolerance();

  static int handleSaveDataToBinaryFile();

  static int handleLoadDataFromBinaryFile();

  /// @brief Obsługuje zakończenie działania aplikacji.
  /// Wyświetla komunikat końcowy przed wyjściem.
  /// @return Kod wyjścia aplikacji (domyślnie 0).
  static int handleExit();

public:
  /// @brief Uruchamia aplikację.
  /// Wyświetla menu i pozwala użytkownikowi wykonywać operacje na liście.
  /// Kontroluje główną pętlę programu, w której użytkownik wybiera opcje z menu.
  /// @return Kod zakończenia aplikacji.
  static int run();
};

#endif /* APP_HPP */
