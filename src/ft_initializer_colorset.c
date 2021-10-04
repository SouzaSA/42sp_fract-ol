/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer_colorset.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:38:53 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 19:01:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static unsigned int	ft_set_color(t_fractal *frac, int val);

/* ************************************************************************** */
/* Responsible to initialize the color array to be user in fractal images.    */
/* ************************************************************************** */
int	ft_init_color(t_fractal *frac, t_img *img)
{
	int				i;
	unsigned int	*palette;

	i = 0;
	palette = (unsigned int *)malloc(frac->max_iter * sizeof(unsigned int));
	while (i < frac->max_iter)
	{
		palette[i] = ft_set_color(frac, i);
		i++;
	}
	img->palette = palette;
	return (0);
}

static unsigned int	ft_set_color(t_fractal *frac, int val)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	color;

	t = pow(log(val) / log(frac->max_iter), 3);
	color = 0x101010;
	if (t < 0.99)
	{
		r = 7 * (1 - t) * t * t * t * 255;
		g = 12 * (1 - t) * (1 - t) * t * t * 255;
		b = 7 * (1 - t) * (1 - t) * (1 - t) * t * 255;
		color = r << 16 | g << 8 | b;
	}
	return (color);
}
