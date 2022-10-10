/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:36:32 by ahermawa          #+#    #+#             */
/*   Updated: 2022/10/10 16:46:58 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	toggle_button3(int button, t_zoom *zoom)
{
	double	temp;

	if (button == 123)
	{
		temp = ((zoom->x_end - zoom->x_start) * 0.1);
		zoom->x_start -= temp;
		zoom->x_end -= temp;
		screen_iteration(zoom->img, zoom);
		mlx_put_image_to_window(zoom->mlx->mlx,
			zoom->mlx->win, zoom->img->img, 0, 0);
	}
	else if (button == 124)
	{
		temp = ((zoom->x_end - zoom->x_start) * 0.1);
		zoom->x_start += temp;
		zoom->x_end += temp;
		screen_iteration(zoom->img, zoom);
		mlx_put_image_to_window(zoom->mlx->mlx,
			zoom->mlx->win, zoom->img->img, 0, 0);
	}
}

void	toggle_button2(int button, t_zoom *zoom)
{
	double	temp;

	if (button == 126)
	{
		temp = ((zoom->y_end - zoom->y_start) * 0.1);
		zoom->y_start -= temp;
		zoom->y_end -= temp;
		screen_iteration(zoom->img, zoom);
		mlx_put_image_to_window(zoom->mlx->mlx,
			zoom->mlx->win, zoom->img->img, 0, 0);
	}
	else if (button == 125)
	{
		temp = ((zoom->y_end - zoom->y_start) * 0.1);
		zoom->y_start += temp;
		zoom->y_end += temp;
		screen_iteration(zoom->img, zoom);
		mlx_put_image_to_window(zoom->mlx->mlx,
			zoom->mlx->win, zoom->img->img, 0, 0);
	}
	else
		toggle_button3(button, zoom);
}

int	toggle_button(int button, t_zoom *zoom)
{	
	if (button == 53)
	{
		ft_putendl("You have exit fractol");
		exit(EXIT_SUCCESS);
	}
	else
		toggle_button2(button, zoom);
	return (0);
}
