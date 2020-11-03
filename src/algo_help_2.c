/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_help_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:11:52 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/01 17:28:42 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	fill_potential(t_lemin *lem)
{
	int i;

	i = -1;
	while (++i < ROOMS_NUM)
		POTENTIAL[i] = DISTANCE[i];
}

void	do_all_matrix(t_lemin *lem)
{
	if (!(FLOW_MATRIX = ft_create_matrix_int(ROOMS_NUM)) ||
		!(WEIGHT_MATRIX = ft_create_matrix_int(ROOMS_NUM)) ||
		!(PARENT = ft_memalloc(sizeof(int) * ROOMS_NUM)) ||
		!(DISTANCE = ft_memalloc(sizeof(int) * ROOMS_NUM)) ||
		!(POTENTIAL = ft_memalloc(sizeof(int) * ROOMS_NUM)))
	{
		ERROR = 1;
		return ;
	}
	fill_weight_matrix(lem);
}

void	count_all_distance_dkst(t_lemin *lem, int *vst, t_min *min, int v)
{
	int i;
	int w;

	i = -1;
	while (++i < ROOMS_NUM)
	{
		if (!vst[i])
		{
			if (CAP_MATRIX[v][i])
			{
				w = WEIGHT_MATRIX[v][i] + POTENTIAL[v] - POTENTIAL[i];
				if (DISTANCE[i] > DISTANCE[v] + w)
				{
					DISTANCE[i] = DISTANCE[v] + w;
					PARENT[i] = v;
				}
			}
			if (DISTANCE[i] < min->dist)
			{
				min->dist = DISTANCE[i];
				min->room = i;
			}
		}
	}
}

void	count_all_distance_ford(t_lemin *lem, int *inq, void *data, t_queue **q)
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

void	refresh_all(t_lemin *lem, int **mini_flow)
{
	adapt_flowmatrix(lem, mini_flow);
	refresh_path(lem);
	refresh_ants(lem);
}
