/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_process_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:50:09 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:36:08 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				pf_process_str(t_params *params, char *arg)
{
	if (arg == NULL)
	{
		if (!(params->str = ft_strdup("(null)")))
			params->mem_error = 1;
		return ;
	}
	if (!(params->str = ft_strdup(arg)))
		params->mem_error = 1;
}

long long			get_signed_arg(t_params *params)
{
	if (params->length == 'h' + 'h')
		return ((long long)va_arg(params->ap, int));
	else if (params->length == 'h')
		return ((long long)va_arg(params->ap, int));
	else if (params->length == 'l')
		return ((long long)va_arg(params->ap, long));
	else if (params->length == 'l' + 'l')
		return ((long long)va_arg(params->ap, long long));
	return ((long long)va_arg(params->ap, int));
}

unsigned long long	get_unsigned_arg(t_params *params)
{
	if (params->length == 'h' + 'h')
		return ((unsigned long long)va_arg(params->ap, unsigned int));
	else if (params->length == 'h')
		return ((unsigned long long)va_arg(params->ap, unsigned int));
	else if (params->length == 'l')
		return ((unsigned long long)va_arg(params->ap, unsigned long));
	else if (params->length == 'l' + 'l')
		return ((unsigned long long)va_arg(params->ap, unsigned long long));
	return ((unsigned long long)va_arg(params->ap, unsigned int));
}

void				process_arguments(t_params *params)
{
	if (params->conv_spec == 'd' || params->conv_spec == 'i')
		pf_itoa_int(params, get_signed_arg(params));
	else if (params->conv_spec == 'u')
		pf_itoa_base(params, get_unsigned_arg(params), 10);
	else if (params->conv_spec == 'o')
		pf_itoa_base(params, get_unsigned_arg(params), 8);
	else if (params->conv_spec == 'x' || params->conv_spec == 'X')
		pf_itoa_base(params, get_unsigned_arg(params), 16);
	else if (params->conv_spec == 's')
		pf_process_str(params, (char*)va_arg(params->ap, char*));
	else if (params->conv_spec == 'c')
		pf_char_to_str(params, (int)va_arg(params->ap, int));
	else if (params->conv_spec == '%')
		pf_char_to_str(params, '%');
	else if (params->conv_spec == 'p')
	{
		params->alt = 1;
		pf_itoa_base(params, (unsigned long)va_arg(params->ap,
			unsigned long), 16);
	}
	else if (params->conv_spec == 'f')
		conv_float(params);
}
