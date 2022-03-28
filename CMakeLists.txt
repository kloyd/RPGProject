cmake_minimum_required(VERSION 3.21)
project(RPGProject)

set(CMAKE_CXX_STANDARD 14)
set (SOURCES main.cpp Mage.cpp Warrior.cpp Player.cpp Priest.cpp)

add_executable(RPGProject ${SOURCES})
