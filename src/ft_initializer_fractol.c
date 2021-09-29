/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer_fractol.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:08:19 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 20:55:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void	ft_set_limits_frac_function(t_fractal *frac, char *name);
static void	ft_set_julia_viewport_limits(t_fractal *fractal);
static void	ft_set_mandelbrot_viewport_limits(t_fractal *fractal);
static void	ft_set_burning_viewport_limits(t_fractal *fractal);

/* ************************************************************************** */
/* Responsible for initialize fractal structures variables.                   */
/* ************************************************************************** */
int	ft_init_frac(t_fractal *frac, char *name, t_canvas *canvas, t_point *cte)
{
	int		i;
	int		width;
	int		height;
	char	*name_lower;

	i = 0;
	width = canvas->width;
	height = canvas->height;
	name_lower = ft_strtolower(ft_strdup(name));
	frac->vals = malloc(height * width * sizeof(int));
	if (!frac->vals)
		ft_frac_error_handler("Fail to malloc memory to fractal", errno);
	frac->max_iter = 256;
	ft_set_limits_frac_function(frac, name_lower);
	frac->cte.x = cte->x;
	frac->cte.y = cte->y;
	frac->pixel_size.x = (frac->limit.max.x - frac->limit.min.x) / width;
	frac->pixel_size.y = (frac->limit.max.y - frac->limit.min.y) / height;
	fr_color_selector(frac, 0);
	free(name_lower);
	return (0);
}

static void	ft_set_limits_frac_function(t_fractal *frac, char *name)
{
	if (ft_strcmp(name, "julia") == 0)
	{
		ft_set_julia_viewport_limits(frac);
		frac->fractal_calc = &ft_julia_calc;
	}
	else if (ft_strcmp(name, "mandelbrot") == 0)
	{
		ft_set_mandelbrot_viewport_limits(frac);
		frac->fractal_calc = &ft_mandelbrot_calc;
	}
	else
	{
		ft_set_burning_viewport_limits(frac);
		frac->fractal_calc = &ft_burning_ship_calc;
	}
}

static void	ft_set_julia_viewport_limits(t_fractal *fractal)
{
	fractal->title = JULIA;
	fractal->limit.min.x = -2.0;
	fractal->limit.max.x = 2.0;
	fractal->limit.min.y = -2.0;
	fractal->limit.max.y = 2.0;
	fractal->std.min.x = -2.0;
	fractal->std.max.x = 2.0;
	fractal->std.min.y = -2.0;
	fractal->std.max.y = 2.0;
}

static void	ft_set_mandelbrot_viewport_limits(t_fractal *fractal)
{
	fractal->title = MANDELBROT;
	fractal->limit.min.x = -2.5;
	fractal->limit.max.x = 1.0;
	fractal->limit.min.y = -1.5;
	fractal->limit.max.y = 1.5;
	fractal->std.min.x = -2.5;
	fractal->std.max.x = 1.0;
	fractal->std.min.y = -1.5;
	fractal->std.max.y = 1.5;
}

static void	ft_set_burning_viewport_limits(t_fractal *fractal)
{
	fractal->title = BURNING_SHIP;
	fractal->limit.min.x = -3.0;
	fractal->limit.max.x = 2.0;
	fractal->limit.min.y = -2.0;
	fractal->limit.max.y = 1.0;
	fractal->std.min.x = -3.0;
	fractal->std.max.x = 2.0;
	fractal->std.min.y = -2.0;
	fractal->std.max.y = 1.0;
}
