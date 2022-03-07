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
	if (count_int(stack[0]) == 3 || count_int(stack[0]) == 5)
		special_cases(stack);
	sort_stacks(stack);
	freestack(stack);
	return (0);
}
