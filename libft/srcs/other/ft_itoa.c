/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:29:36 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/08/11 16:20:57 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_freshstr(char *str, int minus, int count)
{
	int		i;
	char	*result;

	if (!(result = (char*)malloc(sizeof(char) *
		(minus == 1 ? count + 2 : count + 1))))
		return (NULL);
	i = 0;
	if (minus)
		result[i++] = '-';
	while (count)
		result[i++] = str[--count];
	result[i] = '\0';
	return (result);
}

char			*ft_itoa(int n)
{
	char	cur;
	int		minus;
	char	str[12];
	size_t	count;

	count = 0;
	minus = (n < 0 ? 1 : 0);
	ft_bzero(str, 12);
	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	if (n == 0)
	{
		str[0] = '0';
		return (ft_strncpy(ft_strnew(1), str, 1));
	}
	else if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		cur = n % 10 + '0';
		n = n / 10;
		str[count++] = cur;
	}
	return (ft_freshstr(str, minus, count));
}
