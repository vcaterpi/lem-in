/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/09/23 21:17:23 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void togo_ants(t_lemin *lem)
{
	int flag;
	int i;
	t_lst_ants *a;
	t_lst_ants *prev;
	t_lst_path *p;

	flag = 0;
	p = PATH;
	while (p)
	{
		i = -1;
		while (p->ants && p->ants[++i] != -1)
		{
			if (((i == 0) || ((prev = lem->arr_ants[p->ants[i - 1]])->room_id != 0)
				&& (prev->room_id != p->rooms[1])) &&
			 	((a = lem->arr_ants[p->ants[i]])->room_id != ROOM_LAST))
			{
				if ((a->room_id = p->rooms[++(a->index)]) != ROOM_LAST)
					flag = 1;
				ft_printf("L%d-%s ", p->ants[i] + 1, (lem->arr_room[a->room_id])->name);
			}
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

int main(void)
{
	t_lemin *lem;
	t_lst_path *path;

	lem = lemin_create();
	lemin_read(ROOMS, lem);
	apply_algo(lem);
	get_path(lem);
	distribution_ants(lem);
	test(lem);
	togo_ants(lem);
	lemin_free(lem);
	return (0);
}
