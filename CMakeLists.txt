cmake_minimum_required(VERSION 3.14)

project(CsvParsing)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GTEST_ADD_TESTS_NO_EXECUTE ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(src/app src/lineParser src/logger src/treeData)

set(SOURCES src/main.cpp src/app/app.cpp src/lineParser/lineData.cpp src/logger/logger.cpp src/treeData/treeData.cpp)

add_executable(CsvParsing ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

enable_testing()

add_executable(
  CsvParsingTest
  tests/csv_parser_test.cpp
)

target_link_libraries(
  CsvParsingTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CsvParsingTest)
