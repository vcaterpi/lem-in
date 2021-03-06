/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:40:26 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/11/02 20:11:08 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

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
** дейкстра
*/

int			dijkstra(t_lemin *lem)
{
	int		*vst;
	int		v;
	t_min	min;
	int		step;

	if (!(vst = ft_memalloc(sizeof(int) * ROOMS_NUM)))
		ERROR = 1;
	fill_distance(lem);
	parent_zero(lem);
	step = 0;
	min.room = -1;
	min.dist = INF;
	v = -1;
	while (++step)
	{
		v = (step == 1 ? 0 : min.room);
		if (v == -1 || v == ROOMS_NUM - 1)
			break ;
		vst[v] = 1;
		min.room = -1;
		min.dist = INF;
		count_all_distance_dkst(lem, vst, &min, v);
	}
	free(vst);
	return (DISTANCE[ROOMS_NUM - 1] < INF);
}

/*
** беллман форд
*/

int			shortest_paths(t_lemin *lem)
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
	count_all_distance_ford(lem, inq, data, &q);
	fill_potential(lem);
	free(inq);
	free(data);
	return (DISTANCE[ROOMS_NUM - 1] < INF);
}

t_lemin		*apply_algo(t_lemin *lem)
{
	int			steps;
	int			**flow_matr_backup;
	int			**mini_flow;
	t_lemin		*result;
	static int	round;

	if (!(result = NULL) && ERROR)
		return (NULL);
	result = lemin_backup(result, lem, INF);
	mini_flow = adapt_capmatrix(lem);
	do_all_matrix(lem);
	while ((!round++ ? shortest_paths(lem) : dijkstra(lem)))
	{
		refresh_caps(lem);
		flow_matr_backup = FLOW_MATRIX;
		refresh_all(lem, mini_flow);
		FLOW_MATRIX = flow_matr_backup;
		ROOMS_NUM = (ROOMS_NUM - 2) * 2 + 2;
		if ((steps = count_steps(lem)) >= result->steps_num)
			break ;
		result = lemin_backup(result, lem, steps);
	}
	ft_delete_table(&mini_flow, (ROOMS_NUM + 2) / 2);
	lemin_free(lem);
	return (result);
}
