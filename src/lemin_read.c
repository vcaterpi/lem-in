/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:18 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 20:05:10 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static void	fill_capmatrix(char *op0, char *op1, t_lemin *lem,
								t_lst_rooms *rooms)
{
	t_lst_rooms		*r_1;
	t_lst_rooms		*r_2;

	if ((r_1 = lst_room_get_by_name(rooms, op0)) != NULL &&\
		(r_2 = lst_room_get_by_name(rooms, op1)) != NULL &&\
		(r_1->id != -1) && (r_2->id != -1))
	{
		CAP_MATRIX[r_1->id][r_2->id] = 1;
		CAP_MATRIX[r_2->id][r_1->id] = 1;
	}
	else
		lemin_error();
}

t_lst_rooms	*reconstr(t_lst_rooms *rooms, char *line, int ex)
{
	char		**operand;
	t_lst_rooms	*temp;

	temp = rooms;
	rooms->x = 0;
	operand = ft_strsplit(line, ' ');
	if (operand[0] && operand[1] && operand[2] && !operand[3] &&
		ft_is_number(operand[1]) && ft_is_number(operand[2]))
	{
		temp->name = ft_strdup(operand[0]);
		temp->x = ft_atoi(operand[1]);
		temp->y = ft_atoi(operand[2]);
		temp->id = lst_room_length(temp) - 1;
		temp->ex = ex;
		if (!lst_room_check(temp) || ft_checkoverflow(temp->x, operand[1])
			|| ft_checkoverflow(temp->y, operand[2]))
			lemin_error();
		ft_strsplitfree(&operand);
		return (temp);
	}
	ft_strsplitfree(&operand);
	operand = ft_strsplit(line, '-');
	temp = (COND_6 ? NULL : temp);
	ft_strsplitfree(&operand);
	return (temp);
}

t_lst_rooms	*to_read_room(t_lst_rooms *rooms, int *is_ref, int *ex, char *line)
{
	if (line[0] == '#' && line[1] == '#' && *ex != -1)
		lemin_error();
	else if (ft_strequ(line, "##start") && *ex == -1)
		*ex = 0;
	else if (ft_strequ(line, "##end") && *ex == -1)
		*ex = 1;
	else if (line[0] != '#')
	{
		rooms = (rooms) ? lst_room_add(rooms) : lst_room_create();
		rooms = reconstr(rooms, line, *ex);
		if (rooms == NULL)
			lemin_error();
		if (rooms->id == -1)
			*is_ref = 1;
		*ex = -1;
	}
	return (rooms);
}

t_lemin		*to_read_link(t_lst_rooms *rooms, char *line, int is_ref,\
			t_lemin *lem)
{
	char			**operand;

	if (is_ref == 1)
	{
		ROOMS_NUM = lst_room_length(rooms);
		CAP_MATRIX = ft_create_matrix_int(ROOMS_NUM - 2);
	}
	if (line[0] != '#')
	{
		operand = ft_strsplit(line, '-');
		if (operand[0] && operand[1] && !operand[2])
		{
			fill_capmatrix(operand[0], operand[1], lem, rooms);
			ft_strsplitfree(&operand);
			return (lem);
		}
		lemin_error();
		ft_strsplitfree(&operand);
	}
	return (lem);
}

t_lst_rooms	*lemin_read(t_lst_rooms *rooms, t_lemin *lem)
{
	char	*line;
	int		ex;
	int		is_ref;

	is_ref = -1;
	ex = -1;
	while (get_next_line(0, &line) > 0)
	{
		lem->text = (lem->text) ? lst_text_add(lem->text) : lst_text_create();
		lem->text->line = ft_strdup(line);
		if (is_ref == -1 && ft_strlen(line) < 11 && ft_atoi(line) > 0)
		{
			is_ref += 1;
			ANTS_NUM = ft_atoi(line);
		}
		else if (ANTS_NUM == -1 || line[0] == 'L')
			lemin_error();
		else if (is_ref == 0)
			rooms = to_read_room(rooms, &is_ref, &ex, line);
		if (is_ref >= 1)
		{
			rooms = lst_room_update_id(lst_room_get_start(rooms));
			lem = to_read_link(rooms, line, is_ref++, lem);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (rooms);
}
