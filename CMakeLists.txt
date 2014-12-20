cmake_minimum_required(VERSION 2.6)
project(particles)

add_executable(particles main.cpp particle.cpp)

install(TARGETS particles RUNTIME DESTINATION bin)
