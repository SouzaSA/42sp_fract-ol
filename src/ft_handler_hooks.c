/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:29:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/23 11:06:21 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

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

int	ft_mouse_hook(int button, int x, int y, t_vars *vars)
{
	vars->data.fractal.focus.x = x;
	vars->data.fractal.focus.y = y;
	if (button == 1)
	{
		ft_win_to_viewport(&vars->data.fractal, x, y, &vars->minimap.fractal.cte);
		ft_fractal_calc(&vars->minimap.fractal, vars->minimap.img.canvas.width, vars->minimap.img.canvas.height);
		ft_render_next_frame(&vars->minimap.fractal, &vars->minimap.img, vars->minimap.img.canvas.width, vars->minimap.img.canvas.height);
	}
	if (button == 4)
	{
		ft_zoom(&vars->data, vars->data.img.canvas.width, vars->data.img.canvas.height, ZOOM_IN);
		ft_fractal_calc(&vars->data.fractal, vars->data.img.canvas.width, vars->data.img.canvas.height);
		ft_render_next_frame(&vars->data.fractal, &vars->data.img, vars->data.img.canvas.width, vars->data.img.canvas.height);
	}
	if (button == 5)
	{
		ft_zoom(&vars->data, vars->data.img.canvas.width, vars->data.img.canvas.height, ZOOM_OUT);
		ft_fractal_calc(&vars->data.fractal, vars->data.img.canvas.width, vars->data.img.canvas.height);
		ft_render_next_frame(&vars->data.fractal, &vars->data.img, vars->data.img.canvas.width, vars->data.img.canvas.height);
	}
	printf("%d, %d, %d\n", x, y, button); //apagar
	ft_put_hud_to_window(vars);
	return (0);
}

int	ft_mouse_motion_hook(int x,int y, t_vars *vars)
{

	if (ft_strcmp(vars->data.fractal.title, MANDELBROT) == 0
		&& x < vars->data.img.canvas.width && y < vars->data.img.canvas.height)
	{
		ft_win_to_viewport(&vars->data.fractal, x, y, &vars->minimap.fractal.cte);
		ft_fractal_calc(&vars->minimap.fractal, vars->minimap.img.canvas.width, vars->minimap.img.canvas.height);
		ft_render_next_frame(&vars->minimap.fractal, &vars->minimap.img, vars->minimap.img.canvas.width, vars->minimap.img.canvas.height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->minimap.img.img, vars->minimap.img.canvas.start_w, vars->minimap.img.canvas.start_h);
	}
	if (ft_strcmp(vars->data.fractal.title, JULIA) == 0
		&& x > vars->minimap.img.canvas.start_w && y > vars->minimap.img.canvas.start_h)
	{
		ft_win_to_viewport(&vars->minimap.fractal, x - vars->minimap.img.canvas.start_w, y - vars->minimap.img.canvas.start_h, &vars->data.fractal.cte);
		ft_fractal_calc(&vars->data.fractal, vars->data.img.canvas.width, vars->data.img.canvas.height);
		ft_render_next_frame(&vars->data.fractal, &vars->data.img, vars->data.img.canvas.width, vars->data.img.canvas.height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img.img, vars->data.img.canvas.start_w, vars->data.img.canvas.start_h);
	}
	return (0);
}