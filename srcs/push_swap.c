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

int	main(int argc, char const **argv)
{
	t_stack	*stack[2];

	stack[0] = NULL;
	stack[1] = NULL;
	if (argc <= 1)
		return (-1);
	if (check_args(argv) == -1)
		return (0);
	stack[0] = create_stack(stack[0], argc, argv);
	if (check_order(stack[0]) == 1)
	{
		freestack(stack);
		return (0);
	}
	if (stack_size(stack[0]) == 3 || stack_size(stack[0]) == 5)
		special_cases(stack);
	else
		sort_stacks(stack);
	freestack(stack);
	return (0);
}
