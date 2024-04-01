NAME = so_long
BONUS_NAME = so_long_bonus
PRINTF_PATH = lib/ft_Printf
LIBFT_PATH = lib/libft

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

MLX_PATH = lib/mlx
MLX = $(MLX_PATH)/libmlx.a
LDFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/control.c \
	mandatory/map_check.c \
	mandatory/move.c \
	mandatory/utils.c \
	mandatory/map_check2.c \
	mandatory/window.c \
	mandatory/xpm_control.c \
	mandatory/so_long.c \

BNS_SRC = bonus/control_bonus.c \
	bonus/map_check_bonus.c \
	bonus/move_bonus.c \
	bonus/utils_bonus.c \
	bonus/map_check2_bonus.c \
	bonus/window_bonus.c \
	bonus/xpm_control_bonus.c \
	bonus/so_long_bonus.c \
	bonus/utils2_bonus.c \

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS_SRC:.c=.o)
CC = gcc
RM = rm -f

BLUE = \033[0;34m
LIGHT_GREEN = \033[1;32m
BOLD = \033[1m
RESET = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)
	@echo "\033[1;34mCompile\033[0m \033[1;32m[Success]\033[0m"
	@echo "$(BLUE)$(BOLD)How to use :$(RESET) $(LIGHT_GREEN)$(BOLD)./so_long maps/<map name>.ber$(RESET)"

bonus: $(BNS_OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(MLX)
	@$(CC) $(CFLAGS) $(BNS_OBJ) $(PRINTF) $(LIBFT) $(MLX) $(LDFLAGS) -o $(BONUS_NAME)
	@echo "\033[1;34mCompile\033[0m \033[1;32m[Success]\033[0m"
	@echo "$(BLUE)$(BOLD)How to use :$(RESET) $(LIGHT_GREEN)$(BOLD)./so_long_bonus maps/map_bonus/<map name>.ber$(RESET)"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

clean:
	@$(MAKE) -C $(PRINTF_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@$(RM) $(OBJ)
	@$(RM) $(BNS_OBJ)
	@echo "$(RED)$(BOLD)All object files have been deleted.$(RESET)"

fclean: clean
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)$(BOLD)Program file have been deleted.$(RESET)"

re: fclean all
	@echo "$(YELLOW)$(BOLD)Program being recompiled.$(RESET)"

.PHONY: all clean fclean re