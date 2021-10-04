/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_next_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:40:43 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 19:01:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static unsigned int	ft_get_color(t_fractal *frac, t_img *img, int val);

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
				*(unsigned int *)dst = ft_get_color(frac, img, frac->vals[idx]);
			j++;
		}
		i++;
	}
	return (0);
}

static unsigned int	ft_get_color(t_fractal *frac, t_img *img, int val)
{
	unsigned int	rawcolor;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	color;

	rawcolor = img->palette[val - 1];
	a = (rawcolor & 0x00FF0000u) >> 16;
	b = (rawcolor & 0x0000FF00u) >> 8;
	c = (rawcolor & 0x000000FFu);
	color = frac->fractal_color(a, b, c);
	return (color);
}
