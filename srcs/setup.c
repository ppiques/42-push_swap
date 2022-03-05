/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:24:42 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/05 18:07:03 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_int(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}


t_stack	*stack_insert(t_stack *stack, char const *nbr)
{
	int nb;
	t_stack *new;
	t_stack *current;

	nb = ft_atoi(nbr);
	current = stack;
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
//			write(1, &argv[i][0], 1);
			i--;
			stack->pos = i;
		}
	}
	stack = find_target(stack);
	return (stack);
}
