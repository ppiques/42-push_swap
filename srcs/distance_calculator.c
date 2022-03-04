/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:29:35 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/04 18:29:21 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *set_half(t_stack *stack)
{
	int size;
	t_stack *current;

	size = stack_size(stack);
	printf("size=%d\n", size);
	current = stack;
	while (current != NULL)
	{
		current->half = half_calculator(current->pos, size);
		printf("half=%d\n", current->half);
		current = current->next;
	}
	if (stack != NULL)
		printf("final half=%d\n", stack->half);
	return (stack);
}

int	half_calculator(int pos, int size)
{
	if ((size / 2) >= pos)
		return (0);
	return (1);
}

int	stack_size(t_stack *stack)
{
	int i;
	t_stack *current;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
