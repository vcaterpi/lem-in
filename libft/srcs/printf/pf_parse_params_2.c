/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_params_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:42:14 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 14:20:07 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_flags(t_params *params)
{
	int f;

	f = 0;
	if (*(params->format) == '-')
		(params->align = 'l') && (f++);
	else if (*(params->format) == '+')
		(params->sign = 1) && (f++);
	else if (*(params->format) == ' ')
		(params->space = 1) && (f++);
	else if (*(params->format) == '#')
		(params->alt = 1) && (f++);
	else if (*(params->format) == '0')
		(params->nul = 1) && (f++);
	if (f == 1)
		params->format++;
	return (f ? 1 : 0);
}
