/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:34:55 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/14 17:16:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_julia_point(t_fractal *fractal, double x, double y);

int	ft_julia_calc(t_fractal *fractal, int width, int height)
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
			fractal->vals[idx] = ft_julia_point(fractal, p.x, p.y);
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

static int	ft_julia_point(t_fractal *fractal, double x, double y)
{
	int		i;
	double	x2;
	double	y2;
	double	w;

	i = 0;
	x2 = 0;
	y2 = 0;
	while (i < fractal->max_iter && x2 + y2 < 4)
	{
		x2 = x * x;
		y2 = y * y;
		w = (x + y) * (x + y) - x2 - y2;
		x = x2 - y2 + fractal->cte.x;
		y = w + fractal->cte.y;
		i++;
	}
	return (i);
}
