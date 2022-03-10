/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:29:52 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/09 18:29:52 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*restore_pos(t_stack *stack)
{
	t_stack	*current;
	int		i;

	i = 1;
	current = stack;
	while (current != NULL)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
	return (stack);
}

void	bonus_swap(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next == NULL || stack == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
	*stack = restore_pos(*stack);
	return ;
}

void	bonus_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	last = *stack;
	if ((*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	last->next->next = NULL;
	temp = *stack;
	temp = NULL;
	*stack = restore_pos(*stack);
	return ;
}

void	bonus_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	last = *stack;
	if ((*stack)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			temp = last;
		last = last->next;
	}
	last->next = (*stack);
	temp->next = NULL;
	last = restore_pos(last);
	*stack = last;
	return ;
}

void	bonus_push(t_stack **stack, char flag)
{
	t_stack	*temp;

	if (flag == 'a' && stack[1] != NULL)
	{
		temp = stack[1]->next;
		stack[1]->next = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
	if (flag == 'b' && stack[0] != NULL)
	{
		temp = stack[0]->next;
		stack[0]->next = stack[1];
		stack[1] = stack[0];
		stack[0] = temp;
	}
	stack[0] = restore_pos(stack[0]);
	stack[1] = restore_pos(stack[1]);
	return ;
}
