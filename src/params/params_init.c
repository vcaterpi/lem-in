/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 22:52:46 by antondob          #+#    #+#             */
/*   Updated: 2020/09/19 16:17:29 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Инициализируем все переменные, входящие в структуру lemin
*/

void	params_init(t_lemin *params)
{
	ROOMS_NUM = 0;
	ANTS_NUM = 0;
	ERROR = 0;
	FLOW_MATRIX = NULL;
	CAP_MATRIX = NULL;
	PARENT = NULL;
	POINT = NULL;
}

/*
** Очищаем память, веделенную под все параметры lemin
*/

void	params_free(t_lemin *params)
{
	ft_delete_table(&CAP_MATRIX, ROOMS_NUM);
	ft_delete_table(&FLOW_MATRIX, ROOMS_NUM);
	free(PARENT);
	PARENT = NULL;
}
