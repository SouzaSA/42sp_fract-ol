/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_update_translation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:13:27 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/25 14:51:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_shift_mark(t_vars *vars, int direction)
{
	int			shift_w;
	int			shift_h;
	t_data		*data;

	data = &vars->data;
	shift_w = (double)data->img.canvas.width * data->shift_factor;
	shift_h = (double)data->img.canvas.height * data->shift_factor;
	if (!ft_strcmp(vars->data.fractal.title, MANDELBROT))
	{
		if (direction == ARROW_UP)
			vars->mark_pos.y -= shift_h;
		else if (direction == ARROW_DOWN)
			vars->mark_pos.y += shift_h;
		else if (direction == ARROW_LEFT)
			vars->mark_pos.x -= shift_w;
		else
			vars->mark_pos.x += shift_w;
	}
	return (0);
}
