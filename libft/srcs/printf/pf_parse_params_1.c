/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_params_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:56:46 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 14:23:54 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		parse_width(t_params *params)
{
	params->width = (*(params->format) >= 48 &&
		*(params->format) <= 57 ? ft_atoi(params->format) : 0);
	if (params->width < 0)
	{
		params->width = 0;
		(params->format)++;
	}
	while (*(params->format) >= 48 && *(params->format) <= 57)
		params->format++;
}

void		parse_preci(t_params *params)
{
	if (*(params->format) == '.')
	{
		params->preci = ft_atoi(++(params->format));
		params->preci_bool = 'y';
	}
	else
		params->preci_bool = 'n';
	if (*(params->format) == '-')
		params->format++;
	while (*(params->format) >= 48 && *(params->format) <= 57)
		params->format++;
}

void		parse_length(t_params *params)
{
	if (*(params->format) == 'h')
	{
		if (*(params->format + 1) == 'h')
		{
			params->length = 'h' + 'h';
			params->format++;
		}
		else
			params->length = 'h';
	}
	else if (*(params->format) == 'l')
	{
		if (*(params->format + 1) == 'l')
		{
			params->length = 'l' + 'l';
			params->format++;
		}
		else
			params->length = 'l';
	}
	else if (*(params->format) == 'L')
		params->length = 'L';
	if (params->length != 0)
		params->format++;
}

void		parse_conversion(t_params *params)
{
	if (ft_strchr("fdiouxXcsp%", *(params->format)) == NULL)
	{
		clean_params(params);
		ft_putstr("\n**invalid format string -> man 2 printf**\n");
		params->ret = -1;
		return ;
	}
	else
		params->conv_spec = *(params->format);
}

void		parse_params(t_params *params)
{
	params->format++;
	while (parse_flags(params))
		;
	parse_width(params);
	parse_preci(params);
	parse_length(params);
	parse_conversion(params);
}
