/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:18:39 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:30:28 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst - src < (int)n)
		while ((int)(--n) >= 0)
			((unsigned char*)dst)[n] = ((unsigned char*)src)[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
