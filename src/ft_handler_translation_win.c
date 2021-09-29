/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_translation_win.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:25:57 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 20:49:42 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible for window movement.                                           */
/* ************************************************************************** */
int	ft_shift_win(t_data *data, int direction)
{
	int			shift_w;
	int			shift_h;
	t_canvas	scr;

	shift_w = (double)data->img.canvas.width * data->shift_factor;
	shift_h = (double)data->img.canvas.height * data->shift_factor;
	scr.width = data->img.canvas.width;
	scr.height = data->img.canvas.height;
	if (direction == KEY_DOWN)
		ft_shift_up(data, shift_h, &scr);
	else if (direction == KEY_UP)
		ft_shift_down(data, shift_h, &scr);
	else if (direction == KEY_RIGHT)
		ft_shift_left(data, shift_w, &scr);
	else
		ft_shift_right(data, shift_w, &scr);
	ft_render_next_frame(&data->fractal, &data->img, scr.width, scr.height);
	return (0);
}
