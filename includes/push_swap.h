/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:42:56 by sapril            #+#    #+#             */
/*   Updated: 2020/01/21 20:49:22 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define	MULTIPLE_INPUT_PARAMS 2
# define 	ONE_INPUT_PARAM 1
# define	ERROR 0
# define	NO_MEDIAN 2147483647
# define	CHECK_UNTIL_TOP 1
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
# define CLR "\e[1;1H\e[2J"
# define WHITE   "\x1B[37m"



typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				weight;
}					t_stack;

typedef struct s_part
{
	t_stack			*start;
	t_stack			*end;
}			t_part;

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
}					t_stacks;

int 			solver(t_stacks *stacks);
void			create_stack(t_stacks *stacks, t_stack **stack);
void create_arr_from_linked_list(t_stack *stack, int *arr, int *counter);
//visualization
void visual_commands(t_stacks *stacks);
void run_visualization(t_stacks *stacks);

// utils
int		get_less_then_num_count(t_stack *stack, int median);

// checker
void check_commands(t_stacks *stacks);
int				*argv_to_int_arr(int argc, char *argv[], int *array_size);
int				checker(int argc, char *argv[]);
int			print_error();
void			free_push_swap(int *arr_num);
int				*handle_multiple_input_params(int argc, char *argv[], int *array_size);
int				*handle_one_input_params(char *argv[], int *array_size);

// input handle

int				check_input_condition(int argc, char *argv[]);
int				*convert_str_to_int_array(int argc, char *argv[], int *array_size);
int				has_duplicates(int *num_arr, int size);

// get stack info
int get_min_b_value(t_stack *stack_b);
int get_max_b_value(t_stack *stack_b);
t_stack *get_last_stack_elem(t_stack *stack);
int get_stack_size(t_stack *stack);
// commands
int					ft_apply_s(t_stack **stack, t_stacks *stacks);
int					ft_apply_ss(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks);
int					ft_apply_p(t_stack **from, t_stack **to, t_stacks *stacks);
int					ft_apply_r(t_stack **stack, t_stacks *stacks);
int					ft_apply_r_st(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks);
int					ft_apply_rr(t_stack **stack, t_stacks *stacks);
int					ft_apply_rr_st(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks);

// push
void ft_stack_push_back(t_stack **head, t_stack *target);
void ft_stack_push_front(t_stack **head, t_stack *target);
t_stack				*ft_get_last_stack_elem(t_stack **head);

// create
t_stack 				*ft_create_new_stack_elem(int value);

// pop
t_stack *ft_stack_pop_front(t_stack **stack);
t_stack		*ft_stack_pop_back(t_stack **stack);

// visualize input process
void print_commands();
void visualize_input_process(t_stacks *stacks);
void print_stacks(t_stack* stack_a, t_stack* stack_b);

// stacks set
int free_data(t_stacks *stacks);
void create_stack_a(t_stacks *stacks);
t_stacks *create_stacks(int argc, char *argv[]);

// ps_algorithm
int is_sorted(t_stack *stack_a);

// a_stack_handle
void sort_three_elems_a(t_stack **a, t_stacks *stacks);
void sort_a(t_stack **a, t_stacks *stacks,  int capacity);
void push_less_than_median_to_b(t_stacks *stacks, int median);
int get_elems_count_a(t_stack *stack, t_stacks *stacks);
int a_to_b(t_stacks *stacks);
void find_shortest_way_to_element_a(t_stacks *stacks);
void handle_five_elems_a(t_stacks *stacks);
void handle_four_elems_a(t_stacks *stacks);
void fast_handle_only_three_elems(t_stack **stack, t_stacks *stacks);
int check_is_equal_num(int stack_value, int *arr, int len);
void handle_special_range(t_stacks *stacks);
int is_rev_sorted(t_stack *stack);

// b_stack_handle
void sort_three_elems_b(t_stacks *stacks);
void sort_b(t_stacks *stacks,  int capacity);
int get_elems_count_b(t_stacks *stacks);
int b_to_a(t_stacks *stacks);
void push_more_than_median_to_a(t_stacks *stacks, int median);
int get_max_of_partition(t_stack *start, t_stack *end);
int get_min_of_partition(t_stack *start, t_stack *end);
void push_b(t_stacks *stacks, t_stack **stack_b, int capacity);

// true median
int true_median(t_stacks *stacks, t_stack *stack);
int special_median_a(t_stacks *stacks);
int special_median_b(t_stacks *stacks);

// stack_manipulations
void		stack_step_back(t_stack **stack, t_stacks *stacks, int skip);
void		update_current_partition(t_stacks *stacks);
int		push_more_than_median_b_rutine(t_stack **stack_b, t_stacks *stacks, int median, int *skip);
void		reverse_stack_step_back(t_stack **stack, t_stacks *stacks, int skip);

// visualize sort
void set_weight_to_each_value(t_stacks *stacks);

#endif
