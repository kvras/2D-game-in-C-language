/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help_functions_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:27:17 by miguiji           #+#    #+#             */
/*   Updated: 2024/02/18 17:48:23 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_game	*copy(t_game *so_long)
{
	t_game		*copy;
	int			i;

	copy = (t_game *)malloc(sizeof(t_game));
	if (!copy)
		return (NULL);
	copy->map = (char **)malloc(sizeof(char *) * so_long->len);
	if (!copy->map)
		return (free_struct(copy), NULL);
	i = -1;
	while (++i < so_long->len)
	{
		copy->map[i] = ft_strdup(so_long->map[i]);
		if (!copy->map[i])
			return (free_struct(copy), NULL);
	}
	copy->len = so_long->len;
	copy->width = so_long->width;
	copy->x = so_long->x;
	copy->y = so_long->y;
	copy->player = so_long->player;
	return (copy->collect = so_long->collect, copy->exit = so_long->exit, copy);
}

char	*get_next_line_caller(int fd, char **line)
{
	free(*line);
	*line = NULL;
	*line = get_next_line(fd);
	return (*line);
}

int	components_checker(t_game *so_long)
{
	if (so_long->exit == 1 && so_long->player == 1 && so_long->collect > 0)
		return (1);
	return (0);
}

int	deep_checker(t_game *so_long)
{
	int	x;

	x = 0;
	while (so_long->map[x])
		x++;
	if (so_long->len != x)
		return (0);
	if (components_counter(so_long) && components_checker(so_long)
		&& borders_checker(so_long))
		return (1);
	return (0);
}
