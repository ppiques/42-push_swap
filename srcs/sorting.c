/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:52:38 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/08 16:54:53 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack)
{
	int	i;
	t_stack	*current;
	t_stack	*last;

	while (stack_size(stack[0]) > 1)
	{
		i = 1;
		current = stack[0];
		while (current->next != NULL)
		{
			if (current->target < current->next->target)
				i++;
			current = current->next;
		}
		if ( i == stack_size(stack[0]))
			break ;
		last = current;
		if (stack[0]->target > last->target)
			stack[0] = rotate(stack[0], 'a');
		else
			push(stack, 'b');
	}
	return ;
}

void	set_distance(t_stack **stack)
{
	t_stack	*current[2];

	current[0] = stack[0];
	current[1] = stack[1];
	while (current[1] != NULL)
	{
		current[1]->dist = distance_calculator(current, \
		stack_size(stack[0]), stack_size(stack[1]));
		current[1] = current[1]->next;
	}
	return ;
}

int	distance_calculator(t_stack **stack, int sizeA, int sizeB)
{
	int	i;
	int	j;
	t_stack *baseA;

	baseA = find_base(stack);
	i = stack_optimizer(baseA, stack[1], sizeA, sizeB);
	if (stack[1]->half == 0)
	{
		if (baseA->half == 0)
			j = stack[1]->pos - 1 + baseA->pos - 1 - i;
		else
			j = stack[1]->pos - 1 + sizeA - baseA->pos + 1;
	}
	else
	{
		if (baseA->half == 0)
			j = sizeB - stack[1]->pos + 1 + baseA->pos - 1;
		else
			j = (sizeB - stack[1]->pos + 1) + (sizeA - baseA->pos + 1) - i;
	}
	return (j);
}

int	stack_optimizer(t_stack *baseA, t_stack *stackB, int sizeA, int sizeB)
{
	int	i;

	i = 0;
	if (stackB->half == 0)
	{
		if (baseA->half == 0)
		{
			if (stackB->pos <= baseA->pos)
				i = stackB->pos - 1;
			else
				i = baseA->pos - 1;
		}
	}
	else
	{
		if (baseA->half == 1)
		{
			if ((sizeB - stackB->pos + 1) <= (sizeA - baseA->pos + 1))
				i = (sizeB - stackB->pos + 1);
			else
				i = (sizeA - baseA->pos + 1);
		}
	}
	return (i);
}

void	sort_stacks(t_stack **stack)
{
	push_to_b(stack);
	while(stack[1] != NULL)
	{
		stack[0] = set_half(stack[0]);
		stack[1] = set_half(stack[1]);
		set_distance(stack);
		move(stack);
	}
	stack[0] = set_half(stack[0]);
	move(stack);
}
