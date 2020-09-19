/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: air_must <air_must@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:22:06 by slynell           #+#    #+#             */
/*   Updated: 2020/09/18 02:13:19 by air_must         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/header/libft.h"

# define L_OPT 		1
# define RR_OPT 	2
# define A_OPT 		4
# define R_OPT 		8
# define T_OPT 		16
# define U_OPT 		32
# define ONE_OPT	64
# define S_OPT		128
# define C_OPT		256

enum					{ERROR, USAGE};

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
	int					**mat;
	int					ant;
	int					count;
}						t_lemin;

/*
** ========================== FUNCTION LIST FILES ==============================
*/
t_lst_point				*lst_create();
t_lst_point				*lst_add(t_lst_point *lst);
int						lst_length(t_lst_point *lst);

// t_lst_file				*ls_lst_insert(t_lst_file *root,\
// 						t_lst_file *lst, int *s, int x);
t_lst_point				*lst_get_start(t_lst_point *lst);
// t_lst_file				*ls_lst_reverse(t_lst_file *lst);
void					lst_free(t_lst_point *lst);
int						lst_check(t_lst_point *lst);
t_lst_point				*lst_get_by_name(t_lst_point *lst, char *name);
// t_lst_file				*ls_lst_swap(t_lst_file *lst);
// int						ls_lst_sort_by_atime(t_lst_file *lst);
// int						ls_lst_sort_by_ctime(t_lst_file *lst);
// int						ls_lst_sort_by_mtime(t_lst_file *lst);
// int						ls_lst_sort_by_name(t_lst_file *lst);
// int						ls_root(t_lst_file *lst);
// t_lst_file				*ls_lst_sort(t_lst_file *lst, int opt);
void					lst_print_lst(t_lst_point *lst, int depth);
// t_lst_file				*lst_get_by_name(t_lst_file *lst, int index,\
// 						int is_hidden);
// size_t					ls_lst_name_max_length(t_lst_file *lst);


/*
** ========================== LEM_IN FUNCTION =================================
*/

void					err();
#endif
