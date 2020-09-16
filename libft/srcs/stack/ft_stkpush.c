/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:31:34 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:48:53 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_stkpush(t_stack **head, void *data, size_t type_size)
{
	t_stack *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_stack))))
		return ;
	if (!(tmp->data = ft_memalloc(type_size)))
	{
		free(tmp);
		tmp = NULL;
		return ;
	}
	ft_memcpy(tmp->data, data, type_size);
	tmp->next = (*head);
	(*head) = tmp;
}
