/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/09/22 22:45:37 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void togo_ants(t_lemin *lem)
{
	int id_ant;
	int is_good;
	int flag;
	int j;
	t_lst_ants *a_1;
	t_lst_ants *a_2;
	t_lst_path *p_1;

	id_ant = -1;  
	while (1)
	{
		is_good = 0;
		a_1 = lst_ants_get_by_id(ANTS, ++id_ant);
		if (a_1->room_id != ROOMS_NUM - 1)
		{
			flag = 1;
			j = -1;
			while (++j < ANTS_NUM)
			{
				a_2 = lst_ants_get_by_id(ANTS, j);
				if (a_1->path_id == a_2->path_id &&
					a_1->index + 1 == a_2->index &&
					a_2->room_id != ROOMS_NUM - 1)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				a_1->index += 1;
				a_1->room_id = lst_path_get_by_id(PATH, a_1->path_id)->rooms[a_1->index];
				ft_printf("L%d-%s ", id_ant + 1, lst_room_get_by_id(ROOMS, a_1->room_id)->name);
			}
		}
		is_good = (a_1->room_id != ROOMS_NUM - 1 ? is_good + 1 : is_good);
		if (id_ant == ANTS_NUM - 1 && !is_good)
			break ; 
		if ((id_ant == ANTS_NUM - 1) && (id_ant = -1))
			ft_printf("\n");
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
