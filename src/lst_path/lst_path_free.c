/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/23 18:38:39 by air_must         ###   ########.fr       */
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
