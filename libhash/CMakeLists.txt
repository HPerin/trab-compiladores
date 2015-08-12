cmake_minimum_required(VERSION 2.8)
project(hash)

include_directories(include)
set(SOURCE_FILES
    src/hash.c)
set(HEADER_FILES
    include/hash.h)

add_library(hash ${SOURCE_FILES} ${HEADER_FILES})

# Test executable (you can make your tests in the main.c)

project(test_hash)

include_directories(include)
set(SOURCE_FILES
    src/main.c
    src/hash.c)
set(HEADER_FILES
    include/hash.h)

add_executable(test_hash ${SOURCE_FILES} ${HEADER_FILES})
