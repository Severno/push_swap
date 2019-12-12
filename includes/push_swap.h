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

//typedef struct		s_el
//{
//	struct s_stack	*next;
//	struct s_stack	*prev;
//	struct s_stack	*top;
//	struct s_stack	*bottom;
//	int				value;
//}					t_el;

typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a_head;
	t_stack			*a_tail;
	t_stack			*b_head;
	t_stack			*b_tail;
	int				len_a;
	int				len_b;
	int				middle_pos_a;
	int				middle_pos_b;
	int				*sorted_arr;
	int				*unsorted_arr;
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
int				*argv_to_int_arr(int argc, char *argv[], size_t *array_size);
int				checker(int argc, char *argv[]);
void			print_error();
void			free_push_swap(int *arr_num);
int				*handle_multiple_input_params(int argc, char *argv[], size_t *array_size);
int				*handle_one_input_params(char *argv[], size_t *array_size);

// input handle
int				check_input_condition(int argc, char *argv[]);
int				*convert_str_to_int_array(int argc, char *argv[], size_t *array_size);
int				has_duplicates(int *num_arr, size_t size);

int get_middle_pos(int length);
int get_stack_size(t_stack *head);

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

#endif
