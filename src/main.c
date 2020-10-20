/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/10/20 21:32:31 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int		main(void)
{
	t_lemin		*lem;

	lem = lemin_create();
	lemin_read(ROOMS, lem);
	if (ROOMS_NUM == -1)
		lemin_error();
	lemin_rooms_clear(lem);
	lem = apply_algo(lem);
	optimize_lem(lem);
	print_rooms(lem);
	print_links(lem);
	print_ants(lem);
	lemin_free(lem);
	return (0);
}
