/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:41:03 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 16:41:05 by vcaterpi         ###   ########.fr       */
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
		result->text = lem->text;
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
	lem->text = NULL;
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
	POTENTIAL = NULL;
	ANTS_NUM = -1;
	ANTS = NULL;
	ROOMS_NUM = -1;
	PATH_NUM = 0;
	STEPS = INF;
	lem->text = NULL;
	lem->arr_ants = NULL;
	lem->arr_path = NULL;
	lem->arr_room = NULL;
	ROOMS = lst_room_create();
	PATH = NULL;
	ERROR = 0;
	return (lem);
}
