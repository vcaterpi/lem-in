/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pf_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:59:00 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 15:45:39 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_suffix(char *str, int count, char c)
{
	char	*zero_str;
	char	*res;

	if (count <= 0)
		return (str);
	if (!(zero_str = ft_strnew(count)))
	{
		free(str);
		return (NULL);
	}
	ft_memset(zero_str, c, count);
	res = ft_strjoin(str, zero_str);
	free(str);
	free(zero_str);
	return (res);
}
