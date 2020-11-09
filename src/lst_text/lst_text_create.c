/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_text_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:40:43 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 16:40:45 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_text	*lst_text_create(void)
{
	t_lst_text *lst;

	if (!(lst = (t_lst_text *)malloc(sizeof(t_lst_text))))
		lemin_error();
	lst->next = NULL;
	lst->prev = NULL;
	lst->line = NULL;
	return (lst);
}
