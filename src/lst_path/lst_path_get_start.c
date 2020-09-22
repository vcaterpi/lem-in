/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_path_get_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/23 02:18:13 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_path		*lst_path_get_start(t_lst_path *lst)
{
	t_lst_path	*temp_lst;

	temp_lst = lst;
	while (temp_lst && temp_lst->prev)
		temp_lst = temp_lst->prev;
	return (temp_lst);
}
