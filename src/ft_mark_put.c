/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:42:51 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 22:39:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_draw_mark(t_vars *vars);

/* ************************************************************************** */
/* Responsible for put mark on window, on the right place.                    */
/* ************************************************************************** */
int	ft_put_mark(t_vars *vars)
{
	t_fractal	*dt_frac;
	t_fractal	*mm_frac;
	int			is_valid_area;

	dt_frac = &vars->data.fractal;
	mm_frac = &vars->minimap.fractal;
	is_valid_area = vars->mark_pos.x < vars->data.img.canvas.width;
	if (vars->selection)
	{
		if (ft_strcmp(dt_frac->title, MANDELBROT) == 0 && is_valid_area)
		{
			ft_viewport_to_win(dt_frac, mm_frac->cte.x, mm_frac->cte.y, \
				&vars->mark_pos);
			ft_draw_mark(vars);
		}
		if (ft_strcmp(dt_frac->title, JULIA) == 0)
		{
			ft_viewport_to_win(mm_frac, dt_frac->cte.x, dt_frac->cte.y, \
				&vars->mark_pos);
			vars->mark_pos.x += vars->minimap.img.canvas.start_w;
			vars->mark_pos.y += vars->minimap.img.canvas.start_h;
			ft_draw_mark(vars);
		}
	}
	return (0);
}

static int	ft_draw_mark(t_vars *vars)
{
	t_point	*pt;

	pt = &vars->mark_pos;
	mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x + 1, pt->y, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x - 1, pt->y, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y + 1, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y - 1, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x + 2, pt->y, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x - 2, pt->y, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y + 2, 0xFF0000);
	mlx_pixel_put(vars->mlx, vars->win, pt->x, pt->y - 2, 0xFF0000);
	return (0);
}
