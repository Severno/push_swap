cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_CHECKER
        "includes/*.h"
        "src/a_stack_handle.c"
        "src/a_stack_handle_support.c"
        "src/a_stack_special_case.c"
        "src/apply_visual_commands.c"
        "src/b_stack_handle.c"
        "src/b_stack_handle_support.c"
        "src/checker.c"
        "src/commands.c"
        "src/commands_rotate.c"
        "src/free_data.c"
        "src/get_stack_info.c"
        "src/input_handle.c"
        "src/median.c"
        "src/print_visual_state.c"
        "src/stack_manipulations.c"
        "src/stack_pop.c"
        "src/stack_push.c"
        "src/stack_set.c"
        "src/utils.c"
        "src/visualize_input_process.c"
        "src/visualize_print_loops.c"
        "src/visualize_sorting.c"
        )
file(GLOB SRC_PUSH_SWAP
        "includes/*.h"
        "src/a_stack_handle.c"
        "src/a_stack_handle_support.c"
        "src/a_stack_special_case.c"
        "src/apply_visual_commands.c"
        "src/b_stack_handle.c"
        "src/b_stack_handle_support.c"
        "src/commands.c"
        "src/commands_rotate.c"
        "src/free_data.c"
        "src/get_stack_info.c"
        "src/input_handle.c"
        "src/median.c"
        "src/print_visual_state.c"
        "src/push_swap.c"
        "src/stack_manipulations.c"
        "src/stack_pop.c"
        "src/stack_push.c"
        "src/stack_set.c"
        "src/utils.c"
        "src/visualize_input_process.c"
        "src/visualize_print_loops.c"
        "src/visualize_sorting.c"
        )
file(GLOB LIBFT_SRC
        "libft/includes/*.h"
        libft/src/ft_str/ft_check_end_spaces.c
        libft/src/ft_str/ft_check_start_spaces.c
        libft/src/ft_str/ft_convert_dec_base_to_str.c
        libft/src/ft_str/ft_convert_undec_base_to_str.c
        libft/src/ft_str/ft_find_and_remove_char.c
        libft/src/ft_str/ft_isalnum.c
        libft/src/ft_str/ft_isalpha.c
        libft/src/ft_str/ft_isascii.c
        libft/src/ft_str/ft_isdigit.c
        libft/src/ft_str/ft_isprint.c
        libft/src/ft_str/ft_isspace.c
        libft/src/ft_str/ft_itoa.c
        libft/src/ft_str/ft_str_is_lowercase.c
        libft/src/ft_str/ft_str_is_numeric_no_spaces.c
        libft/src/ft_str/ft_str_is_numeric_with_spaces.c
        libft/src/ft_str/ft_str_is_printable.c
        libft/src/ft_str/ft_str_is_uppercase.c
        libft/src/ft_str/ft_strcat.c
        libft/src/ft_str/ft_strchr.c
        libft/src/ft_str/ft_strclr.c
        libft/src/ft_str/ft_strcmp.c
        libft/src/ft_str/ft_strcpy.c
        libft/src/ft_str/ft_strdel.c
        libft/src/ft_str/ft_strdup.c
        libft/src/ft_str/ft_strequ.c
        libft/src/ft_str/ft_striter.c
        libft/src/ft_str/ft_striteri.c
        libft/src/ft_str/ft_strjoin.c
        libft/src/ft_str/ft_strlcat.c
        libft/src/ft_str/ft_strlen.c
        libft/src/ft_str/ft_strmap.c
        libft/src/ft_str/ft_strmapi.c
        libft/src/ft_str/ft_strncat.c
        libft/src/ft_str/ft_strncmp.c
        libft/src/ft_str/ft_strncpy.c
        libft/src/ft_str/ft_strnequ.c
        libft/src/ft_str/ft_strnew.c
        libft/src/ft_str/ft_strnlen.c
        libft/src/ft_str/ft_strnstr.c
        libft/src/ft_str/ft_strrchr.c
        libft/src/ft_str/ft_strsplit.c
        libft/src/ft_str/ft_strstr.c
        libft/src/ft_str/ft_strsub.c
        libft/src/ft_str/ft_strtrim.c
        libft/src/ft_str/ft_tolower.c
        libft/src/ft_str/ft_toupper.c
        )

add_executable(push_swap ${SRC_PUSH_SWAP} ${LIBFT_SRC} src/input_handle_check.c)
add_executable(checker ${SRC_CHECKER} ${LIBFT_SRC} src/input_handle_check.c)
target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/libft.a)
target_link_libraries(checker ${CMAKE_SOURCE_DIR}/libft.a)
