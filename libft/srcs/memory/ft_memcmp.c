/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:00:58 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/09/25 22:50:44 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t i;

	if (!n)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		if (((unsigned char*)buf1)[i] != ((unsigned char*)buf2)[i])
			break ;
		i++;
	}
	return (((unsigned char*)buf1)[i] - ((unsigned char*)buf2)[i]);
}
