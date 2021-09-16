/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_mandelbrot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:34:58 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/15 11:57:00 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_mandelbrot_point(t_fractal *fractal, double x, double y);

int	ft_mandelbrot_calc(t_fractal *fractal, int width, int height)
{
	t_point	p;
	int		i;
	int		j;
	int		idx;

	i = 0;
	fractal->max_val_reached = 0;
	fractal->min_val_reached = fractal->max_iter;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			idx = j * width + i;
			ft_win_to_viewport(fractal, i, j, &p);
			fractal->vals[idx] = ft_mandelbrot_point(fractal, p.x, p.y);
			if (fractal->vals[idx] < fractal->min_val_reached)
				fractal->min_val_reached = fractal->vals[idx];
			if (fractal->vals[idx] > fractal->max_val_reached)
				fractal->max_val_reached = fractal->vals[idx];
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_mandelbrot_point(t_fractal *fractal, double x, double y)
{
	int		i;
	double	z[2];
	double	z2[2];
	double	w;

	i = 0;
	w = 0;
	z2[0] = 0;
	z2[1] = 0;
	while (i < fractal->max_iter && z2[0] + z2[1] <= 4)
	{
		z[0] = z2[0] - z2[1] + x;
		z[1] = w - z2[0] - z2[1] + y;
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		w = (z[0] + z[1]) * (z[0] + z[1]);
		i++;
	}
	return (i - 1);
}
