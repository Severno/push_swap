/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:42:56 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 13:56:19 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define	MULTIPLE_INPUT_PARAMS 2
# define 	ONE_INPUT_PARAM 1
# define	ERROR 0
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int			len_a;
	int				len_b;
	int				b_max;
	int				b_min;
	long long		cur_range_min_val;
	long long		cur_range_max_val;
	int			middle_pos_a;
	int			chanks_amount;
	int			amount_found_pos;
	int			chank_search_range;
	int			chank_range_len;
	int				*poss_cur_range;
	int				*sorted_arr;
	int				*unsorted_arr;
	int				sum_of_commands;
}					t_stacks;


//typedef struct		s_ps_params
//{
//	int				start; // саоме первое значаение
//	int				end; // самое последнее значение
//	int				middle; // позиция среднего элемента
//	int				lowest; // значение самого маленького элемента
//	int				highest; // значение самого большого элемента
//	size_t			length; // длина стека
//	int				*sorted_arr;
//}					t_ps_params;

t_stack			*create_stack(int capacity);
int				stack_size(t_stack *stack);

// checker
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
int get_middle_pos(int length);
int get_stack_size(t_stack *head);
size_t get_chanks_num(size_t arr_length);
size_t get_chank_range_len(t_stacks *stacks);
int get_min_b_value(t_stack *stack_b);
int get_max_b_value(t_stack *stack_b);
t_stack *get_last_stack_elem(t_stack *stack);
int get_number_of_elements(t_stack *stack);
// commands
int					ft_apply_s(t_stack **stack);
int					ft_apply_ss(t_stack **stack_a, t_stack **stack_b);
int					ft_apply_p(t_stack **from, t_stack **to);
int					ft_apply_r(t_stack **stack);
int					ft_apply_r_st(t_stack **stack_a, t_stack **stack_b);
int					ft_apply_rr(t_stack **stack);
int					ft_apply_rr_st(t_stack **stack_a, t_stack **stack_b);

// push
void ft_stack_push_back(t_stack **head, t_stack *target);
void ft_stack_push_front(t_stack **head, t_stack *target);
t_stack				*ft_get_last_stack_elem(t_stack **head);

// create
t_stack				*ft_create_new_stack_elem(int value);

// pop
t_stack *ft_stack_pop_front(t_stack **stack);
t_stack		*ft_stack_pop_back(t_stack **stack);

// stacks init
void add_array_elems_to_stack_a(t_stacks *stacks);
void stacks_init(t_stacks **stacks, int *unsorted_arr, size_t array_size);

// visualize input process
void print_commands();
void visualize_input_process(t_stacks *stacks);
void print_stacks(t_stack* stack_a, t_stack* stack_b);

// stacks set
int free_data(t_stacks *stacks);
void free_stack(t_stack **head);
t_stack *create_stack_a(t_stacks *stacks);
t_stacks *create_stacks(int argc, char *argv[]);

// ps_algorithm
int is_sorted(t_stack *stack_a);
void ps_small_range(t_stacks *stacks);
void ps_middle_range(t_stacks *stacks);
void ps_big_range(t_stacks *stacks);


// algos handle
int		*get_poss_of_val_cur_range(t_stacks *stacks);
void reduce_by_one(t_stacks *stacks, int cur_range_pos);
int stack_b_is_sorted(t_stacks *stacks);
void sort_stack_b(t_stacks *stacks);
void find_correct_position(t_stacks *stacks);

// algo handle addition
void compare_push_value_and_top_stack_b(t_stacks *stacks);
void push_a_to_sorted_b(t_stacks *stacks);
void push_all_b_to_a(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks);
void handle_one_chank(t_stacks *stacks);
#endif
