/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/18 18:29:17 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int lst_check(t_lst_point *lst)
{
	t_lst_point *temp_lst;
	int c;

	c = 0;
	temp_lst = lst_get_start(lst);
	while (temp_lst && temp_lst->next)
	{
		if ((ft_strequ(lst->name, temp_lst->name) ||
			 (lst->x == temp_lst->x && lst->y == temp_lst->y) ||
			 (lst->ex == temp_lst->ex && lst->ex > -1)) &&
			lst->id != temp_lst->id)
		{
			ft_printf("%d -> %d", temp_lst->id, lst->id);
			return (0);
		}
		temp_lst = temp_lst->next;
	}
	return (1);
}
