/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:43:44 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 17:36:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible to up the system, starting the mlx, win, call functions to     */
/* start all struct variables, set the hooks and call the loop.               */
/* ************************************************************************** */
int	ft_fractol(char *fractal_name, int width, int height, t_point *constant)
{
	t_vars	vars;

	if (width < 800 || height < 500)
		ft_frac_error_handler("Wrong window size", WRONG_WINDOW_SIZE);
	vars.win_canvas.height = height;
	vars.win_canvas.width = width;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, PROG_NAME);
	ft_init_hud(&vars, fractal_name, constant);
	ft_render_hud(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_key_hook, &vars);
	mlx_mouse_hook(vars.win, &ft_mouse_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, &ft_clear_memory, &vars);
	mlx_hook(vars.win, 6, 1L << 6, &ft_mouse_motion_hook, &vars);
	mlx_expose_hook(vars.win, &ft_put_hud_to_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
