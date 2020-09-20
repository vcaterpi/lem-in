
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:05:45 by antondob          #+#    #+#             */
/*   Updated: 2020/09/20 22:15:10 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"


void distribution_ants(t_lemin *lem)
{
	int	i;
	int mini;
	int id;
	t_lst_path *path;

	i = -1;
	while(++i < ANTS_NUM)
	{
		path = PATH;
		mini = INT32_MAX;
		id = 0;
		while(path)
		{
			if(path->counter < mini)
			{
				mini = path->counter;
				id = path->path_id;
			}
			path = path->next;
		}
		lst_ants_get_by_id(ANTS, i)->path_id = id;
		lst_path_get_by_id(PATH, id)->counter++;
	}
	return ;
}
