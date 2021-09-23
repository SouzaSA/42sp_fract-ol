/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:20:27 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/23 09:37:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_fractal_calc(t_fractal *fractal, int width, int height)
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
			fractal->vals[idx] = fractal->fractal_calc(fractal, p.x, p.y);
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
