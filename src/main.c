/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/11/03 19:56:10 by air_must         ###   ########.fr       */
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
	if (lst_path_length(lem->path) == 0)
		lemin_error();
	print_text_inst(lem);
	print_ants(lem);
	lemin_free(lem);
	return (0);
}
