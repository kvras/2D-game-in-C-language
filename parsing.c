/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:45:27 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/15 00:26:09 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct(t_game *so_long)
{
	int	i;

	i = 0;
	while ( so_long && so_long->map && i < so_long->len)
	{
		free(so_long->map[i]);
		i++;
	}
	if (so_long && so_long->map)
		free(so_long->map);
	free(so_long);
}

t_game	*copy(t_game *so_long)
{
	t_game		*copy;
	int			i;
	int			j;

	copy = (t_game *)malloc(sizeof(t_game));
	copy->map = (char **)malloc(sizeof(char *) * so_long->len);
	if(!copy || !copy->map)
		return (free_struct(copy), NULL);
	i = 0;
	while (i < so_long->len)
	{
		copy->map[i] = (char *)malloc(sizeof(char) * so_long->width);
		if (!copy->map[i])
			return (free_struct(copy), NULL);
		j = 0;
		while (j < so_long->width)
		{
			copy->map[i][j] = so_long->map[i][j];
			j++;
		}
		i++;
	}
	copy->len = so_long->len;
	copy->width = so_long->width;
	copy->avatar_x = so_long->avatar_x;
	copy->avatar_y = so_long->avatar_y;
	copy->player = so_long->player;
	copy->collect = so_long->collect;
	copy->exit = so_long->exit;
	return (copy);
}

char	*get_next_line_caller(int fd, char **line)
{
	free(*line);
	*line = NULL;
	*line = get_next_line(fd);
	return (*line);
}

int	map_matrix(t_game *so_long, int fd)
{
	char	*line;
	char	*list;
	char	*tmp;
	int		i;

	list = NULL;
	line = NULL;
	i = 0;
	while (get_next_line_caller(fd, &line))
	{
		if (i == 0)
			so_long->width = ft_strlen(line);
		tmp = ft_strjoin(list, line);
		free(line);
		free(list);
		line = NULL;
		list = tmp;
		i++;
	}
	if(!list || list[ft_strlen(list) - 1] == '\n')
		return (0);
	so_long->map = ft_split(list, '\n');
	if(!so_long->map)
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
	if (so_long->map[x][y] == 'E')
	{
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
int	components_checker(t_game *so_long)
{
	if (so_long->exit == 1 && so_long->player == 1 && so_long->collect > 0)
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
			if ((y == so_long->width - 1 || x == so_long->len - 1 ) && so_long->map[x][y] != '1')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
int	components_counter(t_game *so_long)
{
	int	x;
	int	y;

	x = 0;
	while (so_long->map[x])
	{
		y = 0;
		while (so_long->map[x][y])
		{
			if (so_long->map[x][y] == 'E')
				so_long->exit++;
			else if (so_long->map[x][y] == 'C')
				so_long->collect++;
			else if (so_long->map[x][y] == 'P')
			{
				so_long->player++;
				so_long->avatar_x = x;
				so_long->avatar_y = y;
			}
			else if (so_long->map[x][y] != '0' && so_long->map[x][y] != '1')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	deep_checker(t_game *so_long)
{
	int	x;

	x = 0;
	while (so_long->map[x])
		x++;
	if (so_long->len != x)
		return (0);
	if (components_counter(so_long) && components_checker(so_long) && borders_checker(so_long))
		return (1);
	return (0);
}
int checker_caller(char *file, t_game *so_long)
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
	if(!map_matrix(so_long, fd))
		return (0);
	response = deep_checker(so_long);
	if (response == 1)
	{
		copy_struct = copy(so_long);
		if (!copy_struct)
			return (0);
		response = flood_fill(copy_struct, so_long->avatar_x, so_long->avatar_y);
		free_struct(copy_struct);
	}
	close(fd);
	return (response);
}
