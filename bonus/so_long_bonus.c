/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:29:22 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/15 21:03:29 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy(t_game display)
{
	mlx_destroy_image(display.init, display.avatar);
	mlx_destroy_image(display.init, display.wall);
	mlx_destroy_image(display.init, display.road);
	mlx_destroy_image(display.init, display.collect_img);
	mlx_destroy_image(display.init, display.exit_img);
	mlx_destroy_window(display.init, display.window);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

int	checker(int x, int y, void *param)
{
	int		j;
	char	*str;
	t_game	*mlx;

	mlx = (t_game *)param;
	if (mlx->map[mlx->avatar_x][mlx->avatar_y] == 'C')
	{
		mlx->map[mlx->avatar_x][mlx->avatar_y] = '0';
		mlx->collect--;
	}
	else if (mlx->map[mlx->avatar_x][mlx->avatar_y] == 'E')
	{
		if (mlx->collect == 0)
		{
			ft_printf("You won in %d mouvements\n", ++mlx->mouvements);
			mlx_destroy_window(mlx->init, mlx->window);
			exit(0);
		}
		mlx->avatar_x = x;
		mlx->avatar_y = y;
		return (1);
	}
	else if (mlx->map[mlx->avatar_x][mlx->avatar_y] == 'G')
	{
		mlx_destroy_window(mlx->init, mlx->window);
		exit(0);
	}
	ft_printf("total mouvements: %d\n", ++mlx->mouvements);
	j = 0;
	while (j <= 5)
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->wall, j++ * 50, 0);
	str = ft_itoa(mlx->mouvements);
	mlx_string_put(mlx->init, mlx->window, 20, 15, 16777215, "Number of mouvements : ");
	mlx_string_put(mlx->init, mlx->window, 250, 15, 16777215, str);
	return (free(str), 1);
}

int	img_mnpl(int keycode, void *param)
{
	t_game	*mlx;
	int		y;
	int		x;

	mlx = (t_game *)param;
	x = mlx->avatar_x;
	y = mlx->avatar_y;
	if (keycode == 13 && mlx->map[x - 1][y] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->road, mlx->avatar_y * 50, mlx->avatar_x-- * 50);
		if(checker(x, y, param))
			mlx_put_image_to_window(mlx->init, mlx->window, mlx->upper, mlx->avatar_y * 50, mlx->avatar_x * 50);
	}
	if (keycode == 1 && mlx->map[x + 1][y] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->road, mlx->avatar_y * 50, mlx->avatar_x++ * 50);
		if(checker(x, y, param))
			mlx_put_image_to_window(mlx->init, mlx->window, mlx->down, mlx->avatar_y * 50, mlx->avatar_x * 50);
	}
	if (keycode == 2 && mlx->map[x][y + 1] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->road, mlx->avatar_y++ * 50, mlx->avatar_x * 50);
		if(checker(x, y, param))
			mlx_put_image_to_window(mlx->init, mlx->window, mlx->avatar, mlx->avatar_y * 50, mlx->avatar_x * 50);
	}
	if (keycode == 0 && mlx->map[x][y - 1] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->road, mlx->avatar_y-- * 50, mlx->avatar_x * 50);
		if (checker(x, y, param))
			mlx_put_image_to_window(mlx->init, mlx->window, mlx->left, mlx->avatar_y * 50, mlx->avatar_x * 50);
	}
	return (0);
}
int close_window(int keycode, void *param)
{
	t_game *mlx;
 
	mlx = (t_game *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->init, mlx->window);
		exit(0);
	}
	img_mnpl(keycode, param);
	return (0);
}

void f()
{
	system("leaks so_long");
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
				mlx_put_image_to_window(game->init, game->window, game->road, x * 50, y * 50);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->init, game->window, game->wall, x * 50, y * 50);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->init, game->window, game->collect_img, x * 50, y * 50);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->init, game->window, game->avatar, x * 50, y * 50);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->init, game->window, game->exit_img, x * 50, y * 50);
			else if (game->map[y][x] == 'G')
				mlx_put_image_to_window(game->init, game->window, game->ennemy, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
int on_destroy(void *param)
{
	t_game	*mlx;

	mlx = (t_game *)param;
	mlx_destroy_window(mlx->init, mlx->window);
	destroy(*mlx);
	free_arr(mlx->map);
	exit(0);
}

void	v()
{
	system("leaks so_long");
}
void	initialise_images(t_game *display)
{
	int	width;
	int	height;

	display->avatar = mlx_xpm_file_to_image(display->init,
			"./textures/pacman_b.xpm", &width, &height);
	display->wall = mlx_xpm_file_to_image(display->init,
			"./textures/wall.xpm", &width, &height);
	display->road = mlx_xpm_file_to_image(display->init,
			"./textures/map.xpm", &width, &height);
	display->collect_img = mlx_xpm_file_to_image(display->init,
			"./textures/collectible.xpm", &width, &height);
	display->exit_img = mlx_xpm_file_to_image(display->init,
			"./textures/p.xpm", &width, &height);
	display->ennemy = mlx_xpm_file_to_image(display->init,
			"./textures/ghost1.xpm", &width, &height);
	display->down = mlx_xpm_file_to_image(display->init,
			"./textures/down.xpm", &width, &height);
	display->upper = mlx_xpm_file_to_image(display->init,
			"./textures/upper.xpm", &width, &height);
	display->left = mlx_xpm_file_to_image(display->init,
			"./textures/left.xpm", &width, &height);
	display->window = mlx_new_window(display->init,
			display->width * 50, display->len * 50, "so_long");
}
int main(int argc, char **argv)
{
	t_game		display;

	atexit(f);
	display.map = NULL;
	if (argc != 2)
		return (0);
	else if (checker_caller(argv[1], &display) == 0)
		return (free_arr(display.map), ft_printf("Error\n"), 0);
	display.mouvements = 0;
	display.init = mlx_init();
	display.width--;
	initialise_images(&display);
	if (!display.avatar || !display.wall || !display.road || !display.collect_img || !display.exit_img || !display.init || !display.window || !display.ennemy)
		return (free_arr(display.map), destroy(display), ft_printf("Error\n"), 0);
	print_components(&display);
	mlx_key_hook(display.window, close_window, (void *)(&display));
	mlx_hook(display.window, 17, 0, on_destroy, (void *)(&display));
	mlx_loop(display.init);
	return (destroy(display), free_arr(display.map), 0);
}
