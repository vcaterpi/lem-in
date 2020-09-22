/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/22 16:11:27 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_room_free(t_lst_rooms *lst)
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
