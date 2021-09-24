/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hooks_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:34:08 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/23 21:03:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_redraw_frac(t_vars *vars, int i, int j)
{
	t_fractal	*dt_frac;
	t_fractal	*mm_frac;
	t_img		*dt_img;
	t_img		*mm_img;

	dt_frac = &vars->data.fractal;
	mm_frac = &vars->minimap.fractal;
	dt_img = &vars->data.img;
	mm_img = &vars->minimap.img;
	if (ft_strcmp(dt_frac->title, MANDELBROT) == 0 && i < dt_img->canvas.width
		&& j < dt_img->canvas.height)
	{
		ft_win_to_viewport(dt_frac, i, j, &mm_frac->cte);
		ft_fractal_calc(mm_frac, mm_img->canvas.width, mm_img->canvas.height);
		ft_render_next_frame(mm_frac, mm_img, mm_img->canvas.width,
			mm_img->canvas.height);
		mlx_put_image_to_window(vars->mlx, vars->win, mm_img->img,
			mm_img->canvas.start_w, mm_img->canvas.start_h);
	}
	if (ft_strcmp(dt_frac->title, JULIA) == 0  && i > mm_img->canvas.start_w
		&& j > mm_img->canvas.start_h)
	{
		ft_win_to_viewport(mm_frac, i - mm_img->canvas.start_w,
			j - mm_img->canvas.start_h, &dt_frac->cte);
		ft_fractal_calc(dt_frac, dt_img->canvas.width, dt_img->canvas.height);
		ft_render_next_frame(dt_frac, &vars->data.img, dt_img->canvas.width,
			dt_img->canvas.height);
		mlx_put_image_to_window(vars->mlx, vars->win, dt_img->img,
			dt_img->canvas.start_w, dt_img->canvas.start_h);
	}
	return (0);
}