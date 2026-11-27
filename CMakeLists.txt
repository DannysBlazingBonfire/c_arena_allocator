cmake_minimum_required(VERSION 4.4)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project(arena_allocator LANGUAGES C)

add_subdirectory(allocator)
add_subdirectory(allocator_lib)
