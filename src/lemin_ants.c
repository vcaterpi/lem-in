/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:00:38 by slynell           #+#    #+#             */
/*   Updated: 2020/09/23 00:18:23 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void			path_ants_create(t_lemin *lem, t_lst_path *path)
{
	int i;

	if (!(path->ants = (int*)malloc(sizeof(int) * ANTS_NUM)))
		lemin_error();
	i = -1;
	while(++i < ANTS_NUM)
		path->ants[i] = -1;
}

void			distribution_ants(t_lemin *lem)
{
	int			i;
	int			mini;
	int			id;
	t_lst_path	*path;

	i = -1;
	while (++i < ANTS_NUM)
	{
		path = PATH;
		mini = INT32_MAX;
		id = 0;
		while (path)
		{
			if (path->counter < mini)
			{
				mini = path->counter;
				id = path->path_id;
			}
			path = path->next;
		}
		lst_ants_get_by_id(ANTS, i)->path_id = id;
		path = lst_path_get_by_id(PATH, id);
		path->counter++;
		if (!path->ants)
			path_ants_create(lem, path);
		path->ants[path->counter - path->length - 1] = i; 
	}
	return ;
}
