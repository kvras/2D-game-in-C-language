/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:15:48 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/18 17:39:39 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mini_img_to_window(t_game *param, void *img, int x, int y)
{
	mlx_put_image_to_window(param->init, param->window, img, x, y);
}

int	img_manipul(int keycode, void *param)
{
	t_game	*mlx;

	mlx = (t_game *)param;
	if (keycode == 13 && mlx->map[mlx->x - 1][mlx->y] != '1')
	{
		mini_img_to_window(mlx, mlx->road, mlx->y * 50, (mlx->x--) * 50);
		checker(mlx->x + 1, mlx->y, param);
	}
	if (keycode == 1 && mlx->map[mlx->x + 1][mlx->y] != '1')
	{
		mini_img_to_window(mlx, mlx->road, mlx->y * 50, (mlx->x++) * 50);
		checker(mlx->x - 1, mlx->y, param);
	}
	if (keycode == 2 && mlx->map[mlx->x][mlx->y + 1] != '1')
	{
		mini_img_to_window(mlx, mlx->road, (mlx->y++) * 50, mlx->x * 50);
		checker(mlx->x, mlx->y - 1, param);
	}
	if (keycode == 0 && mlx->map[mlx->x][mlx->y - 1] != '1')
	{
		mini_img_to_window(mlx, mlx->road, (mlx->y--) * 50, mlx->x * 50);
		checker(mlx->x, mlx->y + 1, param);
	}
	mini_img_to_window(mlx, mlx->right, mlx->y * 50, mlx->x * 50);
	return (0);
}

int	initialise_images(t_game *d)
{
	int	x;
	int	y;

	d->right = NULL;
	d->wall = NULL;
	d->road = NULL;
	d->coin = NULL;
	d->door = NULL;
	d->window = NULL;
	d->init = NULL;
	d->init = mlx_init();
	if (!d->init)
		return (ft_printf("Error\n"), 0);
	d->right = mlx_xpm_file_to_image(d->init, "./textures/right.xpm", &x, &y);
	d->wall = mlx_xpm_file_to_image(d->init, "./textures/wall.xpm", &x, &y);
	d->road = mlx_xpm_file_to_image(d->init, "./textures/map.xpm", &x, &y);
	d->coin = mlx_xpm_file_to_image(d->init, "./textures/collect.xpm", &x, &y);
	d->door = mlx_xpm_file_to_image(d->init, "./textures/door.xpm", &x, &y);
	d->window = mlx_new_window(d->init, d->width * 50, d->len * 50, "so_long");
	return (initialisation_check(d));
}

void	print_components(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				mini_img_to_window(game, game->road, x * 50, y * 50);
			else if (game->map[y][x] == '1')
				mini_img_to_window(game, game->wall, x * 50, y * 50);
			else if (game->map[y][x] == 'C')
				mini_img_to_window(game, game->coin, x * 50, y * 50);
			else if (game->map[y][x] == 'P')
				mini_img_to_window(game, game->right, x * 50, y * 50);
			else if (game->map[y][x] == 'E')
				mini_img_to_window(game, game->door, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
