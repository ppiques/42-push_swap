/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:33:26 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/09 18:33:26 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    bonus_move(char*str, t_stack **stack, t_stack **stackA, t_stack **stackB)
{
    if (ft_strncmp(str, "sa", 3) == 0)
        bonus_swap(stackA);
    if (ft_strncmp(str, "sb", 3) == 0)
        bonus_swap(stackB);
    if (ft_strncmp(str, "ss", 3) == 0)
    {
        bonus_swap(stackA);
        bonus_swap(stackB)
    }
	if (ft_strncmp(str, "ra", 2) == 0)
		bonus_rotate(stackA);
	if (ft_strncmp(str, "rb", 2) == 0)
		bonus_rotate(stackB);
	if (ft_strncmp(str, "rr", 3) == 0)
	{
		bonus_rotate(stackA);
		bonus_rotate(stackB);
	}
	if (ft_strncmp(str, "pa", 2) == 0)
		bonus_push(stack, 'a');
	if (ft_strncmp(str, "pb", 2) == 0)
		bonus_push(stack, 'b');
	else
		bonus_reverse_rotater(str, stackA, stackB);
}

void    bonus_reverse_rotater(char *str, t_stack **stackA, t_stack **stackB)
{
    if (ft_strncmp(str, "rra", 3) == 0)
		bonus_reverse_rotate(stackA);
	if (ft_strncmp(str, "rrb", 3) == 0)
		bonus_reverse_rotate(stackB);
	if (ft_strncmp(str, "rrr", 3) == 0)
	{
		bonus_reverse_rotate(stackA);
		bonus_reverse_rotate(stackB);
	}
    return ;
}

void	checker(t_stack **stack)
{
	t_stack	*current;

	current = stack[0];
	if (stack[1] != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (current != NULL)
	{
		if (current->pos != current->target)
		{
			write(1, "KO\n", 3);
			current = stack[0];
			return ;
		}
		current = current->next;
	}
	write(1, "OK\n", 3);
	return ;
}