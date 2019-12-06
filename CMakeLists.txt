cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap main.c src/merge_sort.c)
target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft.a)