/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:18:01 by ahermawa          #+#    #+#             */
/*   Updated: 2022/10/05 13:02:51 by ahermawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbscorn(double c1, double c2, t_zoom *zoom)
{
	double	z;
	double	z1;
	double	temp;
	int		n;

	z = 0;
	z1 = 0;
	n = 0;
	while (n < MAX_ITER && (z1 * z1 + z * z) < 4)
	{
		if (zoom->burningship == 1)
		{
			z = fabs(z);
			z1 = fabs(z1);
		}
		temp = z;
		z = zoom->tricorn * (z * z1) + c1;
		z1 = z1 * z1 + temp * temp * (-1) + c2;
		n++;
	}
	return (n);
}

int	julia(double c1, double c2, const double cc1, const double cc2)
{
	double	z;
	double	z1;
	double	temp;
	int		n;

	z = c1;
	z1 = c2;
	n = 0;
	while (n < MAX_ITER && (z1 * z1 + z * z) < 4)
	{
		temp = z;
		z = 2 * (z * z1) + cc1;
		z1 = z1 * z1 + temp * temp * (-1) + cc2;
		n++;
	}
	return (n);
}

int	option(double c1, double c2, const double cc1, const double cc2)
{
	double	z;
	double	z1;
	double	temp;
	int		n;

	z = c1;
	z1 = c2;
	n = 0;
	while (n < MAX_ITER && (z1 * z1 + z * z) < 4)
	{
		z = fabs(z);
		z1 = fabs(z1);
		temp = z;
		z = 2 * (z * z1) + cc1;
		z1 = z1 * z1 + temp * temp * (-1) + cc2;
		n++;
	}
	return (n);
}

int	chooser(double c1, double c2, int fractal, t_zoom *zoom)
{
	if (fractal == 0)
		return (mandelbscorn(c1, c2, zoom));
	else if (fractal == 1)
	{
		zoom->burningship = 1;
		return (mandelbscorn(c1, c2, zoom));
	}
	else if (fractal == 2)
	{
		zoom->tricorn = -2;
		return (mandelbscorn(c1, c2, zoom));
	}
	else if (fractal == 3)
		return (julia(c1, c2, zoom->cc1, zoom->cc2));
	else if (fractal == 4)
		return (julia(c1, c2, zoom->cc1, zoom->cc2));
	return (0);
}
