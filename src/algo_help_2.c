/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_help_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:11:52 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/15 19:27:32 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	do_all_matrix(t_lemin *lem)
{
	if (!(FLOW_MATRIX = ft_create_matrix_int(ROOMS_NUM)) ||
		!(WEIGHT_MATRIX = ft_create_matrix_int(ROOMS_NUM)) ||
		!(PARENT = ft_memalloc(sizeof(int) * ROOMS_NUM)) ||
		!(DISTANCE = ft_memalloc(sizeof(int) * ROOMS_NUM)))
	{
		ERROR = 1;
		return ;
	}
	fill_weight_matrix(lem);
}

void	count_all_distance(t_lemin *lem, int *inq, void *data, t_queue **q)
{
	int i;

	while (*q)
	{
		data = ft_qpop(q, sizeof(int));
		inq[DATA] = 0;
		i = -1;
		while (++i < ROOMS_NUM)
		{
			if ((i != 0) && CAP_MATRIX[DATA][i] > 0 &&
				(DISTANCE[i] > DISTANCE[DATA] + WEIGHT_MATRIX[DATA][i]))
			{
				DISTANCE[i] = DISTANCE[DATA] + WEIGHT_MATRIX[DATA][i];
				PARENT[i] = DATA;
				if (!inq[i])
				{
					inq[i] = 1;
					ft_qpush(q, &i, sizeof(int));
				}
			}
		}
		free(data);
		data = NULL;
	}
}
