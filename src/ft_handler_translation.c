/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_translation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:25:57 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/21 11:23:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int ft_shift_up(t_data *data, int shift_h, t_canvas *screen);
static int ft_shift_down(t_data *data, int shift_h, t_canvas *screen);
static int ft_shift_left(t_data *data, int shift_w, t_canvas *screen);
static int ft_shift_right(t_data *data, int shift_w, t_canvas *screen);

int	ft_shift(t_data *data, int direction)
{
	int			shift_w;
	int			shift_h;
	t_canvas	screen;

	shift_w = data->img.canvas.width * data->shift_factor;
	shift_h = data->img.canvas.height * data->shift_factor;
	screen.width = data->img.canvas.width;
	screen.height = data->img.canvas.height;
	if (direction == ARROW_UP)
		ft_shift_up(data, shift_h, &screen);
	else if (direction == ARROW_DOWN)
		ft_shift_down(data, shift_h, &screen);
	else if (direction == ARROW_LEFT)
		ft_shift_left(data, shift_w, &screen);
	else
		ft_shift_right(data, shift_w, &screen);
	ft_render_next_frame(&data->fractal, data->img.img, screen.width, screen.height);
	return (0);
}

static int ft_shift_up(t_data *data, int shift_h, t_canvas *screen)
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
				vals[i * screen->width + j] = vals[(i + shift_h) * screen->width + j];
			j++;
		}
		i++;
	}
	data->fractal.limit.min.x += shift_h;
	data->fractal.limit.max.x += shift_h;
	ft_frac_recalc_h(&data->fractal, 0, shift_h, screen);
	return (0);
}

static int ft_shift_down(t_data *data, int shift_h, t_canvas *screen)
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
			if (i < screen->height - shift_h)
				vals[(i + shift_h) * screen->width + j] = vals[i * screen->width + j];
			j++;
		}
		i++;
	}
	data->fractal.limit.min.x -= shift_h;
	data->fractal.limit.max.x -= shift_h;
	ft_frac_recalc_h(&data->fractal, screen->height - shift_h, screen->height, screen);
	return (0);
}

static int ft_shift_left(t_data *data, int shift_w, t_canvas *screen)
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
			if (i < screen->height - shift_w)
				vals[i * screen->width + j + shift_w] = vals[i * screen->width + j];
			j++;
		}
		i++;
	}
	data->fractal.limit.min.y += shift_w;
	data->fractal.limit.max.y += shift_w;
	ft_frac_recalc_w(&data->fractal, 0,  shift_w, screen);
	return (0);
}

static int ft_shift_right(t_data *data, int shift_w, t_canvas *screen)
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
			if (i < screen->height - shift_w)
				vals[i * screen->width + j] = vals[i * screen->width + j + shift_w];
			j++;
		}
		i++;
	}
	data->fractal.limit.min.y -= shift_w;
	data->fractal.limit.max.y -= shift_w;
	ft_frac_recalc_w(&data->fractal, screen->width - shift_w, screen->width, screen);
	return (0);
}
