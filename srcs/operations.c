/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:25:25 by ppiques           #+#    #+#             */
/*   Updated: 2022/02/24 16:25:25 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *restore_pos(t_stack *stack)
{
	t_stack *current;
	int	i;

	i = 1;
	current = stack;
	while (current != NULL)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
	return (current);
}

t_stack *swap(t_stack *stack, char flag)
{
	t_stack *temp;

	if (stack->next == NULL || stack == NULL)
		return (NULL);
	temp = stack->next;
	stack->next = stack->next->next;
	temp->next = stack;
	stack = temp;
	// stack = restore_pos(stack);
	if (flag == 'a')
		write(1, "sa\n", 3);
	if (flag == 'b')
		write (1, "sb\n", 3);
	return (stack);
}

t_stack *rotate(t_stack *stack, char flag)
{
	t_stack *last;
	t_stack *temp;

	temp = stack;
	last = stack;
	if (stack->next == NULL)
		return (stack);
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			temp = last;
		last = last->next;
	}
	last->next = stack;
	temp->next = NULL;
	// stack = restore_pos(stack);
	if (flag == 'a')
		write(1, "ra\n", 3);
	if (flag == 'b')
		write(1, "rb\n", 3);
	return (stack);
}

t_stack *reverse_rotate(t_stack *stack, char flag)
{
	t_stack *last;
	t_stack *temp;

	temp = stack;
	last = stack;
	if (stack->next == NULL)
		return (stack);
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			temp = last;
		last = last->next;
	}
	last->next = stack;
	temp->next = NULL;
	// last = restore_pos(last);
	if (flag == 'a')
		write(1,"rra\n", 4);
	if (flag == 'b')
		write(1, "rrb\n", 4);
	return (last);
}

t_stack **push(t_stack **stack, char flag)
{
	t_stack *temp;

	if (flag == 'a' && stack[1] != NULL)
	{
		temp = stack[1]->next;
		stack[1]->next = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
		write(1, "pa\n", 3);
	}
	if (flag == 'b' && stack[1] != NULL)
	{
		temp = stack[0]->next;
		stack[0]->next = stack[1];
		stack[1] = stack[0];
		stack[0] = temp;
		write(1, "pb\n", 3);
	}
	stack[0] = restore_pos(stack[0]);
	stack[1] = restore_pos(stack[1]);
	return (stack);
}
