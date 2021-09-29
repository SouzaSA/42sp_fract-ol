/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:53:36 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 15:43:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	draw_line_w(t_minimap *mini, int x1, int x2, int y);
static int	draw_line_h(t_minimap *mini, int y1, int y2, int x);

/* ************************************************************************** */
/* Function that draws a square in zoom area of minimap.                      */
/* ************************************************************************** */
int	ft_draw_square(t_vars *vars)
{
	t_point	pt_min;
	t_point	pt_max;
	t_point	*frc_min;
	t_point	*frc_max;

	ft_render_next_frame(&vars->minimap.fractal, &vars->minimap.img, \
		vars->minimap.img.canvas.width, vars->minimap.img.canvas.height);
	if (!ft_strcmp(vars->data.fractal.title, BURNING_SHIP))
	{
		frc_min = &vars->data.fractal.limit.min;
		frc_max = &vars->data.fractal.limit.max;
		ft_viewport_to_win(&vars->minimap.fractal, frc_min->x, -frc_min->y, \
			&pt_min);
		ft_viewport_to_win(&vars->minimap.fractal, frc_max->x, -frc_max->y, \
			&pt_max);
		draw_line_w(&vars->minimap, pt_min.x, pt_max.x, pt_min.y);
		draw_line_h(&vars->minimap, pt_min.y, pt_max.y, pt_min.x);
		draw_line_w(&vars->minimap, pt_min.x, pt_max.x, pt_max.y);
		draw_line_h(&vars->minimap, pt_min.y, pt_max.y, pt_max.x);
	}
	return (0);
}

static int	draw_line_w(t_minimap *mini, int x1, int x2, int y)
{
	int		start;
	int		end;
	char	*dst;

	start = x1;
	end = x2;
	if (x1 > x2)
	{
		start = x2;
		end = x1;
	}
	while (start < end && y >= 0 && y < mini->img.canvas.height)
	{
		if (start >= 0 && start < mini->img.canvas.width)
		{
			dst = mini->img.addr + (y * mini->img.line_len + start * \
				(mini->img.bpp / 8));
			*(unsigned int *)dst = 0xFCFF45;
		}
		start++;
	}
	return (0);
}

static int	draw_line_h(t_minimap *mini, int y1, int y2, int x)
{
	int		start;
	int		end;
	char	*dst;

	start = y1;
	end = y2;
	if (y1 > y2)
	{
		start = y2;
		end = y1;
	}
	while (start < end && x >= 0 && x < mini->img.canvas.width)
	{
		if (start >= 0 && start < mini->img.canvas.height)
		{
			dst = mini->img.addr + (start * mini->img.line_len + x * \
				(mini->img.bpp / 8));
			*(unsigned int *)dst = 0xFCFF45;
		}
		start++;
	}
	return (0);
}
