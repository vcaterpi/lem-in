# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: air_must <air_must@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/09/19 19:39:05 by air_must         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

CC = gcc

FLAGS = -Wall -Werror -Wextra -O2
# -Wall -Werror -Wextra -O2

# /*
# ** ========================== HEADER ==============================
# */
INCS = lem_in.h
IDIR = header
INCS += $(addprefix $(LDIR)/,$(addprefix $(IDIR)/,$(libft.h)))
INCLUDES = $(addprefix $(IDIR)/,$(INCS))

LDIR = libft
LIBFT = $(addprefix $(LDIR)/,libft.a)


# /*
# ** ====================== SOURCE LS MAIN ==========================
# */
SDIR = src
ODIR = obj

SRCS = main.c
SRCS += lemin_create.c
SRCS += lemin_error.c
SRCS += lemin_read.c
SRCS += lemin_free.c
SRCS += algo_apply.c
SRCS += algo_help.c
SRCS += print_test.c

# SRCS += ls_read.c
# SRCS += ls_print_lst_file.c


SOURCES = $(addprefix $(SDIR)/,$(SRCS))
OBJECTS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

# /*
# ** ====================== SOURCE LST FILE ==========================
# */
SDIR_LST_FILE = src/lst_point
ODIR_LST_FILE = obj/lst_point

SRC_LST_FILE = lst_add.c
SRC_LST_FILE += lst_create.c
SRC_LST_FILE += lst_free.c
SRC_LST_FILE += lst_get_start.c

# SRC_LST_FILE += ls_lst_reverse.c
# SRC_LST_FILE += ls_lst_swap.c
SRC_LST_FILE += lst_length.c
# SRC_LST_FILE += ls_lst_sort_by_atime.c
# SRC_LST_FILE += ls_lst_sort_by_ctime.c
# SRC_LST_FILE += ls_lst_sort_by_mtime.c
# SRC_LST_FILE += ls_lst_sort_by_name.c
# SRC_LST_FILE += ls_lst_is_root.c
SRC_LST_FILE += lst_get_by_name.c
SRC_LST_FILE += lst_check.c
SRC_LST_FILE += lst_print_lst.c
SRC_LST_FILE += lst_update_id.c
# SRC_LST_FILE += ls_lst_insert.c
# SRC_LST_FILE += ls_lst_ind.c
# SRC_LST_FILE += ls_lst_name_max_length.c



SOURCES_LST_FILE = $(addprefix $(SDIR_LST_FILE)/,$(SRC_LST_FILE))
OBJECTS_LST_FILE = $(addprefix $(ODIR_LST_FILE)/,$(SRC_LST_FILE:.c=.o))


.PHONY: clean fclean all re

all :  $(LIBFT) $(NAME)
	@make -C $(LDIR) 2> tmp.log
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log

$(NAME) :  $(LIBFT) $(OBJECTS) $(OBJECTS_LST_FILE) $(INCLUDES) Makefile
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(OBJECTS_LST_FILE)  -I $(IDIR) $(LIBFT)
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE LIBFT ==========================
# */
$(LIBFT) :
	@make -C $(LDIR) 2> tmp.log

# /*
# ** ====================== MAKE LST POINT ==========================
# */
$(ODIR_LST_FILE)/%.o : $(SDIR_LST_FILE)/%.c $(INCLUDES) Makefile
	@if [[ $< == src/lst_point/lst_add.c ]]; then \
		echo "\n > Make \033[33mlst_point\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_LST_FILE) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== SOURCE LS MAIN  ==========================
# */
$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES) Makefile
	@if [[ $< == src/main.c ]]; then \
		echo "Make \033[33m$(NAME)\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


clean:
	@make clean -C $(LDIR) 2> tmp.log
	@rm -rf $(OBJS) 2> tmp.log
	@rm -rf $(ODIR) 2> tmp.log

fclean: clean
	@make fclean -C $(LDIR) 2> tmp.log
	@rm -rf $(NAME) 2> tmp.log
	@echo "\033[31m> Clear $(NAME)\033[0m"

re: fclean all
