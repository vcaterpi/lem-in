/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:00:51 by antondob          #+#    #+#             */
/*   Updated: 2020/07/31 17:42:10 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_is_number(char *str)
{
	if (!str || !(*str))
		return (0);
	if (!(ft_strchr("+-", *str)) && !(ft_isdigit(*str)))
		return (0);
	while (*(++str))
		if (!ft_isdigit(*str))
			return (0);
	return (1);
}
