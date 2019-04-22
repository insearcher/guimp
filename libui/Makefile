# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2019/04/22 04:14:16 by sbednar          ###   ########.fr        #
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

SRC_BFS			=	bfs_iter.c \
					queue.c

SRC_UI_EL		=	ui_el_add_child.c \
					ui_el_free.c \
					ui_el_init.c \
					ui_el_create_texture.c \
					ui_el_load_surface_from.c \
					ui_el_set_current_texture_by_id.c \
					ui_el_add_texture.c \
					ui_el_create_texture_from_surface.c \
					ui_el_get_current_texture.c \
					ui_el_set_abs_size.c \
					ui_el_set_rel_size.c \
					ui_el_set_abs_pos.c \
					ui_el_set_rel_pos.c \
					ui_el_default_pointer_enter.c \
					ui_el_default_pointer_exit.c \
					ui_el_setup_default.c \
					ui_find_dynamic_elements.c

SRC_UI_DRAW_EV	=	ui_el_draw_event.c

SRC_UI_DRAW		=	ui_draw.c \
					ui_draw_window.c \
					ui_draw_windows.c \
					ui_clear_windows.c \
					ui_show_window.c \
					ui_show_windows.c

SRC_UI_EVENT	=	ui_event_init.c \
					ui_event_add_listener.c \
					ui_event_clear.c \
					ui_event_invoke.c

SRC_UI_LOG		=	ui_log_mouse_motion.c \
					ui_log_mouse_button_down.c \
					ui_log_mouse_button_up.c \
					ui_log_window_focus_gained.c \
					ui_log_window_focus_lost.c \
					ui_log_window_closed.c \
					ui_log_window_resized.c \
					ui_log_el_pointer_stay.c \
					ui_log_el_pointer_enter.c \
					ui_log_el_pointer_exit.c \
					ui_log_key_pressed.c \
					ui_log_key_released.c

SRC_UI_MAIN		=	ui_main_loop.c \
					ui_main_init.c \
					ui_main_add_window.c \
					ui_main_handle_event.c \
					ui_main_handle_mouse_event.c \
					ui_main_handle_window_event.c \
					ui_main_find_window_by_id.c \
					ui_main_remove_window_by_id.c \
					ui_main_handle_keyboard_event.c \
					ui_main_handle_raycast.c \
					ui_main_handle_continious_event.c

SRC_UI_SDL		=	ui_sdl_init.c \
					ui_sdl_deinit.c

SRC_UI_WIN		=	ui_win_init.c \
					ui_win_setup_default.c \
					ui_win_create.c \
					ui_win_close.c \
					ui_win_update_size.c

SRC_UI_RAYCAST	=	ui_raycast.c \
					ui_el_is_pointer_inside.c

SRC_UI_STUFF	=	ui_get_mouse_win_pos.c

OBJ			=		$(addprefix $(OBJ_DIR)/,$(SRC_BFS:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_EL:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_DRAW_EV:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_DRAW:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_EVENT:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_LOG:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_MAIN:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_SDL:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_WIN:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_RAYCAST:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_STUFF:.c=.o))

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/bfs/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_draw_events/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_render/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_raycast/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_stuff/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
