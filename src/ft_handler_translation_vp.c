/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_translation_vp.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:25:57 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/26 16:58:25 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_shift_vp(t_data *data, int direction)
{
	int			shift_w;
	int			shift_h;
	t_canvas	scr;

	shift_w = (double)data->img.canvas.width * data->shift_factor;
	shift_h = (double)data->img.canvas.height * data->shift_factor;
	scr.width = data->img.canvas.width;
	scr.height = data->img.canvas.height;
	if (direction == ARROW_UP)
		ft_shift_up(data, shift_h, &scr);
	else if (direction == ARROW_DOWN)
		ft_shift_down(data, shift_h, &scr);
	else if (direction == ARROW_LEFT)
		ft_shift_left(data, shift_w, &scr);
	else
		ft_shift_right(data, shift_w, &scr);
	ft_render_next_frame(&data->fractal, &data->img, scr.width, scr.height);
	return (0);
}
