/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_print_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:02:27 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:50:09 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_path_print_lst(t_lst_path *lst, int depth)
{
	t_lst_path	*temp;
	int			i;

	temp = lst;
	while (temp)
	{
		i = -1;
		while (++i < depth)
			ft_printf("\t ");
		ft_printf("Id path: %d\tcounter: %d\tlength: %d\tArray: [ ",\
			temp->path_id, temp->counter, temp->length);
		i = -1;
		while (++i < temp->length)
			ft_printf("%d ", temp->rooms[i]);
		ft_printf("]\n");
		temp = temp->next;
	}
}
