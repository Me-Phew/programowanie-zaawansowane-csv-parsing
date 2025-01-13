/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iomanip>
#include <ctime>
#include <cstdio>
#include <sstream>

#include "logger.hpp"

 /// \var logger
 /// \brief Globalny logger dla standardowych komunikat�w.
Logger logger("log");

/// \var loggerError
/// \brief Globalny logger dla komunikat�w b��d�w.
Logger loggerError("log_error");

/// \var loggerErrorCount
/// \brief Licznik wyst�pie� b��d�w logowanych przez loggerError.
int loggerErrorCount = 0;

/// \brief Konstruktor klasy Logger.
/// \details Tworzy plik logu z unikaln� nazw� opart� na aktualnej dacie i godzinie.
/// \param filename Nazwa podstawowa pliku logu.
Logger::Logger(const std::string& filename) {
    auto t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << filename << "_" << std::put_time(&tm, "%d%m%Y_%H%M%S") << ".txt";
    std::string datedFilename = oss.str();

    if (std::remove(datedFilename.c_str()) != 0) {
        // Plik nie istnieje lub nie mo�na go usun��.
    }
    logFile.open(datedFilename, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Nie mo�na otworzy� pliku log");
    }
}

/// \brief Destruktor klasy Logger.
/// \details Zamykany jest otwarty plik logu.
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

/// \brief Zapisuje komunikat do pliku logu.
/// \param message Komunikat do zapisania.
void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        auto t = std::time(nullptr);
        std::tm tm;
        localtime_s(&tm, &t);
        logFile << std::put_time(&tm, "%d.%m.%Y %H:%M:%S") << " " << message << std::endl;
    }

    if (this == &loggerError) {
        ++loggerErrorCount;
    }
}
