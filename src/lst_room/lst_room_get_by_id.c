/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_get_by_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:53:27 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_point		*lst_get_by_id(t_lst_point *lst, int point_id)
{
	t_lst_point	*temp_lst;

	temp_lst = lst_get_start(lst);
	while (temp_lst)
	{
		if (temp_lst->id == point_id)
			return (temp_lst);
		temp_lst = temp_lst->next;
	}
	return (NULL);
}
