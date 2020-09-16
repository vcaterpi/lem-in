/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pow_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:24:13 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 12:59:09 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_pow(int n, int p)
{
	int		res;

	res = 1;
	while (p--)
		res *= n;
	return (res);
}

int			maxpower(int n)
{
	unsigned long long	maxp;
	int					i;

	i = 0;
	maxp = 1;
	while (maxp < BASE)
	{
		maxp *= n;
		i++;
	}
	i--;
	return (i);
}

t_big_int	*pow_div(t_big_int *big, int b, int pow)
{
	t_big_int	*res;
	t_big_int	*new;
	int			maxp;
	int			bmaxp;
	int			p;

	maxp = maxpower(b);
	bmaxp = ft_pow(b, maxp);
	p = 0;
	b_int_copy(&new, big);
	while ((p += maxp) < pow)
	{
		res = b_int_div(new, bmaxp);
		big_int_del(new);
		new = res;
	}
	p -= maxp;
	bmaxp = ft_pow(b, pow - p);
	res = b_int_div(new, bmaxp);
	big_int_del(new);
	return (res);
}

t_big_int	*pow_mult(t_big_int *big, int b, int pow)
{
	t_big_int	*res;
	t_big_int	*new;
	int			maxp_bmaxp_p[3];

	if (pow < 0)
		return (pow_div(big, b, -pow));
	maxp_bmaxp_p[0] = maxpower(b);
	maxp_bmaxp_p[1] = ft_pow(b, maxp_bmaxp_p[0]);
	maxp_bmaxp_p[2] = 0;
	if (b_int_copy(&new, big))
		return (NULL);
	while ((maxp_bmaxp_p[2] += maxp_bmaxp_p[0]) < pow)
	{
		if (!(res = b_int_mult(new, maxp_bmaxp_p[1])))
			return (mem_error_bi(new));
		big_int_del(new);
		new = res;
	}
	maxp_bmaxp_p[2] -= maxp_bmaxp_p[0];
	maxp_bmaxp_p[1] = ft_pow(b, pow - maxp_bmaxp_p[2]);
	if (!(res = b_int_mult(new, maxp_bmaxp_p[1])))
		return (mem_error_bi(new));
	big_int_del(new);
	return (res);
}
