/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ants_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:49:40 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/15 17:50:09 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_ants		**lst_ants_array(t_lst_ants *lst, int size)
{
	t_lst_ants	*temp_lst;
	t_lst_ants	**array;
	int			i;

	i = 0;
	temp_lst = lst_ants_get_start(lst);
	array = (t_lst_ants**)malloc(sizeof(t_lst_ants*) * size);
	while (temp_lst)
	{
		if (temp_lst->ant_id != -1)
			array[temp_lst->ant_id] = temp_lst;
		temp_lst = temp_lst->next;
	}
	return (array);
}
