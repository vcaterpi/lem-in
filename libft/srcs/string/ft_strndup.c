/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:08:38 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:35:01 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int i)
{
	char	*dst;

	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	dst[i] = 0;
	while (--i >= 0)
		dst[i] = str[i];
	return (dst);
}
