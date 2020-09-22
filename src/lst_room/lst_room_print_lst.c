/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_room_print_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:02:27 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/22 16:10:00 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_room_print_lst(t_lst_rooms *lst, int depth)
{
	t_lst_rooms	*temp;
	int			i;

	temp = lst;
	while (temp && temp->next)
	{
		i = -1;
		while (++i < depth)
			ft_printf("\t ");
		ft_printf("name: %s\tid: %d\tx: %d\ty: %d\tex: %d\n",\
			temp->name, temp->id, temp->x, temp->y, temp->ex);
		temp = temp->next;
	}
	return ;
}
