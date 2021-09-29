/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:29:17 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 20:01:23 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Manages what the program should do when some specific key is pressed.      */
/* ************************************************************************** */
int	ft_key_hook(int key, t_vars *vars)
{
	if (key == KEY_LEFT || key == KEY_UP || key == KEY_RIGHT || key == KEY_DOWN)
		vars->mv_function(&vars->data, key);
	if (key == KEY_ESC)
		ft_clear_memory(vars);
	if (key == KEY_R)
		ft_reset(vars);
	if (key == KEY_M)
		ft_translation_set(vars);
	if (key == KEY_C)
		ft_color_set(vars);
	ft_put_hud_to_window(vars);
	return (0);
}

/* ************************************************************************** */
/* Manages what the program should do when mouse button is pressed.           */
/* ************************************************************************** */
int	ft_mouse_hook(int button, int i, int j, t_vars *vars)
{
	int	data_width;
	int	data_height;

	data_width = vars->data.img.canvas.width;
	data_height = vars->data.img.canvas.height;
	vars->data.fractal.focus.x = i;
	vars->data.fractal.focus.y = j;
	if (button == 1)
		ft_set_mark(vars, i, j);
	if (button == 3)
		vars->selection = 0;
	if (button == 4 && i < data_width)
		ft_zoom(&vars->data, data_width, data_height, ZOOM_IN);
	if (button == 5 && i < data_width)
		ft_zoom(&vars->data, data_width, data_height, ZOOM_OUT);
	ft_put_hud_to_window(vars);
	return (0);
}

/* ************************************************************************** */
/* Manages what the program should do when mouse walks on screen.             */
/* ************************************************************************** */
int	ft_mouse_motion_hook(int i, int j, t_vars *vars)
{
	if (!vars->selection)
	{
		ft_redraw_frac(vars, i, j);
	}
	return (0);
}
