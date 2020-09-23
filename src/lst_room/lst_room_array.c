/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/23 21:13:25 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_rooms		**lst_room_array(t_lst_rooms *lst, int size)
{
	t_lst_rooms	*temp_lst;
	t_lst_rooms	**array;
	int			i;

	i = 0;
	temp_lst = lst_room_get_start(lst);
	array = (t_lst_rooms**)malloc(sizeof(t_lst_rooms*) * size);
	while (temp_lst)
	{
		if(temp_lst->id != -1)
			array[temp_lst->id] = temp_lst;
		temp_lst = temp_lst->next;
	}
	return (array);
}
