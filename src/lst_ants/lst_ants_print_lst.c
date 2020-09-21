/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ants_print_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:02:27 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:55:15 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_ants_print_lst(t_lst_ants *lst, int depth)
{
	t_lst_ants	*temp;
	int			i;

	temp = lst;
	while (temp && temp->next)
	{
		i = -1;
		while (++i < depth)
			ft_printf("\t ");
		ft_printf("Id ant: %d\tid room: %d\tid path: %d\tindex: %d\n",\
			temp->ant_id, temp->room_id, temp->path_id, temp->index);
		temp = temp->next;
	}
	return ;
}
