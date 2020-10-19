/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_update_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/10/18 18:17:45 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_rooms		*lst_room_update_id(t_lst_rooms *tf)
{
	t_lst_rooms	*temp_lst;
	int			c;
	int			flag;
	static	int i;

	if (i)
		return (tf);
	c = 1;
	flag = 0;
	temp_lst = tf;
	while (temp_lst)
	{
		if (temp_lst->ex == 0)
		{
			temp_lst->id = 0;
			flag++;
		}
		else if (temp_lst->ex == 1)
		{
			temp_lst->id = lst_room_length(tf) - 3;
			flag++;
		}
		else if (temp_lst->id != -1)
			temp_lst->id = c++;
		temp_lst = temp_lst->next;
	}
	IF_TRUE(flag != 2, lemin_error());
	i++;
	return (tf);
}
