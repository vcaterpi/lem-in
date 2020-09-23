/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/09/23 18:38:46 by air_must         ###   ########.fr       */
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
			if (((i == 0) || ((prev = lst_ants_get_by_id(ANTS, p->ants[i - 1]))->room_id != 0)
				&& (prev->room_id != p->rooms[1])) &&
			 	((a = lst_ants_get_by_id(ANTS, p->ants[i]))->room_id != ROOM_LAST))
			{
				if ((a->room_id = p->rooms[++(a->index)]) != ROOM_LAST)
					flag = 1;
				ft_printf("L%d-%s ", p->ants[i] + 1, (lst_room_get_by_id(ROOMS, a->room_id))->name);
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

int main(void)
{
	t_lemin *lem;
	t_lst_path *path;

	lem = lemin_create();
	lemin_read(ROOMS, lem);
	apply_algo(lem);
	get_path(lem);
	distribution_ants(lem);
	togo_ants(lem);
	lemin_free(lem);
	return (0);
}
