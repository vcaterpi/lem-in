/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/10/16 21:15:57 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int			lst_room_length(t_lst_rooms *lst)
{
	t_lst_rooms	*temp_lst;
	int			c;

	c = 0;
	temp_lst = lst_room_get_start(lst);
	if (temp_lst && !temp_lst->next)
		return (1);
	while (temp_lst && ++c)
		temp_lst = temp_lst->next;
	return (c);
}
