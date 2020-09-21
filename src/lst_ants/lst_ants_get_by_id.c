/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ants_get_by_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:55:32 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_ants		*lst_ants_get_by_id(t_lst_ants *lst, int ant_id)
{
	t_lst_ants	*temp_lst;

	temp_lst = lst_ants_get_start(lst);
	while (temp_lst)
	{
		if (temp_lst->ant_id == ant_id)
			return (temp_lst);
		temp_lst = temp_lst->next;
	}
	return (NULL);
}
