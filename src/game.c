/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:29:02 by miguiji           #+#    #+#             */
/*   Updated: 2024/03/19 21:00:01 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	print_score(t_game *mlx)
{
	int		j;
	char	*str;
	int		color;
	char	*string;

	string = "steps : ";
	color = 16777215;
	j = 0;
	ft_printf("%s %d\n", string, ++mlx->mouvements);
	while (j <= 3)
	{
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->wall, j * 50, 0);
		j++;
	}
	str = ft_itoa(mlx->mouvements);
	if (!str)
		return ;
	mlx_string_put(mlx->init, mlx->window, 20, 15, color, string);
	mlx_string_put(mlx->init, mlx->window, 100, 15, color, str);
	free(str);
	str = NULL;
}

int	checker(int x, int y, void *param)
{
	t_game	*mlx;

	mlx = (t_game *)param;
	if (mlx->map[mlx->x][mlx->y] == 'C')
	{
		mlx->map[mlx->x][mlx->y] = '0';
		mlx->collect--;
	}
	else if ((mlx->map[mlx->x][mlx->y] == 'E' && mlx->collect == 0)
		|| mlx->map[mlx->x][mlx->y] == 'G')
	{
		print_score(mlx);
		destroy(*mlx);
		exit(0);
	}
	else if (mlx->map[mlx->x][mlx->y] == 'E')
	{
		mlx->x = x;
		mlx->y = y;
		return (1);
	}
	print_score(mlx);
	return (1);
}

int	initialisation_check(t_game *d)
{
	if (!d->right || !d->wall || !d->road || !d->coin || !d->door || !d->window
		|| !d->init || !d->ennemy || !d->up || !d->down || !d->left)
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
