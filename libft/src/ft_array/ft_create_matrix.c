/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:58:25 by slynell           #+#    #+#             */
/*   Updated: 2020/09/21 14:58:27 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_create_matrix_int(int size)
{
	int	i;
	int	j;
	int	**matrix;

	matrix = (int **)malloc(sizeof(int *) * (size + 1));
	i = -1;
	while (++i < size)
		matrix[i] = (int *)malloc(sizeof(int) * (size + 1));
	matrix[i] = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			matrix[i][j] = 0;
	}
	return (matrix);
}

int		**ft_do_table(int rows, int cols)
{
	int **table;

	if (!(table = (int**)malloc(sizeof(int*) * rows)))
		return (NULL);
	while (--rows >= 0)
	{
		if (!(table[rows] = (int*)malloc(sizeof(int*) * cols)))
		{
			ft_delete_table(&table, rows);
			return (NULL);
		}
		ft_bzero(table[rows], sizeof(int) * cols);
	}
	return (table);
}
