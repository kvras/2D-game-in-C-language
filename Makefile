cc = gcc
CFLAGS = -Wall -Wextra -Werror
NAME_M = so_long
NAME_B = so_long_bonus
SRC_M = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c mandatory/parsing.c mandatory/so_long.c
SRC_B = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c bonus/parsing_bonus.c bonus/so_long_bonus.c
OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME_M) mandatory/so_long.h

$(NAME_M) : $(OBJ_M)
	(cd libft && make)
	(cd ft_printf && make)
	$(cc) $(CFLAGS) $(OBJ_M) libft/libft.a ft_printf/libftprintf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME_M)

bonus: $(NAME_B) bonus/so_long_bonus.h

$(NAME_B) : $(OBJ_B)
	(cd libft && make)
	(cd ft_printf && make)
	$(cc) $(CFLAGS) $(OBJ_B) libft/libft.a ft_printf/libftprintf.a -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	(cd libft && make clean)
	(cd ft_printf && make clean)
	rm -f $(OBJ_B) $(OBJ_M)

fclean: clean
	(cd libft && make fclean)
	(cd ft_printf && make fclean)
	rm -f $(NAME_M) $(NAME_B)

re: fclean all