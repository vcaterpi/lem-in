/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2020/11/09 16:52:19 by vcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/header/libft.h"
# include <time.h>

# define INF            20000
# define ANTS_NUM		lem->ants_num
# define ANTS			lem->ants
# define ROOMS_NUM		lem->rooms_num
# define ROOMS			lem->rooms
# define ERROR			lem->error
# define FLOW_MATRIX	lem->flow_matrix
# define CAP_MATRIX		lem->capacity_matrix
# define WEIGHT_MATRIX	lem->weight_matrix
# define PARENT			lem->parent
# define DISTANCE		lem->distance
# define POTENTIAL		lem->potential
# define PATH			lem->path
# define PATH_NUM		lem->path_num
# define DATA			*(int*)data
# define ROOM_LAST		lem->rooms_num - 1
# define PATH_LAST		lem->path_num - 1
# define ARR_ROOM		lem->arr_room
# define ARR_ANTS		lem->arr_ants
# define ARR_PATH		lem->arr_path
# define ANTS_NUM_PATH 	path->ants_num
# define PATH_LEN		path->length
# define STEPS          lem->steps_num
# define COND_1			(prev = lem->arr_ants[p->ants[i - 1]])->room_id != 0
# define COND_2			prev->room_id != p->rooms[1]
# define COND_3			((a = lem->arr_ants[p->ants[i]])->room_id != ROOM_LAST)
# define COND_4			(a->room_id = p->rooms[++(a->index)]) == ROOM_LAST
# define COND_5			(lem->arr_room[a->room_id])->name
# define COND_6			!(operand[0] && operand[1] && !operand[2])
# define COND_7			prev->room_id == ROOM_LAST

typedef struct			s_lst_rooms {
	struct s_lst_rooms	*prev;
	struct s_lst_rooms	*next;
	char				*name;
	int					id;
	int					x;
	int					y;
	int					ex;
}						t_lst_rooms;

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
	int					ants_num;
	int					counter;
	int					*ants;
	int					*rooms;
}						t_lst_path;

typedef struct			s_lst_text {
	struct s_lst_text	*prev;
	struct s_lst_text	*next;
	char				*line;
}						t_lst_text;

typedef struct			s_lemin {
	t_lst_ants			*ants;
	t_lst_rooms			*rooms;
	t_lst_path			*path;
	t_lst_text			*text;
	t_lst_ants			**arr_ants;
	t_lst_path			**arr_path;
	t_lst_rooms			**arr_room;
	int					**capacity_matrix;
	int					**flow_matrix;
	int					**weight_matrix;
	int					steps_num;
	int					ants_num;
	int					rooms_num;
	int					path_num;
	int					*parent;
	int					*potential;
	int					*distance;
	int					error;
}						t_lemin;

typedef struct			s_min
{
	int					room;
	int					dist;
}						t_min;

/*
** ========================== FUNCTION LIST TEXT ==============================
*/
t_lst_text				*lst_text_create();
t_lst_text				*lst_text_add(t_lst_text *lst);
t_lst_text				*lst_text_get_start(t_lst_text *lst);
void					lst_text_free(t_lst_text *lst);

/*
** ========================= FUNCTION LIST POINT ==============================
*/
t_lst_rooms				*lst_room_create();
t_lst_rooms				*lst_room_add(t_lst_rooms *lst);
int						lst_room_length(t_lst_rooms *lst);
t_lst_rooms				*lst_room_get_start(t_lst_rooms *lst);
void					lst_room_free(t_lst_rooms *lst);
int						lst_room_check(t_lst_rooms *lst);
t_lst_rooms				*lst_room_get_by_name(t_lst_rooms *lst, char *name);
t_lst_rooms				*lst_room_get_by_id(t_lst_rooms *lst, int point_id);
void					lst_room_print_lst(t_lst_rooms *lst, int depth);
t_lst_rooms				*lst_room_update_id(t_lst_rooms *tf);
t_lst_rooms				**lst_room_array(t_lst_rooms *lst, int size);
t_lst_rooms				*lst_room_free_one(t_lst_rooms *rooms);
t_lst_rooms				*lst_room_free_two(t_lst_rooms *rooms);

/*
** ========================== FUNCTION LIST PATH ==============================
*/
t_lst_ants				*lst_ants_create();
t_lst_ants				*lst_ants_add(t_lst_ants *lst);
int						lst_ants_length(t_lst_ants *lst);
t_lst_ants				*lst_ants_get_start(t_lst_ants *lst);
void					lst_ants_free(t_lst_ants *lst);
t_lst_ants				*lst_ants_get_by_id(t_lst_ants *lst, int ant_id);
void					lst_ants_print_lst(t_lst_ants *lst, int depth);
t_lst_path				**lst_path_array(t_lst_path *lst, int size);
void					refresh_path(t_lemin *lem);

/*
** ========================== FUNCTION LIST ANTS ==============================
*/
t_lst_path				*lst_path_create();
t_lst_path				*lst_path_add(t_lst_path *lst);
int						lst_path_length(t_lst_path *lst);
t_lst_path				*lst_path_get_start(t_lst_path *lst);
void					lst_path_free(t_lst_path *lst);
t_lst_path				*lst_path_get_by_id(t_lst_path *lst, int path_id);
void					lst_path_print_lst(t_lst_path *lst, int depth);
t_lst_ants				**lst_ants_array(t_lst_ants *lst, int size);
t_lst_ants				*create_ants(t_lemin *lem);
void					refresh_ants(t_lemin *lem);

/*
** ========================== LEM_IN FUNCTION =================================
*/

t_lemin					*lemin_create();
t_lemin					*lemin_backup(t_lemin *result, t_lemin *lem, int steps);
void					lemin_error();
t_lst_rooms				*lemin_read(t_lst_rooms *tf, t_lemin *lem);
void					lemin_free(t_lemin *lem);
void					get_path(t_lemin *lem);
void					distribution_ants(t_lemin *lem);
void					print_ants(t_lemin *lem);
void					print_rooms(t_lemin *lem);
void					print_links(t_lemin *lem);
void					lemin_rooms_clear(t_lemin *lem);
void					optimize_lem(t_lemin *lem);
void					refresh_all(t_lemin *lem, int **matrix);
void					fill_potential(t_lemin *lem);

/*
** Params processing
*/

void					params_init(t_lemin *lem);
void					params_free(t_lemin *lem);

/*
** Algorightm functions
*/

t_lemin					*apply_algo(t_lemin *lem);
int						**adapt_capmatrix(t_lemin *lem);
void					adapt_flowmatrix(t_lemin *lem, int **matrix);
void					parent_zero(t_lemin *lem);
void					do_all_matrix(t_lemin *lem);
void					fill_distance(t_lemin *lem);
void					fill_weight_matrix(t_lemin *lem);
void					count_all_distance_ford(t_lemin *lem, int *inq,
							void *data, t_queue **q);
void					count_all_distance_dkst(t_lemin *lem, int *vst,
							t_min *min, int v);

/*
** Print and test functions
*/
void					test_params(t_lemin *lem);
void					print_matrix(t_lemin *lem);
void					print_graph(t_lemin *lem);
void					print_paths(t_lemin *lem, int curr);
void					print_flowmatrix(t_lemin *lem);
void					print_text_inst(t_lemin *lem);
void					print_capmatrix(t_lemin *lem);
void					print_max_flow(t_lemin *lem);
void					print_ants_in_path(t_lemin *lem, t_lst_path *p,
							int *flag);

#endif
