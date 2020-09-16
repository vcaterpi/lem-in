/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:48:06 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 16:03:26 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define BASE 1000000000

typedef struct			s_params
{
	char				conv_spec;
	int					sign;
	int					space;
	int					alt;
	int					nul;
	int					width;
	int					preci;
	int					length;
	int					ret;
	int					char_nul;
	int					error;
	char				align;
	va_list				ap;
	char				*format;
	char				*str;
	char				preci_bool;
	int					mem_error;
}						t_params;

typedef struct			s_big_int
{
	int					sign;
	int					*arr;
	int					size;
}						t_big_int;

typedef struct			s_float
{
	unsigned long long	m;
	int					e;
	char				sign;
	char				*str;
	char				*intpart;
	char				*fraction;
}						t_float;

t_float					*get_params(long double f);
t_float					*get_fl(t_params *params);
char					*add_suffix(char *str, int count, char c);
int						get_str(t_float *fl);
int						ft_round(char **intpart, char *fraction, int end);
int						get_fstr(t_params *params, t_float *fl);
int						float_handler(t_params *params, t_float *fl);
int						conv_float(t_params *params);
int						mem_error(t_params *params);
int						mem_error2(t_params *params, t_float *fl);
char					*mem_error3(char **arr);
int						mem_error4(t_big_int *tmp, t_big_int *tmp1);
t_big_int				*mem_error_bi(t_big_int *new);
int						mem_error_int(t_big_int *new);
int						help_round(char **intpart, char **new, char *fraction);
int						fstr_help(t_params *params, t_float *fl,
						int point, int flen);
int						mem_error_int(t_big_int *new);
char					*add_prefix(char *str, int count, char c);
char					*ft_strstick(char **arr, int len, int size);
char					*big_int_tostr(t_big_int *b_int);
t_big_int				*big_int_new(int size);
void					big_int_del(t_big_int *b_int);
int						b_int_copy(t_big_int **dest, t_big_int *src);
void					b_int_unshift(t_big_int **bb_int);
int						b_int_push(t_big_int **bb_int, int push);
t_big_int				*b_int_div(t_big_int *b_int, int d);
t_big_int				*b_int_mult(t_big_int *b_int, int m);
int						ft_pow(int n, int p);
int						maxpower(int n);
t_big_int				*pow_div(t_big_int *big, int b, int pow);
t_big_int				*pow_mult(t_big_int *big, int b, int pow);
int						get_unumsize(unsigned long long n);
t_big_int				*read_ull(unsigned long long n);
int						ft_printf(const char *format, ...);
void					apply_flags(t_params *params);
void					init_params(t_params *params, char *format);
void					process_arguments(t_params *params);
void					parse_params(t_params *params);
void					pf_char_to_str(t_params *params, int c);
void					pf_itoa_int(t_params *params, long long arg);
void					pf_itoa_base(t_params *params,
									unsigned long long arg, int base);
void					clean_params(t_params *params);
void					print_string(t_params *params);
void					print_char(t_params *params, char c);
int						parse_flags(t_params *params);
void					print_errors(t_params *params);

#endif
