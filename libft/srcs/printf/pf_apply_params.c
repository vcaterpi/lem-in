/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:53:05 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 14:25:25 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_precision(t_params *params)
{
	char	*nul;
	int		len;

	len = ft_strlen(params->str);
	if (params->preci_bool == 'n' || params->preci == len ||
		(params->conv_spec != 's' && params->preci <= len))
		return ;
	if (params->conv_spec == 's' || params->conv_spec == 'c')
	{
		if (params->preci < 0)
		{
			free(params->str);
			len = params->preci * (-1);
			params->str = ft_strnew(len);
			ft_strfill(params->str, ' ', len);
		}
		else if (params->preci >= 0 && params->preci < len)
			params->str = ft_strsub_free(params->str, 0, params->preci);
		return ;
	}
	len = params->preci - len;
	nul = ft_strnew(len);
	ft_strfill(nul, '0', len);
	params->str = ft_strjoin_free(nul, params->str);
}

void	apply_sign(t_params *params)
{
	if (!params->str)
		return ;
	if (params->sign == -1)
		params->str = ft_strjoin_free(ft_strdup("-"), params->str);
	else if (ft_strchr("dif", params->conv_spec))
	{
		if (params->sign == 1 && *(params->str) != '-')
			params->str = ft_strjoin_free(ft_strdup("+"), params->str);
		else if (params->space == 1 && *(params->str) != '-')
			params->str = ft_strjoin_free(ft_strdup(" "), params->str);
	}
}

void	apply_width(t_params *params)
{
	int		len;
	char	filler;
	char	*tmp;

	if (!params->str)
		return ;
	filler = ' ';
	len = ft_strlen(params->str);
	if (params->width <= len)
		return ;
	len = params->width - len - 2 * (params->alt == 1 &&
		ft_strchr("xX", params->conv_spec) &&
		*(params->str) != '0' && !ft_strchr("xX", *(params->str + 1)))
		- ((params->sign != 0 || params->space == 1) &&
		ft_strchr("dif", params->conv_spec) &&
		!ft_strchr("+- ", *(params->str))) - (params->char_nul == 1);
	tmp = ft_strnew(len);
	if (params->align == 'r' && params->nul == 1 && (params->preci_bool == 'n'
		|| (params->preci_bool == 'y' && params->conv_spec == 'f')))
		filler = '0';
	ft_strfill(tmp, filler, len);
	params->str = (params->align == 'l' ? ft_strjoin_free(params->str, tmp) :
		ft_strjoin_free(tmp, params->str));
}

void	apply_alternative(t_params *params)
{
	if (!params->str)
		return ;
	if (params->alt != 1)
		return ;
	if (params->conv_spec == 'o' && *(params->str) != '0')
		params->str = ft_strjoin_free(ft_strdup("0"), params->str);
	else if (params->conv_spec == 'x' || params->conv_spec == 'p')
		params->str = ft_strjoin_free(ft_strdup("0x"), params->str);
	else if (params->conv_spec == 'X')
		params->str = ft_strjoin_free(ft_strdup("0X"), params->str);
}

void	apply_flags(t_params *params)
{
	if (!params->str && !(params->str = ft_strnew(0)))
		return ;
	apply_precision(params);
	if ((params->sign != 0 || params->alt == 1 ||
		params->space == 1) && params->nul == 1 &&
		(params->preci_bool == 'n' || (params->preci_bool == 'y' &&
		params->conv_spec == 'f')))
	{
		apply_width(params);
		apply_sign(params);
		apply_alternative(params);
		return ;
	}
	apply_sign(params);
	apply_alternative(params);
	apply_width(params);
	if (!params->str)
		params->mem_error = 1;
}
