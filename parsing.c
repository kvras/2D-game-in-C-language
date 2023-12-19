#include "so_long.h"

void map_matrix(map *map, int fd)
{
	char *str = NULL;
	char *list = NULL;
	char *tmp;
	int i =0;
	while (1)
	{
		str = get_next_line(fd);
		if(!str)
			break;
		else if(i == 0)
			map->width = strlen(str) - 1;
		tmp = ft_strjoin(list, str);
		free(list);
		list = NULL;
		list = tmp;
		free(str);
		str = NULL;
		i++;
	}
	map->map = ft_split(list, '\n');
	free(list);
	map->len = i;
	map->player = 0;
	map->collect = 0;
	map->exit = 0;
}
int flood_fill(map *map,int x, int y)
{
	int i;
	i = 0;
	if(map->collect == 0 && map->exit == 0)
		return (1);
	if(map->map[x][y] == 'P')
		map->map[x][y] = '1';
	if(map->map[x][y] == 'C')
		(map->collect)--;
	if(map->map[x][y] == 'E')
		(map->exit)--;
	map->map[x][y] = '1';
	if(map->map[x + 1][y] != '1')
		flood_fill(map, x + 1, y);
	if(map->map[x - 1][y]!= '1')
		flood_fill(map, x - 1, y);
	if(map->map[x][y + 1] != '1')
		flood_fill(map, x, y + 1);
	if(map->map[x][y - 1] != '1')
		flood_fill(map, x, y - 1);
	if(map->collect == 0 && map->exit == 0)
		return (1);
	return (0);
}
int simple_checker(map *map)
{
	int i;
	int x;
	int y;
	i = 0;
	x = 0;
	y = 0;
	while(map->map[x])
	{
		if(strlen(map->map[x]) != map->width)
			return (0);
		y = 0;
		while (map->map[x][y])
		{
			if(map->map[x][y] == 'E')
				map->exit++;
			else if(map->map[x][y] == 'C')
				map->collect++;
			else if(map->map[x][y] == 'P')
				map->player++;
			else if(map->map[x][y] != '0' && map->map[x][y] != '1')
				return (0);
			if(map->map[x][0] != '1' || map->map[x][map->width - 1] != '1')
				return (0);
			if(x == 0)
			{
				if(map->map[x][y] != '1')
					return (0);
			}
			else if (x == map->len - 1)
			{
				if(map->map[x][y] != '1')
					return (0);
			}
			y++;
		}
		x++;
		
	}
	return (1);
}

int deep_checker(map *map)
{
	if(simple_checker(map) && map->exit == 1 && map->collect > 0 && map->player == 1)
			return (1);
	return (0);
}
int checker_caller(char *file, map *map)
{
	int response = 0;
	int fd;
	int i = 0;
	if(strnstr(file, ".ber", strlen(file)) == NULL)
		return (0);
	fd = open(file, O_RDONLY);
	if(fd == -1)
		return (0);
	map_matrix(map,fd);
	response = deep_checker(map);
	if(response == 1)
		response = flood_fill(map,6,1);
	close(fd);
	return (response);
}
// int main(int argc, char **argv)
// {
// 	int i;
// 	if(argc == 2)
// 		i = checker_caller(argv[1]);
// 	else
// 	{
// 		printf("Error\n");
// 		return (0);
// 	}
// 	if(i == 1)
// 		printf("OK\n");
// 	else
// 		printf("Error\n");
// }
