cmake_minimum_required(VERSION 3.9)
project(dev)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_C_COMPILER /usr/bin/gcc)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic")

set(SOURCE_FILES main.cpp)
add_executable(dev main.cpp Element.cpp Element.h Entity.cpp Entity.h Personnage.cpp Personnage.h Stats.cpp Stats.h Direction.cpp Direction.h Animation.cpp Animation.h Decors.cpp Decors.h IndestructableDecor.cpp IndestructableDecor.h DestructibleDecor.cpp DestructibleDecor.h Enemy.cpp Enemy.h Fighter.cpp Fighter.h Shooter.cpp Shooter.h MoveableDecor.cpp MoveableDecor.h MoveDestructDecor.cpp MoveDestructDecor.h MoveIndestructDecor.cpp MoveIndestructDecor.h Projectile.cpp Projectile.h)

set(EXECUTABLE_NAME ${PROJECT_NAME})

# Detect and add SFML
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
