/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ants_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/22 16:32:51 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int			lst_ants_length(t_lst_ants *lst)
{
	t_lst_ants	*temp_lst;
	int			c;

	c = 0;
	temp_lst = lst_ants_get_start(lst);
	if (temp_lst && !temp_lst->next)
		return (1);
	while (temp_lst && ++c)
		temp_lst = temp_lst->next;
	return (c);
}
