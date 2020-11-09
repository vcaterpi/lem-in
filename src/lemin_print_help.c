/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_print_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:28:25 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 17:24:34 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	print_ants_in_path(t_lemin *lem, t_lst_path *p,
	int *flag)
{
	int			i;
	int			count;
	t_lst_ants	*a;
	t_lst_ants	*prev;

	i = -1;
	count = 1;
	while (p->ants && ++i < ANTS_NUM && p->ants[i] != -1)
		if (((i == 0) || ((COND_1) && (COND_2)) || (COND_7 && count)) &&
			COND_3)
		{
			*flag += COND_4;
			count -= (a->room_id == ROOM_LAST);
			ft_printf("L%d-%s ", p->ants[i] + 1, COND_5);
		}
}
