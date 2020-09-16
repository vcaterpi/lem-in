/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:57:21 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 14:17:22 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_itoa_nul(t_params *params)
{
	if ((params->str = ft_strnew(1)))
	{
		*(params->str) = (params->preci_bool == 'n' ? '0' : 0);
		if (params->conv_spec != 'o' && params->conv_spec != 'p')
			params->alt = 0;
	}
	else
		params->mem_error = 1;
}

void	pf_itoa_base(t_params *params, unsigned long long arg, int base)
{
	int		curr;
	char	str[30];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (params->length == 'h' + 'h')
		arg = (unsigned char)arg;
	if (params->length == 'h')
		arg = (unsigned short)arg;
	if (arg == 0)
		pf_itoa_nul(params);
	if (arg == 0)
		return ;
	while (arg > 0)
	{
		curr = arg % base;
		arg = arg / base;
		str[i++] = (base == 16 && curr >= 10 ? 'a' + curr -
			32 * (params->conv_spec == 'X') - 10 : curr + '0');
		len++;
	}
	str[i] = '\0';
	params->str = ft_reverse_str(str);
}

void	pf_itoa_int(t_params *params, long long arg)
{
	if (params->length == 'h' + 'h')
		arg = (signed char)arg;
	if (params->length == 'h')
		arg = (short int)arg;
	if (arg < 0)
	{
		params->sign = -1;
		arg = arg * (-1);
	}
	pf_itoa_base(params, (unsigned long long)arg, 10);
}
