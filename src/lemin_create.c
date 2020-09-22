/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/22 23:29:37 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_lemin		*lemin_create(void)
{
	t_lemin	*lem;

	if (!(lem = (t_lemin *)malloc(sizeof(t_lemin))))
		lemin_error();
	CAP_MATRIX = NULL;
	PARENT = NULL;
	FLOW_MATRIX = NULL;
	ANTS_NUM = -1;
	ANTS = NULL;
	ROOMS_NUM = -1;
	PATH_NUM = 0;
	ROOMS = lst_room_create();
	PATH = NULL;
	return (lem);
}
