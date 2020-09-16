/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_big_int_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:57:43 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 16:07:21 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_prefix(char *str, int count, char c)
{
	char	*zero_str;
	char	*res;

	if (count <= 0)
		return (str);
	if (!(zero_str = ft_strnew(count)))
		return (NULL);
	ft_memset(zero_str, c, count);
	res = ft_strjoin(zero_str, str);
	free(str);
	free(zero_str);
	return (res);
}

char	*ft_strstick(char **arr, int len, int size)
{
	int		i;
	int		j;
	int		start;
	int		clen;
	char	*res;

	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	i = size;
	start = 0;
	while (i--)
	{
		j = 0;
		clen = (i == size - 1) ? ft_strlen(arr[i]) : 9;
		while (j < clen)
		{
			res[start + j] = arr[i][j];
			j++;
		}
		start += clen;
		free(arr[i]);
	}
	res[start] = 0;
	return (res);
}

char	*big_int_tostr(t_big_int *b_int)
{
	char	**arr;
	char	*res;
	int		len;
	int		clen;
	int		i;

	len = 0;
	if (!(arr = (char **)malloc(b_int->size * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < b_int->size)
	{
		arr[i] = ft_itoa((b_int->arr)[i]);
		clen = ft_strlen(arr[i]);
		if (!(arr[i] = add_prefix(arr[i], i < b_int->size - 1 ?
			(9 - clen) : -1, '0')))
			return (mem_error3(arr));
		i++;
	}
	len = 9 * (i - 1) + ft_strlen(arr[b_int->size - 1]);
	if (!(res = ft_strstick(arr, len, b_int->size)))
		return (mem_error3(arr));
	free(arr);
	return (res);
}
