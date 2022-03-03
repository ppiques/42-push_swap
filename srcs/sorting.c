/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:52:38 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/03 03:24:45 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_max_finder(t_stack **stack, int flag)
{
	t_stack	*current[2];
	t_stack	*min;
	t_stack	*max;

	current[0] = stack[0];
	min = stack[0];
	max = stack[0];
	while (current[0] != NULL)
	{
		if (current[0]->target > max->target)
			max = current[0];
		if (current[0]->target < min->target)
			min = current[0];
		current[0] = current[0]->next;
	}
	if (flag == 0)
		return (min);
	return (max);
}

t_stack	choose_base(t_stack **stack)
{

}

t_stack	*choose_mover(t_stack *stack)
{
	t_stack	*current;
	t_stack	*mover;

	current = stack;
	mover = stack;
	while (current != NULL)
	{
		if (current->dist < mover->dist)
			mover = current;
		current = current->next;
	}
	return (mover);
}
