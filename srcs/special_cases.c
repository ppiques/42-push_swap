/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:51:17 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/07 18:01:03 by ppiques          ###   ########.fr       */
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
		stack[0] = final_sort(stack[0]);
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

t_stack	*final_sort(t_stack *stack)
{
	if (stack->nbr > stack->next->nbr)
	{
		swap(stack, 'a');
		stack = rotate(stack, 'a');
		stack = rotate(stack, 'a');
	}
	else if (stack->nbr < stack->next->nbr)
	{
		stack = rotate(stack, 'a');
		stack = rotate(stack, 'a');
	}
	return (stack);
}
