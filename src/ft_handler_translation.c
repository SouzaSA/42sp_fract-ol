/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_translation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:25:57 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/20 11:32:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int ft_shift_up(t_data *data, int shift_h, t_canvas *screen);
static int ft_shift_down(t_data *data, int shift_h, t_canvas *screen);
static int ft_shift_left(t_data *data, int shift_w, t_canvas *screen);
static int ft_shift_right(t_data *data, int shift_w, t_canvas *screen);

int	ft_shift(t_data *data, char direction)
{
	int			shift_w;
	int			shift_h;
	t_canvas	screen;

	shift_w = data->img.canvas.width * data->shift_factor;
	shift_h = data->img.canvas.height * data->shift_factor;
	screen.width = data->img.canvas.width;
	screen.height = data->img.canvas.height;
	if (direction == SHIFT_UP)
		ft_shift_up(data, shift_h, screen);
	else if (direction == SHIFT_DOWN)
		ft_shift_dow(data, shift_h, screen);
	else if (direction == SHIFT_LEFT)
		ft_shift_left(data, shift_w, screen);
	else
		ft_shift_right(data, shift_w, screen);
	return (0);
}

static int ft_shift_up(t_data *data, int shift_h, t_canvas *screen)
{
	int i;
	int j;
	int vals;

	i = 0;
	vals = data->fractal.vals;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i + shift_h < height)
				vals[i * width + j] = vals[(i + shift_h) * width + j];
			j++;
		}
		i++;
	}
	data->fractal.limits.min.x += shift_h;
	data->fractal.limits.max.x += shift_h;
	ft_fractal_recalc_h(&data->data.fractal, 0, shift_h, screen);
	return (0);
}

static int ft_shift_down(t_data *data, int shift_h, t_canvas *screen)
{
	int i;
	int j;
	int vals;

	i = 0;
	vals = data->fractal.vals;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i < height - shift_h)
				vals[(i + shift_h) * width + j] = vals[i * width + j];
			j++;
		}
		i++;
	}
	data->fractal.limits.min.x -= shift_h;
	data->fractal.limits.max.x -= shift_h;
	ft_fractal_recalc_h(&data->data.fractal, height - shift_h, height, screen);
	return (0);
}

static int ft_shift_left(t_data *data, int shift_w, t_canvas *screen)
{
	int i;
	int j;
	int vals;

	i = 0;
	vals = data->fractal.vals;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i < height - shift_w)
				vals[(i * width + j + shift_w] = vals[i * width + j];
			j++;
		}
		i++;
	}
	data->fractal.limits.min.y += shift_w;
	data->fractal.limits.max.y += shift_w;
	ft_fractal_recalc_w(&data->data.fractal, 0,  shift_w, screen);
	return (0);
}

static int ft_shift_right(t_data *data, int shift_w, t_canvas *screen)
{
	int i;
	int j;
	int vals;

	i = 0;
	vals = data->fractal.vals;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i < height - shift_w)
				vals[(i * width + j] = vals[i * width + j + shift_w];
			j++;
		}
		i++;
	}
	data->fractal.limits.min.y -= shift_w;
	data->fractal.limits.max.y -= shift_w;
	ft_fractal_recalc_w(&data->data.fractal, width - shift_w, width, screen);
	return (0);
}
