cmake_minimum_required(VERSION 3.1)

project (ProjectileSimulator)

add_executable (ProjectileSimulator main.cpp arrow.cpp config.cpp simulation.cpp utils.cpp)

target_link_libraries (ProjectileSimulator config++ sfml-system sfml-graphics sfml-window stdc++fs)
