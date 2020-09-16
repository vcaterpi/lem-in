/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:28:06 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/03/13 18:50:55 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_stkpop_back(t_stack **head, size_t type_size)
{
	t_stack		*tmp;
	void		*data;

	if (!(*head) || !((*head)->next))
		return (ft_stkpop(head, type_size));
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	if (!(data = ft_memalloc(type_size)))
		return (NULL);
	ft_memcpy(data, tmp->next->data, type_size);
	free(tmp->next->data);
	free(tmp->next);
	tmp->next = NULL;
	return (data);
}
