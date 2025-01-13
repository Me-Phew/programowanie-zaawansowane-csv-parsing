/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca (kgruca7747@gmail.com)
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


Logger logger("log");


Logger loggerError("log_error");


int loggerErrorCount = 0;


Logger::Logger(const std::string& filename) {
    auto t = std::time(nullptr);
    std::tm tm;

#if defined(_WIN32) || defined(_WIN64) // For Windows
    localtime_s(&tm, &t);
#else // For Linux and other POSIX systems
    localtime_r(&t, &tm);
#endif

    std::ostringstream oss;
    oss << filename << "_" << std::put_time(&tm, "%d%m%Y_%H%M%S") << ".txt";
    std::string datedFilename = oss.str();

    if (std::remove(datedFilename.c_str()) != 0) {

    }
    logFile.open(datedFilename, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku log");
    }
}


Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}


void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        auto t = std::time(nullptr);
        std::tm tm;

#if defined(_WIN32) || defined(_WIN64) // For Windows
        localtime_s(&tm, &t);
#else // For Linux and other POSIX systems
        localtime_r(&t, &tm);
#endif

        logFile << std::put_time(&tm, "%d.%m.%Y %H:%M:%S") << " " << message << std::endl;
    }

    if (this == &loggerError) {
        ++loggerErrorCount;
    }
}
