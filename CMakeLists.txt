cmake_minimum_required(VERSION 2.6)
project(particles)

set(CMAKE_CXX_FLAGS "-std=c++1y")

add_executable(particles main.cpp multival.cpp position.cpp direction.cpp simulator.cpp particle.cpp normal.cpp photonic.cpp dual.cpp fissile.cpp dualfissile.cpp namegen.cpp)

install(TARGETS particles RUNTIME DESTINATION bin)
