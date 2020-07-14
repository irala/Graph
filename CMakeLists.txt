cmake_minimum_required(VERSION 3.10.0)

project(graph)

##include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/external)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##ExternalProject_Add(NLOHMANN
##    GIT_REPOSITORY https://github.com/nlohmann/json.git
##    GIT_TAG master
##    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
##)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)


INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/source)


file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/source/*.h
    ${PROJECT_SOURCE_DIR}/source/*.cpp
)




message(${SOURCES})
add_executable (graph ${PROJECT_SOURCE_DIR}/source/main.cpp ${SOURCES} )
##add_dependencies(${PROJECT_NAME} NLOHMANN)
target_link_libraries( ${PROJECT_NAME} pthread -lboost_system -lboost_thread)