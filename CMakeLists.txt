cmake_minimum_required(VERSION 3.0)
project(ncd_project_cacti)

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )

find_package(Threads REQUIRED)
if (Threads_FOUND)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_definitions("-DNTHREADS=1")
    else(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_definitions("-DNTHREADS=8")
    endif(CMAKE_BUILD_TYPE STREQUAL "Debug")
endif(Threads_FOUND)

if (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR
("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"))
    #set(COMMON_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wformat -Wformat-security -Wno-unknown-pragmas")

    set(COMMON_CXX_FLAGS "-std=c++11 -Wno-unknown-pragmas")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_CXX_FLAGS}")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(COMMON_CXX_FLAGS "${COMMON_CXX_FLAGS} -Wall -Wextra -Wformat -Wformat-security")
    endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

    include_directories(${CMAKE_SOURCE_DIR}/include)

    find_package(OpenMP)
    if (OPENMP_FOUND)
        add_definitions("-DOPENMP")

        set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS}        -fopenmp")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fopenmp")
    endif()

    set(CMAKE_CXX_FLAGS_DEBUG   "${COMMON_CXX_FLAGS} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${COMMON_CXX_FLAGS} -O3 -march=native")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG    "${CMAKE_EXE_LINKER_FLAGS_DEBUG}   -g -O0")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE  "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -g -O3")
endif(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR
("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"))

add_subdirectory(src)