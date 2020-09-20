/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 23:54:19 by antondob          #+#    #+#             */
/*   Updated: 2020/09/19 21:14:27 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"


/*
** Вспомогательные функции для работы с алгоритмом
*/

/*
** Обнуляем все элементы массива родителей в -1.
** 0 использовать нельзя, тк 0 - координата нулевой вершины
*/

void	parent_zero(t_lemin *lem)
{
	int i;

	if (ERROR)
		return ;
	i = -1;
	while (++i <= (ROOMS_NUM - 1))
		PARENT[i] = -1;
}

/*
** Удваиваем все вершины матрицы пропусных способностей,
** кроме первой и последней и прописываем необходимые связи так,
** новый граф был эквивалентен исходному
*/

void	adapt_capmatrix(t_lemin *lem)
{
	int **new_matrix;
	int new_rooms;
	int i;
	int j;

	if (ERROR)
		return ;
	new_rooms = (ROOMS_NUM - 2) * 2 + 2;
	if (!(new_matrix = ft_do_table(new_rooms, new_rooms)))
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
	if (!(old_matrix = ft_do_table(old_rooms, old_rooms)))
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
	ft_delete_table(&CAP_MATRIX, ROOMS_NUM);
	FLOW_MATRIX = old_matrix;
	ROOMS_NUM = old_rooms;

}
