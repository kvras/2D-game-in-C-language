/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:50:49 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/15 20:51:30 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/libftprintf.h"
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"
# include <OpenGL/gl.h>
# include <mlx.h>
# include <stdlib.h>
// #define malloc(x)  NULL

typedef struct s_game
{
	int		len;
	int		width;
	int		avatar_x;
	int		avatar_y;
	int		player;
	int		collect;
	int		exit;
	int		mouvements;
	char	**map;
	void	*road;
	void	*avatar;
	void	*wall;
	void	*collect_img;
	void	*exit_img;
	void	*init;
	void	*window;
	void	*ennemy;
}	t_game;

int		checker_caller(char *file, t_game *so_long);
char	*ft_itoa(int nbr);

#endif