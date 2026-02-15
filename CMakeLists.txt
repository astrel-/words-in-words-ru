cmake_minimum_required(VERSION 3.20)

project(words_in_words_ru LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Core logic as a library (shared by app + tests)
add_library(wiw_core
    src/Solver.cpp
    src/TxtReader.cpp
    src/Utf16.cpp
)

target_include_directories(wiw_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (WIN32)
    target_compile_definitions(wiw_core PUBLIC WIN32_LEAN_AND_MEAN NOMINMAX)
endif()

# Main executable
add_executable(words-in-words-ru
    src/main.cpp
)
target_link_libraries(words-in-words-ru PRIVATE wiw_core)

# Tests
add_executable(words-in-words-ru-tests
    tests/test_solver.cpp
)
target_include_directories(words-in-words-ru-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
)
target_link_libraries(words-in-words-ru-tests PRIVATE wiw_core)

enable_testing()
add_test(NAME words_in_words_ru_tests COMMAND words-in-words-ru-tests)
