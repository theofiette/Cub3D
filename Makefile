# ==== VARIABLES ====

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
MLX_DIR     = minilibx-linux
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -lXfixes

CC          = cc

NAME		= cub3d
DIR   		= src
INCLUDE_DIR = includes
BUILD_DIR  	= .build
CFLAGS      = -Wall -Wextra -Werror -g -MMD -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -O2 #-O3 -ffast-math

# ==== SOURCES ====

SRCS =	$(DIR)/main.c \
		$(DIR)/parsing/check_file.c \
		$(DIR)/parsing/parse_file.c \
		$(DIR)/parsing/validity_map_check.c \
		$(DIR)/parsing/utils_parsing.c \
		$(DIR)/parsing/utils_parsing_bis.c \
		$(DIR)/parsing/check_textures.c \
		$(DIR)/errors/error.c \
		$(DIR)/init/init_data.c \
		$(DIR)/init/init_map.c \
		$(DIR)/init/init_mlx.c \
		$(DIR)/init/init_texture.c \
		$(DIR)/init/allocate_mem.c \
		$(DIR)/init/init_zombies.c \
		$(DIR)/init/init_doors.c \
		$(DIR)/graphics/render.c \
		$(DIR)/graphics/render_hud.c \
		$(DIR)/graphics/dda.c \
		$(DIR)/graphics/dda_init.c \
		$(DIR)/graphics/color.c \
		$(DIR)/graphics/image.c \
		$(DIR)/graphics/minimap.c \
		$(DIR)/graphics/minimap_bis.c \
		$(DIR)/graphics/minimap_utils.c \
		$(DIR)/graphics/raycasting.c \
		$(DIR)/graphics/render_door.c \
		$(DIR)/graphics/render_textures.c \
		$(DIR)/graphics/render_zombies.c \
		$(DIR)/graphics/render_zombies_bis.c \
		$(DIR)/graphics/render_textures_assign.c \
		$(DIR)/graphics/dda_floor.c \
		$(DIR)/graphics/gun_n_crosshair.c \
		$(DIR)/graphics/vector_utils.c \
		$(DIR)/logic/delta.c \
		$(DIR)/logic/door_manager.c \
		$(DIR)/logic/hit.c \
		$(DIR)/logic/input_handler.c \
		$(DIR)/logic/player_hp.c \
		$(DIR)/logic/player_movement.c \
		$(DIR)/logic/player_rotation.c \
		$(DIR)/logic/reloading.c \
		$(DIR)/logic/zombie_manager.c \
		$(DIR)/logic/zombie_utils.c \
		$(DIR)/exit/clean_textures.c \
		$(DIR)/exit/exit.c \
		$(DIR)/utils.c

OBJS = $(SRCS:$(DIR)/%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o: $(DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ==== RULES ====

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(MLX_DIR):
	git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR) || true
	make -C $(MLX_DIR)

$(NAME): $(MLX_DIR) $(LIBFT_A) $(OBJS)  
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

DEPS = $(SRCS:$(DIR)/%.c=$(BUILD_DIR)/%.d)
-include $(DEPS)

# ==== CLEANING ====

clean:
	rm -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(MLX_DIR)
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
