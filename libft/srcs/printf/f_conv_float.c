/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:57:55 by jsprouts          #+#    #+#             */
/*   Updated: 2020/02/22 15:48:29 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_str(t_float *fl)
{
	t_big_int	*tmp;
	t_big_int	*tmp1;

	if (!(tmp = read_ull(fl->m)))
		return (1);
	if (!(tmp1 = pow_mult(tmp, 5, 63)))
		return (mem_error_int(tmp));
	big_int_del(tmp);
	if (fl->e < 16383)
	{
		if (!(tmp = pow_mult(tmp1, 10, 16383 - fl->e)))
			return (mem_error_int(tmp1));
		big_int_del(tmp1);
		tmp1 = tmp;
	}
	if (!(tmp = pow_mult(tmp1, 2, fl->e - 16383)))
		return (mem_error_int(tmp1));
	if (!(fl->str = big_int_tostr(tmp)))
		return (mem_error4(tmp, tmp1));
	big_int_del(tmp1);
	big_int_del(tmp);
	return (0);
}

int		ft_round(char **intpart, char *fraction, int end)
{
	char	*new;

	if (!(*intpart) || !(fraction))
		return (1);
	while (fraction[end] == '9' && end >= 0 && (fraction[end] = '0'))
		end--;
	if (end >= 0)
		fraction[end] += 1;
	else if ((end = ft_strlen(*intpart) - 1) >= 0)
	{
		while ((*intpart)[end] == '9' && end >= 0)
		{
			(*intpart)[end] = '0';
			end--;
		}
		if (end >= 0)
			(*intpart)[end] += 1;
		else
			return (help_round(intpart, &new, fraction));
	}
	return (0);
}

int		get_fstr(t_params *params, t_float *fl)
{
	int		point;
	int		flen;

	flen = ft_strlen(fl->str);
	point = flen - 63 + ((fl->e < 16383) ? fl->e - 16383 : 0);
	if (flen - point < params->preci)
		if (!(fl->str = add_suffix(fl->str, params->preci -
		(flen - point), '0')))
			return (1);
	if (point > 0)
	{
		fl->intpart = ft_strndup(fl->str, point);
		fl->fraction = ft_strndup(fl->str + point, params->preci);
		if (fl->str[point + params->preci] > '4')
			if (ft_round(&(fl->intpart), fl->fraction, params->preci - 1))
				return (1);
	}
	else
		return (fstr_help(params, fl, point, flen));
	return (0);
}

int		float_handler(t_params *params, t_float *fl)
{
	free(fl->str);
	if (params->preci || params->alt)
		if (!(fl->intpart = add_suffix(fl->intpart, 1, '.')))
			return (1);
	fl->str = ft_strjoin(fl->intpart, fl->fraction);
	free(fl->intpart);
	free(fl->fraction);
	return (0);
}

int		conv_float(t_params *params)
{
	t_float		*fl;

	if (!(fl = get_fl(params)))
		return (mem_error(params));
	if (get_str(fl))
		return (mem_error2(params, fl));
	if (params->preci_bool == 'n')
		params->preci = 6;
	else if (params->preci < 0)
		params->preci = 0;
	if (get_fstr(params, fl))
		return (mem_error2(params, fl));
	if (float_handler(params, fl))
		return (mem_error2(params, fl));
	params->str = fl->str;
	if (fl->sign)
		params->sign = -1;
	free(fl);
	return (0);
}
