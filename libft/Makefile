# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antondob <antondob@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 00:08:38 by antondob          #+#    #+#              #
#    Updated: 2020/09/16 16:32:40 by antondob         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# EXECUTABLES
LIB_NAME = 	libftprintf.a
# DIRECTORIES
OBJ_DIR = 	objs/
INCL_DIR = 	includes/
# HEADERS
HEADERS = 	libft.h\
			ft_printf.h
# SOURCES
SRCs = 		ft_isdigit.c\
			ft_lstmap.c\
			ft_memdel.c\
			ft_putnbr.c\
			ft_strcmp.c\
			ft_strjoin.c\
			ft_strncpy.c\
			ft_strsub.c\
			ft_isprint.c\
			ft_lstnew.c\
			ft_memmove.c\
			ft_putnbr_fd.c\
			ft_strcpy.c\
			ft_strlcat.c\
			ft_strnequ.c\
			ft_strtrim.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_memalloc.c\
			ft_memset.c\
			ft_putstr.c\
			ft_strdel.c\
			ft_strlen.c\
			ft_strnew.c\
			ft_tolower.c\
			ft_bzero.c\
			ft_lstadd.c\
			ft_memccpy.c\
			ft_putchar.c\
			ft_putstr_fd.c\
			ft_strdup.c\
			ft_strmap.c\
			ft_strnstr.c\
			ft_toupper.c\
			ft_isalnum.c\
			ft_lstdel.c\
			ft_memchr.c\
			ft_putchar_fd.c\
			ft_strcat.c\
			ft_strequ.c\
			ft_strmapi.c\
			ft_strrchr.c\
			ft_isalpha.c\
			ft_lstdelone.c\
			ft_memcmp.c\
			ft_putendl.c\
			ft_strchr.c\
			ft_striter.c\
			ft_strncat.c\
			ft_strsplit.c\
			ft_isascii.c\
			ft_lstiter.c\
			ft_memcpy.c\
			ft_putendl_fd.c\
			ft_strclr.c\
			ft_striteri.c\
			ft_strncmp.c\
			ft_strstr.c\
			ft_split_whitespaces.c\
			ft_sort_integer_table.c\
			ft_factorial.c\
			ft_is_prime.c\
			ft_power.c\
			ft_strchr_num.c\
			ft_strjoin_free.c\
			ft_strsub_free.c\
			ft_delete_table.c\
			ft_do_table.c\
			get_next_line.c\
			ft_max_2.c\
			ft_max_3.c\
			ft_min_2.c\
			ft_min_3.c\
			ft_putocta.c\
			ft_puthex_up.c\
			ft_puthex_low.c\
			ft_putpointer.c\
			ft_reverse_str.c\
			ft_strfill.c\
			pf_apply_params.c\
			pf_parse_params_1.c\
			pf_parse_params_2.c\
			pf_char_str.c\
			pf_itoa.c\
			pf_print_all.c\
			pf_process_arguments.c\
			pf_refresh_params.c\
			ft_printf.c\
			f_big_int_print.c\
			f_conv_float.c\
			f_get_fl.c\
			f_la_help.c\
			f_mult.c\
			f_pf_help.c\
			f_pow_mult.c\
			f_read_ll.c\
			ft_strndup.c\
			f_mem_error.c\
			f_float_help.c\
			ft_is_number.c\
			ft_stktop.c\
			ft_stkpush.c\
			ft_stkpop.c\
			ft_stkdel.c\
			ft_stkpop_back.c\
			ft_stkpush_back.c\
			ft_stksize.c\
			ft_stklast.c\
			ft_stkdel_node.c\
			ft_stkpush_middle.c\
			ft_double_new.c\
			ft_double_free.c\
			ft_double_len.c\
			ft_checkoverflow.c\
			ft_qpush.c\
			ft_qpop.c\
			ft_qdel.c
# OBJECTS
OBJ = $(patsubst %.c, %.o, $(SRCs))
# OBJECT_PATHS
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ))
# INCLUDES
INCLUDES = $(addprefix $(INCL_DIR), $(HEADERS))
# COMPILER
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
# PATHS
vpath %.h $(INCL_DIR)
vpath %.o $(OBJ_DIR)
vpath ft_double%.c srcs/table_char/
vpath ft_%_table.c srcs/table_int/
vpath ft_lst%.c srcs/list/
vpath ft_str%.c srcs/string/
vpath ft_reverse_str.c srcs/string/
vpath ft_split_whitespaces.c srcs/string/
vpath ft_printf.c srcs/printf/
vpath f_%.c srcs/printf/
vpath pf_%.c srcs/printf/
vpath ft_mem%.c srcs/memory/
vpath ft_bzero.c srcs/memory/
vpath ft_put%.c srcs/put/
vpath ft_q%.c srcs/queue/
vpath ft_stk%.c srcs/stack/
vpath get_next_line.c srcs/gnl/
vpath ft_min%.c srcs/math/
vpath ft_max%.c srcs/math/
vpath ft_power.c srcs/math/
vpath ft_factorial.c srcs/math/
vpath ft_is_prime.c srcs/math/
vpath %.c srcs/other/

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
		@ar rcs $(LIB_NAME) $(OBJ_PATH)
		@ranlib $(LIB_NAME)
		@echo "\033[0;93mLIBRARY COMPILATION: \033[1;92mSUCCESS\033[0m"

$(OBJ): %.o: %.c $(INCLUDES)
		@mkdir -p $(OBJ_DIR)
		$(COMPILER) $(FLAGS) -I $(INCL_DIR) -c $< -o $(OBJ_DIR)$@

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(LIB_NAME)

re: fclean all
