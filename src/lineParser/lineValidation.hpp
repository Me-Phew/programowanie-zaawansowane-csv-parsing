/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef LINEVALIDATION_HPP
#define LINEVALIDATION_HPP

#include <string>
#include <cctype>
#include <algorithm>

#include "../logger/logger.hpp"

 /// \brief Funkcja sprawdzaj�ca poprawno�� wiersza danych.
 /// \details Sprawdza, czy wiersz zawiera odpowiedni� liczb� parametr�w, czy nie jest pusty i czy nie zawiera liter.
 /// \param line Wiersz danych wej�ciowych.
 /// \return true, je�li wiersz jest poprawny, false w przeciwnym razie.
bool lineValidation(const std::string& line) {
    if (line.empty()) {
        loggerError.log("Pusta linia");
        return false;
    } else if (line.find("Time") != std::string::npos) {
        loggerError.log("Znaleziono nagłówek: " + line);
        return false;
    } else if (std::any_of(line.begin(), line.end(), [](char c) { return std::isalpha(c); })) {
        loggerError.log("Znaleziono inne dane: " + line);
        return false;
    } else if (std::count(line.begin(), line.end(), ',') != 5) {
        loggerError.log("Nieprawidłowa liczba parametrów: " + line);
        return false;
    } else {
        return true;
    }
}

#endif /* LINEVALIDATION_HPP */
