/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:04 by slynell           #+#    #+#             */
/*   Updated: 2020/09/19 16:16:56 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void ft_free_matrix_char(char ***matrix, int count_row)
{
	int i;

	i = -1;
	while (++i < count_row)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
}

void ft_free_matrix_int(int ***matrix, int count_row)
{
	int i;

	i = -1;
	while (++i < count_row)
		free((*matrix)[i]);
	free(*matrix);
	*matrix = NULL;
}

t_lst_point *reconstr(t_lst_point *tf, char *line, int ex)
{
	char **operand;
	tf->x = 0;

	operand = ft_strsplit(line, ' ');
	if (operand[0] && operand[1] && operand[2] && !operand[3])
	{
		tf->name = ft_strdup(operand[0]);
			tf->x = ft_atoi(operand[1]);
			tf->y = ft_atoi(operand[2]);
		tf->id = lst_length(tf) - 1;
		tf->ex = ex;
		if (!lst_check(tf))
			err();
		ft_strsplitfree(&operand);
		return (tf);
	}
	ft_strsplitfree(&operand);
	operand = ft_strsplit(line, '-');
	if (operand[0] && operand[1] && !operand[2])
	{
		ft_strsplitfree(&operand);
		return (tf);
	}
	err();
	return (NULL);
}

void err()
{
	ft_dprintf(STDERR_FILENO, "ERROR\n");
	exit(EXIT_FAILURE);
}

t_lst_point *to_read_room(t_lst_point *tf, int *is_ref, int *ex, char *line)
{
	if (ft_strequ(line, "##start"))
		*ex = 0;
	else if (ft_strequ(line, "##end"))
		*ex = 1;
	else if (line[0] != '#' && line[0] != 'L')
	{
		tf = (tf) ? lst_add(tf) : lst_create();
		tf = reconstr(tf, line, *ex);
		if (tf->id == -1)
			*is_ref = 1;
		*ex = -1;
	}
	return (tf);
}

t_lst_point *lst_update_id(t_lst_point *tf)
{
	t_lst_point *temp_lst;
	int c;

	c = 1;
	temp_lst = tf;
	while(temp_lst && temp_lst->next)
	{
		if(temp_lst->ex == 0){
			temp_lst->id = 0;
		}
		else if(temp_lst->ex == 1)
			temp_lst->id = lst_length(tf) - 2;
		else if(temp_lst->id != -1){
			temp_lst->id = c++;
		}
		ft_printf("%d -> ", temp_lst->id);
		temp_lst = temp_lst->next;
	}
	ft_printf("|\n");
	return (tf);
}

void create_grid(t_lemin *tf, t_lst_point *po)
{
	int i;
	int j;

	tf->count = lst_length(po) - 1;
	tf->mat = (int **)malloc(sizeof(int *) * (tf->count + 1));
	i = -1;
	while (++i < tf->count)
		tf->mat[i] = (int *)malloc(sizeof(int) * (tf->count + 1));
	tf->mat[i] = 0;
	i = -1;
	while (++i < tf->count)
	{
		j = -1;
		while (++j < tf->count)
			tf->mat[i][j] = 0;
	}
}

void print_lem(t_lemin *lem)
{
	int i;
	int j;

	i = -1;
	ft_printf("\n");
	while (++i < lem->count)
	{
		j = -1;
		while (++j < lem->count)
			ft_printf("%d ", lem->mat[i][j]);
		ft_printf("\n");
	}
}

t_lemin *to_read_link(t_lst_point *tf, char *line, int is_ref, t_lemin *lem)
{
	char **operand;

	if (is_ref == 1)
	{
		create_grid(lem, tf);
	}
	if (line[0] != '#' && line[0] != 'L')
	{
		operand = ft_strsplit(line, '-');
		if (operand[0] && operand[1] && !operand[2])
		{
			if (lst_get_by_name(tf, operand[0]) != NULL && lst_get_by_name(tf, operand[1]) != NULL)
			{
				lem->mat[lst_get_by_name(tf, operand[0])->id][lst_get_by_name(tf, operand[1])->id] = 1;
				lem->mat[lst_get_by_name(tf, operand[1])->id][lst_get_by_name(tf, operand[0])->id] = 1;
			}
			else
				err();
			ft_strsplitfree(&operand);
			return (lem);
		}
		err();
		ft_strsplitfree(&operand);
	}
	return lem;
}

t_lst_point *read_ants(t_lst_point *tf, t_lemin *lem)
{
	char *line;
	int ex;
	int is_ref;

	is_ref = -1;
	ex = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (is_ref == -1 && ft_strlen(line) < 11 && ft_atoi(line) > 0)
		{
			is_ref += 1;
			lem->ant = ft_atoi(line);
		}
		else if (lem->ant == -1)
			err();
		else if (is_ref == 0)
		{
			tf = to_read_room(tf, &is_ref, &ex, line);
		}
		if (is_ref >= 1)
		{
			tf = lst_update_id(lst_get_start(tf));

			lem = to_read_link(tf, line, is_ref, lem);
			is_ref++;
		}
		ft_strdel(&line);
	}
	return (tf);
}

t_lemin *lemin_create()
{
	t_lemin *lst;

	if (!(lst = (t_lemin *)malloc(sizeof(t_lemin))))
		err();
	lst->mat = NULL;
	lst->ant = -1;
	lst->count = -1;
	return (lst);
}

int main(void)
{
	t_lst_point *obj;
	t_lemin *lem;

	lem = lemin_create();
	obj = lst_create();
	obj = read_ants(obj, lem);
	lst_print_lst(lst_get_start(obj), 1);
	print_lem(lem);
	ft_free_matrix_int(&lem->mat, lem->count);
	free(lem);
	lst_free(obj);
	return (0);
}
