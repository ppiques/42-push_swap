/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:23:46 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/07 16:24:10 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_finder(t_stack **stack)
{
	t_stack	*current[2];
	t_stack	*min;

	current[0] = stack[0];
	min = stack[0];
	while (current[0] != NULL)
	{
		if (current[0]->target < min->target)
			min = current[0];
		current[0] = current[0]->next;
	}
	return (min);
}

t_stack	*max_finder(t_stack **stack)
{
	t_stack	*current[2];
	t_stack	*max;

	current[0] = stack[0];
	max = stack[0];
	while (current[0] != NULL)
	{
		if (current[0]->target > max->target)
			max = current[0];
		current[0] = current[0]->next;
	}
	return (max);
}

t_stack	*find_base(t_stack **stack)
{
	t_stack	*current[2];
	t_stack	*min;
	t_stack	*max;
	int	i;

	i = 1;
	min = min_finder(stack);
	max = max_finder(stack);
	current[0] = stack[0];
	if (stack[1] == NULL)
		return (min);
	while (current[0]->target != (stack[1]->target + i))
	{
		current[0] = current[0]->next;
		if (current[0] == NULL)
		{
			if (i > max->target)
				return (min);
			current[0] = stack[0];
			i++;
		}
	}
	return (current[0]);
}
