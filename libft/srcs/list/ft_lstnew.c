/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:05:13 by vcaterpi          #+#    #+#             */
/*   Updated: 2019/11/23 16:48:57 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*tmp;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = malloc(content_size)))
	{
		tmp = new;
		ft_memdel(&tmp);
		return (NULL);
	}
	new->content = (!content ? NULL :
		ft_memcpy(new->content, content, content_size));
	new->content_size = (!content ? 0 : content_size);
	new->next = NULL;
	return (new);
}
