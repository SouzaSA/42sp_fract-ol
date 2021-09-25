/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:42:51 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/24 21:26:53 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_draw_mark(t_vars *vars);

int	ft_put_mark(t_vars *vars)
{
	char		*dt_name;
	char		*mm_name;

	dt_name = vars->data.fractal.title;
	mm_name = vars->minimap.fractal.title;
	if (ft_strcmp(dt_name, MANDELBROT) == 0)
	{
		ft_draw_mark(vars);
	}
	if (ft_strcmp(dt_name, JULIA) == 0)
	{
		ft_draw_mark(vars);
	}
	return (0);
}

static int	ft_draw_mark(t_vars *vars)
{
	t_point	*pt;

	pt = &vars->mark_pos;
	if (vars->selection)
	{
		mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, pt->x + 1, pt->y, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, pt->x - 1, pt->y, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y + 1, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y - 1, 0xFF0000);
	}
	return (0);
}
