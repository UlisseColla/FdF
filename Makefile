FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= fdf
#BONUS_NAME:= checker

MINILIBX:= -L minilibx -lmlx -framework OpenGL -framework AppKit

PATH_LIBFT:= libft
LIBFT:= libft.a

PATH_GNL:= libft/get_next_line
GNL:= get_next_line.a

#PATH_PRINTF:= ft_printf
#FT_PRINTF:= libftprintf.a

FILES_LIST:= main \

FUNCTIONS:= $(patsubst %, %.c, $(FILES_LIST))

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_GNL)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) -o $(NAME)
#	$(MINILIBX)

#$(BONUS_NAME): all

#bonus: $(BONUS_NAME)
#	$(MAKE) -C $(PATH_LIBFT)
#	$(MAKE) -C $(PATH_GNL)
#	$(MAKE) -C $(PATH_PRINTF)
#	$(CC) $(FLAGS) -g $(BONUS) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) ./bonus_checker/push_swap_bonus.h -o $(BONUS_NAME)

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