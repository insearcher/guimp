# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 15:58:51 by sbednar           #+#    #+#              #
#    Updated: 2019/05/23 05:57:25 by edraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include			Makefile.inc

NAME			=	guimp

TEXT_R			=	\033[0m
TEXT_B			=	\033[1m
TEXT_BL			=	\033[5m
TEXT_CR			=	\033[31m
TEXT_CG			=	\033[32m
TEXT_CY			=	\033[33m
TEXT_CB			=	\033[34m
TEXT_CM			=	\033[35m
TEXT_CC			=	\033[36m

FT_DIR			=	./libft
UI_DIR			=	./libui

INC_FT			=	$(FT_DIR)/include
INC_UI			=	$(UI_DIR)/include
INC_DIR			=	./include

SRC_DIR			=	./src
OBJ_DIR			=	./obj
LIB_DIR			=	./lib

SRC				=	main.c \
					draw_func.c \
					draw_main_canvas_event.c \
					gm_init.c

OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

INCS			=	-I$(INC_DIR) \
					-I$(INC_FT) \
					-I$(INC_UI) \
					-I./frameworks/SDL2.framework/Versions/A/Headers \
					-I./frameworks/SDL2_image.framework/Versions/A/Headers \
					-I./frameworks/SDL2_ttf.framework/Versions/A/Headers

FRAMEWORKS		=	-F./frameworks \
					-rpath ./frameworks \
					-framework OpenGL -framework AppKit -framework OpenCl \
					-framework SDL2 -framework SDL2_ttf -framework SDL2_image


LIBS			=	-L$(FT_DIR) -lft \
					-L$(UI_DIR) -lui \

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	@echo "$(TEXT_CC)$(TEXT_B)↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ all$(TEXT_R)"
	@touch $(TEMP)
	@echo "$(TEXT_CR)$(TEXT_B)LIBFT:$(TEXT_R)"
	@make -C $(FT_DIR) all
	@echo "$(TEXT_CR)$(TEXT_B)LIBUI:$(TEXT_R)"
	@make -C $(UI_DIR) all
	@echo "$(TEXT_CR)$(TEXT_B)$(NAME):$(TEXT_R)"
	@make $(OBJ_DIR)
	@make compile
	@rm -f $(TEMP)
	@echo "$(TEXT_CG)$(TEXT_BL)$(TEXT_B)↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ success$(TEXT_R)"

compile: $(OBJ)
	@if [ $(CAT_TEMP) ] ; \
		then \
		make build;\
		fi;

build:
	$(CC) $(CFLAGS) $(OBJ) $(INCS) $(LIBS) $(FRAMEWORKS) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > $(TEMP)

clean:
	@echo "$(TEXT_CC)$(TEXT_B)↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ clean$(TEXT_R)"
	@echo "$(TEXT_CR)$(TEXT_B)LIBFT:$(TEXT_R)"
	@make -C $(FT_DIR) clean
	@echo "$(TEXT_CR)$(TEXT_B)LIBUI:$(TEXT_R)"
	@make -C $(UI_DIR) clean
	@echo "$(TEXT_CR)$(TEXT_B)GUIMP:$(TEXT_R)"
	@rm -f $(TEMP)
	rm -rf $(OBJ_DIR)
	@echo "$(TEXT_CG)$(TEXT_BL)$(TEXT_B)↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ success$(TEXT_R)"

fclean:
	@echo "$(TEXT_CC)$(TEXT_B)↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ fclean$(TEXT_R)"
	@echo "$(TEXT_CR)$(TEXT_B)LIBFT:$(TEXT_R)"
	@make -C $(FT_DIR) fclean
	@echo "$(TEXT_CR)$(TEXT_B)LIBUI:$(TEXT_R)"
	@make -C $(UI_DIR) fclean
	@echo "$(TEXT_CR)$(TEXT_B)$(NAME):$(TEXT_R)"
	@rm -f $(TEMP)
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
