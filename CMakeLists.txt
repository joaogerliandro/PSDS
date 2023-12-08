cmake_minimum_required(VERSION 3.16)
project(PSDS VERSION 1.0 LANGUAGES CXX)

message(STATUS "Project: ${PROJECT_NAME} (version ${CMAKE_PROJECT_VERSION})")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMake Generator: ${CMAKE_GENERATOR}")

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_EXTENSIONS ON) 
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES RELATIVE ${PROJECT_SOURCE_DIR} "source/*.cpp")
file(GLOB_RECURSE HEADERS RELATIVE ${PROJECT_SOURCE_DIR} "include/*.h")
file(GLOB_RECURSE WRAPPERS RELATIVE ${PROJECT_SOURCE_DIR} "include/*.hpp")

set(PROJECT_SOURCES
    ${SOURCES}
    ${HEADERS}
    ${WRAPPERS}
)

if(WIN32)
    find_path(LIBPQ_INCLUDE_DIRS NAMES libpq-fe.h PATH_SUFFIXES include)
    include_directories(${LIBPQ_INCLUDE_DIRS})

    find_library(LIBPQ_LIBRARIES NAMES pq)
    link_directories(${LIBPQ_LIBRARIES})

    find_package(ZeroMQ REQUIRED)

    include_directories(${ZeroMQ_INCLUDE_DIRS})

    find_package(cppzmq REQUIRED)

    find_package(nlohmann_json REQUIRED)
else()
    find_package(PkgConfig)

    pkg_check_modules(PC_ZeroMQ QUIET zmq)

    find_path(ZeroMQ_INCLUDE_DIR
            NAMES zmq.hpp
            PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
            )

    find_library(ZeroMQ_LIBRARY
            NAMES zmq
            PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
            )

    find_package(cppzmq REQUIRED)

    find_package(nlohmann_json REQUIRED)
endif()

add_executable(
    ${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

if(WIN32)
    target_link_libraries(
        ${PROJECT_NAME}  
        libzmq
        cppzmq
        nlohmann_json::nlohmann_json
        ${LIBPQ_LIBRARIES}
    )
else()
    target_link_libraries(
        ${PROJECT_NAME}  
        libzmq
        cppzmq
        nlohmann_json::nlohmann_json
        ${LIBPQ_LIBRARIES}
    )
endif()