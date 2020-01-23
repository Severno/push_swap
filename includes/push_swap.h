/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:42:56 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 18:19:23 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# define MULTIPLE_INPUT_PARAMS 2
# define ONE_INPUT_PARAM 1
# define ERROR 0
# define NO_MEDIAN 2147483647
# define CHECK_UNTIL_TOP 1
# define PUSH_SWAP 1
# define CHECKER 0
# define NUM_LEN_WITH_SIGN 11
# define NUM_LEN_NO_SIGN 10
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define CLR "\e[1;1H\e[2J"
# define WHITE   "\x1B[37m"

typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				weight;
}					t_stack;

typedef struct		s_part
{
	t_stack			*start;
	t_stack			*end;
}					t_part;

typedef struct		s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_stack			*visual_stack;
	t_stack			*stack_a_top;
	t_part			**partitions;
	int				partition_cap;
	int				len_a;
	int				*unsorted_arr;
	int				operations;
	char			*commands;
	int				visual_please;
	int				input_process_please;
	int				checker_run;
	char			**split_argv;
}					t_stacks;

int					get_elems_count_a(t_stack *stack, t_stacks *stacks);
void				sort_a(t_stack **a, t_stacks *stacks, int capacity);
int					a_to_b(t_stacks *stacks);

void				sort_three_elems_a(t_stack **a, t_stacks *stacks);
void				push_less_than_median_to_b(t_stacks *stacks, int median);

void				fast_handle_only_three_elems(t_stack **stack,
					t_stacks *stacks);
void				find_shortest_way_to_element_a(t_stacks *stacks);
void				handle_special_range(t_stacks *stacks);

void				rotate_commands(char *command, t_stacks *stacks);
void				visual_commands(t_stacks *stacks);

void				sort_b(t_stacks *stacks, int capacity);
void				push_b(t_stacks *stacks,
					t_stack **stack_b, int capacity);
int					b_to_a(t_stacks *stacks);

int					get_elems_count_b(t_stacks *stacks);
void				push_more_than_median_to_a(t_stacks *stacks, int median);
void				sort_three_elems_b(t_stacks *stacks);

void				check_commands(t_stacks *stacks);

int					ft_apply_s(t_stack **stack, t_stacks *stacks);
int					ft_apply_ss(t_stack **stack_a,
					t_stack **stack_b, t_stacks *stacks);
int					ft_apply_p(t_stack **from, t_stack **to, t_stacks *stacks);

int					ft_apply_r(t_stack **stack, t_stacks *stacks);
int					ft_apply_r_st(t_stack **stack_a,
					t_stack **stack_b, t_stacks *stacks);
int					ft_apply_rr(t_stack **stack, t_stacks *stacks);
int					ft_apply_rr_st(t_stack **stack_a,
					t_stack **stack_b, t_stacks *stacks);

int					free_data(t_stacks *stacks);
int					print_error(t_stacks *stacks);
void				free_partition_b(t_stacks *stacks);
void				free_stack(t_stack **stack);

t_stack				*get_last_stack_elem(t_stack *stack);
int					get_max_of_partition(t_stack *start, t_stack *end);
int					get_min_of_partition(t_stack *start, t_stack *end);
int					get_stack_size(t_stack *stack);

void				free_split_str(char ***split_str);
void				convert_argv_to_int_array(int argc,
					char *argv[], int *array_size, t_stacks *stacks);
int					has_duplicates(int *num_arr, int size);

void				add_val_to_arr(t_stacks *stacks,
					char *work_value, int arr_c, size_t num_limit);
void				check_bonus_flags(t_stacks *stacks,
					int *split_c, int *full_argv_size, int arg_c);
void				check_value_condition(t_stacks *stacks,
					int *split_c, size_t *arr_c);

int					true_median(t_stacks *stacks, t_stack *stack);
int					special_median_a(t_stacks *stacks);
int					special_median_b(t_stacks *stacks);

void				print_line(t_stack *stack);
void				print_current_visual_state(t_stacks *stacks);
void				update_current_visual_state(t_stacks *stacks,
									int i, char *split_commands);

int					solver(t_stacks *stacks);

void				stack_step_back(t_stack **stack,
					t_stacks *stacks, int skip);
void				update_current_partition(t_stacks *stacks);
int					push_more_than_median_b_rutine(t_stack **stack_b,
					t_stacks *stacks, int median, int *skip);

t_stack				*ft_stack_pop_front(t_stack **stack);
t_stack				*ft_stack_pop_back(t_stack **stack);

t_stack				*ft_get_last_stack_elem(t_stack **head);
void				ft_stack_push_back(t_stack **head, t_stack *target);
void				ft_stack_push_front(t_stack **head, t_stack *target);

void				create_stack(t_stacks *stacks, t_stack **stack);
t_stacks			*create_stacks(int argc, char *argv[], int current_prog);
t_stack				*ft_create_new_stack_elem(int value);

int					is_sorted(t_stack *stack);
int					is_rev_sorted(t_stack *stack);
int					check_is_equal_num(int stack_value, int *arr, int len);
int					get_less_then_num_count(t_stack *stack, int median);
void				create_arr_from_linked_list(t_stack *stack,
					int *arr, int *counter);

void				print_stacks(t_stack *stack_a, t_stack *stack_b);
void				print_commands(void);
int					check_rotate_commands(t_stacks *stacks,
					char *buf, t_stack **stack);
int					check_push_swap_commands(t_stacks *stacks,
					char *buf, t_stack **stack);
void				visualize_input_process(t_stacks *stacks);

void				five_loop(int *i);
void				ten_loop(int *i);
void				hundred_loop(int *i);

void				set_weight_to_each_value(t_stacks *stacks);
void				run_visualization(t_stacks *stacks);

#endif
