# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2019/04/04 01:34:23 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include				../Makefile.inc

NAME 			=	libui.a
WHOAMI			=	$(shell whoami)

SDL_VER			= 	$(shell ls /Users/$(WHOAMI)/.brew/Cellar/sdl2/ | tail -1)
TTF_VER			= 	$(shell ls /Users/$(WHOAMI)/.brew/Cellar/sdl2_ttf/ | tail -1)
IMG_VER			= 	$(shell ls /Users/$(WHOAMI)/.brew/Cellar/sdl2_image/ | tail -1)

INC_FT			=	../libft/include

SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_DIR			=	./include

SRC_UI_EL		=	ui_el_add_child.c \
					ui_el_free.c \
					ui_el_init.c

SRC_EL_EVENT	=	ui_event_init.c \
					ui_event_add_listener.c \
					ui_event_clear.c \
					ui_event_invoke.c

SRC_UI_LOG		=	ui_log_mouse_motion.c \
					ui_log_mouse_button_down.c \
					ui_log_mouse_button_up.c \
					ui_log_window_focus_gained.c \
					ui_log_window_focus_lost.c \
					ui_log_window_closed.c \
					ui_log_window_resized.c

SRC_UI_MAIN		=	ui_main_loop.c \
					ui_main_init.c \
					ui_main_add_window.c \
					ui_main_handle_event.c \
					ui_main_handle_mouse_event.c \
					ui_main_handle_window_event.c \
					ui_main_find_window_by_id.c \
					ui_main_remove_window_by_id.c \
					ui_main_handle_key_down.c \
					ui_main_handle_key_up.c
					# ui_main_handle_mouse_motion.c \
					ui_main_handle_mouse_button_down.c \
					ui_main_handle_mouse_button_up.c \

SRC_UI_SDL		=	ui_sdl_init.c \
					ui_sdl_deinit.c

SRC_UI_WIN		=	ui_win_init.c \
					ui_win_create.c \
					ui_win_close.c

OBJ			=		$(addprefix $(OBJ_DIR)/,$(SRC_UI_EL:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_EL_EVENT:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_LOG:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_MAIN:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_SDL:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_WIN:.c=.o))

INCS		=		-I$(INC_DIR) \
					-I$(INC_FT) \
					-I/Users/$(WHOAMI)/.brew/Cellar/sdl2/$(SDL_VER)/include/ \
					-I/Users/$(WHOAMI)/.brew/Cellar/sdl2/$(SDL_VER)/include/SDL2/ \
					-I/Users/$(WHOAMI)/.brew/Cellar/sdl2_ttf/$(TTF_VER)/include/ \
					-I/Users/$(WHOAMI)/.brew/Cellar/sdl2_image/$(IMG_VER)/include/

CC 			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_el/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_event/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_log/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_main/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_sdl/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_win/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
