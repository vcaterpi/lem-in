/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/23 18:39:16 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	lemin_free(t_lemin *lem)
{
	ft_free_matrix_int(&CAP_MATRIX, ROOMS_NUM);
	ft_free_matrix_int(&FLOW_MATRIX, ROOMS_NUM);
	lst_room_free(ROOMS);
	lst_path_free(PATH);
	lst_ants_free(ANTS);
	free(PARENT);
	free(lem);
	lem = NULL;
}
