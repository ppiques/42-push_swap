/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:59:51 by ppiques           #+#    #+#             */
/*   Updated: 2022/01/31 12:59:51 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char const **argv)
{
    t_stack *stack[2];

    stack[0] = NULL;
    stack[1] = NULL;
    if (check_args(argc, argv) == -1)
        return (0);
    
    return (0);
}