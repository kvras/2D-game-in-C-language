/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:29:22 by miguiji           #+#    #+#             */
/*   Updated: 2023/12/20 02:07:21 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct {
            int x;
            int y;
            int len;
			int width;
            void *avatar;
            void *map;
            void *door;
            void *wall;
            void *collectible;
            char **matrix;
        }struct_img;

typedef struct {
        void *window;
        void *init;
        struct_img img;
    }mlx_type;

int img_mnpl(int keycode , void *param)
{
    mlx_type *mlx = (mlx_type *)param;
    int x = (mlx->img).x;
    int y = (mlx->img).y;
    if(keycode == 123 && (mlx->img).x - 1 >= 0 && mlx->img.matrix[x - 1][y] != '1')
    {
        mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.map, mlx->img.x*50, mlx->img.y*50);
        (mlx->img).x = (mlx->img).x - 1;
    }
    if (keycode == 124 && (mlx->img).x + 1 < mlx->img.len && mlx->img.matrix[x + 1][y] != '1')
    {
        mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.map, mlx->img.x*50, mlx->img.y*50);
        (mlx->img).x = (mlx->img).x + 1;
    }
    if (keycode == 125 && (mlx->img).y + 1 < mlx->img.width && mlx->img.matrix[x][y + 1] != '1')
    {
        mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.map, mlx->img.x*50, mlx->img.y*50);
        (mlx->img).y = (mlx->img).y + 1;
    }
    if (keycode == 126 && (mlx->img).y - 1 >= 0 && mlx->img.matrix[x][y - 1] != '1')
    {
        mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.map, mlx->img.x*50, mlx->img.y*50);
        (mlx->img).y = (mlx->img).y - 1;
    }
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.avatar, mlx->img.x * 50, mlx->img.y * 50);
    return 0;
}
int close_window(int keycode, void *param)
{
    mlx_type *mlx = (mlx_type *)param;
    if(keycode == 53)
    {
        mlx_destroy_window(mlx->init, mlx->window);
        exit(0);
    }
    img_mnpl(keycode, param);
    return 0;
}
int main(int argc, char **argv)
{
    map map;
    mlx_type mlx;

    if (argc != 2)
        return (0);
    else if(!checker_caller(argv[1], &map))
        return (0);
    mlx.img.width = map.width;
    mlx.img.len = map.len;
    mlx.img.matrix = map.map;
    mlx.init = mlx_init();
    char *str;
    int x,y;
    x = 0;
    y = 0;
    int width;
    int height;
    mlx.window = mlx_new_window(mlx.init, map.len*50, map.width*50, "My Window");
    mlx.img.avatar = mlx_xpm_file_to_image(mlx.init, "ghost1.xpm", &width, &height);
    mlx.img.wall = mlx_xpm_file_to_image(mlx.init, "wall.xpm", &width, &height);
    mlx.img.map = mlx_xpm_file_to_image(mlx.init, "map.xpm", &width, &height);
    mlx.img.collectible = mlx_xpm_file_to_image(mlx.init, "collectible.xpm", &width, &height);
    while(x < map.len)
    {
        y = 0;
        while (y < map.width)
        {
            if (map.map[x][y] == '1')
                mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.wall, x*50, y*50);
            else if (map.map[x][y] == 'P')
            {
                mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.avatar, x*50, y*50);
                mlx.img.x = x;
                mlx.img.y = y;
            }
            else if (map.map[x][y] == 'C')
                mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.collectible, x*50, y*50);
            else if (map.map[x][y] == '0')
                mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.map, x*50, y*50);
            y++;
        }
        x++;
    }
    mlx_key_hook(mlx.window, close_window, (void *)(&mlx));
    mlx_loop(mlx.init);
}
