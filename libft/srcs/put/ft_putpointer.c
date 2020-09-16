/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:06:53 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:36:37 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putadress(long int p)
{
	long int rem;

	if (p < 16)
	{
		ft_putchar(p % 16 + '0');
		return ;
	}
	ft_putadress(p / 16);
	rem = p % 16;
	ft_putchar(rem >= 10 ? 'a' + rem - 10 : rem + '0');
}

static void		ft_putprefix(void)
{
	ft_putchar('0');
	ft_putchar('x');
}

void			ft_putpointer(long int p)
{
	ft_putprefix();
	ft_putadress(p);
}
