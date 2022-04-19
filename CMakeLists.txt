cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(EnprintExamples VERSION 0.1.0)

include_directories(
	./include
)

add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wnon-virtual-dtor)

add_executable(EnprintExample_01 examples/example_01.cpp)