/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:55:17 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/03/14 15:04:55 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_stkdel(t_stack **head, size_t type_size)
{
	if (!head || !(*head))
		return ;
	while (*head)
		free(ft_stkpop(head, type_size));
}
