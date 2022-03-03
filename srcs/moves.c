/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 02:50:14 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/03 04:52:29 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack **stack)
{
	t_stack	*mover;
	t_stack	*base;
	t_stack	*current[2];
	int		i;
	int		j;

	mover = NULL;
	j = 0;
	if (stack[1] != NULL)
		mover = choose_mover(stack[1]);
	current[1] = mover;
	current[0] = stack[0];
	base = choose_base(current);
	if (base->half == 1)
		i = base->pos;
	else
		i = base->pos - stack_size(stack[0]);
	if (stack[1] != NULL && mover->half == 1)
		j = mover->pos;
	else if (stack[1] != NULL)
		j = mover->pos - stack_size(stack[1]);
	good_moves(stack, i, j);
	push(stack, 'a');
	return ;
}
