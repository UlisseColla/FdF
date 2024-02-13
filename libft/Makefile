FLAGS:= -Wall -Werror -Wextra

NAME:= libft.a

FILES-1:= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_atol ft_calloc ft_strdup
FILES-2:= ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

OBJECTS-1:= $(patsubst %, %.o, $(FILES-1))
OBJECTS-2:= $(patsubst %, %.o, $(FILES-2))

all: $(NAME)
	
$(NAME):
	cc $(FLAGS) -c $(patsubst %, %.c, $(FILES-1)) $(patsubst %, %.c, $(FILES-2))
	ar -rc $(NAME) $(OBJECTS-1) $(OBJECTS-2)
	ranlib $(NAME)

clean: 
	rm -f $(patsubst %, %.o, $(FILES-1)) $(patsubst %, %.o, $(FILES-2))

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT: