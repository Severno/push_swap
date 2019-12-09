/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:42:56 by sapril            #+#    #+#             */
/*   Updated: 2019/12/09 18:09:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define	MULTIPLE_INPUT_PARAMS 2
# define 	ONE_INPUT_PARAM 1
# define	ERROR 0

typedef struct	s_el
{
	struct s_el	*next;
	struct s_el	*prev;
	int			value;
}				t_el;

typedef struct	s_stack
{
	int			top;
	int			max_size;
	int			*items;
	t_el		*begin_list;
}				t_stack;

typedef struct	s_ps_params
{
	int			start; // саоме первое значаение
	int			end; // самое последнее значение
	int			middle; // позиция среднего элемента
	int			lowest; // значение самого маленького элемента
	int			highest; // значение самого большого элемента
	size_t		length; // длина стека
	int			*sorted_arr;
}				t_ps_params;

t_stack			*create_stack(int capacity);
int				stack_size(t_stack *stack);
int				*convert_str_to_int_array(int argc, char *argv[], size_t *array_size);

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

#endif
