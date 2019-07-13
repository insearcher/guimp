# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 16:14:32 by sbednar           #+#    #+#              #
#    Updated: 2019/07/13 13:55:01 by sbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include				../Makefile.inc

NAME 			=	libui.a

INC_FT			=	../libft/include
INC_JTOC		=	../libjtoc/include

SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_DIR			=	./include

SRC_BFS			=	bfs_iter.c \
					bfs_for_resize.c \
					queue.c

SRC_UI_CURSOR	=	ui_cursor_init.c \
					ui_cursor_to_default.c \
					ui_cursor_from_el_data.c \
					ui_cursor_from.c

SRC_UI_EL		=	ui_el_add_child.c \
					ui_el_init.c \
					ui_el_create_texture.c \
					ui_el_load_surface_from.c \
					ui_el_set_current_texture_by_id.c \
					ui_el_add_texture.c \
					ui_el_create_texture.c \
					ui_el_create_texture_from_surface.c \
					ui_el_get_current_texture.c \
					ui_el_default_pointer_enter.c \
					ui_el_default_pointer_exit.c \
					ui_el_resize_elems.c \
					ui_el_get_texture_by_id.c \
					ui_el_drag.c \
					ui_el_scroll_menu.c \
					ui_el_set_texture.c \
					ui_el_set_text.c \
					ui_el_update_text.c \
					ui_el_change_pos.c \
					ui_el_change_size.c \
					ui_el_add_texture_from_main_by_id.c \
					ui_el_set_pos.c \
					ui_el_set_size.c \
					ui_el_default_resize.c \
					ui_el_menu_resize.c \
					ui_el_set_new_pos.c \
					ui_el_set_new_size.c \
					ui_el_add_texture_from_file_dialog.c \
					ui_el_setup_default_draggable.c \
					ui_el_setup_default_resizable.c \
					ui_el_setup_default_scroll_menu_elem.c \
					ui_el_setup_default_scroll_menu.c \
					ui_el_setup_default.c \
					ui_el_setup_horizontal_draggable.c \
					ui_el_setup_menu_resizable.c \
					ui_el_setup_radio.c \
					ui_el_switch_radio.c \
					ui_el_show_child.c \
					ui_el_children_set_default.c \
					ui_el_create_modal_ok.c \
					ui_modal_win_destroy.c \
					ui_text_destroy.c \
					ui_el_destroy.c \
					ui_el_destroy_children.c \
					ui_el_setup_radio.c \
					ui_el_switch_radio.c

SRC_UI_DRAW_EV	=	ui_el_draw_event.c

SRC_UI_DRAW		=	ui_draw.c \
					ui_draw_window.c \
					ui_draw_windows.c \
					ui_clear_windows.c \
					ui_show_window.c \
					ui_show_windows.c

SRC_UI_EVENT	=	ui_event_init.c \
					ui_event_add_listener.c \
					ui_event_add_listener_front.c \
					ui_event_clear.c \
					ui_event_invoke.c \
					ui_event_destroy.c

SRC_UI_LOG		=	ui_log_mouse_motion.c \
					ui_log_mouse_button_down.c \
					ui_log_mouse_button_up.c \
					ui_log_window_focus_gained.c \
					ui_log_window_focus_lost.c \
					ui_log_window_closed.c \
					ui_log_window_resized.c \
					ui_log_window_moved.c \
					ui_log_el_pointer_stay.c \
					ui_log_el_pointer_enter.c \
					ui_log_el_pointer_exit.c \
					ui_log_key_pressed.c \
					ui_log_key_released.c \
					ui_log_el_scroll_up.c \
					ui_log_el_scroll_down.c \
					ui_log_el_left_button_hold.c \
					ui_log_el_left_button_pressed.c \
					ui_log_el_left_button_released.c \
					ui_log_el_right_button_hold.c \
					ui_log_el_right_button_pressed.c \
					ui_log_el_right_button_released.c

SRC_UI_MAIN		=	ui_main_loop.c \
					ui_main_init.c \
					ui_main_add_window.c \
					ui_main_closing_windows.c \
					ui_main_handle_event.c \
					ui_main_handle_mouse_event.c \
					ui_main_handle_window_event.c \
					ui_main_find_window_by_id.c \
					ui_main_handle_keyboard_event.c \
					ui_main_handle_raycast.c \
					ui_main_handle_continious_event.c \
					ui_main_lmb_pressed.c \
					ui_main_lmb_released.c \
					ui_main_rmb_pressed.c \
					ui_main_rmb_released.c \
					ui_main_scroll_up.c \
					ui_main_scroll_down.c \
					ui_main_pointer_moved.c \
					ui_main_add_font_by_path.c \
					ui_main_add_surface_by_path.c \
					ui_main_get_font_by_id.c \
					ui_main_get_surface_by_id.c \
					ui_main_fill_default_surfaces.c \
					ui_main_fill_default_fonts.c \
					ui_main_set_font_params.c \
					ui_main_add_function_by_id.c \
					ui_main_get_function_by_id.c \
					ui_main_merge_layers.c \
					ui_main_save_texture.c \
					ui_main_open_texture.c

SRC_UI_SDL		=	ui_sdl_init.c \
					ui_sdl_deinit.c

SRC_UI_WIN		=	ui_win_init.c \
					ui_win_setup_default.c \
					ui_win_create.c \
					ui_win_create_modal_win.c \
					ui_win_close.c \
					ui_win_update_size.c \
					ui_win_find_el_by_id.c \
					ui_win_focus.c \
					ui_win_change_text_in_focused_el.c \
					ui_win_destroy.c

SRC_UI_RAYCAST	=	ui_raycast.c \
					ui_el_is_pointer_inside.c

SRC_UI_PREFAB	=	ui_prefab_scroll_menu.c \
					ui_prefab_get_pixel_pos.c \
					ui_prefab_get_pixel_size.c

SRC_UTILITS		=	ui_get_rect_from_frect.c \
					ui_get_pixel_color_from_texture.c \
					ui_get_pixel_color_from_el.c \
					ui_set_pixel_color_to_texture.c

SRC_UI_JTOC		=	ui_main_from_json.c \
					ui_win_from_json.c \
					ui_el_from_json.c \
					ui_el_get_and_setup_json.c \
					ui_el_pref_text.c \
					ui_el_pref_modal_win.c \
					ui_jtoc_utils.c

SRC_UI_FILE		=	ui_open_file_dialog.c \
					ui_save_file_dialog.c \
					ui_parse_path.c \
					ui_find_last_slash.c

OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRC_BFS:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_CURSOR:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_EL:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_DRAW_EV:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_DRAW:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_EVENT:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_LOG:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_MAIN:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_SDL:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_WIN:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_RAYCAST:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_PREFAB:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UTILITS:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_JTOC:.c=.o)) \
					$(addprefix $(OBJ_DIR)/,$(SRC_UI_FILE:.c=.o))

INCS			=	-I$(INC_DIR) \
					-I$(INC_FT) \
					-I$(INC_JTOC) \
					-I../frameworks/SDL2.framework/Versions/A/Headers \
					-I../frameworks/SDL2_image.framework/Versions/A/Headers \
					-I../frameworks/SDL2_ttf.framework/Versions/A/Headers

CC 				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_cursor/%.c
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

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_prefab/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/utilits/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_jtoc/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/ui_file/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "1" > ../$(TEMP)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
