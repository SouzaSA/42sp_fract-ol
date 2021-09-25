/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:29:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/24 21:28:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int ft_set_mark(t_vars *vars, int i, int j);

int	ft_key_hook(int keycode, t_vars *vars)
{
	if (keycode == ARROW_LEFT || keycode == ARROW_UP || keycode == ARROW_RIGHT
		|| keycode == ARROW_DOWN)
	{
		ft_shift(&vars->data, keycode);
	}
	if (keycode == 65307)
	{
		ft_clear_memory(vars);
	}
	if (keycode == 97)
	{
		ft_render_hud(vars);
	}
	ft_put_hud_to_window(vars);
	printf("Key Pressed: %d\n", keycode); //apagar
	return (0);
}

int	ft_mouse_hook(int button, int i, int j, t_vars *vars)
{
	vars->data.fractal.focus.x = i;
	vars->data.fractal.focus.y = j;
	if (button == 1)
	{
		ft_set_mark(vars, i, j);
	}
	if (button == 3)
	{
		vars->selection = 0;
	}
	if (button == 4 && i < vars->data.img.canvas.width)
	{
		ft_zoom(&vars->data, vars->data.img.canvas.width, vars->data.img.canvas.height, ZOOM_IN);
		ft_fractal_calc(&vars->data.fractal, vars->data.img.canvas.width, vars->data.img.canvas.height);
		ft_render_next_frame(&vars->data.fractal, &vars->data.img, vars->data.img.canvas.width, vars->data.img.canvas.height);
	}
	if (button == 5 && i < vars->data.img.canvas.width)
	{
		ft_zoom(&vars->data, vars->data.img.canvas.width, vars->data.img.canvas.height, ZOOM_OUT);
		ft_fractal_calc(&vars->data.fractal, vars->data.img.canvas.width, vars->data.img.canvas.height);
		ft_render_next_frame(&vars->data.fractal, &vars->data.img, vars->data.img.canvas.width, vars->data.img.canvas.height);
	}
	printf("%d, %d, %d\n", i, j, button); //apagar
	ft_put_hud_to_window(vars);
	ft_put_mark(vars);
	return (0);
}

int	ft_mouse_motion_hook(int i,int j, t_vars *vars)
{

	if (!vars->selection)
	{
		ft_redraw_frac(vars, i, j);
	}
	return (0);
}

static int ft_set_mark(t_vars *vars, int i, int j)
{
	t_fractal	*dt_frac;
	t_img		*dt_img;
	t_img		*mm_img;

	dt_frac = &vars->data.fractal;
	dt_img = &vars->data.img;
	mm_img = &vars->minimap.img;
	if (ft_strcmp(dt_frac->title, MANDELBROT) == 0 && i < dt_img->canvas.width
		&& j < dt_img->canvas.height)
	{
		vars->selection = 1;
		vars->mark_pos.x = i;
		vars->mark_pos.y = j;
		ft_redraw_frac(vars, i, j);
	}
	if (ft_strcmp(dt_frac->title, JULIA) == 0  && i > mm_img->canvas.start_w
		&& j > mm_img->canvas.start_h)
	{
		vars->selection = 1;
		vars->mark_pos.x = i;
		vars->mark_pos.y = j;
		ft_redraw_frac(vars, i, j);
	}
	return (0);
}