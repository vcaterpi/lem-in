/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:12:38 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/21 00:10:21 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"


/*
** Реализация алгоритма Эдмондса-Карпа
*/

/*
** См Пункт 2.2.3 Алгоритма ниже
** После нахождения пути из истока в сток -
** обновляем матрицу остаточных пропусных способностей
** и матрицу потоков
*/

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

/*
** См пункт 2.2.2 Алгоритма ниже
** Обходим соседей только что посещенной вершины
*/

static void		find_path(t_lemin *lem,
					void *data, t_queue **q)
{
	int i;

	if (ERROR)
		return ;
	i = -1;
	while ((!ERROR) && (++i < ROOMS_NUM))
	{
		if ((CAP_MATRIX[DATA][i] == 1) &&
			(PARENT[i] == -1) && (i != 0))
		{
			ft_qpush(q, &i, sizeof(int));
			if (!q)
				ERROR = 1;
			PARENT[i] = DATA;
			if (i == ROOMS_NUM - 1)
			{
				ft_qdel(q);
				break ;
			}
		}
	}
}

/*
** Алгоритм Эдмондса-Карпа адаптированный под задачу для
** неориентированного графа
** 1. Cтавим 1 на последнюю комнату, чтобы мы могли войти в цикл
** 2. До тех пор пока не перестанут
** 	  находиться пути из первой комнаты в последнюю
**    выполняем то, что в цикле
**	  2.1 добавляем 1-ю комнату в очередь
**	  2.2 выполяем команды в цикле,
**		  пока в очереди есть хотя бы одна комната
		  2.2.1 Убираем посещенную комнату из очереди
		  2.2.2 Обходим всех соседей только что удаленной комнаты
		  	    2.2.2.1 Если вершина ненулевая, у нее нет родителя и
						у ребра есть положительная остаточная пропускная спопобность,
						добавляем ее в очередь
		  2.2.3 Если найден пусть из истока в сток, то меняем матрицы
		  		остаточных пропускных способностей и потоков
**	3. Очищаем локальные замаллоченные переменные
**
*/

static void		edmonds_karp(t_lemin *lem)
{
	t_queue 	*q;
	void 		*data;

	if (ERROR)
		return ;
	q = NULL;
	if (!(data = ft_memalloc(sizeof(int))))
		ERROR = 1;
	PARENT[ROOMS_NUM - 1] = 1;
	while ((!ERROR) && (PARENT[ROOMS_NUM - 1] >= 0))
	{
		ft_bzero(data, sizeof(int));
		ft_qpush(&q, data, sizeof(int));
		if (!q)
			ERROR = 1;
		parent_zero(lem);
		while (!(ERROR) && (q != NULL))
		{
			ft_memdel(&data);
			data = ft_qpop(&q, sizeof(int));
			find_path(lem, data, &q);
			if (PARENT[ROOMS_NUM - 1] >= 0)
				refresh_caps(lem);
		}
	}
	ft_memdel(&data);
	ft_qdel(&q);
}

/*
** 1. Удваиваем вершины графа,
**    чтобы учесть пропусную сопобность не только ребер,
**    но и вершин
** 2. Применяем алгоритм
** 3. Возвращаем граф к изначальному виду
*/
void		apply_algo(t_lemin *lem)
{
	if (ERROR)
		return ;
	adapt_capmatrix(lem);
	if (!(FLOW_MATRIX = ft_create_matrix_int(ROOMS_NUM)))
		ERROR = 1;

	if (!(PARENT = ft_memalloc(sizeof(int) * ROOMS_NUM)))
		ERROR = 1;

	parent_zero(lem);
	edmonds_karp(lem);
	adapt_flowmatrix(lem);
}
