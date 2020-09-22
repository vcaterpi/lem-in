/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/22 16:11:59 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int	lst_room_check(t_lst_rooms *lst)
{
	t_lst_rooms	*temp_lst;
	int			c;

	c = 0;
	temp_lst = lst_room_get_start(lst);
	while (temp_lst && temp_lst->next)
	{
		if ((ft_strequ(lst->name, temp_lst->name) ||\
			(lst->x == temp_lst->x && lst->y == temp_lst->y) ||\
			(lst->ex == temp_lst->ex && lst->ex > -1)) &&\
			lst->id != temp_lst->id)
		{
			lemin_error();
		}
		temp_lst = temp_lst->next;
	}
	return (1);
}
