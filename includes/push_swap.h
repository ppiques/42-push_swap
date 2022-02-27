/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:28:23 by ppiques           #+#    #+#             */
/*   Updated: 2022/01/31 13:28:23 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "utils.h"

typedef struct s_stack
{
    int pos;
    int value;
    int target;
    int dist;
    int up;
    struct s_stack *next;
}   t_stack;


//  check_args.c
int check_args(int argc, char const **argv);

#endif