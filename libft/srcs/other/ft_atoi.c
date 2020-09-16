/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:57:18 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/08/03 23:48:18 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_skiptab(const char *str, int *i)
{
	while (((str[*i] > 8) && (str[*i] < 14)) || str[*i] == 32)
	{
		(*i)++;
	}
}

int				ft_atoi(const char *str)
{
	int sign;
	int i;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	ft_skiptab(str, &i);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
		result = result * 10 + (int)str[i++] - 48;
	return (result * sign);
}
