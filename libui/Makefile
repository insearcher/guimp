# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2019/03/12 02:34:07 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include			../Makefile.inc

NAME 		=	libui.a
AUTHOR		=	$(shell whoami)

FT_DIR		=	../libft

INC_FT		=	$(FT_DIR)/includes

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./includes

SDL_NUM		=	$(shell ls /Users/$(AUTHOR)/.brew/Cellar/sdl2/ | tail -1)
TTF_NUM		=	$(shell ls /Users/$(AUTHOR)/.brew/Cellar/sdl2_ttf/ | tail -1)
IMG_NUM		=	$(shell ls /Users/$(AUTHOR)/.brew/Cellar/sdl2_image/ | tail -1)

SRC			=	ui_create_env.c \
				ui_create_win.c \
				ui_create_sur.c \
				ui_exit_with_msg.c \
				ui_exit.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
INCS		=	-I$(INC_DIR) \
				-I$(INC_FT) \
				-I/Users/$(AUTHOR)/.brew/Cellar/sdl2/$(SDL_NUM)/include/ \
				-I/Users/$(AUTHOR)/.brew/Cellar/sdl2/$(SDL_NUM)/include/SDL2/ \
				-I/Users/$(AUTHOR)/.brew/Cellar/sdl2_ttf/$(TTF_NUM)/include/ \
				-I/Users/$(AUTHOR)/.brew/Cellar/sdl2_image/$(IMG_NUM)/include/
# LIBS		=	-L/Users/$(AUTHOR)/.brew/lib/ -lSDL2 -lSDL2_ttf -lSDL2_image

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
