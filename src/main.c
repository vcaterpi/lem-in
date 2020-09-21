/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/09/21 15:15:31 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void togo_ants(t_lemin *lem)
{
	int step;
	int id_ant;
	int is_good;
	int j;

	step = -1;
	is_good = 1;
	while (is_good)
	{
		id_ant = -1;
		while (++id_ant < ANTS_NUM)
		{
			if (lst_ants_get_by_id(ANTS, id_ant)->room_id != ROOMS_NUM - 1)
			{
				is_good = 1;
				j = -1;
				while (++j < ANTS_NUM)
					if (lst_ants_get_by_id(ANTS, id_ant)->path_id == lst_ants_get_by_id(ANTS, j)->path_id &&
						lst_ants_get_by_id(ANTS, id_ant)->index + 1 == lst_ants_get_by_id(ANTS, j)->index &&
						lst_ants_get_by_id(ANTS, j)->room_id != ROOMS_NUM - 1)
					{
						is_good = 0;
						break;
					}
				if (is_good)
				{
					lst_ants_get_by_id(ANTS, id_ant)->index += 1;
					lst_ants_get_by_id(ANTS, id_ant)->room_id = lst_path_get_by_id(PATH, lst_ants_get_by_id(ANTS, id_ant)->path_id)->rooms[lst_ants_get_by_id(ANTS, id_ant)->index];
					ft_printf("L%d-%s ", id_ant + 1, lst_get_by_id(ROOMS, lst_ants_get_by_id(ANTS, id_ant)->room_id)->name);
				}
			}
		}
		is_good = 0;
		id_ant = -1;
		while (++id_ant < ANTS_NUM)
			if (lst_ants_get_by_id(ANTS, id_ant)->room_id != ROOMS_NUM - 1)
			{
				is_good = 1;
				break;
			}
		ft_printf("\n");
		step += 1;
	}
}

int main(void)
{
	t_lemin *lem;

	lem = lemin_create();
	lemin_read(ROOMS, lem);
	apply_algo(lem);
	get_path(lem);
	distribution_ants(lem);
	togo_ants(lem);
	lemin_free(lem);
	return (0);
}
