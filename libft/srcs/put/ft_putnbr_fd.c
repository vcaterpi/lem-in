/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:00:55 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/09/26 22:16:40 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_nbrrecurs_fd(int nbr, int fd)
{
	if (nbr == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= (-1);
	}
	ft_nbrrecurs_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

void			ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	ft_nbrrecurs_fd(nbr, fd);
}
