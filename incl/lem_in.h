/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:42:18 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/19 16:14:42 by antondob         ###   ########.fr       */
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
# define POINT          params->point
# define DATA           *(int*)data

typedef struct			s_lst_point {
	struct s_lst_point	*prev;
	struct s_lst_point	*next;
	char				*name;
	int					id;
	int					x;
	int					y;
	int					ex;
}						t_lst_point;

typedef    struct s_lemin 
{
    t_lst_point *point;
    int         **flow_matrix;
    int         **capacity_matrix;
    int         *parent;
    int         ants_num;
    int         rooms_num; 
	int	        error;
    
}                  t_lemin;


/*
** Parser
*/

t_lst_point				*lst_create();
t_lst_point				*lst_add(t_lst_point *lst);
int						lst_length(t_lst_point *lst);
t_lst_point				*lst_get_start(t_lst_point *lst);
void					lst_free(t_lst_point *lst);
int						lst_check(t_lst_point *lst);
t_lst_point				*lst_get_by_name(t_lst_point *lst, char *name);
void					lst_print_lst(t_lst_point *lst, int depth);

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
** Errors
*/

void					err();

/*
**	List of errors
**	1 - 
** 	2 - 
*/

#endif