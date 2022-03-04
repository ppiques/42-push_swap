/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:28:23 by ppiques           #+#    #+#             */
/*   Updated: 2022/01/31 13:28:23 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "utils.h"

typedef struct s_stack
{
	int	nbr;
	int	pos;
	int	half;
	int	dist;
	int	target;
    struct s_stack *next;
}   t_stack;

//	check_args.c
int	check_args(int argc, char const **argv);

//	setup.c
t_stack	*create_stack(t_stack *stack, int argc, const char **argv);
int	count_int(t_stack *stack);

//	find_target.c
t_stack	*find_target(t_stack *stack);

//	operations.c
t_stack *swap(t_stack *stack, char flag);
t_stack *rotate(t_stack *stack, char flag);
t_stack *reverse_rotate(t_stack *stack, char flag);
t_stack **push(t_stack **stack, char flag);

//	special_cases.c
void	special_cases(t_stack **stack);
t_stack *three_numbers_case(t_stack *stack);
void five_numbers_case(t_stack **stack);

// distance_calculator.c
t_stack	*set_half(t_stack *stack);
int	half_calculator(int pos, int size);
int	stack_size(t_stack *stack);

// moves.c
void	move(t_stack **stack);
t_stack	*choose_mover(t_stack *stack);

//	sorting.c
t_stack	*find_base(t_stack **stack);

//	freestack.c
void	freestack(t_stack **stack);

#endif
