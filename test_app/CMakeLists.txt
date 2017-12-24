cmake_minimum_required(VERSION 3.9)
project(test_app)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

set(SOURCE_FILES main.cpp)
add_executable(test_app main.cpp)

set(EXECUTABLE_NAME ${PROJECT_NAME})

# Detect and add SFML
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
