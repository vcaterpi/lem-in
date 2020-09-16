/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:05:45 by antondob          #+#    #+#             */
/*   Updated: 2020/09/16 14:35:17 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Вывод тестовых параметров
*/

/*
** Вывод размера максимального потока в сети
*/

void print_max_flow(t_lemin *params)
{
	int i;
	int maxflow;

	i = -1;
	maxflow = 0;
	while (++i < ROOMS_NUM)
		maxflow += FLOW_MATRIX[0][i];
	ft_printf("maxflow = %d\n", maxflow);
}

/*
** Вывод всех найденных непересекающихся путей
*/

void print_paths(t_lemin *params, int curr)
{
	int j;

	if (curr == ROOMS_NUM - 1)
	{
		ft_printf("\n");
		return ;
	}
	j = -1;
	while (++j < ROOMS_NUM)
	{
		if (FLOW_MATRIX[curr][j] == 1)
		{
			if (curr == 0)
				ft_printf("%d -> %d", curr, j);
			else 
				ft_printf(" -> %d", j);
			print_paths(params, j);
		}
	}
}

/*
** Вывод матрицы остаточных пропускных способностей
*/

void print_capmatrix(t_lemin *params)
{
	int i;
	int j;

	i = -1;
	while (++i <= (ROOMS_NUM - 1))
	{
		j = -1;
		while (++j <= (ROOMS_NUM - 1))
			ft_printf("%3d ", CAP_MATRIX[i][j]);
		ft_printf("\n");
	}
}

/*
** Вывод матрицы потоков
*/

void print_flowmatrix(t_lemin *params)
{
	int i;
	int j;

	i = -1;
	while (++i <= (ROOMS_NUM - 1))
	{
		j = -1;
		while (++j <= (ROOMS_NUM - 1))
			ft_printf("%3d ", FLOW_MATRIX[i][j]);
		ft_printf("\n");
	}
}
