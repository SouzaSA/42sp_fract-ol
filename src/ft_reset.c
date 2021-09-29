/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:15:49 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 22:21:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible for reset the main fractal to start state.                     */
/* ************************************************************************** */
int	ft_reset(t_vars *vars)
{
	int			width;
	int			height;
	t_fractal	*frac;

	width = vars->data.img.canvas.width;
	height = vars->data.img.canvas.height;
	frac = &vars->data.fractal;
	frac->limit.min.x = frac->std.min.x;
	frac->limit.max.x = frac->std.max.x;
	frac->limit.min.y = frac->std.min.y;
	frac->limit.max.y = frac->std.max.y;
	frac->pixel_size.x = (frac->limit.max.x - frac->limit.min.x) / width;
	frac->pixel_size.y = (frac->limit.max.y - frac->limit.min.y) / height;
	ft_fractal_calc(&vars->data.fractal, vars->data.img.canvas.width, \
		vars->data.img.canvas.height);
	ft_render_next_frame(&vars->data.fractal, &vars->data.img, \
		vars->data.img.canvas.width, vars->data.img.canvas.height);
	return (0);
}
