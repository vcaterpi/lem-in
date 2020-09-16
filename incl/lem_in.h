/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:42:18 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/16 13:02:08 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include "../libft/includes/ft_printf.h"

# define ANTS_NUM       params->ants_num
# define ROOMS_NUM      params->rooms_num
# define ERROR          params->error
# define ROOM_NAMES     params->room_names
# define FLOW_MATRIX    params->flow_matrix
# define CAP_MATRIX     params->capacity_matrix
# define PARENT         params->parent
# define DATA           *(int*)data

typedef    struct s_lemin 
{
    char    **room_names;
    int     **flow_matrix;
    int     **capacity_matrix;
    int     *parent;
    int     ants_num;
    int     rooms_num; 
	int		error;
    
}                  t_lemin;

/*
** Params processing
*/

void    params_init(t_lemin *params);
void    params_free(t_lemin *params);

/*
** Algorightm functions
*/

void	apply_algo(t_lemin *params);
void	adapt_capmatrix(t_lemin *params);
void    adapt_flowmatrix(t_lemin *params);
void	parent_zero(t_lemin *params);

/*
** Test functions
*/
void    test_params(t_lemin *params);
void    print_matrix(t_lemin *params);
void    print_graph(t_lemin *params);
void    print_paths(t_lemin *params, int curr);
void    print_flowmatrix(t_lemin *params);
void    print_capmatrix(t_lemin *params);
void    print_max_flow(t_lemin *params);

/*
**	List of errors
**	1 - 
** 	2 - 
*/

#endif