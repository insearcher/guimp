# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2019/03/16 22:59:56 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include			../Makefile.inc

NAME 		=	libui.a
WHOAMI		=	$(shell whoami)

SDL_VER		= 	$(shell ls /Users/$(WHOAMI)/.brew/Cellar/sdl2/ | tail -1)
TTF_VER		= 	$(shell ls /Users/$(WHOAMI)/.brew/Cellar/sdl2_ttf/ | tail -1)
IMG_VER		= 	$(shell ls /Users/$(WHOAMI)/.brew/Cellar/sdl2_image/ | tail -1)

INC_FT		=	../libft/include

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./include

SRC			=	ui_create_env.c \
				ui_create_win.c \
				ui_create_sur.c \
				ui_exit_with_msg.c \
				ui_exit.c \
				ui_set_pixel.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCS		=	-I$(INC_DIR) \
				-I$(INC_FT) \
				-I/Users/$(WHOAMI)/.brew/Cellar/sdl2/$(SDL_VER)/include/ \
				-I/Users/$(WHOAMI)/.brew/Cellar/sdl2/$(SDL_VER)/include/SDL2/ \
				-I/Users/$(WHOAMI)/.brew/Cellar/sdl2_ttf/$(TTF_VER)/include/ \
				-I/Users/$(WHOAMI)/.brew/Cellar/sdl2_image/$(IMG_VER)/include/

CC 			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
