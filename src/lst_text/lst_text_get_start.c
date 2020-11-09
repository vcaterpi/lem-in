/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_text_get_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:41:46 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 16:41:47 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_text		*lst_text_get_start(t_lst_text *lst)
{
	t_lst_text	*temp_lst;

	temp_lst = lst;
	while (temp_lst && temp_lst->prev)
		temp_lst = temp_lst->prev;
	return (temp_lst);
}
