/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:51:17 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/05 18:55:22 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_cases(t_stack **stack)
{
	int	i;

	i = 0;
	if (count_int(stack[0]) == 3)
		stack[0] = three_numbers_case(stack[0]);
	if (count_int(stack[0]) == 5)
	{
		five_numbers_case(stack);
		while (i < 3)
		{
			stack[0] = set_half(stack[0]);
			stack[1] = set_half(stack[1]);
			move(stack);
			i++;
		}
		if (stack[0]->target > stack[0]->next->target)
		{
			swap(stack[0], 'a');
			stack[0] = rotate(stack[0], 'a');
			stack[0] = rotate(stack[0], 'a');
		}
		else if (stack[0]->target < stack[0]->next->target)
		{
			stack[0] = rotate(stack[0], 'a');
			stack[0] = rotate(stack[0], 'a');
		}
	}
}

t_stack *three_numbers_case(t_stack *stack)
{
	while ((stack->target != 1) || (stack->next->target != 2))
	{
		if ((stack->target == 1 && stack->next->target == 3)
			|| (stack->target == 2 && stack->next->target == 1)
			|| (stack->target == 3 && stack->next->target == 2))
			stack = swap(stack, 'a');
		if (stack->target == 3 && stack->next->target == 1)
			stack = rotate(stack, 'a');
		if (stack->target == 2 && stack->next->target == 3)
			stack = reverse_rotate(stack, 'a');
	}
	return (stack);
}

void	five_numbers_case(t_stack **stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		//printf("next->target = %d\n", stack[0]->next->target);
		//printf("next->nbr = %d\n", stack[0]->next->nbr);
		if (stack[0]->target < 4)
			stack[0] = rotate(stack[0], 'a');
		else
		{
			push(stack, 'b');
			i++;
		}
	}
	stack[0] = three_numbers_case(stack[0]);
}
