/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:44:10 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 14:11:44 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	process_conv_spec(t_params *params)
{
	parse_params(params);
	if (params->error == 1)
		return ;
	process_arguments(params);
	apply_flags(params);
	if (params->mem_error == 1)
		return ;
	print_string(params);
	clean_params(params);
}

int		ft_printf(const char *format, ...)
{
	t_params	params;

	va_start(params.ap, format);
	init_params(&params, (char*)format);
	while (*(params.format))
	{
		if (*(params.format) != '%')
			print_char(&params, *(params.format));
		else
		{
			process_conv_spec(&params);
			if (params.error || params.mem_error)
				break ;
		}
		if (!*(params.format))
			break ;
		(params.format)++;
	}
	clean_params(&params);
	print_errors(&params);
	va_end(params.ap);
	return (params.ret);
}
