/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:02:27 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/18 01:08:22 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_print_lst(t_lst_point *lst, int depth)
{
	t_lst_point	*temp;
	int			i;

	temp = lst;
	while (temp && temp->next)
	{
		i = -1;
		while (++i < depth)
			ft_printf("\t");
		ft_printf("name: %s\tid: %d\tx: %d\ty: %d\tex: %d\n", temp->name, temp->id, temp->x, temp->y, temp->ex);
		temp = temp->next;
	}
	return ;
}
