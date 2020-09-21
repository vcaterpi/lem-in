/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_get_by_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:49:44 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_path	*lst_path_get_by_id(t_lst_path *lst, int path_id)
{
	t_lst_path *temp_lst;

	temp_lst = lst_path_get_start(lst);
	while (temp_lst)
	{
		if (temp_lst->path_id == path_id)
			return (temp_lst);
		temp_lst = temp_lst->next;
	}
	return (NULL);
}
