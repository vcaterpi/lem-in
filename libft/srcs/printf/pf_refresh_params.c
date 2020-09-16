/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_refresh_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:17:50 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:36:10 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	clean_params(t_params *params)
{
	params->sign = 0;
	params->align = 'r';
	params->space = 0;
	params->alt = 0;
	params->nul = 0;
	params->char_nul = 0;
	params->width = 0;
	params->preci = 0;
	params->preci_bool = 'n';
	params->length = 0;
	params->conv_spec = 0;
	free(params->str);
	params->str = NULL;
	params->error = 0;
}

void	init_params(t_params *params, char *format)
{
	params->format = format;
	params->sign = 0;
	params->align = 'r';
	params->space = 0;
	params->alt = 0;
	params->nul = 0;
	params->char_nul = 0;
	params->width = 0;
	params->preci = 0;
	params->preci_bool = 'n';
	params->length = 0;
	params->conv_spec = 0;
	params->ret = 0;
	params->str = NULL;
	params->error = 0;
	params->mem_error = 0;
}
