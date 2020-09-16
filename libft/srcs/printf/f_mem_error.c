/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mem_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:58:26 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 15:50:28 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			mem_error(t_params *params)
{
	params->mem_error = 1;
	return (0);
}

int			mem_error2(t_params *params, t_float *fl)
{
	params->mem_error = 1;
	if (fl->str)
		free(fl->str);
	if (fl->intpart)
		free(fl->intpart);
	if (fl->fraction)
		free(fl->fraction);
	free(fl);
	return (1);
}

char		*mem_error3(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

int			mem_error4(t_big_int *tmp, t_big_int *tmp1)
{
	big_int_del(tmp1);
	big_int_del(tmp);
	return (1);
}

t_big_int	*mem_error_bi(t_big_int *new)
{
	big_int_del(new);
	return (NULL);
}
