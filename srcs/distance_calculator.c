/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:29:35 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/05 16:28:57 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *set_half(t_stack *stack)
{
	int size;
	t_stack *current;

	size = stack_size(stack);
	current = stack;
	while (current != NULL)
	{
		current->half = half_calculator(current->pos, size);
		current = current->next;
	}
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
