/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:05:45 by antondob          #+#    #+#             */
/*   Updated: 2020/10/05 13:16:33 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	refresh_path(t_lemin *lem)
{
	PATH_NUM = 0;
	lst_path_free(PATH);
	get_path(lem);
}

void	get_path_room(t_lemin *lem, int curr, int ind, t_lst_path *path)
{
	int	j;

	path->rooms[ind] = curr;
	if (curr == ROOMS_NUM - 1)
		return ;
	j = -1;
	while (++j < ROOMS_NUM)
		if (FLOW_MATRIX[curr][j] == 1)
			get_path_room(lem, j, ind + 1, path);
}

int		get_path_length(t_lemin *lem, int curr)
{
	int	j;

	if (curr == ROOMS_NUM - 1)
		return (1);
	j = -1;
	while (++j < ROOMS_NUM)
		if (FLOW_MATRIX[curr][j] == 1)
			return (get_path_length(lem, j) + 1);
	return (0);
}

void	get_path(t_lemin *lem)
{
	int			j;
	int			s;
	t_lst_path	*path;

	j = -1;
	s = 0;
	path = NULL;
	while (++j < ROOMS_NUM)
		if (FLOW_MATRIX[0][j] == 1)
		{
			path = (path) ? lst_path_add(path) : lst_path_create();
			path->length = get_path_length(lem, j) + 1;
			path->counter = path->length;
			path->rooms = (int *)(malloc(sizeof(int) * path->length));
			path->rooms[0] = 0;
			path->path_id = s++;
			PATH_NUM++;
			get_path_room(lem, j, 1, path);
		}
	PATH = lst_path_get_start(path);
	if (PATH == NULL)
		lemin_error();
}
