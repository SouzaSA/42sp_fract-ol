/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_mandelbrot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:34:58 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 19:01:24 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_check_divergent_area(t_fractal *fractal, double x, double y);

/******************************************************************************/
/* Function who make Mandelbrot set iterations, escape time algorithm.        */
/******************************************************************************/
int	ft_mandelbrot_calc(t_fractal *fractal, double x, double y)
{
	int		i;
	t_point	cpx;
	t_point	pow2;
	double	tmp;

	tmp = 0;
	pow2.x = 0;
	pow2.y = 0;
	i = ft_check_divergent_area(fractal, x, y);
	while (i < fractal->max_iter && pow2.x + pow2.y <= 4)
	{
		cpx.x = pow2.x - pow2.y + x;
		cpx.y = tmp - pow2.x - pow2.y + y;
		pow2.x = cpx.x * cpx.x;
		pow2.y = cpx.y * cpx.y;
		tmp = (cpx.x + cpx.y) * (cpx.x + cpx.y);
		i++;
	}
	return (i);
}

/******************************************************************************/
/* Check if the point is inside the first dregree bulb, cardioid, and the top */
/* and botton bulb of the cardioid, respectively.                             */
/******************************************************************************/
static int	ft_check_divergent_area(t_fractal *fractal, double x, double y)
{
	int		i;
	double	tmp;

	i = 0;
	tmp = (x - 0.25) * (x - 0.25) + y * y;
	if ((x + 1.0) * (x + 1.0) + y * y < 0.0625 \
		|| tmp * (tmp + (x - 0.25)) < 0.25 * y * y \
		|| (((x + 0.125) * (x + 0.125)) + (y - 0.744) * (y - 0.744)) < 0.0088 \
		|| (((x + 0.125) * (x + 0.125)) + (y + 0.744) * (y + 0.744)) < 0.0088)
	{
		i = fractal->max_iter;
	}
	return (i);
}
