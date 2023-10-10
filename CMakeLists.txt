cmake_minimum_required(VERSION 3.23)
project(BlockchainCplusplus)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlockchainCplusplus main.cpp)

target_include_directories(BlockchainCplusplus PRIVATE "C:/Program Files/OpenSSL-Win64/include")
