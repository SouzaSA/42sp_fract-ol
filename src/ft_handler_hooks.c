/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:29:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/21 11:11:27 by sde-alva         ###   ########.fr       */
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img.img, 0, 0);
	printf("Key Pressed: %d\n", keycode); //apagar
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_vars	*vars)
{
	vars->data.fractal.focus.x = x;
	vars->data.fractal.focus.y = y;
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img.img, 0, 0);
	return (0);
}