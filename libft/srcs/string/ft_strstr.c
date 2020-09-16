/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:49:50 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/09/23 22:09:35 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t i;
	size_t k;

	i = 0;
	if (str2[0] == '\0')
		return ((char*)str1);
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[0])
		{
			k = i;
			while ((str1[k] == str2[k - i]) && (str2[k - i] != '\0'))
				k++;
			if (str2[k - i] == '\0')
				return ((char*)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
