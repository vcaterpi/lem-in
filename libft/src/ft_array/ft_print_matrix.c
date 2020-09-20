/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:06:56 by air_must          #+#    #+#             */
/*   Updated: 2020/09/19 17:12:45 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_print_matrix_int(int **matrix, int count)
{
	int i;
	int j;

	i = -1;
	ft_printf("Matrix: \n");
	while (++i < count)
	{
		j = -1;
		while (++j < count)
			ft_printf("%d ", matrix[i][j]);
		ft_printf("\n");
	}
}
