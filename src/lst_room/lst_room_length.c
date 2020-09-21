/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:53:16 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int			lst_length(t_lst_point *lst)
{
	t_lst_point	*temp_lst;
	int			c;

	c = 0;
	temp_lst = lst_get_start(lst);
	while (temp_lst && temp_lst->next)
	{
		c++;
		temp_lst = temp_lst->next;
	}
	return (c);
}
