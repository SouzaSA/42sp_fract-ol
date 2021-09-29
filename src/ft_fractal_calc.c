/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:20:27 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 16:34:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible for iterate window points and call window to viewport converter*/
/* and send then to fractal to execute his scape time algorithm.              */
/* ************************************************************************** */
int	ft_fractal_calc(t_fractal *fractal, int width, int height)
{
	t_point	p;
	int		i;
	int		j;
	int		idx;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			idx = j * width + i;
			ft_win_to_viewport(fractal, i, j, &p);
			fractal->vals[idx] = fractal->fractal_calc(fractal, p.x, p.y);
			j++;
		}
		i++;
	}
	return (0);
}
