# Get Next Line #

FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= get_next_line.a
FILES:= $(patsubst %, %.c, get_next_line get_next_line_utils)
OBJS:= $(FILES:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: