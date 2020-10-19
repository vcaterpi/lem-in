/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/10/18 18:10:52 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_lemin		*lemin_backup(t_lemin *result, t_lemin *lem, int steps)
{
	if (!(result))
	{
		result = lemin_create();
		lst_room_free(result->rooms);
		result->rooms = ROOMS;
		result->rooms_num = ROOMS_NUM;
		result->ants_num = ANTS_NUM;
		result->capacity_matrix = ft_copy_matrix(CAP_MATRIX, ROOMS_NUM);
	}
	if (steps > result->steps_num)
		return (result);
	lst_ants_free(result->ants);
	lst_path_free(result->path);
	result->steps_num = steps;
	result->path = PATH;
	result->ants = ANTS;
	result->path_num = PATH_NUM;
	PATH = NULL;
	ANTS = NULL;
	ROOMS = NULL;
	PATH_NUM = 0;
	return (result);
}

t_lemin		*lemin_create(void)
{
	t_lemin	*lem;

	if (!(lem = (t_lemin *)malloc(sizeof(t_lemin))))
		lemin_error();
	CAP_MATRIX = NULL;
	PARENT = NULL;
	FLOW_MATRIX = NULL;
	WEIGHT_MATRIX = NULL;
	DISTANCE = NULL;
	ANTS_NUM = -1;
	ANTS = NULL;
	ROOMS_NUM = -1;
	PATH_NUM = 0;
	STEPS = INF;
	lem->arr_ants = NULL;
	lem->arr_path = NULL;
	lem->arr_room = NULL;
	ROOMS = lst_room_create();
	PATH = NULL;
	ERROR = 0;
	return (lem);
}
