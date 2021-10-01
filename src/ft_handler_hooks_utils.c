/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hooks_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:34:08 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/01 14:12:56 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_redraw_minimap(t_vars *vars, int i, int j);
static int	ft_redraw_main_img(t_vars *vars, int i, int j);

/* ************************************************************************** */
/* Responsible to make the drawing of Julia set when mouse walk by Mandelbrot */
/* fractal, regardless of the Julia set is on the main screen or minimap. This*/
/* function will choose what image has to be changed.                         */
/* ************************************************************************** */
int	ft_redraw_frac(t_vars *vars, int i, int j)
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
		ft_redraw_minimap(vars, i, j);
	}
	if (ft_strcmp(dt_frac->title, JULIA) == 0 && i > mm_img->canvas.start_w \
		&& j > mm_img->canvas.start_h)
	{
		ft_redraw_main_img(vars, i, j);
	}
	return (0);
}

static int	ft_redraw_minimap(t_vars *vars, int i, int j)
{
	t_fractal	*dt_frac;
	t_fractal	*mm_frac;
	t_img		*dt_img;
	t_img		*mm_img;
	t_canvas	*mm_can;

	dt_frac = &vars->data.fractal;
	mm_frac = &vars->minimap.fractal;
	dt_img = &vars->data.img;
	mm_img = &vars->minimap.img;
	mm_can = &mm_img->canvas;
	ft_win_to_viewport(dt_frac, i, j, &mm_frac->cte);
	ft_fractal_calc(mm_frac, mm_can->width, mm_can->height);
	ft_render_next_frame(mm_frac, mm_img, mm_can->width, mm_can->height);
	mlx_put_image_to_window(vars->mlx, vars->win, mm_img->img, \
		mm_can->start_w, mm_can->start_h);
	return (0);
}

static int	ft_redraw_main_img(t_vars *vars, int i, int j)
{
	t_fractal	*dt_frac;
	t_fractal	*mm_frac;
	t_img		*dt_img;
	t_img		*mm_img;
	t_canvas	*dt_can;

	dt_frac = &vars->data.fractal;
	mm_frac = &vars->minimap.fractal;
	dt_img = &vars->data.img;
	mm_img = &vars->minimap.img;
	dt_can = &dt_img->canvas;
	ft_win_to_viewport(mm_frac, i - mm_img->canvas.start_w, \
		j - mm_img->canvas.start_h, &dt_frac->cte);
	ft_fractal_calc(dt_frac, dt_can->width, dt_can->height);
	ft_render_next_frame(dt_frac, &vars->data.img, dt_can->width, \
		dt_can->height);
	mlx_put_image_to_window(vars->mlx, vars->win, dt_img->img, \
		dt_can->start_w, dt_can->start_h);
	return (0);
}
