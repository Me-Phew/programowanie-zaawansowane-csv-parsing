cmake_minimum_required(VERSION 3.14)

project(CsvParsing)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/app src/lineParser src/logger src/treeData)

set(SOURCES src/main.cpp src/app/app.cpp src/lineParser/lineData.cpp src/logger/logger.cpp src/treeData/treeData.cpp)

add_executable(CsvParsing ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
