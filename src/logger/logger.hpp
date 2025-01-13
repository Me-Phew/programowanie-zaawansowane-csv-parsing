/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>

 /// \class Logger
 /// \brief Klasa obs�uguj�ca logowanie komunikat�w do plik�w tekstowych.
class Logger {
public:
    /// \brief Konstruktor klasy Logger.
    /// \details Tworzy plik logu z unikaln� nazw� opart� na aktualnej dacie i godzinie.
    /// \param filename Nazwa podstawowa pliku logu.
    Logger(const std::string& filename);

    /// \brief Destruktor klasy Logger.
    /// \details Zamyka otwarty plik logu.
    ~Logger();

    /// \brief Zapisuje komunikat do pliku logu.
    /// \param message Komunikat do zapisania.
    void log(const std::string& message);

private:
    std::ofstream logFile; ///< Strumie� pliku logu.
};

/// \var logger
/// \brief Globalny logger dla standardowych komunikat�w.
extern Logger logger;

/// \var loggerError
/// \brief Globalny logger dla komunikat�w b��d�w.
extern Logger loggerError;

/// \var loggerErrorCount
/// \brief Licznik wyst�pie� b��d�w logowanych przez loggerError.
extern int loggerErrorCount;

#endif /* LOGGER_HPP */
