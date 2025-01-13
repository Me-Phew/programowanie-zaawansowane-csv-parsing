/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief Punkt wejścia do aplikacji.
 *
 * Funkcja `main` uruchamia główną aplikację, wywołując metodę `run()` klasy `App`,
 * która odpowiedzialna jest za obsługę interaktywnego menu i wykonywanie operacji.
 *
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 */

#include "app/app.hpp"

 /**
  * @brief Funkcja główna programu.
  *
  * Funkcja wywołuje metodę `App::run()`, która uruchamia aplikację i umożliwia użytkownikowi
  * wykonywanie operacji na tablicy liczb całkowitych przez interaktywne menu.
  *
  * @return Kod zakończenia aplikacji (0 - sukces).
  */
int main() {
  return App::run(); ///< Uruchamia aplikację
}
