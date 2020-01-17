CHECKER=checker
PUSH_SWAP=push_swap
LIBFT_NAME=libft/libft.a

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
LIGHT_GREEN:="\033[1;92m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"

END_IN:=\033[0;0m
BLACK_IN:=\033[1;30m
RED_IN:=\033[1;31m
GREEN_IN:=\033[1;32m
PURPLE_IN:=\033[1;35m
CYAN_IN:=\033[1;36m
WHITE_IN:=\033[1;37m
# ==================

FILES = checker input_handle stack_set checker_handle \
		commands push_swap get_stack_info stack_pop stack_push commands_rotate \
		visualize_input_process \
		median b_stack_handle a_stack_handle stack_manipulations b_stack_handle_support


FILES_PUSH_SWAP= $(filter-out checker, $(FILES))
OBJ_PUSH_SWAP=$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES_PUSH_SWAP)))

FILES_CHECKER= $(filter-out push_swap, $(FILES))
OBJ_CHECKER=$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES_CHECKER)))
OBJ_PATH=objects/
SRC_PATH=src/
HEAD_PATH= includes/

SRC=$(addprefix src/, $(addsuffix .c, $(FILES_CHECKER) $(FILES_PUSH_SWAP)))


CC:=gcc
C_FLAGS:=-Wall -Wextra -Werror -I $(HEAD_PATH)
CACHE=.cache_exists

#test:
#	@echo $(FILES_PUSH_SWAP) "PUSH_SWAP"
#	@echo $(FILES_CHECKER) "CHECKER"

all: libft_make $(PUSH_SWAP) $(CHECKER)

libft_make:
	@cd libft/; make; cp libft.a ..;

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(LIBFT_NAME)
	gcc $(OBJ_PUSH_SWAP) $(LIBFT_NAME) -o $(PUSH_SWAP)

$(CHECKER):  $(OBJ_CHECKER) $(LIBFT_NAME)
	@gcc $(OBJ_CHECKER) $(LIBFT_NAME) -o $(CHECKER)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEAD_PATH) | $(CACHE)
	$(CC) $(C_FLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CACHE):
	@mkdir $(OBJ_PATH)
	@touch $(CACHE)

clean:
	rm -rf $(OBJ_PATH)
	@rm -f $(CACHE)

fclean: clean
	cd libft/; make fclean; cd ..;
	rm checker push_swap
	rm libft.a

re: fclean
	$(MAKE) all

norm:
	@echo $(RED)
	@norminette src/ $(HEAD_PATH) | grep -v Norme -B1 || echo $(END)$(LIGHT_GREEN)"Norm - OK!"$(END)
	@echo $(END)

.PHONY: all clean fclean re test norm libft_make