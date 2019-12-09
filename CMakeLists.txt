cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_CHECKER
        "includes/*.h"
        "src/checker.c"
        )
file(GLOB SRC_PUSH_SWAP
        "includes/*.h"
        "src/*.c"
        )
file(GLOB LIBFT_SRC
        "libft/includes/*.h"
        "libft/src/*/*.c"
        )

add_executable(push_swap ${SRC_PUSH_SWAP} ${LIBFT_SRC})
add_executable(checker ${SRC_CHECKER} ${LIBFT_SRC})
target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft.a)
target_link_libraries(checker ${CMAKE_SOURCE_DIR}/libft.a)