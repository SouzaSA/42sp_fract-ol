/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:22:21 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 21:15:29 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible for set selection flag and set the mark position.              */
/* ************************************************************************** */
int	ft_set_mark(t_vars *vars, int i, int j)
{
	t_fractal	*dt_frac;
	t_img		*dt_img;
	t_img		*mm_img;

	dt_frac = &vars->data.fractal;
	dt_img = &vars->data.img;
	mm_img = &vars->minimap.img;
	if (ft_strcmp(dt_frac->title, MANDELBROT) == 0 && i < dt_img->canvas.width \
		&& j < dt_img->canvas.height)
	{
		vars->selection = 1;
		vars->mark_pos.x = i;
		vars->mark_pos.y = j;
		ft_redraw_frac(vars, i, j);
	}
	if (ft_strcmp(dt_frac->title, JULIA) == 0 && i > mm_img->canvas.start_w \
		&& j > mm_img->canvas.start_h)
	{
		vars->selection = 1;
		vars->mark_pos.x = i;
		vars->mark_pos.y = j;
		ft_redraw_frac(vars, i, j);
	}
	return (0);
}
