/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:18:01 by ahermawa          #+#    #+#             */
/*   Updated: 2022/09/30 12:14:01 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int    mandelbrot(double c1, double c2)
{
    double  z;
    double  z1;
    double  temp;
    int     n;
    
    z = 0;
    z1 = 0;
    n = 0;
    if ()
    while (n < MAX_ITER && (z1 * z1 + z * z) < 4)
    {
        temp = z;
        z = 2 * (z * z1)  + c1;
        z1 = z1 * z1 + temp * temp * (-1) + c2;
        n++;
    }
    return (n);
}

int    burning_ship(double c1, double c2)
{
    double  z;
    double  z1;
    double  temp;
    int     n;
    
    z = 0;
    z1 = 0;
    n = 0;
    while (n < MAX_ITER && (z1 * z1 + z * z) < 4)
    {
        z = fabs(z);
        z1 = fabs(z1);
        temp = z;
        z = 2 * (z * z1) + c1;
        z1 = z1 * z1 + temp * temp * (-1) + c2;
        n++;
    }
    return (n);
}

int    julia(double c1, double c2, const double cc1, const double cc2)
{
    double  z;
    double  z1;
    double  temp;
    int     n;
    
    z = c1;
    z1 = c2;
    n = 0;
    while (n < MAX_ITER && (z1 * z1 + z * z) < 4)
    {
        z = (z);
        z1 = (z1);
        temp = z;
        z = 2 * (z * z1) + cc1;
        z1 = z1 * z1 + temp * temp * (-1) + cc2;
        n++;
    }
    return (n);
}

int chooser(double c1, double c2, int fractal, t_zoom *zoom)
{
    if (fractal == 0)
        return (mandelbrot(c1, c2));
    else if (fractal == 1)
        return (mandelbrot(c1, c2));
    else if (fractal == 2)
        return (julia(c1, c2, zoom->cc1, zoom->cc2));
    return (0);
}
