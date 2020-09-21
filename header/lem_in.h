/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/09/21 14:56:09 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/header/libft.h"

# define ANTS_NUM		lem->ants_num
# define ANTS			lem->ants
# define ROOMS_NUM		lem->rooms_num
# define ROOMS			lem->rooms
# define ERROR			lem->error
# define FLOW_MATRIX	lem->flow_matrix
# define CAP_MATRIX		lem->capacity_matrix
# define PARENT			lem->parent
# define PATH			lem->path
# define DATA			*(int*)data

typedef struct			s_lst_point {
	struct s_lst_point	*prev;
	struct s_lst_point	*next;
	char				*name;
	int					id;
	int					x;
	int					y;
	int					ex;
}						t_lst_point;

typedef struct			s_lst_ants {
	struct s_lst_ants	*prev;
	struct s_lst_ants	*next;
	int					ant_id;
	int					room_id;
	int					path_id;
	int					index;
}						t_lst_ants;

typedef struct			s_lst_path {
	struct s_lst_path	*prev;
	struct s_lst_path	*next;
	int					path_id;
	int					length;
	int					counter;
	int					*rooms;
}						t_lst_path;

typedef struct			s_lemin {
	int					ants_num;
	t_lst_ants			*ants;
	int					rooms_num;
	t_lst_point			*rooms;
	int					**capacity_matrix;
	int					**flow_matrix;
	int					*parent;
	t_lst_path			*path;
	int					error;
}						t_lemin;

/*
** ========================= FUNCTION LIST POINT ==============================
*/
t_lst_point				*lst_create();
t_lst_point				*lst_add(t_lst_point *lst);
int						lst_length(t_lst_point *lst);
t_lst_point				*lst_get_start(t_lst_point *lst);
void					lst_free(t_lst_point *lst);
int						lst_check(t_lst_point *lst);
t_lst_point				*lst_get_by_name(t_lst_point *lst, char *name);
t_lst_point				*lst_get_by_id(t_lst_point *lst, int point_id);
void					lst_print_lst(t_lst_point *lst, int depth);
t_lst_point				*lst_update_id(t_lst_point *tf);

/*
** ========================== FUNCTION LIST PATH ==============================
*/
t_lst_ants				*lst_ants_create();
t_lst_ants				*lst_ants_add(t_lst_ants *lst);
int						lst_ants_length(t_lst_ants *lst);
t_lst_ants				*lst_ants_get_start(t_lst_ants *lst);
void					lst_ants_free(t_lst_ants *lst);
t_lst_ants				*lst_ants_get_by_id(t_lst_ants *lst, int path_id);
void					lst_ants_print_lst(t_lst_ants *lst, int depth);

/*
** ========================== FUNCTION LIST ANTS ==============================
*/
t_lst_path				*lst_path_create();
t_lst_path				*lst_path_add(t_lst_path *lst);
int						lst_path_length(t_lst_path *lst);
t_lst_path				*lst_path_get_start(t_lst_path *lst);
void					lst_path_free(t_lst_path *lst);
t_lst_path				*lst_path_get_by_id(t_lst_path *lst, int ant_id);
void					lst_path_print_lst(t_lst_path *lst, int depth);

/*
** ========================== LEM_IN FUNCTION =================================
*/

t_lemin					*lemin_create();
void					lemin_error();
t_lst_point				*lemin_read(t_lst_point *tf, t_lemin *lem);
void					lemin_free(t_lemin *lem);
void					get_path(t_lemin *lem);
void					distribution_ants(t_lemin *lem);

/*
** Params processing
*/

void					params_init(t_lemin *lem);
void					params_free(t_lemin *lem);

/*
** Algorightm functions
*/

void					apply_algo(t_lemin *lem);
void					adapt_capmatrix(t_lemin *lem);
void					adapt_flowmatrix(t_lemin *lem);
void					parent_zero(t_lemin *lem);

/*
** Test functions
*/
void					test_params(t_lemin *lem);
void					print_matrix(t_lemin *lem);
void					print_graph(t_lemin *lem);
void					print_paths(t_lemin *lem, int curr);
void					print_flowmatrix(t_lemin *lem);
void					print_capmatrix(t_lemin *lem);
void					print_max_flow(t_lemin *lem);

#endif
