/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_text_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:41:24 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 16:41:26 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_text		*lst_text_add(t_lst_text *lst)
{
	t_lst_text	*temp_lst;

	temp_lst = lst_text_create();
	temp_lst->next = lst;
	lst->prev = temp_lst;
	lst = lst->prev;
	return (lst);
}
