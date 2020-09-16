/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:29:12 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:29:27 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_up(int nbr)
{
	int rem;

	if (nbr < 16)
	{
		ft_putchar(nbr % 16 + '0');
		return ;
	}
	ft_puthex_up(nbr / 16);
	rem = nbr % 16;
	ft_putchar(rem >= 10 ? 'A' + rem - 10 : rem + '0');
}
