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

FILES_LIST:= utils/fdf_utils \
			utils/free_and_errors \
			utils/handle_menu \
			build_map/build_map \
			build_map/shade_definition \
			drawing/color_handling \
			drawing/draw_utils \
			drawing/ft_pixel_put \
			drawing/line_drawing \
			drawing/put_grid \
			drawing/put_grid_extra \
			transformation/isometric \
			transformation/translate \
			transformation/scale \
			transformation/zoom \
			transformation/transformation_utils \
			main \
#			transformation/rotate_z \

FUNCTIONS:= $(patsubst %, %.c, $(FILES_LIST))

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_GNL)
#	cowsay -f ghostbusters "Compiled!"
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