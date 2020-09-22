# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antondob <antondob@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/09/23 02:31:58 by antondob         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

FLAGS = -Wall
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
SRCS += lemin_path.c
SRCS += lemin_ants.c
SRCS += algo_apply.c
SRCS += algo_help.c
SRCS += print_test.c

# SRCS += ls_read.c
# SRCS += ls_print_lst_file.c


SOURCES = $(addprefix $(SDIR)/,$(SRCS))
OBJECTS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

# /*
# ** ====================== SOURCE LST ROOM ==========================
# */
SDIR_LST_ROOM = src/lst_room
ODIR_LST_ROOM = obj/lst_room

SRC_LST_ROOM = lst_room_add.c
SRC_LST_ROOM += lst_room_create.c
SRC_LST_ROOM += lst_room_free.c
SRC_LST_ROOM += lst_room_get_start.c
SRC_LST_ROOM += lst_room_length.c
SRC_LST_ROOM += lst_room_get_by_name.c
SRC_LST_ROOM += lst_room_get_by_id.c
SRC_LST_ROOM += lst_room_check.c
SRC_LST_ROOM += lst_room_print_lst.c
SRC_LST_ROOM += lst_room_update_id.c

SOURCES_LST_ROOM = $(addprefix $(SDIR_LST_ROOM)/,$(SRC_LST_ROOM))
OBJECTS_LST_ROOM = $(addprefix $(ODIR_LST_ROOM)/,$(SRC_LST_ROOM:.c=.o))

# /*
# ** ====================== SOURCE LST ANTS ==========================
# */
SDIR_LST_ANTS = src/lst_ants
ODIR_LST_ANTS = obj/lst_ants

SRC_LST_ANTS = lst_ants_add.c
SRC_LST_ANTS += lst_ants_create.c
SRC_LST_ANTS += lst_ants_free.c
SRC_LST_ANTS += lst_ants_get_start.c
SRC_LST_ANTS += lst_ants_length.c
SRC_LST_ANTS += lst_ants_get_by_id.c
SRC_LST_ANTS += lst_ants_print_lst.c

SOURCES_LST_ANTS = $(addprefix $(SDIR_LST_ANTS)/,$(SRC_LST_ANTS))
OBJECTS_LST_ANTS = $(addprefix $(ODIR_LST_ANTS)/,$(SRC_LST_ANTS:.c=.o))

# /*
# ** ====================== SOURCE LST PATH ==========================
# */
SDIR_LST_PATH = src/lst_path
ODIR_LST_PATH = obj/lst_path

SRC_LST_PATH = lst_path_add.c
SRC_LST_PATH += lst_path_create.c
SRC_LST_PATH += lst_path_free.c
SRC_LST_PATH += lst_path_get_start.c
SRC_LST_PATH += lst_path_length.c
SRC_LST_PATH += lst_path_get_by_id.c
SRC_LST_PATH += lst_path_print_lst.c

SOURCES_LST_PATH = $(addprefix $(SDIR_LST_PATH)/,$(SRC_LST_PATH))
OBJECTS_LST_PATH = $(addprefix $(ODIR_LST_PATH)/,$(SRC_LST_PATH:.c=.o))


.PHONY: clean fclean all re

all :  $(LIBFT) $(NAME)
	@make -C $(LDIR) 2> tmp.log
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log

$(NAME) :  $(LIBFT) $(OBJECTS) $(OBJECTS_LST_ROOM) $(OBJECTS_LST_ANTS) $(OBJECTS_LST_PATH)  $(INCLUDES) Makefile
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(OBJECTS_LST_ROOM)  $(OBJECTS_LST_ANTS) $(OBJECTS_LST_PATH)  -I $(IDIR) $(LIBFT)
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE LIBFT ==========================
# */
$(LIBFT) :
	@make -C $(LDIR) 2> tmp.log

# /*
# ** ====================== MAKE LST PATH ==========================
# */
$(ODIR_LST_PATH)/%.o : $(SDIR_LST_PATH)/%.c $(INCLUDES) Makefile
	@if [[ $< == src/lst_path/lst_path_add.c ]]; then \
		echo "\n > Make \033[33mlst_path\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_LST_PATH) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== MAKE LST ANTS ==========================
# */
$(ODIR_LST_ANTS)/%.o : $(SDIR_LST_ANTS)/%.c $(INCLUDES) Makefile
	@if [[ $< == src/lst_ants/lst_ants_add.c ]]; then \
		echo "\n > Make \033[33mlst_ants\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_LST_ANTS) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** ====================== MAKE LST ROOM ==========================
# */
$(ODIR_LST_ROOM)/%.o : $(SDIR_LST_ROOM)/%.c $(INCLUDES) Makefile
	@if [[ $< == src/lst_room/lst_room_add.c ]]; then \
		echo "\n > Make \033[33mlst_room\033[0mfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_LST_ROOM) 2> tmp.log
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
