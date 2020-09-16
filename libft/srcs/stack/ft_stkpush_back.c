/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:16:46 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/07/31 17:48:24 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	ft_stkpush_back(t_stack **head, void *data, size_t type_size)
{
	t_stack *tmp;
	t_stack *new;

	if (!(new = ft_memalloc(sizeof(t_stack))))
		return ;
	if (!(new->data = ft_memalloc(type_size)))
	{
		free(new);
		new = NULL;
		return ;
	}
	ft_memcpy(new->data, data, type_size);
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
