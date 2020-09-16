/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:38:07 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/09/26 22:16:38 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_nbrrecurs(int nbr)
{
	if (nbr == 0)
		return ;
	ft_nbrrecurs(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void			ft_putnbr(int nbr)
{
	if (nbr == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= (-1);
	}
	ft_nbrrecurs(nbr);
}
