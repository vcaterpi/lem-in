/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/19 17:20:33 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_point *lst_create()
{
	t_lst_point *lst;

	if (!(lst = (t_lst_point *)malloc(sizeof(t_lst_point))))
		lemin_error();
	lst->name = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	lst->x = -1;
	lst->y = -1;
	lst->ex = -1;
	lst->id = -1;
	return (lst);
}
