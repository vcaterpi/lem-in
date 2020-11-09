/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:42:43 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/09 16:42:44 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	lemin_free(t_lemin *lem)
{
	ft_free_matrix_int(&CAP_MATRIX, ROOMS_NUM);
	ft_free_matrix_int(&WEIGHT_MATRIX, ROOMS_NUM);
	ft_free_matrix_int(&FLOW_MATRIX, ROOMS_NUM);
	lst_room_free(ROOMS);
	lst_path_free(PATH);
	lst_ants_free(ANTS);
	lst_text_free(lem->text);
	free(PARENT);
	free(DISTANCE);
	free(POTENTIAL);
	free(lem->arr_ants);
	free(lem->arr_path);
	free(lem->arr_room);
	free(lem);
}
