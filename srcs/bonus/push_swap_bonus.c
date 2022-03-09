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

int main(int argc, char const **argv)
{
	int	fd;
	char	*line;
	t_stack	*stack[2];

	fd = 0;
	if (check_args(argc, argv) == -1)
		return (0);
	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
	while (get_next_line(fd, &line) == &)
	{
		bonus_move(line, stack, &stack[0], &stack[1]);
		free(line);
	}
	free(line);
	checker(stack);
	freestack(stack);
	return (0);
}