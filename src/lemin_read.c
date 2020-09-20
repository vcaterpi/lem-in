/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:21:40 by air_must          #+#    #+#             */
/*   Updated: 2020/09/19 19:21:09 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_lst_point *reconstr(t_lst_point *rooms, char *line, int ex)
{
	char **operand;
	rooms->x = 0;

	operand = ft_strsplit(line, ' ');
	if (operand[0] && operand[1] && operand[2] && !operand[3])
	{
		rooms->name = ft_strdup(operand[0]);
			rooms->x = ft_atoi(operand[1]);
			rooms->y = ft_atoi(operand[2]);
		rooms->id = lst_length(rooms) - 1;
		rooms->ex = ex;
		if (!lst_check(rooms))
			lemin_error();
		ft_strsplitfree(&operand);
		return (rooms);
	}
	ft_strsplitfree(&operand);
	operand = ft_strsplit(line, '-');
	if (operand[0] && operand[1] && !operand[2])
	{
		ft_strsplitfree(&operand);
		return (rooms);
	}
	return (NULL);
}

t_lst_point *to_read_room(t_lst_point *rooms, int *is_ref, int *ex, char *line)
{
	if (ft_strequ(line, "##start"))
		*ex = 0;
	else if (ft_strequ(line, "##end"))
		*ex = 1;
	else if (line[0] != '#' && line[0] != 'L')
	{

		rooms = (rooms) ? lst_add(rooms) : lst_create();

		rooms = reconstr(rooms, line, *ex);
		if (rooms->id == -1)
			*is_ref = 1;
		*ex = -1;
	}
	return (rooms);
}


t_lemin *to_read_link(t_lst_point *rooms, char *line, int is_ref, t_lemin *lem)
{
	char **operand;

	if (is_ref == 1)
	{
		ROOMS_NUM = lst_length(rooms) - 1;
		CAP_MATRIX = ft_create_matrix_int(ROOMS_NUM);
	}
	if (line[0] != '#' && line[0] != 'L')
	{
		operand = ft_strsplit(line, '-');
		if (operand[0] && operand[1] && !operand[2])
		{
			if (lst_get_by_name(rooms, operand[0]) != NULL && lst_get_by_name(rooms, operand[1]) != NULL)
			{
				CAP_MATRIX[lst_get_by_name(rooms, operand[0])->id][lst_get_by_name(rooms, operand[1])->id] = 1;
				CAP_MATRIX[lst_get_by_name(rooms, operand[1])->id][lst_get_by_name(rooms, operand[0])->id] = 1;
			}
			else
				lemin_error();
			ft_strsplitfree(&operand);
			return (lem);
		}
		lemin_error();
		ft_strsplitfree(&operand);
	}
	return lem;
}

t_lst_point *lemin_read(t_lst_point *rooms, t_lemin *lem)
{
	char *line;
	int ex;
	int is_ref;

	is_ref = -1;
	ex = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (is_ref == -1 && ft_strlen(line) < 11 && ft_atoi(line) > 0)
		{
			is_ref += 1;
			ANTS_NUM = ft_atoi(line);
		}
		else if (ANTS_NUM == -1)
			lemin_error();
		else if (is_ref == 0)
		{
			rooms = to_read_room(rooms, &is_ref, &ex, line);
		}
		if (is_ref >= 1)
		{
			rooms = lst_update_id(lst_get_start(rooms));
			lem = to_read_link(rooms, line, is_ref, lem);
			is_ref++;
		}
		ft_strdel(&line);
	}
	return (rooms);
}

