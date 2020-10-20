/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:49:14 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/20 21:32:59 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

/*
** https://cp-algorithms.com/graph/min_cost_flow.html
*/

/*
** обновляем матрицы, которые необходимо обновить
*/

void		refresh_caps(t_lemin *lem)
{
	int curr;
	int prev;

	if (ERROR)
		return ;
	curr = ROOMS_NUM - 1;
	prev = PARENT[curr];
	while (curr)
	{
		CAP_MATRIX[prev][curr]--;
		CAP_MATRIX[curr][prev]++;
		FLOW_MATRIX[prev][curr]++;
		FLOW_MATRIX[curr][prev]--;
		curr = prev;
		prev = PARENT[curr];
	}
}

/*
** находим самые короткие пути
*/

void		shortest_paths(t_lemin *lem)
{
	t_queue	*q;
	void	*data;
	int		*inq;
	int		i;

	q = NULL;
	if (!(inq = ft_memalloc(sizeof(int) * ROOMS_NUM)))
		ERROR = 1;
	i = -1;
	while (++i < ROOMS_NUM)
		inq[i] = 0;
	if (!(data = ft_memalloc(sizeof(int))))
		ERROR = 1;
	fill_distance(lem);
	parent_zero(lem);
	ft_bzero(data, sizeof(int));
	ft_qpush(&q, data, sizeof(int));
	if (!q)
		ERROR = 1;
	count_all_distance(lem, inq, data, &q);
	free(inq);
	free(data);
}

int			count_steps(t_lemin *lem)
{
	int			i;
	int			steps;
	int			max;
	t_lst_path	*path;

	path = PATH;
	i = 0;
	max = 0;
	steps = 0;
	while (++i <= PATH_NUM)
	{
		steps = ANTS_NUM_PATH + PATH_LEN;
		if (steps > max)
			max = steps;
		path = path->next;
	}
	return (steps - 1);
}

int			min_cost_algo(t_lemin *lem)
{
	int flow;

	flow = 0;
	shortest_paths(lem);
	if (DISTANCE[ROOMS_NUM - 1] == INF)
		return (flow);
	refresh_caps(lem);
	return (++flow);
}

t_lemin		*apply_algo(t_lemin *lem)
{
	int		steps;
	int		**flow_matr_backup;
	int		delta_one;
	t_lemin	*result;

	if (!(result = NULL) && ERROR)
		return (NULL);
	result = lemin_backup(result, lem, INF);
	adapt_capmatrix(lem);
	do_all_matrix(lem);
	delta_one = 0;
	while (min_cost_algo(lem))
	{
		flow_matr_backup = ft_copy_matrix(FLOW_MATRIX, ROOMS_NUM);
		refresh_all(lem);
		FLOW_MATRIX = flow_matr_backup;
		ROOMS_NUM = (ROOMS_NUM - 2) * 2 + 2;
		if (result->steps_num - (steps = count_steps(lem)) == 1)
			delta_one += 1;
		if (steps >= result->steps_num || delta_one >= 1)
			break ;
		result = lemin_backup(result, lem, steps);
	}
	lemin_free(lem);
	return (result);
}
