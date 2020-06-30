cmake_minimum_required(VERSION 3.10.0)

project(Graph)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/source)
include_directories("thirdparty/nlohmann_json")


file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/source/*.h
    ${PROJECT_SOURCE_DIR}/source/*.cpp
    ${PROJECT_SOURCE_DIR}/thirdparty/nlohmann_json/json.hpp
)

message(${SOURCES})

add_executable (graph ${PROJECT_SOURCE_DIR}/source/main.cpp ${SOURCES} )