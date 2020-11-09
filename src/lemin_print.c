/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:44:18 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 18:08:20 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	optimize_lem(t_lemin *lem)
{
	lem->arr_path = lst_path_array(PATH, PATH_NUM);
	lem->arr_ants = lst_ants_array(ANTS, ANTS_NUM);
	lem->arr_room = lst_room_array(ROOMS, ROOMS_NUM);
}

void	print_links(t_lemin *lem)
{
	int			i;
	int			j;
	t_lst_rooms	*rooms;
	t_lst_rooms *tmp;

	i = -1;
	while (++i < ROOMS_NUM)
	{
		rooms = lst_room_get_by_id(ROOMS, i);
		j = -1;
		while (++j < ROOMS_NUM)
			if (CAP_MATRIX[i][j])
			{
				tmp = lst_room_get_by_id(ROOMS, j);
				ft_printf("%s-%s\n", rooms->name, tmp->name);
				CAP_MATRIX[j][i] = 0;
			}
	}
	ft_printf("\n");
}

void	print_rooms(t_lemin *lem)
{
	t_lst_rooms *rooms;
	int			i;

	ft_printf("%d\n", ANTS_NUM);
	rooms = lst_room_get_start(ROOMS);
	i = -1;
	while (++i < ROOMS_NUM)
	{
		if (rooms->id == 0)
			ft_printf("##start\n");
		else if (rooms->id == ROOMS_NUM - 1)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", rooms->name, rooms->x, rooms->y);
		rooms = rooms->next;
	}
}

void	print_ants(t_lemin *lem)
{
	int			flag;
	t_lst_path	*p;

	p = PATH;
	flag = 0;
	while (p)
	{
		print_ants_in_path(lem, p, &flag);
		if (!(p = p->next))
		{
			ft_printf("\n", flag);
			if (flag == ANTS_NUM)
				break ;
			p = PATH;
		}
	}
}

void	print_text_inst(t_lemin *lem)
{
	t_lst_text	*x;

	x = lst_text_get_start(lem->text);
	while (x && x->next)
		x = x->next;
	while (x)
	{
		ft_printf("%s\n", x->line);
		x = x->prev;
	}
	ft_printf("\n");
	return ;
}
