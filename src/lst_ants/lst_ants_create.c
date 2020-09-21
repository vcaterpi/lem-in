/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ants_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:55:26 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_ants		*lst_ants_create(void)
{
	t_lst_ants	*lst;

	if (!(lst = (t_lst_ants *)malloc(sizeof(t_lst_ants))))
		lemin_error();
	lst->next = NULL;
	lst->prev = NULL;
	lst->ant_id = -1;
	lst->room_id = 0;
	lst->path_id = -1;
	lst->index = 0;
	return (lst);
}
