cmake_minimum_required(VERSION 3.10.0)

project(graph)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -Wno-missing-field-initializers -Wno-unused-parameter -Wno-unused-but-set-variable ")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/source)
include_directories("thirdparty/nlohmann_json")


file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/source/*.h
    ${PROJECT_SOURCE_DIR}/source/*.cpp
    ${PROJECT_SOURCE_DIR}/thirdparty/nlohmann_json/json.hpp
)

message(${SOURCES})

add_library (lprot ${PROJECT_SOURCE_DIR}/source/main.cpp ${SOURCES} )
add_executable (prot ${PROJECT_SOURCE_DIR}/source/main.cpp ${SOURCES} )