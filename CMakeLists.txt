cmake_minimum_required(VERSION 3.30)
project(ProgLabNote)

set(CMAKE_CXX_STANDARD 26)

# Libreria con codice reale
add_library(core
        Note.cpp
        Collezioni.cpp
        Importanti.cpp
        ConcreteObserver.cpp
)

# Eseguibile principale
add_executable(ProgLabNote main.cpp)
target_link_libraries(ProgLabNote core)

# Includi GoogleTest
add_subdirectory(googletest)

# Eseguibile dei test
add_executable(tests tests/test_notes.cpp)
target_link_libraries(tests core gtest gtest_main)

# Trovo gli header
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_test(NAME allTests COMMAND tests)
