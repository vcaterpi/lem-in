/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ants_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:55:03 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_ants_free(t_lst_ants *lst)
{
	t_lst_ants *temp_lst;

	if (lst)
	{
		if (lst->prev)
			lst = lst_ants_get_start(lst);
		while (lst)
		{
			temp_lst = lst->next;
			free(lst);
			lst = temp_lst;
		}
		lst = NULL;
	}
	free(lst);
	lst = NULL;
}
