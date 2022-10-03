/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:24:56 by ahermawa          #+#    #+#             */
/*   Updated: 2022/10/03 18:01:36 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_zoom *zoom)
{
	zoom->cc1 = 0;
	zoom->cc2 = 0;
	zoom->bool = 0;
	zoom->burningship = 0;
	zoom->tricorn = 2;
	zoom->clr = 0;
	zoom->x_start = -2;
	zoom->x_end = 1;
	zoom->y_start = -1;
	zoom->y_end = 1;
}

void	error_msg(char *message, int error)
{
	if (error == 0)
		ft_putendl(message);
	if (error == 1)
	{
		ft_putendl(message);
		exit (0);
	}
}

void	init_mlx(t_mlx *mlx, t_img *img, t_zoom *zoom)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		error_msg("Error with mlx pointer", 1);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FRACTOL");
	if (img->img == NULL)
		error_msg("Window creation failure", 1);
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!img->img)
		error_msg("Creating new image failed!", 1);
	img->data = mlx_get_data_addr(img->img, &img->bpp,
			&img->stride, &img->endian);
	if (!img->data)
		error_msg("Getting the Image address failed!", 1);
	screen_iteration(img, zoom);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	mlx_hook(mlx->win, 4, 0, mouse_hook, zoom);
	mlx_hook(mlx->win, 6, 0, mouse_hook, zoom);
	mlx_hook(mlx->win, 6, 0, mouse_move, zoom);
	mlx_hook(mlx->win, 2, 1L << 0, toggle_button, zoom);
}
