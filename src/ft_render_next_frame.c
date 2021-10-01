/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_next_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:40:43 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/01 13:52:51 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static unsigned int	ft_get_color(t_fractal *frac, int val);

/* ************************************************************************** */
/* Responsible for set color of every pixel on screem based on number of      */
/* iterations obtained on fractal algorithm.                                  */
/* ************************************************************************** */
int	ft_render_next_frame(t_fractal *frac, t_img *img, int width, int height)
{
	int		i;
	int		j;
	char	*dst;
	int		idx;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			idx = i * width + j;
			dst = img->addr + (i * img->line_len + j * (img->bpp / 8));
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				*(unsigned int *)dst = 0x004f0000;
			else if (i == 1 || i == height - 2 || j == 1 || j == width - 2)
				*(unsigned int *)dst = 0x00450000;
			else
				*(unsigned int *)dst = ft_get_color(frac, frac->vals[idx]);
			j++;
		}
		i++;
	}
	return (0);
}

static unsigned int	ft_get_color(t_fractal *frac, int val)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	color;

	t = pow(log(((double)(val % 128))) / log(128.0), 2);
	color = 0x101010;
	if (t < 0.99)
	{
		r = 8 * (1 - t) * t * t * t * 255;
		g = 14 * (1 - t) * (1 - t) * t * t * 255;
		b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
		color = frac->fractal_color(r, g, b);
	}
	return (color);
}
