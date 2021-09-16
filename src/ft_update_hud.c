/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_hud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:04:26 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/09 15:55:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int ft_hud_update(t_vars *vars, int width, int height)
{

	ft_julia_calc(&vars->data.fractal, vars->data.img.size.width, vars->data.img.size.height);
	ft_render_next_frame(&vars->data.fractal, &vars->data.img, vars->data.img.size.width, vars->data.img.size.height);
	ft_mandelbrot_calc(&vars->minimap.fractal, vars->minimap.img.size.width, vars->minimap.img.size.height);
	ft_render_next_frame(&vars->minimap.fractal, &vars->minimap.img, vars->minimap.img.size.width, vars->minimap.img.size.height);
}

static int ft_data_update(t_vars *vars, int width, int height)
{

	return (0);
}
static int ft_info_update(t_vars *vars, int width, int height)
{

	return (0);
}
static int ft_minimap_update(t_vars *vars, int width, int height)
{

	return (0);
}