/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_zoom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:37:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 20:53:42 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_zoom_apply(t_fractal *frac, int width, int height, double zoom);

/* ************************************************************************** */
/* Responsible for select the zoom type (IN or OUT) and apply this, also      */
/* update the zomm level variable.                                            */
/* ************************************************************************** */
int	ft_zoom(t_data *data, int width, int height, char direction)
{
	t_boundaries	*default_limit;
	t_boundaries	*limit;
	double			default_size;
	double			zoom_step;

	zoom_step = 0;
	default_limit = &data->fractal.std;
	limit = &data->fractal.limit;
	default_size = default_limit->max.x - default_limit->min.x;
	if (direction == ZOOM_OUT)
		zoom_step = data->zoom_factor / (1 - data->zoom_factor);
	else if (direction == ZOOM_IN)
		zoom_step = -1 * data->zoom_factor;
	ft_zoom_apply(&data->fractal, width, height, zoom_step);
	data->total_zoom = default_size / (limit->max.x - limit->min.x);
	ft_fractal_calc(&data->fractal, data->img.canvas.width, \
		data->img.canvas.height);
	ft_render_next_frame(&data->fractal, &data->img, data->img.canvas.width, \
		data->img.canvas.height);
	return (0);
}

static int	ft_zoom_apply(t_fractal *frac, int width, int height, double zoom)
{
	double	x_pixel;
	double	y_pixel;
	double	delta_x;
	double	delta_y;

	x_pixel = frac->focus.x / width;
	y_pixel = frac->focus.y / height;
	delta_x = frac->limit.max.x - frac->limit.min.x;
	delta_y = frac->limit.max.y - frac->limit.min.y;
	frac->limit.min.x -= zoom * delta_x * x_pixel;
	frac->limit.max.x += zoom * delta_x * (1 - x_pixel);
	frac->limit.min.y -= zoom * delta_y * y_pixel;
	frac->limit.max.y += zoom * delta_y * (1 - y_pixel);
	frac->pixel_size.x = (frac->limit.max.x - frac->limit.min.x) / width;
	frac->pixel_size.y = (frac->limit.max.y - frac->limit.min.y) / height;
	return (0);
}
