cmake_minimum_required(VERSION 3.20)
project(datetime_synchronize)

set(CMAKE_CXX_STANDARD 14)

add_executable(datetime_synchronize main.cpp win/trigger_datetime_update.cpp win/trigger_datetime_update.h)
