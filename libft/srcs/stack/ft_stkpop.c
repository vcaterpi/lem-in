/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:51:30 by antondob          #+#    #+#             */
/*   Updated: 2020/09/03 16:28:17 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_stkpop(t_stack **head, size_t type_size)
{
	t_stack		*tmp;
	void		*data;

	if (!(*head))
		return (NULL);
	tmp = *head;
	(*head) = (*head)->next;
	if (!(data = ft_memalloc(type_size)))
		return (NULL);
	ft_memcpy(data, tmp->data, type_size);
	free(tmp->data);
	free(tmp);
	return (data);
}
