/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:55:05 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/27 19:41:54 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdlib.h>
# include "mlx.h"

# define WIDTH 1980
# define HEIGHT 1080
# define DATA_JUMP 4
# define MAX_ITER 100

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
	
}           t_mlx;

typedef struct s_img
{
    void    *img;
    char    *data;
    int     bpp;
    int     stride;
    int     endian;
}             t_img;

typedef struct s_zoom
{
    double  x_start;
    double  x_end;
	double	y_start;
	double	y_end;
	t_img	*img;
	t_mlx	*mlx;
}			t_zoom;

int   	mouse_hook(int button, int x, int y, t_zoom *zoom);
void    screen_iteration(t_img *img, t_zoom *zoom);
int		toggle_button(int button, t_zoom *zoom);

#endif
