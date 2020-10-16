/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/10/16 00:11:14 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	print_rooms(t_lemin *lem)
{
	t_lst_rooms *rooms;
	t_lst_rooms *tmp;
	int i;
	int j;

	ft_printf("%d\n", ANTS_NUM);
	rooms = lst_room_get_start(ROOMS);
	i = -1;
	/*while (++i < ROOMS_NUM)
	{
		if (rooms->id == 0)
			ft_printf("##start\n");
		else if (rooms->id == ROOMS_NUM - 1)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", rooms->name, rooms->x, rooms->y);
		rooms = rooms->next;
	}*/
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

void	togo_ants(t_lemin *lem)
{
	int			flag;
	int			i;
	t_lst_ants	*a;
	t_lst_ants	*prev;
	t_lst_path	*p;

	flag = 0;
	p = PATH;
	while (p)
	{
		i = -1;
		while (p->ants && p->ants[++i] != -1 && i < ANTS_NUM)
			if (((i == 0) || ((COND_1) && (COND_2))) && COND_3)
			{
				flag = 0 + COND_4;
				ft_printf("L%d-%s ", p->ants[i] + 1, COND_5);
			}
		if (!(p = p->next))
		{
			ft_printf("\n");
			if (!flag--)
				break ;
			p = PATH;
		}
	}
}

void	test(t_lemin *lem)
{
	lem->arr_path = lst_path_array(PATH, PATH_NUM);
	lem->arr_ants = lst_ants_array(ANTS, ANTS_NUM);
	lem->arr_room = lst_room_array(ROOMS, ROOMS_NUM);
}

int		main(void)
{
	t_lemin *lem;

	lem = lemin_create();
	lemin_read(ROOMS, lem);
	lem = apply_algo(lem);
	test(lem);
	print_rooms(lem);
	togo_ants(lem);
	lemin_free(lem);
	return (0);
}
