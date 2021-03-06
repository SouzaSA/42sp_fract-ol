/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_burning_ship.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:16:18 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 16:38:50 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Function who make Burning Ship set.                                        */
/* ************************************************************************** */
int	ft_burning_ship_calc(t_fractal *fractal, double x, double y)
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
		cpx.y = fabs(w - pow2.x - pow2.y) - y;
		pow2.x = cpx.x * cpx.x;
		pow2.y = cpx.y * cpx.y;
		w = (cpx.x + cpx.y) * (cpx.x + cpx.y);
		i++;
	}
	return (i);
}
