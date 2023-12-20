#ifndef so_long
#define so_long
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <OpenGL/gl.h>
#include <mlx.h>
#include <stdlib.h>
typedef struct {
			int len;
			int width;
			char **map;
			int player;
			int collect;
			int exit;
			int avatar_x;
			int avatar_y;
		}map;
int checker_caller(char *file, map *map);
#endif