/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:43:17 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/04 18:37:45 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_target_one(t_stack *stack)
{
	t_stack	*current;
	int	last_assigned;

	current = stack;
	last_assigned = current->nbr;
	while (current != NULL)
	{
		if (last_assigned >= current->nbr)
		{
			last_assigned = current->nbr;
			current->target = 1;
		}
		current = current->next;
	}
	return (last_assigned);
}

int	target_max(t_stack *stack)
{
	int	max;
	t_stack *current;

	current = stack;
	max = current->nbr;
	while (current !=NULL)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

int	find_last_assigned_target(t_stack*stack, int max, int last_assigned)
{
	int	temp;
	t_stack *current;

	current = stack;
	temp = max;
	while (current != NULL)
	{
		if (current->nbr > last_assigned && current->nbr < temp)
			temp = current->nbr;
		current = current->next;
	}
	last_assigned = temp;
	return (last_assigned);
}

t_stack	*find_target(t_stack *stack)
{
	int	i;
	int	last_assigned;
	int	max;
	t_stack	*current;

	i = 1;
	current = stack;
	last_assigned = current->nbr;
	max = current->nbr;
	last_assigned = set_target_one(stack);
	max = target_max(stack);
	while (i++ <= count_int(stack))
	{
		current = stack;
		while (current != NULL)
		{
			if (current->nbr > last_assigned && current->nbr <= max)
				current->target = i;
			current = current->next;
		}
		current = stack;
		last_assigned = find_last_assigned_target(stack, max, last_assigned);
	}
	return (current);
}
