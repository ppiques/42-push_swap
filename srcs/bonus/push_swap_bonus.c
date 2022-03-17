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
	int		fd;
	int		size;
	char	*line;
	t_stack	*stack[2];

	fd = 0;
	if (argc <= 1)
		return (-1);
	if (check_args(argv) == -1)
		return (-1);
	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
	size = stack_size(stack[0]);
	while (get_next_line(fd, &line) == 1)
	{
		bonus_move(line, stack, &stack[0], &stack[1]);
		free(line);
	}
	free(line);
	checker(stack, size);
	freestack(stack);
	return (0);
}
