/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:50:49 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/20 18:14:33 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <OpenGL/gl.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_game
{
	int		len;
	int		width;
	int		x;
	int		y;
	int		player;
	int		collect;
	int		exit;
	int		mouvements;
	char	**map;
	void	*road;
	void	*right;
	void	*left;
	void	*up;
	void	*down;
	void	*avatar;
	void	*wall;
	void	*coin;
	void	*door;
	void	*init;
	void	*window;
	void	*ennemy;
}	t_game;

int		checker_caller(char *file, t_game *game);
void	destroy(t_game display);
void	free_arr(char **arr);
int		close_window(int keycode, void *param);
int		on_destroy(void *param);
void	free_struct(t_game *game);
int		img_manipul(int keycode, void *param);
void	mini_img_to_window(t_game *param, void *img, int x, int y);
int		img_manipul(int keycode, void *param);
int		initialise_images(t_game *d);
void	print_components(t_game *game);
int		initialisation_check(t_game *d);
int		checker(int x, int y, void *param);
t_game	*copy(t_game *game);
char	*get_next_line_caller(int fd, char **line);
int		components_checker(t_game *game);
int		components_counter(t_game *game);
int		borders_checker(t_game *game);
int		deep_checker(t_game *game);
char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *str, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_itoa(int nbr);
char	**ft_split(char *original, char c);
void	ft_putadresse(void *ptr, int *len, int *erreur);
void	ft_putunsigned(unsigned int nbr, int *len, int *erreur);
void	ft_putchar(char c, int *len, int *erreur);
void	ft_putstr(char *string, int *len, int *erreur);
void	ft_putnbr(int nb, int *len, int *erreur);
int		ft_printf(char *format, ...);
void	ft_puthex(unsigned long long nbr, char format, int *len, int *erreur);
void	ft_puthexx(unsigned int nbr, char format, int *len, int *erreur);
char	*get_next_line(int fd);
#endif