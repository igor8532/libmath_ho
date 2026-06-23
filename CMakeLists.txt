cmake_minimum_required(VERSION 3.10)

project(libmath_ho)

add_library(libmath_ho INTERFACE)

target_include_directories(
	libmath_ho
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
