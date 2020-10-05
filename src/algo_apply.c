/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:49:14 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/10/05 16:00:24 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

//https://cp-algorithms.com/graph/min_cost_flow.html

// зануляем массив родителей и указывем, что все ребра основные
void	parent_zero(t_lemin *lem)
{
	int i;

	if (ERROR)
		return ;
	i = -1;
	while (++i < ROOMS_NUM)
		PARENT[i] = -1;
	
		
}
//запоняем матрицы весов - для прямых ребер 1, для обратных ребер -1
void	fill_weight_matrix(t_lemin *lem)
{
	int i;
	int j;

	if (ERROR)
		return ;
	i = -1;
	while (++i < ROOMS_NUM)
	{
		j = -1;
		while (++j < ROOMS_NUM)
		{
			if (CAP_MATRIX[i][j] == 1)
			{
				WEIGHT_MATRIX[i][j] = 1;
				WEIGHT_MATRIX[j][i] = -1;
			}
		}
	}
}
//обновляем матрицы, которые необходимо обновить 
static void		refresh_caps(t_lemin *lem)
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

//заполняем массив кратчайших растояний до вершин бесконечностями
void	fill_distance(t_lemin *lem)
{
	int i;

	i = -1;
	while (++i < ROOMS_NUM)
		DISTANCE[i] = INF;
	DISTANCE[0] = 0;
}
//находим самые короткие пути
void	shortest_paths(t_lemin *lem)
{
	t_queue	*q;
	void	*data;
	int 	*inq;
	int 	i;

	//ft_printf("func_call\n");
	q = NULL;
	if (!(inq = ft_memalloc(sizeof(int) * ROOMS_NUM)))
		ERROR = 1;
	i = -1;
	while (++i < ROOMS_NUM)
		inq[i] = 0;
	if (!(data = ft_memalloc(sizeof(int))))
		ERROR = 1;
	fill_distance(lem);
	//ft_printf("distance[room_num - 1] = %d\n", DISTANCE[ROOMS_NUM -1]);
	parent_zero(lem);
	ft_bzero(data, sizeof(int));
	ft_qpush(&q, data, sizeof(int));
	if (!q)
		ERROR = 1;
	while (q)
	{
		data = ft_qpop(&q, sizeof(int));
		inq[DATA] = 0;
		i = -1;
		//дистанция по второй таблице вычисляется уже после первой
		while (++i < ROOMS_NUM)
		{
			if ((i != 0) && CAP_MATRIX[DATA][i] > 0 && (DISTANCE[i] > DISTANCE[DATA] + WEIGHT_MATRIX[DATA][i]))
			{
				DISTANCE[i] = DISTANCE[DATA] + WEIGHT_MATRIX[DATA][i]; //WEIGHT_MATRIX_2[DATA][i];
				PARENT[i] = DATA;
				if (!inq[i])
				{
					inq[i] = 1;
					ft_qpush(&q, &i, sizeof(int));
				}
			}
		}
		free(data);
		data = NULL;
	}
	
}
//;;;;;;;;;;;;;;;;;
int count_steps(t_lemin *lem)
{
	int i;
	int steps;
	int max;
	t_lst_path *path;

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
//;;;;;;;;;;;;;;;;;;
//алгоритм нахождения максимального потока минимальной стоимости
int	min_cost_algo(t_lemin *lem)
{
	int flow;

	flow = 0;
	//while (flow < INF)
	//{   
		//printf("flow = %d\n", flow);
		shortest_paths(lem);
		if (DISTANCE[ROOMS_NUM - 1] == INF)
			return(flow);
		refresh_caps(lem);
		return(++flow);
		//
		
		//
	//}
	//ft_printf("flow = %d\n", flow);
}

t_lemin		*apply_algo(t_lemin *lem)
{
	int 	steps;
	int 	new_rooms;
	int 	**flow_matr_backup;
	t_lemin *result;

	if (ERROR)
		return (NULL) ;
	//удваиваем вершины
	adapt_capmatrix(lem);
	result = NULL;
	//создаем доп матрицу пропускных способностей и матрицы потоков
	if (!(FLOW_MATRIX = ft_create_matrix_int(ROOMS_NUM)) ||
		!(WEIGHT_MATRIX = ft_create_matrix_int(ROOMS_NUM)) ||
		!(PARENT = ft_memalloc(sizeof(int) * ROOMS_NUM)) ||
		!(DISTANCE = ft_memalloc(sizeof(int) * ROOMS_NUM)))
		ERROR = 1;
	//создаем матрицы весов
	fill_weight_matrix(lem);
	result = lemin_backup(result, lem, INF);
	while (min_cost_algo(lem))
	{
		flow_matr_backup = ft_copy_matrix(FLOW_MATRIX, ROOMS_NUM);
		adapt_flowmatrix(lem);
		refresh_path(lem);
		refresh_ants(lem);
		//ft_delete_table(&FLOW_MATRIX, ROOMS_NUM);
		
		FLOW_MATRIX = flow_matr_backup;
		if ((steps = count_steps(lem)) > result->steps_num)
			break ;
		result = lemin_backup(result, lem, steps);
		ROOMS_NUM = (ROOMS_NUM - 2) * 2 + 2;
	}
	lemin_free(lem);
	return (result);
}