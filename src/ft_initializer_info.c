/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:34:48 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/21 23:42:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_fill_info_img(t_img *img, int width, int height);

int	ft_render_info_img(t_vars *vars)
{
	int		i;
	int		j;
	t_img	*img;

	img = &vars->info.img;
	i = img->canvas.start_w;
	j = img->canvas.start_h;
	vars->info.total_zoom = &vars->data.total_zoom;
	vars->info.limits = &vars->data.fractal.limit;
	ft_fill_info_img(img, img->canvas.width, img->canvas.height);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, i, j);
	return (0);
}

static int	ft_fill_info_img(t_img *img, int width, int height)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			dst = img->addr + (i * img->line_len + j * (img->bpp / 8));
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1) //mudar onde gera essa jaca de borda
				*(unsigned int *)dst = 0x004f0000;
			else if (i == 1 || i == height - 2 || j == 1 || j == width - 2)
				*(unsigned int *)dst = 0x00450000;
			else
				*(unsigned int *)dst = 0x001e1e1e;
			j++;
		}
		i++;
	}
	return (0);
}
