/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:27:50 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:35:44 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_char_to_str(t_params *params, int c)
{
	char *str;

	if (!(str = ft_strnew(2)))
	{
		params->mem_error = 1;
		return ;
	}
	if (c == 0)
		params->char_nul = 1;
	str[0] = c;
	str[1] = '\0';
	params->str = str;
}
