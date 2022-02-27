/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:28:06 by ppiques           #+#    #+#             */
/*   Updated: 2022/02/16 12:28:06 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long int	ret;

	i = 0;
	minus = 1;
	ret = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		ret = 10 * ret + str[i++] - '0';
	if (str[i] != 0 && ft_isdigit(str[i]) == 0)
		return (0);
	ret = ret * minus;
	return (ret);
}
