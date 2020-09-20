/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_update_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/19 17:00:38 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_lst_point *lst_update_id(t_lst_point *tf)
{
	t_lst_point *temp_lst;
	int c;

	c = 1;
	temp_lst = tf;
	while(temp_lst && temp_lst->next)
	{
		if(temp_lst->ex == 0){
			temp_lst->id = 0;
		}
		else if(temp_lst->ex == 1)
			temp_lst->id = lst_length(tf) - 2;
		else if(temp_lst->id != -1){
			temp_lst->id = c++;
		}
		temp_lst = temp_lst->next;
	}
	return (tf);
}
