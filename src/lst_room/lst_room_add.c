/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/22 14:21:59 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_rooms		*lst_room_add(t_lst_rooms *lst)
{
	t_lst_rooms	*temp_lst;

	temp_lst = lst_room_create();
	temp_lst->next = lst;
	lst->prev = temp_lst;
	lst = lst->prev;
	return (lst);
}
