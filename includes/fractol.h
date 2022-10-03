/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:55:05 by ahermawa          #+#    #+#             */
/*   Updated: 2022/10/03 14:15:18 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "../libft/includes/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define DATA_JUMP 4
# define MAX_ITER 50

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
	double	cc1;
	double	cc2;
	t_img	*img;
	t_mlx	*mlx;
    int     fractal;
	uint8_t	bool;
    int     trigger_bs;
    int     tricorn;
	unsigned int	clr;
}			t_zoom;

void    init(t_zoom *zoom);
void    screen_iteration(t_img *img, t_zoom *zoom);
void    error_msg(char *message, int error);
void	init_mlx(t_mlx *mlx, t_img *img, t_zoom *zoom);
int   	mouse_hook(int button, int x, int y, t_zoom *zoom);
int		toggle_button(int button, t_zoom *zoom);
int		mouse_move(int x, int y, t_zoom *zoom);
int 	chooser(double c1, double c2, int fractal, t_zoom *zoom);
int		close_program(t_mlx *mlx);



#endif
