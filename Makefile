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
INCLUDES = -I includes $(LIBFT_INCLUDES) -I $(MLX_DIR)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES)

# ============== SRC FILES =================

# **** MINILIBX ****
MLX_FILES = src/minilibx/events/events.c src/minilibx/events/keyboard_events.c src/minilibx/events/loop_event.c \
src/minilibx/events/mouse_events.c src/minilibx/events/window_events.c src/minilibx/window/window.c \
src/minilibx/minilibx.c src/minilibx/resize_image.c src/minilibx/resize_image_nearest_neighbor.c

# **** BONUS ****
B_EV_FOLDER= src/app/bonus/events
BONUS_EVENTS_FILES = $(B_EV_FOLDER)/events_bonus.c $(B_EV_FOLDER)/callbacks/keyboard_callbacks_bonus.c \
$(B_EV_FOLDER)/callbacks/mouse_callbacks_bonus.c $(B_EV_FOLDER)/callbacks/window_callbacks_bonus.c \
$(B_EV_FOLDER)/callbacks/callbacks.c $(B_EV_FOLDER)/gestures/gestures.c $(B_EV_FOLDER)/gestures/mouse_gestures.c \
$(B_EV_FOLDER)/gestures/wasd_gestures.c $(B_EV_FOLDER)/state/set_camera_rotation_i.c $(B_EV_FOLDER)/state/set_camera_rotation_ii.c \
$(B_EV_FOLDER)/state/set_camera_translation_i.c $(B_EV_FOLDER)/state/set_camera_translation_ii.c \
$(B_EV_FOLDER)/state/set_state_bonus.c $(B_EV_FOLDER)/state/state_bonus.c \


BONUS_FILES = $(BONUS_EVENTS_FILES) src/app/bonus/context.c src/app/bonus/frame/frame.c src/app/bonus/frame/draw_forms.c \
src/app/bonus/frame/process_state.c src/app/bonus/frame/show_frame_info.c

SRC_BONUS_FILES = $(MLX_FILES) $(BONUS_FILES)

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

TEST_PROGRAMS = null

# ============== CUSTOM SLEEP =================
SLEEP = 0.07


# ***************************************************************************************************
# ********************************************           ********************************************
# ********************************************  TARGETS  ********************************************
# ********************************************           ********************************************
# ***************************************************************************************************

all: $(NAME)

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
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(MAIN_BONUS_PROGRAM) $(COMPILATION_DEPENDENCIES)  -o $@ $(DEPENDENCIES)

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
	@$(CC) $(CFLAGS) -c $< -o $@


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
