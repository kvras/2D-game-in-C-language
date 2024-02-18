/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:00:31 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/18 17:40:19 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_game display)
{
	if (display.right)
		mlx_destroy_image(display.init, display.right);
	if (display.wall)
		mlx_destroy_image(display.init, display.wall);
	if (display.road)
		mlx_destroy_image(display.init, display.road);
	if (display.coin)
		mlx_destroy_image(display.init, display.coin);
	if (display.door)
		mlx_destroy_image(display.init, display.door);
	if (display.window)
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

int	close_window(int keycode, void *param)
{
	t_game	*mlx;

	mlx = (t_game *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->init, mlx->window);
		exit(0);
	}
	img_manipul(keycode, param);
	return (0);
}

int	on_destroy(void *param)
{
	t_game	*mlx;

	mlx = (t_game *)param;
	mlx_destroy_window(mlx->init, mlx->window);
	destroy(*mlx);
	free_arr(mlx->map);
	exit(0);
}

void	free_struct(t_game *so_long)
{
	int	i;

	i = 0;
	while (so_long && so_long->map && i < so_long->len)
	{
		free(so_long->map[i]);
		i++;
	}
	if (so_long && so_long->map)
		free(so_long->map);
	free(so_long);
}
