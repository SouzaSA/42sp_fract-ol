/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:21:38 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 22:03:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible render the frame, using values obtained on fractal calculation.*/
/* ************************************************************************** */
int	ft_render_hud(t_vars *vars)
{
	t_img	*dt_img;
	t_img	*mm_img;

	dt_img = &vars->data.img;
	mm_img = &vars->minimap.img;
	ft_fractal_calc(&vars->data.fractal, dt_img->canvas.width, \
		dt_img->canvas.height);
	ft_render_next_frame(&vars->data.fractal, dt_img, dt_img->canvas.width, \
		dt_img->canvas.height);
	ft_fractal_calc(&vars->minimap.fractal, mm_img->canvas.width, \
		mm_img->canvas.height);
	ft_render_next_frame(&vars->minimap.fractal, mm_img, mm_img->canvas.width, \
		mm_img->canvas.height);
	ft_put_hud_to_window(vars);
	return (0);
}
