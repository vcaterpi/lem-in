/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_text_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/11/03 02:21:47 by air_must         ###   ########.fr       */
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
