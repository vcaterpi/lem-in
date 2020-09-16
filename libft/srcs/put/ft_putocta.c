/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putocta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:03:07 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:32:27 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putocta(int nbr)
{
	if (nbr < 8)
	{
		ft_putchar(nbr % 8 + '0');
		return ;
	}
	ft_putocta(nbr / 8);
	ft_putchar(nbr % 8 + '0');
}
