/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_translation_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:25:57 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/26 16:56:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int ft_shift_up(t_data *data, int shift_h, t_canvas *screen)
{
	int i;
	int j;
	int *vals;

	i = 0;
	vals = data->fractal.vals;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
		{
			if (i + shift_h < screen->height)
				vals[i * screen->width + j] = \
					vals[(i + shift_h) * screen->width + j];
			j++;
		}
		i++;
	}
	data->fractal.limit.min.y += shift_h * data->fractal.pixel_size.y;
	data->fractal.limit.max.y += shift_h * data->fractal.pixel_size.y;
	ft_frac_recalc_h(&data->fractal, screen->height - shift_h, screen->height, screen);
	return (0);
}

int ft_shift_down(t_data *data, int shift_h, t_canvas *screen)
{
	int i;
	int j;
	int *vals;

	i = screen->height - 1;
	vals = data->fractal.vals;
	while (i > 0)
	{
		j = 0;
		while (j < screen->width)
		{
			if (i + shift_h < screen->height)
				vals[(i + shift_h) * screen->width + j] = \
					vals[i * screen->width + j];
			j++;
		}
		i--;
	}
	data->fractal.limit.min.y -= shift_h * data->fractal.pixel_size.y;
	data->fractal.limit.max.y -= shift_h * data->fractal.pixel_size.y;
	ft_frac_recalc_h(&data->fractal, 0, shift_h + 1, screen);
	return (0);
}

int ft_shift_left(t_data *data, int shift_w, t_canvas *screen)
{
	int i;
	int j;
	int *vals;

	i = 0;
	vals = data->fractal.vals;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
		{
			if (j + shift_w < screen->width)
				vals[i * screen->width + j] = \
					vals[i * screen->width + j + shift_w];
			j++;
		}
		i++;
	}
	data->fractal.limit.min.x += shift_w * data->fractal.pixel_size.x;
	data->fractal.limit.max.x += shift_w * data->fractal.pixel_size.x;
	ft_frac_recalc_w(&data->fractal, screen->width - shift_w, screen->width, screen);
	return (0);
}

int ft_shift_right(t_data *data, int shift_w, t_canvas *screen)
{
	int i;
	int j;
	int *vals;

	i = 0;
	vals = data->fractal.vals;
	while (i < screen->height)
	{
		j = screen->width - 1;
		while (j > 0)
		{
			if (j + shift_w < screen->width)
				vals[i * screen->width + j + shift_w] = \
					vals[i * screen->width + j];
			j--;
		}
		i++;
	}
	data->fractal.limit.min.x -= shift_w * data->fractal.pixel_size.x;
	data->fractal.limit.max.x -= shift_w * data->fractal.pixel_size.x;
	ft_frac_recalc_w(&data->fractal, 0,  shift_w + 1, screen);
	return (0);
}
