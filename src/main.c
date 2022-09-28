/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:53:59 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/28 18:38:10 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#define REAL_START 	-2
#define REAL_END 	1
#define IMG_START 	-1
#define IMG_END 	1

int	close_program(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

void    pxl_put(t_img *img, int x, int y, unsigned int colour)
{
    if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
        return ;
    *(unsigned int *)(img->data + (((x + (y * WIDTH)) * DATA_JUMP))) = colour;
}

void    screen_iteration(t_img *img, t_zoom *zoom)
{
    double			x;
    double 			y;
	unsigned int	ret;
	unsigned int	clr;
	double			c1;
	double			c2;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
			c1 = zoom->x_start + (x / WIDTH) * (zoom->x_end - zoom->x_start);
			c2 = zoom->y_start + (y / HEIGHT) * (zoom->y_end - zoom->y_start);
			ret = chooser(c2, c1, zoom->fractal, zoom);
			if (!(ret))
				clr = 0;
			else
				clr = 0xfffff - (unsigned int)(ret * 0xfffff / MAX_ITER);
            pxl_put(img, x, y, clr);
			x++;
        }
        y++;
    }
}

int    get_fractal(char *str)
{
    if (ft_strequ(str, "mandelbrot"))
        return (0);
    if (ft_strequ(str, "burningship"))
        return (1);
    if (ft_strequ(str, "julia"))
        return (2);
    return (-1);
}

int main(int argc,char **argv)
{
    t_mlx   		mlx;
    t_img   		img;
	static t_zoom	zoom = {-2, 1, -1, 1};

    if (argc != 2)
        (exit(0));
    init(&zoom);
	zoom.mlx = &mlx;
	zoom.img = &img;
    zoom.fractal = get_fractal(argv[1]);
    if (zoom.fractal == (-1))
        exit(0);
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FRACTOL");
    img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
    img.data = mlx_get_data_addr(img.img, &img.bpp, &img.stride, &img.endian);
	screen_iteration(&img, &zoom);
    mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
    mlx_hook(mlx.win, 4, 0, &mouse_hook, &zoom);
    mlx_hook(mlx.win, 6, 0, &mouse_hook, &zoom);
    mlx_hook(mlx.win, 6, 0, &mouse_move, &zoom);
    mlx_hook(mlx.win, 2, 1L << 0, &toggle_button, &zoom);
	mlx_hook(mlx.win, 17, 0, &close_program, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
