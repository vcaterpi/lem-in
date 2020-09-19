/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:47:33 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/19 16:17:31 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     main()
{
	t_lemin params;

	// --> initialize_common_structure
	params_init(&params);

	// *** for test purpose only ***
	/*test_params(&params);
	ft_putstr("\n**** BEFORE ALGORITHM ***\n");
	print_capmatrix(&params);
	ft_putstr("**** BEFORE ALGORITHM ***\n");
	apply_algo(&params);
	ft_putstr("\n**** AFTER ALGORITHM ***\n");
	ft_putstr("--> FLOW_MATRIX \n");
	print_flowmatrix(&params);
	ft_putstr("\n--> PATHS \n");
	print_paths(&params, 0);
	ft_putstr("\n--> MAX_FLOW \n");
	print_max_flow(&params);
	ft_putstr("**** AFTER ALGORITHM ***\n\n");
	*/
	// --> read_and_validate_input
	lem = le
	// --> apply algorithm

	// --> print result

	// --> free_common_structure
	params_free(&params);
}