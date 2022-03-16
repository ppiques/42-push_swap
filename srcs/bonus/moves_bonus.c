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

void	bonus_move(char *str, t_stack **stack, t_stack **A, t_stack **B)
{
	if (ft_strncmp(str, "sa", 3) == 0)
		bonus_swap(A);
	else if (ft_strncmp(str, "sb", 3) == 0)
		bonus_swap(B);
	else if (ft_strncmp(str, "ss", 3) == 0)
	{
		bonus_swap(A);
		bonus_swap(B);
	}
	else if (ft_strncmp(str, "ra", 3) == 0)
		bonus_rotate(A);
	else if (ft_strncmp(str, "rb", 3) == 0)
		bonus_rotate(B);
	else if (ft_strncmp(str, "rr", 3) == 0)
	{
		bonus_rotate(A);
		bonus_rotate(B);
	}
	else if (ft_strncmp(str, "pa", 3) == 0)
		bonus_push(stack, 'a');
	else if (ft_strncmp(str, "pb", 3) == 0)
		bonus_push(stack, 'b');
	else
		bonus_rev_rotater(str, A, B);
}

void	bonus_rev_rotater(char *s, t_stack **sA, t_stack **sB)
{
	if (ft_strncmp(s, "rra", 4) == 0)
		bonus_reverse_rotate(sA);
	else if (ft_strncmp(s, "rrb", 4) == 0)
		bonus_reverse_rotate(sB);
	else if (ft_strncmp(s, "rrr", 4) == 0)
	{
		bonus_reverse_rotate(sA);
		bonus_reverse_rotate(sB);
	}
	else
	{
		sA[0]->errorflag = 1;
	}
	return ;
}

void	checker(t_stack **stack)
{
	t_stack	*current;

	current = stack[0];
	if (current->errorflag == 1)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (stack[1] != NULL && stack[1]->pos != 0)
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
