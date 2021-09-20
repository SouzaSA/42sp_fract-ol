/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:40:43 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/10 10:50:47 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static unsigned int	ft_get_collor(double val);

int	ft_render_next_frame(t_fractal *frac, t_img *img, int width, int height)
{
	int		i;
	int		j;
	char	*dst;
	int		delta_iter;

	i = 0;
	delta_iter = frac->max_val_reached;// - frac->min_val_reached;
	if (delta_iter <= 0)
		delta_iter = 1;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			dst = img->addr + (i * img->line_len + j * (img->bpp / 8));
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				*(unsigned int *)dst = 0x004f0000;
			else if (i == 1 || i == height - 2 || j == 1 || j == width - 2)//mudar onde gera essa jaca de borda
				*(unsigned int *)dst = 0x00450000;
			else
				*(unsigned int *)dst = ft_get_collor(frac->vals[i * width + j]/((delta_iter)/4.0)); //;(frac->max_iter/4));
			j++;
		}
		i++;
	}
	return (0);
}

static unsigned int	ft_get_collor(double val)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	color;
	t = 0;

	t = val / 4.0;
	color = 0x101010;
	if (t < 0.99)
	{
		r = 8 * (1 - t) * t * t * t * 255;
		g = 15 * (1 - t) * (1 - t) * t * t * 255;
		b = 8 * (1 - t ) * (1 - t ) * (1 - t ) * t * 255;
		color = r << 16 | g << 8 | b;
	}
	return (color);
}

// unsigned int ft_delta_abs(unsigned int a, unsigned int b)
// {
// 	unsigned rtn;

// 	rtn = a - b;
// 	if (b > a)
// 		rtn = b - a;
// 	return (rtn);
// }

// static unsigned int	ft_get_collor(double val)
// {
// 	int				u;
// 	unsigned int	r;
// 	unsigned int	g;
// 	unsigned int	b;
// 	unsigned int	pal[5];

// 	pal[0] = 0x7F1637;
// 	pal[1] = 0x047878;
// 	pal[2] = 0xFFB733;
// 	pal[3] = 0xF57336;
// 	pal[4] = 0xC22121;
// 	u = (int)val;
// 	r = (pal[u] >> 16) + (val - u) * ft_delta_abs(pal[u] >> 16, pal[u+1] >> 16);
// 	g = (pal[u] >> 8) + (val - u) * ft_delta_abs(pal[u] >> 8, pal[u+1] >> 8);
// 	b = pal[u] + (val - u) * ft_delta_abs(pal[u], pal[u+1]);


// 	return (r << 16 | g << 8 | b);
// }
