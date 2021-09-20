/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:43:44 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/17 19:44:38 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_fractol(char *fractal_name, int width, int height, t_point *constant)
{
	t_vars	vars;

	vars.win_canvas.height = height;
	vars.win_canvas.width = width;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, PROG_NAME);
	ft_init_hud(&vars, fractal_name, &vars.win_canvas, constant);
	mlx_hook(vars.win, 2, 1L << 0, ft_key_hook, &vars);
	mlx_mouse_hook(vars.win, &ft_mouse_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, &ft_clear_memory, &vars);
	mlx_expose_hook(vars.win, &ft_put_hud_to_window, &vars);
	//mlx_loop_hook(vars.mlx, ft_render_hud, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
