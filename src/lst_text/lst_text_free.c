/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:40:14 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/03 02:23:08 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void	lst_text_free(t_lst_text *lst)
{
	t_lst_text *temp_lst;

	if (lst)
	{
		if (lst->prev)
			lst = lst_text_get_start(lst);
		while (lst)
		{
			temp_lst = lst->next;
			free(lst->line);
			free(lst);
			lst = temp_lst;
		}
		lst = NULL;
	}
	free(lst);
	lst = NULL;
}
