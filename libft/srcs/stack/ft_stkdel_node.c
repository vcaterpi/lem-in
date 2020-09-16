/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkdel_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 12:53:16 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:45:00 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_stkdel_node(t_stack **head, t_stack **node)
{
	t_stack *tmp;

	if (!head || !(*head))
		return ;
	tmp = (*head);
	while (tmp && tmp->next != *node)
		tmp = tmp->next;
	if (!tmp)
		return ;
	tmp->next = (*node)->next;
	free((*node)->data);
	free((*node));
	(*node) = tmp->next;
}
