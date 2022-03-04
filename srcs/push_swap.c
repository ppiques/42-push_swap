/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:30:22 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/03 01:30:22 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char const **argv)
{
	t_stack	*stack[2];
	int	i;

	i = 0;
	stack[0] = NULL;
	stack[1] = NULL;
	if (check_args(argc, argv) == -1)
		return (0);
	stack[0] = create_stack(stack[0], argc, argv);
	special_cases(stack);
	if (count_int(stack[0]) == 5)
		while (i < 3)
		{
			stack[0] = set_half(stack[0]);
			stack[1] = set_half(stack[1]);
			move(stack);
			i++;
		}
	freestack(stack);
    return (0);
}
