/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:29:22 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/18 17:28:01 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(int x, int y, void *param)
{
	t_game	*mlx;

	mlx = (t_game *)param;
	if (mlx->map[mlx->x][mlx->y] == 'C')
	{
		mlx->map[mlx->x][mlx->y] = '0';
		mlx->collect--;
	}
	else if (mlx->map[mlx->x][mlx->y] == 'E')
	{
		if (mlx->collect == 0)
		{
			ft_printf("total mouvements: %d\n", ++mlx->mouvements);
			mlx_destroy_window(mlx->init, mlx->window);
			exit(0);
		}
		mlx->x = x;
		mlx->y = y;
		return (1);
	}
	ft_printf("total mouvements: %d\n", ++mlx->mouvements);
	return (1);
}

int	initialisation_check(t_game *d)
{
	if (!d->right || !d->wall || !d->road || !d->coin || !d->door || !d->window
		|| !d->init)
		return (destroy(*d), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game		display;

	display.map = NULL;
	if (argc != 2)
		return (0);
	else if (checker_caller(argv[1], &display) == 0)
		return (free_arr(display.map), ft_printf("Error\n"), 0);
	display.mouvements = 0;
	if (initialise_images(&display) == 0)
		return (free_arr(display.map), ft_printf("Error\n"), 0);
	print_components(&display);
	mlx_key_hook(display.window, close_window, (void *)(&display));
	mlx_hook(display.window, 17, 0, on_destroy, (void *)(&display));
	mlx_loop(display.init);
	return (destroy(display), free_arr(display.map), 0);
}
