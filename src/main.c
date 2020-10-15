/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/10/15 19:28:22 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

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
		while (p->ants && p->ants[++i] != -1)
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
	togo_ants(lem);
	lemin_free(lem);
	return (0);
}
