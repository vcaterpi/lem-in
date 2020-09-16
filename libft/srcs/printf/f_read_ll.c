/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:59:14 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 12:59:15 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_unumsize(unsigned long long n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		n /= BASE;
		size++;
	}
	return (size);
}

t_big_int	*read_ull(unsigned long long n)
{
	t_big_int		*big_int;
	int				i;

	big_int = (t_big_int *)malloc(sizeof(t_big_int));
	if (!big_int)
		return (NULL);
	big_int->sign = 1;
	big_int->size = get_unumsize(n);
	big_int->arr = (int *)malloc(big_int->size * sizeof(int));
	if (!big_int->arr)
	{
		free(big_int);
		return (NULL);
	}
	i = 0;
	while (n)
	{
		(big_int->arr)[i] = n % BASE;
		n /= BASE;
		i++;
	}
	if (i == 0)
		(big_int->arr)[0] = 0;
	return (big_int);
}
