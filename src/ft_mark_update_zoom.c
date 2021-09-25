/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_update_zoom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 09:39:54 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/25 14:59:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int ft_upt_mk(t_vars *vars, double step_fac);

int	fr_update_mark_on_zoom(t_vars *vars,int direction)
{
	int		width;
	int		height;
	double	zoom_step;
	char	*frac_name;

	width = vars->data.img.canvas.width;
	height = vars->data.img.canvas.height;
	zoom_step = 0;
	frac_name = vars->data.fractal.title;
	if (direction == ZOOM_OUT)
		zoom_step = 1.0 - vars->data.zoom_factor;
	else if (direction == ZOOM_IN)
		zoom_step = 1 + vars->data.zoom_factor / (1.0 - vars->data.zoom_factor);
	if (!ft_strcmp(frac_name, MANDELBROT))
		ft_upt_mk(vars, zoom_step);
	return (0);
}

static int ft_upt_mk(t_vars *vars, double step_fac)
{
	double	x_focus;
	double	y_focus;
	double	delta_x;
	double	delta_y;

	x_focus = vars->data.fractal.focus.x;
	y_focus = vars->data.fractal.focus.y;
	delta_x = (vars->mark_pos.x - x_focus) * step_fac;
	delta_y = (vars->mark_pos.y - y_focus) * step_fac;
	vars->mark_pos.x = x_focus + delta_x;
	vars->mark_pos.y = y_focus + delta_y;
	return (0);
}