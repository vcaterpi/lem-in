/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:31:15 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/15 16:31:35 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_path		**lst_path_array(t_lst_path *lst, int size)
{
	t_lst_path	*temp_lst;
	t_lst_path	**array;
	int			i;

	i = 0;
	temp_lst = lst_path_get_start(lst);
	array = (t_lst_path**)malloc(sizeof(t_lst_path*) * size);
	while (temp_lst)
	{
		if (temp_lst->path_id != -1)
			array[temp_lst->path_id] = temp_lst;
		temp_lst = temp_lst->next;
	}
	return (array);
}
