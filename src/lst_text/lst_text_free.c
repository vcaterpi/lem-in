/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_text_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:41:38 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 16:41:39 by vcaterpi         ###   ########.fr       */
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
