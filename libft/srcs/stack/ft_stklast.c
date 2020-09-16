/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stklast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:25:07 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:46:20 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_stklast(t_stack *head, size_t type_size)
{
	void	*data;

	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	if (!(data = ft_memalloc(type_size)))
		return (NULL);
	ft_memcpy(data, head->data, type_size);
	return (data);
}
