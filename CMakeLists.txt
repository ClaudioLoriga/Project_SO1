cmake_minimum_required(VERSION 3.17)
project(ProgettoSpaceInvaders C)

set(CMAKE_C_STANDARD 90)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(ProgettoSpaceInvaders main/main.c sprite.h)

target_link_libraries(ProgettoSpaceInvaders ${CURSES_LIBRARIES})