/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 02:06:07 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 15:01:57 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	lemin_error(void)
{
	ft_putstr_fd("ERROR", 2);
	exit(EXIT_FAILURE);
}
