/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 23:51:10 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:36:37 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_table(int ***table, int rows)
{
	if (!table || !(*table))
		return ;
	while (--rows >= 0)
		free((*table)[rows]);
	free(*table);
	*table = NULL;
}
