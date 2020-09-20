/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_by_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/18 02:17:47 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_point *lst_get_by_name(t_lst_point *lst, char *name)
{
	t_lst_point *temp_lst;

	temp_lst = lst_get_start(lst);
	while (temp_lst)
	{
		if (temp_lst->id != -1 && ft_strequ(temp_lst->name, name))
			return (temp_lst);
		temp_lst = temp_lst->next;
	}
	return (NULL);
}
