/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ants_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/23 21:06:34 by air_must         ###   ########.fr       */
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
		if(temp_lst->ant_id != -1)
			array[temp_lst->ant_id] = temp_lst;
		temp_lst = temp_lst->next;
	}
	return (array);
}
