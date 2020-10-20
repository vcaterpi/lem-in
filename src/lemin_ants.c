/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:00:38 by slynell           #+#    #+#             */
/*   Updated: 2020/10/20 20:13:32 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		refresh_ants(t_lemin *lem)
{
	lst_ants_free(ANTS);
	ANTS = create_ants(lem);
	distribution_ants(lem);
}

t_lst_ants	*create_ants(t_lemin *lem)
{
	int			i;
	t_lst_ants	*ants;

	i = 0;
	ants = lst_ants_create();
	ants->ant_id = 0;
	while (++i < ANTS_NUM)
	{
		ants = lst_ants_add(ants);
		ants->ant_id = i;
	}
	return (lst_ants_get_start(ants));
}

void		path_ants_create(t_lemin *lem, t_lst_path *path)
{
	int i;

	if (!(path->ants = (int*)malloc(sizeof(int) * ANTS_NUM)))
		lemin_error();
	i = -1;
	while (++i < ANTS_NUM)
		path->ants[i] = -1;
}

int			path_for_next_ant(t_lemin *lem)
{
	t_lst_path	*path;
	int			id;
	int			mini;

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
	return (id);
}

void		distribution_ants(t_lemin *lem)
{
	int			i;
	int			id;
	t_lst_path	*path;

	i = -1;
	while (++i < ANTS_NUM)
	{
		id = path_for_next_ant(lem);
		lst_ants_get_by_id(ANTS, i)->path_id = id;
		path = lst_path_get_by_id(PATH, id);
		path->counter++;
		if (!path->ants)
			path_ants_create(lem, path);
		path->ants[path->counter - path->length - 1] = i;
		ANTS_NUM_PATH++;
	}
	return ;
}
