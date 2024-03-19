/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:45:27 by miguiji           #+#    #+#             */
/*   Updated: 2024/03/19 21:06:46 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	map_matrix(t_game *game, int fd)
{
	char	*line;
	char	*list;
	char	*tmp;
	int		i;

	line = NULL;
	list = NULL;
	i = 0;
	while (get_next_line_caller(fd, &line))
	{
		if (i++ == 0)
			game->width = ft_strlen(line) - 1;
		tmp = ft_strjoin(list, line);
		free(list);
		list = tmp;
	}
	close(fd);
	if (!list || list[ft_strlen(list) - 1] == '\n')
		return (free(list), 0);
	game->map = ft_split(list, '\n');
	if (!game->map)
		return (free(list), 0);
	free(list);
	game->len = i;
	return (game->player = 0, game->collect = 0, game->exit = 0, 1);
}

int	flood_fill(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (game->map[x][y] == 'C')
		(game->collect)--;
	if (game->map[x][y] == 'E' || game->map[x][y] == 'G')
	{
		if (game->map[x][y] == 'E')
			(game->exit)--;
		game->map[x][y] = '1';
		return (0);
	}
	game->map[x][y] = '1';
	if (game->map[x + 1][y] != '1')
		flood_fill(game, x + 1, y);
	if (game->map[x - 1][y] != '1')
		flood_fill(game, x - 1, y);
	if (game->map[x][y + 1] != '1')
		flood_fill(game, x, y + 1);
	if (game->map[x][y - 1] != '1')
		flood_fill(game, x, y - 1);
	if (game->collect == 0 && game->exit == 0)
		return (1);
	return (0);
}

int	borders_checker(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if ((y == 0 || x == 0) && game->map[x][y] != '1')
				return (0);
			if ((y == game->width - 1 || x == game->len - 1)
				&& game->map[x][y] != '1')
				return (0);
			y++;
		}
		if (ft_strlen(game->map[x]) != (size_t)game->width)
			return (0);
		x++;
	}
	if (game->len > 100 || game->width > 100)
		return (0);
	return (1);
}

int	components_counter(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == 'E')
				game->exit++;
			else if (game->map[x][y] == 'C')
				game->collect++;
			else if (game->map[x][y] == 'P')
			{
				game->player++;
				game->x = x;
				game->y = y;
			}
			else if (game->map[x][y] != '0' && game->map[x][y] != '1'
				&& game->map[x][y] != 'G')
				return (0);
		}
	}
	return (1);
}

int	checker_caller(char *file, t_game *game)
{
	t_game	*copy_struct;
	int		response;
	int		fd;
	int		i;

	i = 0;
	response = 0;
	if (ft_strnstr(file + (ft_strlen(file) - 4), ".ber", 4) == NULL)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!map_matrix(game, fd))
		return (0);
	response = deep_checker(game);
	if (response == 1)
	{
		copy_struct = copy(game);
		if (!copy_struct)
			return (0);
		response = flood_fill(copy_struct, game->x,
				game->y);
		free_struct(copy_struct);
	}
	return (response);
}
