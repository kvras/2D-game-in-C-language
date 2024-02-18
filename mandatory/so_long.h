/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:50:49 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/18 13:43:01 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <string.h>
# include <OpenGL/gl.h>
# include <mlx.h>
# include <stdlib.h>
# include "../ft_printf/libftprintf.h"
# include "../basic_functions/libft.h"

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
	void	*wall;
	void	*coin;
	void	*door;
	void	*init;
	void	*window;
	void	*ennemy;
}	t_game;

int		checker_caller(char *file, t_game *so_long);
void	destroy(t_game display);
void	free_arr(char **arr);
int		close_window(int keycode, void *param);
int		on_destroy(void *param);
void	free_struct(t_game *so_long);
int		img_mnpl(int keycode, void *param);
void	mini_img_to_window(t_game *param, void *img, int x, int y);
int		img_manipul(int keycode, void *param);
int		initialise_images(t_game *d);
void	print_components(t_game *game);
int		initialisation_check(t_game *d);
int		checker(int x, int y, void *param);
t_game	*copy(t_game *so_long);
char	*get_next_line_caller(int fd, char **line);
int		components_checker(t_game *so_long);
int		components_counter(t_game *so_long);
int		borders_checker(t_game *so_long);
int		deep_checker(t_game *so_long);
#endif