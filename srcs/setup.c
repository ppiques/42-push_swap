/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:24:42 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/10 16:37:13 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_insert(t_stack *stack, char const *nbr)
{
	int		nb;
	t_stack	*new;

	nb = ft_atoi(nbr);
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	new->nbr = nb;
	new->next = stack;
	stack = new;
	return (stack);
}

t_stack	*create_stack(t_stack *stack, int argc, char const **argv)
{
	int	i;

	i = 0;
	if (argc >= 2)
	{
		i = argc - 1;
		while (i != 0)
		{
			stack = stack_insert(stack, argv[i]);
			i--;
			stack->pos = i;
		}
	}
	stack = find_target(stack);
	return (stack);
}
