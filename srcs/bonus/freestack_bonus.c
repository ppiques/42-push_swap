/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:25:13 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/09 18:25:13 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	freestack(t_stack **stack)
{
	t_stack	*current[2];

	current[0] = stack[0];
	current[1] = stack[1];
	while (current[0] != NULL)
	{
		current[0] = current[0]->next;
		free(stack[0]);
		stack[0] = current[0];
	}
	free(current[0]);
	while (current[1] != NULL)
	{
		current[1] = current[1]->next;
		free(stack[1]);
		stack[1] = current[1];
	}
	free(current[1]);
	exit(1);
	return ;
}
