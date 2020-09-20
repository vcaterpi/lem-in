/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   lem_in.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: air_must <air_must@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/07/25 14:22:06 by slynell		   #+#	#+#			 */
/*   Updated: 2020/09/19 19:25:41 by air_must		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/header/libft.h"

enum					{ERROR, USAGE};

# define ANTS_NUM		lem->ants_num
# define ROOMS_NUM		lem->rooms_num
# define ROOMS			lem->rooms
# define ERROR			lem->error
# define FLOW_MATRIX	lem->flow_matrix
# define CAP_MATRIX		lem->capacity_matrix
# define PARENT			lem->parent
# define POINT			lem->point
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

typedef struct			s_lemin {
	int					ants_num;
	int					rooms_num;
	t_lst_point			*rooms;
	int					**capacity_matrix;
	int					**flow_matrix;
	int					*parent;
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
void					lst_print_lst(t_lst_point *lst, int depth);
t_lst_point				*lst_update_id(t_lst_point *tf);


/*
** ========================== LEM_IN FUNCTION =================================
*/

t_lemin					*lemin_create();
void					lemin_error();
t_lst_point				*lemin_read(t_lst_point *tf, t_lemin *lem);
void					lemin_free(t_lemin *lem);


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
