/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_mandelbrot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:34:58 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/18 15:23:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_mandelbrot_calc(t_fractal *fractal, double x, double y)
{
	int		i;
	t_point	cpx;
	t_point	pow2;
	double	w;

	i = 0;
	w = 0;
	pow2.x = 0;
	pow2.y = 0;
	while (i < fractal->max_iter && pow2.x + pow2.y <= 4)
	{
		cpx.x = pow2.x - pow2.y + x;
		cpx.y = w - pow2.x - pow2.y + y;
		pow2.x = cpx.x * cpx.x;
		pow2.y = cpx.y * cpx.y;
		w = (cpx.x + cpx.y) * (cpx.x + cpx.y);
		i++;
	}
	return (i - 1);
}
