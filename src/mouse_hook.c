/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:34:26 by ahermawa          #+#    #+#             */
/*   Updated: 2022/10/10 16:42:54 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_out(int x, int y, t_zoom *zoom)
{
	double	c1;
	double	c2;

	c1 = zoom->x_start + ((double)x / WIDTH) * (zoom->x_end - zoom->x_start);
	c2 = zoom->y_start + ((double)y / HEIGHT) * (zoom->y_end - zoom->y_start);
	zoom->x_start = zoom->x_start + ((zoom->x_start - c1) * 0.1);
	zoom->y_start = zoom->y_start + ((zoom->y_start - c2) * 0.1);
	zoom->x_end = zoom->x_end - ((c1 - zoom->x_end) * 0.1);
	zoom->y_end = zoom->y_end - ((c2 - zoom->y_end) * 0.1);
	screen_iteration(zoom->img, zoom);
	mlx_put_image_to_window(zoom->mlx->mlx, zoom->mlx->win,
		zoom->img->img, 0, 0);
}

void	zoom_in(int x, int y, t_zoom *zoom)
{
	double	c1;
	double	c2;

	c1 = zoom->x_start + ((double)x / WIDTH) * (zoom->x_end - zoom->x_start);
	c2 = zoom->y_start + ((double)y / HEIGHT) * (zoom->y_end - zoom->y_start);
	zoom->x_start = zoom->x_start - ((zoom->x_start - c1) * 0.1);
	zoom->y_start = zoom->y_start - ((zoom->y_start - c2) * 0.1);
	zoom->x_end = zoom->x_end + ((c1 - zoom->x_end) * 0.1);
	zoom->y_end = zoom->y_end + ((c2 - zoom->y_end) * 0.1);
	screen_iteration(zoom->img, zoom);
	mlx_put_image_to_window(zoom->mlx->mlx, zoom->mlx->win,
		zoom->img->img, 0, 0);
}

int	mouse_hook(int button, int x, int y, t_zoom *zoom)
{
	if (button == 1)
	{
		if (zoom->bool == 0)
			zoom->bool = 1;
		else
			zoom->bool = 0;
	}
	if (button == 4 && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		zoom_in(x, y, zoom);
	else if (button == 5 && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		zoom_out(x, y, zoom);
	return (0);
}

int	mouse_move(int x, int y, t_zoom *zoom)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && zoom->bool == 0)
	{
		zoom->cc2 = zoom->x_start + ((double)x / WIDTH)
			* (zoom->x_end - zoom->x_start);
		zoom->cc1 = zoom->y_start + ((double)y / HEIGHT)
			* (zoom->y_end - zoom->y_start);
		screen_iteration(zoom->img, zoom);
		mlx_put_image_to_window(zoom->mlx->mlx, zoom->mlx->win,
			zoom->img->img, 0, 0);
	}
	return (0);
}
