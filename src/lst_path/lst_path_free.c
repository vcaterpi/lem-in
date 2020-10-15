/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:40:14 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/15 17:40:18 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_path_free(t_lst_path *lst)
{
	t_lst_path *temp_lst;

	if (lst)
	{
		if (lst->prev)
			lst = lst_path_get_start(lst);
		while (lst)
		{
			temp_lst = lst->next;
			free(lst->rooms);
			free(lst->ants);
			free(lst);
			lst = temp_lst;
		}
		lst = NULL;
	}
	free(lst);
	lst = NULL;
}
