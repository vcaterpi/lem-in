/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:48:19 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/19 20:48:37 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	lemin_rooms_clear(t_lemin *lem)
{
	t_lst_rooms *rooms;
	t_lst_rooms *temp;

	rooms = lst_room_get_start(ROOMS);
	while (rooms)
	{
		if (rooms->id < 0)
		{
			if (!rooms->prev)
				rooms = lst_room_free_one(rooms);
			else
				rooms = lst_room_free_two(rooms);
			continue ;
		}
		if (rooms)
			temp = rooms;
		rooms = rooms->next;
	}
	ROOMS_NUM -= 2;
	ROOMS = temp;
}
