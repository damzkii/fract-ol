/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:24:56 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/30 11:59:09 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init(t_zoom *zoom)
{
    zoom->cc1 = 0;
    zoom->cc2 = 0;
    zoom->bool = 0;
}

void    error_msg(char *message, int error)
{
    if (error == 0)
        ft_putendl(message);
    if (error == 1)
    {
        ft_putendl(message);
        exit (0);
    }    
}   

void init_mlx(t_mlx *mlx, t_img *img, t_zoom *zoom)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FRACTOL");
    img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    img->data = mlx_get_data_addr(img->img, &img->bpp, &img->stride, &img->endian);
	screen_iteration(img, zoom);
    mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
    mlx_hook(mlx->win, 4, 0, mouse_hook, zoom);
    mlx_hook(mlx->win, 6, 0, mouse_hook, zoom);
    mlx_hook(mlx->win, 6, 0, mouse_move, zoom);
    mlx_hook(mlx->win, 2, 1L << 0, toggle_button, zoom);
}