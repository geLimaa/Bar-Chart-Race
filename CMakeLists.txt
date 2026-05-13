cmake_minimum_required(VERSION 3.5)
project(BarChartRace VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(APP_NAME "bcr")
set(SOURCES
    src/main.cpp
    src/Reader.cpp
    src/BarChart.cpp
    src/BarItem.cpp
    src/Database.cpp
    src/Animation.cpp
    src/UserInput.cpp
    src/UserOutput.cpp
)

add_executable(${APP_NAME} ${SOURCES})

target_include_directories(${APP_NAME}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

target_compile_features(${APP_NAME}
    PUBLIC cxx_std_17
)

target_compile_options(${APP_NAME}
    PRIVATE
    -Wall
    -Wextra
    -pedantic
    -g
)
