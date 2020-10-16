/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 23:54:19 by antondob          #+#    #+#             */
/*   Updated: 2020/10/15 17:51:36 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

/*
** Вспомогательные функции для работы с алгоритмом
*/

/*
** заполняем массив кратчайших растояний до вершин бесконечностями
*/

void	fill_distance(t_lemin *lem)
{
	int i;

	i = -1;
	while (++i < ROOMS_NUM)
		DISTANCE[i] = INF;
	DISTANCE[0] = 0;
}

/*
** зануляем массив родителей и указывем, что все ребра основные
*/

void	parent_zero(t_lemin *lem)
{
	int i;

	if (ERROR)
		return ;
	i = -1;
	while (++i < ROOMS_NUM)
		PARENT[i] = -1;
}

/*
** запоняем матрицы весов - для прямых ребер 1, для обратных ребер -1
*/

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

/*
** Удваиваем все вершины матрицы пропусных способностей,
** кроме первой и последней и прописываем необходимые связи так,
** новый граф был эквивалентен исходному
*/

void	adapt_capmatrix(t_lemin *lem)
{
	int	**new_matrix;
	int	new_rooms;
	int	i;
	int	j;

	if (ERROR)
		return ;
	new_rooms = (ROOMS_NUM - 2) * 2 + 2;
	if (!(new_matrix = ft_create_matrix_int(new_rooms)))
		ERROR = 1;
	i = -1;
	while ((!ERROR) && (++i < ROOMS_NUM))
	{
		j = -1;
		while (++j < ROOMS_NUM)
			if (CAP_MATRIX[i][j] == 1)
				new_matrix[i * 2 - (i == ROOMS_NUM - 1)]\
				[(j * 2 - 1) * (j != 0)] = 1;
			else if ((i == j) && (i * j != 0) &&
				(i != ROOMS_NUM - 1) && (j != ROOMS_NUM - 1))
				new_matrix[i * 2 - 1][j * 2] = 1;
	}
	ft_delete_table(&CAP_MATRIX, ROOMS_NUM);
	CAP_MATRIX = new_matrix;
	ROOMS_NUM = new_rooms;
}

/*
** После применения алгоритма и нахождения всех непересекающихся путей
** приводим граф к старому виду и старому размеру так, чтобы
** найденные пути были эквивалентны
*/

void	adapt_flowmatrix(t_lemin *lem)
{
	int	old_rooms;
	int	**old_matrix;
	int	i;
	int	j;

	if (ERROR)
		return ;
	old_rooms = (ROOMS_NUM + 2) / 2;
	if (!(old_matrix = ft_create_matrix_int(old_rooms)))
		ERROR = 1;
	i = -1;
	while ((!ERROR) && (++i < old_rooms))
	{
		j = -1;
		while (++j < old_rooms)
			if ((j != 0) && (i != old_rooms - 1) &&
				FLOW_MATRIX[i * 2][j * 2 - 1] == 1)
				old_matrix[i][j] = 1;
	}
	ft_delete_table(&FLOW_MATRIX, ROOMS_NUM);
	FLOW_MATRIX = old_matrix;
	ROOMS_NUM = old_rooms;
}