# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2019/03/10 20:52:38 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libui.a
AUTHOR		=	$(shell whoami)

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./includes

SDL_NUM		=	$(shell ls /Users/$(AUTHOR)/.brew/Cellar/sdl2/ | tail -1)
TTF_NUM		=	$(shell ls /Users/$(AUTHOR)/.brew/Cellar/sdl2_ttf/ | tail -1)
IMG_NUM		=	$(shell ls /Users/$(AUTHOR)/.brew/Cellar/sdl2_image/ | tail -1)

SRC			=	ui_exit_with_msg.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
INCS		=	-I$(INC_DIR) \
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

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
