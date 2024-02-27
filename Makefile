FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= fdf

#MINILIBX_MACOS:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux 
MLX_FLAGS:= -lm -lX11 -lXext
MLX_PATH:= ../minilibx-linux/
MLX:= libmlx.a

PATH_LIBFT:= ./libft
LIBFT:= libft.a

PATH_GNL:= ./libft/get_next_line
GNL:= get_next_line.a

#PATH_PRINTF:= ft_printf
#FT_PRINTF:= libftprintf.a

FILES_LIST:= main \
			fdf_utils \
			ft_pixel_put \
			ft_free \
			put_grid \
			build_map \
			isometric \

FUNCTIONS:= $(patsubst %, %.c, $(FILES_LIST))

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_GNL)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) $(MLX_PATH)$(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(PATH_LIBFT)
	$(MAKE) clean -C $(PATH_GNL)
	rm -f $(FUNCTIONS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(PATH_LIBFT)
	$(MAKE) fclean -C $(PATH_GNL)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: