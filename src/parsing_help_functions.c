/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:27:17 by miguiji           #+#    #+#             */
/*   Updated: 2024/03/19 21:06:46 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_game	*copy(t_game *game)
{
	t_game		*copy;
	int			i;

	copy = (t_game *)malloc(sizeof(t_game));
	if (!copy)
		return (NULL);
	copy->map = (char **)malloc(sizeof(char *) * game->len);
	if (!copy->map)
		return (free_struct(copy), NULL);
	i = -1;
	while (++i < game->len)
	{
		copy->map[i] = ft_strdup(game->map[i]);
		if (!copy->map[i])
			return (free_struct(copy), NULL);
	}
	copy->len = game->len;
	copy->width = game->width;
	copy->x = game->x;
	copy->y = game->y;
	copy->player = game->player;
	return (copy->collect = game->collect, copy->exit = game->exit, copy);
}

char	*get_next_line_caller(int fd, char **line)
{
	free(*line);
	*line = NULL;
	*line = get_next_line(fd);
	return (*line);
}

int	components_checker(t_game *game)
{
	if (game->exit == 1 && game->player == 1 && game->collect > 0)
		return (1);
	return (0);
}

int	deep_checker(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x])
		x++;
	if (game->len != x)
		return (0);
	if (components_counter(game) && components_checker(game)
		&& borders_checker(game))
		return (1);
	return (0);
}
