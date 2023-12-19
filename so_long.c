/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguiji <miguiji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:29:22 by miguiji           #+#    #+#             */
/*   Updated: 2023/12/19 15:56:01 by miguiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// mlx_destroy_image(mlx->init, (mlx->img).img);
// mlx_put_image_to_window(mlx->init, mlx->window, (mlx->img).img, 205, 205);
#include "so_long.h"

typedef struct {
            int x;
            int y;
            void *img;
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
    while(x < (mlx->img).x + 100)
    {
        y = (mlx->img).y;
        while (y < (mlx->img).y + 120)
        {
            mlx_pixel_put(mlx->init, mlx->window, x, y, 0xFFFFFF);
            y++;
        }
        x++;
    }
    if(keycode == 123 && (mlx->img).x - 50 >= 0)
        (mlx->img).x = (mlx->img).x - 50;
    if (keycode == 124 && (mlx->img).x + 50 < mlx->width*50)
        (mlx->img).x = (mlx->img).x + 50;
    if (keycode == 125 && (mlx->img).y + 50 < mlx->len*50)
        (mlx->img).y = (mlx->img).y + 50;
    if (keycode == 126 && (mlx->img).y - 50 >= 0)
        (mlx->img).y = (mlx->img).y - 50;
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.img, mlx->img.x, mlx->img.y);
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
    //mlx_key_hook(mlx->window, img_mnpl, (void *)(mlx));
    img_mnpl(keycode, param);
    return 0;
}
int main(int argc, char **argv)
{
    map map;
    if (argc != 2)
        return (0);
    else if(!checker_caller(argv[1], &map))
        return (0);
    mlx_type mlx;
    mlx.init = mlx_init();
    char *str;
    int x,y;
    x = 0;
    y = 0;
    int width, height;
    mlx.window = mlx_new_window(mlx.init, map.width*50, map.len*50, "My Window");
    // while(x < map.width*50)
    // {
    //     y = 0;
    //     while (y < map.len*50)
    //     {
    //         mlx_pixel_put(mlx.init, mlx.window, x, y, 0xFFFFFF);
    //         y = y + 50;
    //     }
    //     x = x + 50;
    // }
    mlx.img.img = mlx_xpm_file_to_image(mlx.init, "ghost.xpm", &width, &height);
    mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.img, mlx.img.x, mlx.img.y);
    mlx_key_hook(mlx.window, close_window, (void *)(&mlx));
    mlx_loop(mlx.init);
}
