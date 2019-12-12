cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_CHECKER
        "includes/*.h"
        "src/checker.c"
        "src/checker_handle.c"
        "src/input_handle.c"
        )
file(GLOB SRC_PUSH_SWAP
        "includes/*.h"
        "src/checker_handle.c"
        "src/commands.c"
        "src/commands_rotate.c"
        "src/get_stack_info.c"
        "src/input_handle.c"
        "src/push_swap.c"
        "src/stack_pop.c"
        "src/stack_push.c"
        "src/stack_set.c"
        )
file(GLOB LIBFT_SRC
        "libft/includes/*.h"
        "libft/src/*/*.c"
        )

add_executable(push_swap ${SRC_PUSH_SWAP})
add_executable(checker ${SRC_CHECKER})
target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft.a)
target_link_libraries(checker ${CMAKE_SOURCE_DIR}/libft.a)
