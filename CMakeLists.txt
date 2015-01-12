cmake_minimum_required(VERSION 2.6)
project(particles)

set(CMAKE_CXX_FLAGS "-std=c++1y")

add_executable(particles main.cpp position.cpp multival.cpp collision.cpp direction.cpp simulator.cpp particle.cpp normal.cpp photonic.cpp dual.cpp fissile.cpp dualfissile.cpp namegen.cpp)

install(TARGETS particles RUNTIME DESTINATION bin)
