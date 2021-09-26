/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hud_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:21:38 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/25 20:29:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_put_hud_to_window(t_vars *vars)
{
	t_img	*dt_img;
	t_img	*mm_img;
	t_img	*nf_img;

	dt_img = &vars->data.img;
	mm_img = &vars->minimap.img;
	nf_img = &vars->info.img;
	mlx_put_image_to_window(vars->mlx, vars->win, dt_img->img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, mm_img->img,
			mm_img->canvas.start_w, mm_img->canvas.start_h);
	mlx_put_image_to_window(vars->mlx, vars->win, nf_img->img,
		nf_img->canvas.start_w, nf_img->canvas.start_h);
	ft_put_informantion(vars);
	ft_put_mark(vars);
	return (0);
}
