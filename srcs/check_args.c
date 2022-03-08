/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:11:22 by ppiques           #+#    #+#             */
/*   Updated: 2022/02/16 12:11:22 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_limits(char const **argv)
{
    int i;

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
    return (0);
}

static int check_doubles(char const **argv)
{
    int i;
    int j;

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

int check_args(int argc, char const **argv)
{
    int i;
    int j;

    i = 1;
	j = 0;
    if (argc <= 1)
        return (-1);
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

int check_order(t_stack *stack)
{
    int temp;
    t_stack *current;

    current = stack;
    temp = 0;
    if (current != NULL)
    {
        temp = current->nbr;
        current = current->next;
    }
    while (current != NULL)
    {
        if (temp > current->nbr)
            return (0);
        temp = current->nbr;
        current = current->next;
    }
    return (1);
}