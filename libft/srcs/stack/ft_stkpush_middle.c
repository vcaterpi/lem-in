/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush_middle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 15:12:51 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:47:29 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_stkpush_middle(t_stack **head,
	t_stack *after, void *data, size_t type_size)
{
	t_stack *new;
	t_stack *tmp;

	if (!(new = ft_memalloc(sizeof(t_stack))))
		return ;
	if (!(new->data = ft_memalloc(sizeof(int))))
	{
		free(new);
		return ;
	}
	tmp = (*head);
	while (tmp->next != after)
		tmp = tmp->next;
	ft_memcpy(new->data, data, type_size);
	tmp->next = new;
	new->next = after;
}
