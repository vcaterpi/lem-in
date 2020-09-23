/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/23 21:02:48 by air_must         ###   ########.fr       */
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
		if(temp_lst->path_id != -1)
			array[temp_lst->path_id] = temp_lst;
		temp_lst = temp_lst->next;
	}
	return (array);
}
