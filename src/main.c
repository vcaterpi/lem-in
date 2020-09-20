/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/09/19 21:25:09 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"



int main(void)
{
	t_lemin *lem;

	lem = lemin_create();
	lemin_read(ROOMS, lem);
	apply_algo(lem);
	ft_putstr("\n--> PATHS \n");
	print_paths(lem, 0);
	ft_putstr("\n--> MAX_FLOW \n");
	print_max_flow(lem);
	ft_putstr("**** AFTER ALGORITHM ***\n\n");
	lemin_free(lem);
	return (0);
}
