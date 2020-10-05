/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/10/04 22:42:31 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_path	*lst_path_create(void)
{
	t_lst_path *lst;

	if (!(lst = (t_lst_path *)malloc(sizeof(t_lst_path))))
		lemin_error();
	lst->next = NULL;
	lst->prev = NULL;
	lst->path_id = -1;
	lst->rooms = NULL;
	lst->ants = NULL;
	lst->ants_num = 0;
	lst->length = -1;
	lst->counter = -1;
	return (lst);
}
