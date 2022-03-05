/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:50:14 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/05 18:36:27 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotate(t_stack **stack, int *i, int *j)
{
	while (*i < 1 && *j < 1 && stack[1] != NULL)
	{
		stack[1] = reverse_rotate(stack[1], 'c');
		stack[0] = reverse_rotate(stack[0], 'c');
		(*i)++;
		(*j)++;
		write(1, "rrr\n", 4);
	}
	while (*i > 1 && *j > 1 && stack[1] != NULL)
	{
		stack[1] = rotate(stack[1], 'c');
		stack[0] = rotate(stack[0], 'c');
		(*i)--;
		(*j)--;
		write(1, "rr\n", 3);
	}
}

void	operate_moves(t_stack **stack, int i, int j)
{
	while (i > 1)
	{
		stack[0] = rotate(stack[0], 0);
		i--;
	}
	while (i < 1)
	{
		stack[0] = reverse_rotate(stack[0], 0);
		i++;
	}
	while (j > 1 && stack[1] != NULL)
	{
		stack[1] = rotate(stack[1], 1);
		j--;
	}
	while (j < 1 && stack[1] != NULL)
	{
		stack[1]= reverse_rotate(stack[1], 1);
		j++;
	}
	return ;

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

void	move(t_stack **stack)
{
	t_stack	*current[2];
	t_stack	*base;
	t_stack	*mover;
	int		i;
	int		j;

	mover = NULL;
	j = 0;
	if (stack[1] != NULL)
		mover = choose_mover(stack[1]);
	current[1] = mover;
	current[0] = stack[0];
	base = find_base(current);
	if (base->half == 0)
		i = base->pos;
	else
		i = base->pos - stack_size(stack[0]);
	if (stack[1] != NULL && mover->half == 0)
		j = mover->pos;
	else if (stack[1] != NULL)
		j = mover->pos - stack_size(stack[1]);
	double_rotate(stack, &i, &j);
	operate_moves(stack, i, j);
	push(stack, 'a');
	return ;
}
