/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:34:35 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/10/04 20:24:06 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t dlen;

	dlen = ft_strlen(dst);
	if (n > dlen)
		ft_strncat(dst, src, (n - dlen - 1));
	if (n < dlen)
		return (ft_strlen(src) + n);
	return (dlen + ft_strlen(src));
}
