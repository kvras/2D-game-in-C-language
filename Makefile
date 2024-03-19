cc = cc
CFLAGS = -Wall -Wextra -Werror
NAME = game

SRC =  src/parsing.c src/game.c src/protection_functions.c src/graphic_functions.c\
		 src/parsing_help_functions.c src/get_next_line.c src/get_next_line_utils.c src/ft_putadresse.c\
		 src/ft_split.c src/ft_strjoin.c src/ft_strnstr.c src/ft_memmove.c src/ft_itoa.c\
		 src/ft_puthex.c src/ft_putnbr.c src/ft_putstr.c src/ft_putchar.c src/ft_printf.c src/ft_puthexx.c src/ft_putunsigned.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c src/game.h
	$(cc) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) src/game.h
	$(cc) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)

re: fclean all