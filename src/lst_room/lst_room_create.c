/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 16:10:44 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_rooms		*lst_room_create(void)
{
	t_lst_rooms	*lst;

	if (!(lst = (t_lst_rooms *)malloc(sizeof(t_lst_rooms))))
		lemin_error();
	lst->name = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	lst->x = -1;
	lst->y = -1;
	lst->ex = -1;
	lst->id = -1;
	return (lst);
}
