/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_float_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:47:58 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 16:06:18 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		help_round(char **intpart, char **new, char *fraction)
{
	if (!(*new = ft_strnew(ft_strlen(*intpart) + 1)))
	{
		free(fraction);
		free(*intpart);
		return (1);
	}
	(*new)[0] = '1';
	ft_strcpy(*new + 1, *intpart);
	free(*intpart);
	*intpart = *new;
	return (0);
}

int		fstr_help(t_params *params, t_float *fl, int point, int flen)
{
	if (!(fl->intpart = ft_strdup("0")))
		return (1);
	flen = point + params->preci;
	fl->fraction = flen > 0 ? ft_strndup(fl->str, flen) : ft_strdup("");
	if (!(fl->fraction))
		return (1);
	fl->fraction = add_prefix(fl->fraction, flen > 0 ?
	-point : params->preci, '0');
	if (!(fl->fraction))
		return (1);
	if (fl->str[flen > 0 ? flen : 0] > '4')
		if (ft_round(&(fl->intpart), fl->fraction, params->preci - 1))
			return (1);
	return (0);
}

int		mem_error_int(t_big_int *new)
{
	big_int_del(new);
	return (1);
}
