/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:34:55 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 16:38:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Function who make Julia set.                                               */
/* ************************************************************************** */
int	ft_julia_calc(t_fractal *fractal, double x, double y)
{
	int		i;
	double	x2;
	double	y2;
	double	w;

	i = 0;
	x2 = 0;
	y2 = 0;
	while (i < fractal->max_iter && x2 + y2 < (1L << 16))
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
