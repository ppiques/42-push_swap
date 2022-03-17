/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:25:00 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/09 18:25:00 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_minus_in_arg(char const **argv, int i, int j)
{
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
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

static int	check_limits(char const **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi (argv[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	if (check_minus(argv) == -1)
		return (-1);
	return (0);
}

static int	check_doubles(char const **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strncmp(argv[i], argv[j], 20) == 0)
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char const **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (check_limits(argv) == -1)
		return (-1);
	if (check_doubles(argv) == -1)
		return (-1);
	return (0);
}
