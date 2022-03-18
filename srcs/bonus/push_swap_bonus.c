/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:16:20 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/09 18:16:20 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char const **argv)
{
	int		size;
	char	*line;
	t_stack	*stack[2];

	if (argc <= 1)
		return (-1);
	if (check_args(argv) == -1)
		return (-1);
	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
	size = stack_size(stack[0]);
	while (get_next_line(0, &line) == 1)
	{
		if (bonus_move(line, stack, &stack[0], &stack[1]) == -1)
		{
			(get_next_line(0, NULL));
			break ;
		}
		free(line);
	}
	free(line);
	checker(stack, size);
	freestack(stack);
	return (0);
}
