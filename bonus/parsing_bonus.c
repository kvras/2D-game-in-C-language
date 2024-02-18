/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:45:27 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/18 14:13:34 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_matrix(t_game *so_long, int fd)
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
			so_long->width = ft_strlen(line) - 1;
		tmp = ft_strjoin(list, line);
		free(list);
		list = tmp;
	}
	if (!list || list[ft_strlen(list) - 1] == '\n')
		return (free(list), 0);
	so_long->map = ft_split(list, '\n');
	if (!so_long->map)
		return (free(list), 0);
	free(list);
	so_long->len = i;
	return (so_long->player = 0, so_long->collect = 0, so_long->exit = 0, 1);
}

int	flood_fill(t_game *so_long, int x, int y)
{
	int	i;

	i = 0;
	if (so_long->map[x][y] == 'C')
		(so_long->collect)--;
	if (so_long->map[x][y] == 'E' || so_long->map[x][y] == 'G')
	{
		if (so_long->map[x][y] == 'E')
			(so_long->exit)--;
		so_long->map[x][y] = '1';
		return (0);
	}
	so_long->map[x][y] = '1';
	if (so_long->map[x + 1][y] != '1')
		flood_fill(so_long, x + 1, y);
	if (so_long->map[x - 1][y] != '1')
		flood_fill(so_long, x - 1, y);
	if (so_long->map[x][y + 1] != '1')
		flood_fill(so_long, x, y + 1);
	if (so_long->map[x][y - 1] != '1')
		flood_fill(so_long, x, y - 1);
	if (so_long->collect == 0 && so_long->exit == 0)
		return (1);
	return (0);
}

int	borders_checker(t_game *so_long)
{
	int	x;
	int	y;

	x = 0;
	while (so_long->map[x])
	{
		y = 0;
		while (so_long->map[x][y])
		{
			if ((y == 0 || x == 0) && so_long->map[x][y] != '1')
				return (0);
			if ((y == so_long->width - 1 || x == so_long->len - 1)
				&& so_long->map[x][y] != '1')
				return (0);
			y++;
		}
		x++;
	}
	if (so_long->len > 100 || so_long->width > 100)
		return (0);
	return (1);
}

int	components_counter(t_game *so_long)
{
	int	x;
	int	y;

	x = -1;
	while (so_long->map[++x])
	{
		y = -1;
		while (so_long->map[x][++y])
		{
			if (so_long->map[x][y] == 'E')
				so_long->exit++;
			else if (so_long->map[x][y] == 'C')
				so_long->collect++;
			else if (so_long->map[x][y] == 'P')
			{
				so_long->player++;
				so_long->x = x;
				so_long->y = y;
			}
			else if (so_long->map[x][y] != '0' && so_long->map[x][y] != '1'
				&& so_long->map[x][y] != 'G')
				return (0);
		}
	}
	return (1);
}

int	checker_caller(char *file, t_game *so_long)
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
	if (!map_matrix(so_long, fd))
		return (0);
	response = deep_checker(so_long);
	if (response == 1)
	{
		copy_struct = copy(so_long);
		if (!copy_struct)
			return (0);
		response = flood_fill(copy_struct, so_long->x,
				so_long->y);
		free_struct(copy_struct);
	}
	return (close(fd), response);
}
