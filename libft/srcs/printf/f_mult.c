/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mult.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:58:51 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 12:58:52 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_big_int	*b_int_div(t_big_int *b_int, int d)
{
	t_big_int			*res;
	unsigned long long	n;
	unsigned long long	tmp;
	unsigned long long	mem;
	int					i;

	b_int_copy(&res, b_int);
	i = b_int->size;
	mem = 0;
	while (i--)
	{
		tmp = (res->arr)[i];
		n = mem * BASE + tmp;
		(res->arr)[i] = n / d;
		mem = n % d;
	}
	if ((res->arr)[res->size - 1] == 0 && res->size > 1)
		b_int_unshift(&res);
	return (res);
}

t_big_int	*b_int_mult(t_big_int *b_int, int m)
{
	t_big_int			*res;
	unsigned long long	mult;
	int					i;
	unsigned long long	mem;

	if (b_int_copy(&res, b_int))
		return (NULL);
	i = 0;
	mem = 0;
	while (i < res->size)
	{
		mult = (unsigned long long)m * res->arr[i];
		res->arr[i] = (mult + mem) % BASE;
		mem = (mult + mem) / BASE;
		i++;
	}
	if (mem)
		if (b_int_push(&res, mem))
			return (NULL);
	return (res);
}
