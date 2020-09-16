/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:01:29 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/09/25 22:32:07 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *new_el;
	t_list *prev_el;

	if (!lst || !(*f))
		return (NULL);
	new = f(lst);
	prev_el = new;
	lst = lst->next;
	while (lst)
	{
		new_el = f(lst);
		prev_el->next = new_el;
		prev_el = new_el;
		lst = lst->next;
	}
	prev_el->next = NULL;
	return (new);
}
