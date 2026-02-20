# ============== CUSTOM TEXT =================
BOLD=\033[1m
RESET=\033[0m
LIGHT_RED=\033[91m
LIGHT_GREEN=\033[92m
LIGHT_CYAN=\033[96m

# ============== MAIN INFO =================
NAME = miniRT

# ============== LIBFT COMMANDS =================
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I $(LIBFT_DIR)/includes -I $(LIBFT_DIR)/dependency_includes

# ============== MLX COMMANDS =================
MLX_DIR = lib/minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_DEPENDENCIES = -lXext -lX11 -lbsd

# ============== COMPILATION COMMANDS =================
INCLUDES = \
	-I includes \
	$(LIBFT_INCLUDES) \
	-I src/math_rt/includes \
	-I src/data_structures \
	-I src/core/parser/includes \
	-I src/core/scene/includes \
	-I src/core/scene/camera/includes \
	-I src/core/scene/polyhedron/includes \
	-I src/core/ray_tracer/light/includes \
	-I src/core/ray_tracer/includes \
	-I src/core/ray_tracer/colision/includes \
	-I src/core/ray_tracer/camera/includes \
	-I src/app/bonus \
	-I src/app/bonus/threads/includes \
	-I src/app/bonus/frame \
	-I src/app/bonus/events/gestures/includes \
	-I src/minilibx/includes \
	-I lib/minilibx
CC = cc
CFLAGS := -Wall -Werror -Wextra -O3 -march=native -flto -funroll-loops $(INCLUDES)
CFLAGS_DEBUG := -Wall -Werror -Wextra -g $(INCLUDES)
CFLAGS_USED := $(CFLAGS)

# ============== SRC FILES =================

# **** MINILIBX ****
MLX_FILES = src/minilibx/events/events.c src/minilibx/events/keyboard_events.c src/minilibx/events/loop_event.c \
src/minilibx/events/mouse_events.c src/minilibx/events/window_events.c src/minilibx/window/window.c \
src/minilibx/minilibx.c src/minilibx/resize_image.c src/minilibx/resize_image_nearest_neighbor.c

# **** MATH_RT ****
MATH_RT_FILES = src/math_rt/is_between.c src/math_rt/point_3d.c src/math_rt/vector_3d.c \
src/math_rt/vector_3d_ops_i.c src/math_rt/vector_3d_ops_ii.c src/math_rt/utils.c src/math_rt/vector_3d_ops_iii.c


# **** PARSER ****
PARSER_FILES = src/core/parser/parser_utils_i.c src/core/parser/parser_utils_ii.c src/core/parser/parser_form_scene_i.c src/core/parser/parser_form_scene_ii.c \
src/core/parser/parser_form_scene_iii.c src/core/parser/parser_verify_i.c src/core/parser/parser_verify_ii.c src/core/parser/parser_verify_iii.c \
src/core/parser/parser_verify_iv.c src/core/parser/parser.c src/core/parser/parser_form_scene_iv.c

# **** SCENE ****
SCENE_FILES = src/core/scene/scene.c src/core/scene/polyhedron/polyhedron.c src/core/scene/polyhedron/find_polyhedron.c src/core/scene/camera/camera_init.c

# **** RAY_TRACER ****
RAY_TRACER_FILES = src/core/ray_tracer/ray_tracer.c src/core/ray_tracer/colision/colision.c src/core/ray_tracer/colision/colision_pl.c \
src/core/ray_tracer/colision/colision_cy.c src/core/ray_tracer/colision/colision_sp.c src/core/ray_tracer/colision/colision_polyhedron.c \
src/core/ray_tracer/colision/colision_co.c src/core/ray_tracer/camera/trace_ray.c \
src/core/ray_tracer/camera/camera_ray.c src/core/ray_tracer/light/light.c src/core/ray_tracer/light/calc_u_v_i.c src/core/ray_tracer/light/calc_u_v_ii.c \
src/core/ray_tracer/light/norm_and_color_map.c src/core/ray_tracer/camera/anti_aliasing.c


# **** DATA_STRUCTURES ****
DATA_STRUCTURES = src/data_structures/linkedlist/iteration.c src/data_structures/linkedlist/linkedlist_node.c src/data_structures/linkedlist/linkedlist.c \
src/data_structures/linkedlist_array/linkedlist_array.c src/data_structures/hashtable/hashtable.c \
src/data_structures/binary_tree/binary_tree_node.c src/data_structures/binary_tree/binary_tree.c


# **** BONUS ****
B_EV_DIR= src/app/bonus/events
BONUS_EVENTS_FILES = $(B_EV_DIR)/events_bonus.c $(B_EV_DIR)/callbacks/keyboard_callbacks_bonus.c \
$(B_EV_DIR)/callbacks/mouse_callbacks_bonus.c $(B_EV_DIR)/callbacks/window_callbacks_bonus.c \
$(B_EV_DIR)/callbacks/callbacks.c $(B_EV_DIR)/gestures/gestures.c $(B_EV_DIR)/gestures/mouse_gestures.c \
$(B_EV_DIR)/gestures/wasd_gestures.c $(B_EV_DIR)/gestures/number_gestures.c $(B_EV_DIR)/gestures/rgb_gestures.c \
$(B_EV_DIR)/gestures/select_gestures.c  $(B_EV_DIR)/state/camera/set_camera.c $(B_EV_DIR)/state/camera/set_camera_rotation_i.c $(B_EV_DIR)/state/camera/set_camera_rotation_ii.c \
$(B_EV_DIR)/state/camera/set_camera_translation_i.c $(B_EV_DIR)/state/camera/set_camera_translation_ii.c \
$(B_EV_DIR)/state/polyhedron/set_polyhedron_rotation_i.c $(B_EV_DIR)/state/polyhedron/set_polyhedron_rotation_ii.c \
$(B_EV_DIR)/state/polyhedron/set_polyhedron_select.c $(B_EV_DIR)/state/polyhedron/set_polyhedron_translation_i.c \
$(B_EV_DIR)/state/polyhedron/set_polyhedron_translation_ii.c $(B_EV_DIR)/state/polyhedron/set_polyhedron.c \
$(B_EV_DIR)/state/set_state_bonus.c $(B_EV_DIR)/state/state_bonus.c

B_FRAME_DIR = src/app/bonus/frame
BONUS_FRAME_FILES = $(B_FRAME_DIR)/frame.c $(B_FRAME_DIR)/draw_forms.c \
$(B_FRAME_DIR)/process_state.c $(B_FRAME_DIR)/show_frame_info.c $(B_FRAME_DIR)/process_camera.c \
$(B_FRAME_DIR)/process_camera_translation.c $(B_FRAME_DIR)/process_camera_rotation.c $(B_FRAME_DIR)/process_polyhedron.c \
$(B_FRAME_DIR)/show_selected_polyedron_ui.c

B_THREAD_DIR = src/app/bonus/threads
BONUS_THREAD_FILES = $(B_THREAD_DIR)/context_callbacks_i.c $(B_THREAD_DIR)/context_callbacks_ii.c \
$(B_THREAD_DIR)/flow_control.c $(B_THREAD_DIR)/parallelize.c $(B_THREAD_DIR)/threads_bonus.c $(B_THREAD_DIR)/threads_routine.c

BONUS_FILES = $(BONUS_EVENTS_FILES) $(BONUS_FRAME_FILES) $(BONUS_THREAD_FILES) src/app/bonus/context.c src/app/bonus/ray_tracing.c

SRC_BONUS_FILES = $(MLX_FILES) $(BONUS_FILES) $(PARSER_FILES) $(DATA_STRUCTURES) $(SCENE_FILES) $(RAY_TRACER_FILES) $(MATH_RT_FILES)

# ============== PROGRAM FILES =================
MAIN_PROGRAM = src/app/mandatory/main.c
MAIN_BONUS_PROGRAM = src/app/bonus/main_bonus.c
TEST_PROGRAM = src/main_test.c

# ============== PROGRAM DEPENDENCIES =================

DEPENDENCIES = -lm -pthread $(MLX_DEPENDENCIES)

# ============== COMPILATION =================
COMPILATION_DEPENDENCIES = $(LIBFT) $(MLX)

OBJS = $(SRC_FILES:%.c=%.o)
OBJS_BONUS = $(SRC_BONUS_FILES:%.c=%.o)
OBJ_MAIN_PROGRAM = $(MAIN_PROGRAM:%.c=%.o)
OBJ_MAIN_BONUS_PROGRAM = $(MAIN_BONUS_PROGRAM:%.c=%.o)
OBJ_TEST_PROGRAM = $(TEST_PROGRAM:%.c=%.o)

TEST_PROGRAMS = 

# ============== CUSTOM SLEEP =================
SLEEP = 0.07


# ***************************************************************************************************
# ********************************************           ********************************************
# ********************************************  TARGETS  ********************************************
# ********************************************           ********************************************
# ***************************************************************************************************

all: $(NAME)

debug:
	@$(MAKE) -s fclean
	@$(MAKE) -s CFLAGS_USED="$(CFLAGS_DEBUG)" all
	@clear

stats:
	@printf "$(BOLD)$(LIGHT_CYAN)src stats:$(RESET)\n"
#	=================== FILES AMOUNT INFO =====================
	@printf " - Total Files:$(BOLD) "
	@printf "%s\n$(RESET)" $(shell find src -type f ! -name '*.o' | wc -l)

	@printf "    * Total Images:$(BOLD) "
	@printf "%8s\n$(RESET)" $(shell find src \( -name "*.png" -o -name "*.jpg -o -name "*.jpeg -o -name "*.webp""" \) | wc -l) | tr ' ' '.'

	@printf "    * Total READMEs:$(BOLD) "
	@printf "%7s\n$(RESET)" $(shell find src -name "README.md" | wc -l) | tr ' ' '.'

	@printf "    * Total .h Files:$(BOLD) "
	@printf "%6s\n$(RESET)" $(shell find src -name "*.h" | wc -l) | tr ' ' '.'

	@printf "    * Total .c Files:$(BOLD) "
	@printf "%6s\n$(RESET)" $(shell find src -name "*.c" | wc -l) | tr ' ' '.'
#	=================== LINES WRITTEN INFO =====================
	@printf "\n - Lines Written *.{c,h}:$(BOLD) "
	@printf "%s\n$(RESET)" $(shell cat $(shell find src \( -name "*.c" -o -name "*.h" \)) | wc -l)

	@printf "    * Lines Written *.c:$(BOLD) "
	@printf "%8s\n$(RESET)" $(shell cat $(shell find src -name "*.c") | wc -l) | tr ' ' '.'

	@printf "    * Lines Written *.h:$(BOLD) "
	@printf "%8s\n$(RESET)" $(shell cat $(shell find src -name "*.h") | wc -l) | tr ' ' '.'
#	=================== CONCLUSION =====================
	@printf "\n - Conclusion:$(BOLD) "
	@printf "%s\n$(RESET)" "Best miniRT Ever"

$(NAME): $(COMPILATION_DEPENDENCIES) $(OBJS_BONUS) $(MAIN_BONUS_PROGRAM)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS_USED) $(OBJS_BONUS) $(MAIN_BONUS_PROGRAM) $(COMPILATION_DEPENDENCIES)  -o $@ $(DEPENDENCIES)

$(LIBFT):
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) SLEEP="$(SLEEP)"

$(MLX):
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(MLX_DIR) SLEEP="$(SLEEP)"

run_valgrind: $(NAME)
	@valgrind -q --track-origins=yes --show-leak-kinds=all --track-fds=yes --leak-check=full ./$(NAME)

%.o: %.c
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$<$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS_USED) -c $< -o $@


clean:
	@echo "$(LIGHT_RED)>> $(BOLD)cleanning$(RESET) $(LIGHT_CYAN)./src$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(OBJS) $(OBJS_BONUS) $(OBJ_MAIN_PROGRAM) $(OBJ_MAIN_BONUS_PROGRAM) $(OBJ_TEST_PROGRAM)
	@echo "$(LIGHT_RED)>> $(BOLD)cleanning$(RESET) $(LIGHT_CYAN)./$(LIBFT_DIR)$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)$(LIBFT_DIR)$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)$(MLX_DIR)$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(MLX)
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)./$(NAME)$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(NAME)
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)./$(BONUS)$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(BONUS)
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)$(TEST_PROGRAMS)$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(TEST_PROGRAMS)
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)$(OBJ_MAIN_PROGRAM)$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(OBJ_MAIN_PROGRAM)


re: fclean all

.PHONY: all clean fclean re
