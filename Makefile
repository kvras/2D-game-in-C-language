cc = cc
CFLAGS = -Wall -Wextra -Werror
NAME_M = so_long
NAME_B = so_long_bonus
SRC_GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_PRINTF = ft_printf/ft_printf.c ft_printf/ft_puthex.c ft_printf/ft_puthexx.c ft_printf/ft_putchar.c \
		ft_printf/ft_putstr.c ft_printf/ft_putnbr.c ft_printf/ft_putunsigned.c ft_printf/ft_putadresse.c
SRC_LIBFT = basic_functions/ft_split.c basic_functions/ft_strjoin.c basic_functions/ft_strnstr.c \
			basic_functions/ft_memmove.c basic_functions/ft_itoa.c
SRC_M =  mandatory/parsing.c mandatory/so_long.c mandatory/protection_functions.c mandatory/graphic_functions.c \
		mandatory/parsing_help_functions.c $(SRC_PRINTF) $(SRC_LIBFT) $(SRC_GET_NEXT_LINE)

SRC_B =  bonus/parsing_bonus.c bonus/so_long_bonus.c bonus/protection_functions_bonus.c $(SRC_PRINTF) \
		bonus/graphic_functions_bonus.c bonus/parsing_help_functions_bonus.c $(SRC_LIBFT) $(SRC_GET_NEXT_LINE)
OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
commun_includes = basic_functions/libft.h get_next_line/get_next_line.h
all: $(NAME_M)

$(NAME_M) : $(OBJ_M) mandatory/so_long.h $(commun_includes)
	$(cc) $(CFLAGS) $(OBJ_M) -lmlx -framework OpenGL -framework AppKit -o $(NAME_M)

bonus: $(NAME_B)

$(NAME_B) : $(OBJ_B) bonus/so_long_bonus.h $(commun_includes)
	$(cc) $(CFLAGS) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	rm -f $(OBJ_B) $(OBJ_M)

fclean: clean
	rm -f $(NAME_M) $(NAME_B)

re: fclean all