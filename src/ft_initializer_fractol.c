/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer_fractol.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:08:19 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/15 21:12:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_fractol_init(t_fractal *frac, char *name, int width, int height)
{
	int		i;
	char	*name_lower;

	name_lower = ft_strtolower(ft_strdup(name));
	i = 0;
	frac->vals = malloc(height * width * sizeof(int));
	if (!frac->vals)
		ft_frac_error_handler("Fail to malloc memory to fractal", errno);
	frac->max_iter = 256;
	if (ft_strcmp(name_lower, "julia") == 0)
	{
		frac->limit.min.x = -2.0;
		frac->limit.max.x = 2.0;
		frac->limit.min.y = -2.0;
		frac->limit.max.y = 2.0;
	}
	else if (ft_strcmp(name_lower, "mandelbrot") == 0)
	{
		frac->limit.min.x = -2.5;
		frac->limit.max.x = 1.0;
		frac->limit.min.y = -1.1;
		frac->limit.max.y = 1.1;
	}
	else
	{
		frac->limit.min.x = -3.0;
		frac->limit.max.x = 2.0;
		frac->limit.min.y = -2.0;
		frac->limit.max.y = 1.0;
	}
	frac->pixel_size.x = (frac->limit.max.x - frac->limit.min.x) / width;
	frac->pixel_size.y = (frac->limit.max.y - frac->limit.min.y) / height;
	free(name_lower);
	return (0);
}

int	ft_set_fractal_constant(t_vars *vars, t_point *point)
{
	vars->data.fractal.cte.x = point->x;
	vars->data.fractal.cte.y = point->y;
	vars->minimap.fractal.cte.x = point->x;
	vars->minimap.fractal.cte.y = point->y;
	return (0);
}
