/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:29:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/23 21:07:11 by sde-alva         ###   ########.fr       */
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
	int put_pixel;

	put_pixel = 0;
	vars->data.fractal.focus.x = x;
	vars->data.fractal.focus.y = y;
	if (button == 1)
	{
		put_pixel = 1;
		vars->selection = 1;
		ft_redraw_frac(vars, x, y);
	}
	if (button == 3)
	{
		vars->selection = 0;
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
	if (put_pixel)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, x+1, y, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, x-1, y, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, x, y+1, 0xFF0000);
		mlx_pixel_put(vars->mlx, vars->win, x, y-1, 0xFF0000);

	}
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