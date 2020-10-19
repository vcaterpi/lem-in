/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/10/19 20:40:14 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_rooms	*lst_room_free_two(t_lst_rooms *rooms)
{
	t_lst_rooms *temp;

	rooms->prev->next = rooms->next;
	temp = rooms->prev;
	free(rooms->name);
	free(rooms);
	if (temp->next)
		temp->next->prev = temp;
	return (temp->next ? temp->next : temp->prev);
}

t_lst_rooms	*lst_room_free_one(t_lst_rooms *rooms)
{
	t_lst_rooms *temp;

	temp = rooms->next;
	free(rooms->name);
	free(rooms);
	rooms = temp;
	if (rooms)
		rooms->prev = 0;
	return (rooms);
}

void		lst_room_free(t_lst_rooms *lst)
{
	t_lst_rooms *temp_lst;

	if (lst)
	{
		if (lst->prev)
			lst = lst_room_get_start(lst);
		while (lst)
		{
			temp_lst = lst->next;
			free(lst->name);
			free(lst);
			lst = temp_lst;
		}
		lst = NULL;
	}
	free(lst);
	lst = NULL;
}
