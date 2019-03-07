# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 15:58:51 by sbednar           #+#    #+#              #
#    Updated: 2019/03/07 18:44:48 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	guimp

TEXT_R		=	\033[0m
TEXT_B		=	\033[1m
TEXT_BL		=	\033[5m
TEXT_CR		=	\033[31m
TEXT_CG		=	\033[32m
TEXT_CY		=	\033[33m
TEXT_CB		=	\033[34m
TEXT_CM		=	\033[35m
TEXT_CC		=	\033[36m

FT_DIR		=	./libft
UI_DIR		=	./libui
MLX_DIR		=	./minilibx

FT_INC		=	$(FT_DIR)/inc
UI_INC		=	$(UI_DIR)/inc

INC_DIR		=	./inc
SRC_DIR		=	./src
OBJ_DIR		=	./obj
# DEP_DIR		=	./dep

SRC			=	main.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
# OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.o=.d))

INCS		=	-I$(INC_DIR) \
				-I$(FT_INC) \
				-I$(MLX_DIR) \
				#-I$(UI_INC)
LIBS		=	-L$(FT_DIR) -lft \
				-L$(MLX_DIR) -lmlx \
				#-L$(UI_DIR) -lui
FRAMES		=	-framework OpenGL \
				-framework AppKit \
				#-framework OpenCL \
				-framework SDL2 \
				-framework SDL2_image \
				-framework SDL2_ttf

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME):
	@echo "$(TEXT_CC)$(TEXT_B)↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ all$(TEXT_R)"
	@echo "$(TEXT_CR)$(TEXT_B)LIBFT:$(TEXT_R)"
	@make -C $(FT_DIR) all
	@echo "$(TEXT_CR)$(TEXT_B)LIBMLX:$(TEXT_R)"
	@make -C $(MLX_DIR) all
	@echo "$(TEXT_CR)$(TEXT_B)LIBUI:$(TEXT_R)"
	@make -C $(UI_DIR) all
	@echo "$(TEXT_CR)$(TEXT_B)$(NAME):$(TEXT_R)"
	@make $(OBJ_DIR)
	@make build
	@echo "$(TEXT_CG)$(TEXT_BL)$(TEXT_B)↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ success$(TEXT_R)"

build: $(OBJ)
	$(CC) $(CFLAGS) $(INCS) $(LIBS) $(FRAMES) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	@echo "$(TEXT_CC)$(TEXT_B)↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ clean$(TEXT_R)"
	@echo "$(TEXT_CR)$(TEXT_B)LIBFT:$(TEXT_R)"
	@make -C $(FT_DIR) clean
	@echo "$(TEXT_CR)$(TEXT_B)LIBMLX:$(TEXT_R)"
	@make -C $(MLX_DIR) clean
	@echo "$(TEXT_CR)$(TEXT_B)LIBUI:$(TEXT_R)"
	@make -C $(UI_DIR) clean
	@echo "$(TEXT_CR)$(TEXT_B)$(NAME):$(TEXT_R)"
	rm -rf $(OBJ_DIR)
	@echo "$(TEXT_CG)$(TEXT_BL)$(TEXT_B)↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ success$(TEXT_R)"

fclean:
	@echo "$(TEXT_CC)$(TEXT_B)↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ fclean$(TEXT_R)"
	@echo "$(TEXT_CR)$(TEXT_B)LIBFT:$(TEXT_R)"
	@make -C $(FT_DIR) fclean
	@echo "$(TEXT_CR)$(TEXT_B)LIBMLX:$(TEXT_R)"
	@make -C $(MLX_DIR) clean
	@echo "$(TEXT_CR)$(TEXT_B)LIBUI:$(TEXT_R)"
	@make -C $(UI_DIR) fclean
	@echo "$(TEXT_CR)$(TEXT_B)$(NAME):$(TEXT_R)"
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	@echo "$(TEXT_CG)$(TEXT_BL)$(TEXT_B)↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ success$(TEXT_R)"

re: fclean all

norm:
	@echo "$(TEXT_CC)$(TEXT_B)↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ norminette$(TEXT_R)"
	@norminette $(SRC_DIR)
	@norminette $(INC_DIR)
	@norminette $(UI_DIR)/src
	@norminette $(UI_DIR)/inc
	@echo "$(TEXT_CG)$(TEXT_BL)$(TEXT_B)↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ success$(TEXT_R)"

.PHONY: all $(NAME) clean fclean re norm
