/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:15:36 by slynell           #+#    #+#             */
/*   Updated: 2020/09/19 19:43:29 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix_char(char ***matrix, int count_row)
{
	int i;

	i = -1;
	while (++i < count_row)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
}

void	ft_free_matrix_int(int ***matrix, int count_row)
{
	int i;

	i = -1;
	while (++i < count_row)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
}


void	ft_delete_table(int ***table, int rows)
{
	if (!table || !(*table))
		return ;
	while (--rows >= 0)
		free((*table)[rows]);
	free(*table);
	*table = NULL;
}
