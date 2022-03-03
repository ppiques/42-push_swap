/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:51:17 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/03 01:26:58 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *three_numbers_case(t_stack *stack)
{
	printf("target1 = %d\n", stack->target);
	printf("target2 = %d\n", stack->next->target);
	printf("target3 = %d\n", stack->next->next->target);
	while ((stack->target != 1) || (stack->next->target != 2))
	{
		if ((stack->target == 1 && stack->next->target == 3)
			|| (stack->target == 2 && stack->next->target == 1)
			|| (stack->target == 3 && stack->next->target == 2))
			stack = swap(stack, 'a');
		if (stack->target == 3 && stack->next->target == 2)
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
			rotate(stack[0], 'a');
		else
		{
			push(stack, 'b');
			i++;
		}
	}
	stack[0] = three_numbers_case(stack[0]);
}
