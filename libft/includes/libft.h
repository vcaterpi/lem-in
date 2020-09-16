/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:29:44 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/09/04 14:17:27 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define NEW_TYPE
# define BUFF_SIZE 1000

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	void			*data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_queue
{
	void			*data;
	struct s_queue	*next;
}					t_queue;

void				*ft_memset(void *buf, int c, size_t n);
void				ft_bzero(void *buf, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *buf, int c, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *str);
char				**ft_strsplit(char const *str, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_factorial(int nb);
int					ft_power(int nb, int power);
void				ft_sort_integer_table(int *tab, int size);
char				**ft_split_whitespaces(char const *str);
int					ft_is_prime(int nb);
void				ft_double_free(char **str, int i);
int					ft_double_len(char **arr);
char				**ft_double_new(int nwords, int wordlen);
int					ft_strchr_num(const char *str, int c);
char				*ft_strjoin_free(char const *s1, char const *s2);
char				*ft_strsub_free(char const *s, unsigned int start,
						size_t len);
int					**ft_do_table(int rows, int cols);
void				ft_delete_table(int ***table, int rows);
int					get_next_line(const int fd, char **line);
int					ft_max_2(int a, int b);
int					ft_max_3(int a, int b, int c);
int					ft_min_2(int a, int b);
int					ft_min_3(int a, int b, int c);
void				ft_putocta(int nbr);
void				ft_puthex_up(int nbr);
void				ft_puthex_low(int nbr);
void				ft_putpointer(long int p);
char				*ft_reverse_str(char *str);
void				ft_strfill(char *str, char c, int repeat);
char				*ft_strndup(const char *str, int i);
int					ft_is_number(char *str);
void				ft_stkpush(t_stack **head, void *data, size_t type_size);
void				*ft_stkpop(t_stack **head, size_t type_size);
void				*ft_stktop(t_stack **head);
void				ft_stkdel(t_stack **head, size_t type_size);
void				ft_stkpush_back(t_stack **head,\
						void *data, size_t type_size);
void				*ft_stkpop_back(t_stack **head, size_t type_size);
int					ft_stksize(t_stack *head);
void				*ft_stklast(t_stack *head, size_t type_size);
void				ft_stkdel_node(t_stack **head, t_stack **node);
void				ft_stkpush_middle(t_stack **head, t_stack *after,\
						void *data, size_t type_size);
int					ft_checkoverflow(int nbr, char *str);
void				ft_qpush(t_queue **head, void *data, size_t type_size);
void				*ft_qpop(t_queue **head, size_t type_size);
void				ft_qdel(t_queue **head);

#endif
