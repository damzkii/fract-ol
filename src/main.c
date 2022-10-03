/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:53:59 by ahermawa          #+#    #+#             */
/*   Updated: 2022/10/03 14:18:34 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	close_program(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

void	pxl_put(t_img *img, int x, int y, unsigned int colour)
{
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	*(unsigned int *)(img->data + (((x + (y * WIDTH)) * DATA_JUMP))) = colour;
}

void	screen_iteration(t_img *img, t_zoom *zoom)
{
	double			x;
	double			y;
	double			c1;
	double			c2;
	unsigned int	ret;

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
				zoom->clr = 0;
			else
				zoom->clr = 0xfffff - (unsigned int)(ret * 0xfffff / MAX_ITER);
			pxl_put(img, x, y, zoom->clr);
			x++;
		}
		y++;
	}
}

int	get_fractal(char *str)
{
	if (ft_strequ(str, "Mandelbrot"))
		return (0);
	if (ft_strequ(str, "Burningship"))
		return (1);
	if (ft_strequ(str, "Tricorn"))
		return (2);
	if (ft_strequ(str, "Julia"))
		return (3);
	if (ft_strequ(str, "Pabo"))
		return (4);
	else
	{
		error_msg("Incorrect name. \nExample ./fractol [Name] \
					\nMandelbrot\nJulia\nBurningship\nTricorn \
					\nPabo", 1);
		return (-1);
	}
}

int	main(int argc, char **argv)
{
	t_mlx			mlx;
	t_img			img;
	static t_zoom	zoom = {-2, 1, -1, 1};

	if (argc != 2)
	{
		error_msg("Usage: ./fractol Mandelbrot or Julia or Burningship'", 0);
		return (0);
	}
	init(&zoom);
	zoom.mlx = &mlx;
	zoom.img = &img;
	zoom.fractal = get_fractal(argv[1]);
	if (zoom.fractal == -1)
		exit(0);
	init_mlx(&mlx, &img, &zoom);
	mlx_hook(mlx.win, 17, 0, &close_program, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
