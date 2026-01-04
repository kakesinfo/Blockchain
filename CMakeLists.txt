cmake_minimum_required(VERSION 3.0.0)
project(badcoin C CXX)

set(
	SOURCE_FILES
	src/main.cpp
	src/blockchain.cpp
	src/sha256.cpp
	src/net.cpp	
)

set(
	HEADER_FILES
	src/block.h
	src/transaction.h
	src/blockchain.hpp
	src/sha256.hpp
	src/net.hpp
)

add_compile_options(-Wall -Wextra -Werror)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

