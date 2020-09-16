/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:25:10 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/09/23 02:16:41 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	while ((int)i >= 0)
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		i--;
	}
	return (NULL);
}
