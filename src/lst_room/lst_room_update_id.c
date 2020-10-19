/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_update_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/10/19 20:02:57 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_rooms		*lst_room_update_id(t_lst_rooms *tf)
{
	t_lst_rooms	*temp_lst;
	static int	c;
	int			flag;

	if (c++)
		return (tf);
	flag = 0;
	temp_lst = tf;
	while (temp_lst)
	{
		if (temp_lst->ex == 0 && ++flag)
			temp_lst->id = 0;
		else if (temp_lst->ex == 1 && ++flag)
			temp_lst->id = lst_room_length(tf) - 3;
		else if (temp_lst->id != -1)
			temp_lst->id = c++;
		temp_lst = temp_lst->next;
	}
	if (flag != 2)
		lemin_error();
	return (tf);
}
