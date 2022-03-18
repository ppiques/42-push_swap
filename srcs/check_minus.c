/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:09:39 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/18 18:18:08 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_minus_in_arg(char const **argv, int i, int j)
{
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (j != 0)
				{
					write(2, "Error\n", 6);
					return (-1);
				}
				if (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
				{
					write(2, "Error\n", 6);
					return (-1);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_minus(char const **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (check_minus_in_arg(argv, i, j) == -1)
		return (-1);
	return (0);
}
