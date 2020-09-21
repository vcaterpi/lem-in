/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:08:42 by slynell           #+#    #+#             */
/*   Updated: 2020/09/21 19:29:25 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

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
		temp->id = lst_length(temp) - 1;
		temp->ex = ex;
		if (!lst_check(temp) || ft_checkoverflow(temp->x, operand[1])
			|| ft_checkoverflow(temp->y, operand[2]))
			lemin_error();
		ft_strsplitfree(&operand);
		return (temp);
	}
	ft_strsplitfree(&operand);
	operand = ft_strsplit(line, '-');
	if (!(operand[0] && operand[1] && !operand[2]))
		temp = NULL;
	ft_strsplitfree(&operand);
	return (temp);
}

t_lst_rooms	*to_read_room(t_lst_rooms *rooms, int *is_ref, int *ex, char *line)
{
	if (line[0] == '#' && line[1] == '#' && *ex != -1 || line[0] == 'L')
		lemin_error(); //если текущая строка - любая команда, а предыдущая start или end, или начинается на L
	else if (ft_strequ(line, "##start") && *ex == -1)
		*ex = 0; //если текущая строка - команда start, а предыдущая - не команда 
	else if (ft_strequ(line, "##end") && *ex == -1)
		*ex = 1; //если текущая строка - команда end, а предыдущая - не команда
	else if (line[0] != '#') //если строка начинается не на # или L
	{
		rooms = (rooms) ? lst_add(rooms) : lst_room_create(); //если комнаты уже есть, то добавялем, если нет, то создаем
		rooms = reconstr(rooms, line, *ex); //вносим данные о комнате
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
	char	**operand;

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
			if (lst_get_by_name(rooms, operand[0]) != NULL &&\
				lst_get_by_name(rooms, operand[1]) != NULL)
			{
				CAP_MATRIX[lst_get_by_name(rooms, operand[0])->id]
				[lst_get_by_name(rooms, operand[1])->id] = 1;
				CAP_MATRIX[lst_get_by_name(rooms, operand[1])->id]
				[lst_get_by_name(rooms, operand[0])->id] = 1;
			}
			else
				lemin_error();
			ft_strsplitfree(&operand);
			return (lem);
		}
		lemin_error();
		ft_strsplitfree(&operand);
	}
	return (lem);
}

t_lst_ants	*create_ants(t_lemin *lem)
{
	int			i;
	t_lst_ants	*ants;

	i = -1;
	ants = lst_ants_create();
	ants->ant_id = 0;
	while (++i < ANTS_NUM)
	{
		ants = lst_ants_add(ants);
		ants->ant_id = i;
	}
	return (lst_ants_get_start(ants));
}

/*
** Читаем строку. Если is_ref == -1, то это должно быть количество муравьев,
** если is_ref == 0, то это должны быть координаты комнаты или комментарий.
** если is_ref >= 1, то это должны быть связи.
** 
*/

t_lst_rooms	*lemin_read(t_lst_rooms *rooms, t_lemin *lem)
{
	char	*line;
	int		ex;
	int		is_ref;

	is_ref = -1;
	ex = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (is_ref == -1 && ft_strlen(line) < 11 && ft_atoi(line) > 0)
		{
			is_ref += 1;
			ANTS_NUM = ft_atoi(line);
			ANTS = create_ants(lem);
		}
		else if (ANTS_NUM == -1)
			lemin_error();
		else if (is_ref == 0)
			rooms = to_read_room(rooms, &is_ref, &ex, line);
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
