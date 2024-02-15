cc = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = get_next_line.c get_next_line_utils.c parsing.c so_long.c
OBJ = $(SRC:.c=.o)

all: $(NAME) so_long.h

$(NAME) : $(OBJ) so_long.h
	$(cc) $(CFLAGS) $(OBJ) libft.a libftprintf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all