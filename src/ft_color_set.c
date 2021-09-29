/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:36:05 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 19:59:14 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible to call function that change the color mixer function and      */
/* after changing the function repaint the img pixels.                        */
/* ************************************************************************** */
int	ft_color_set(t_vars *vars)
{
	t_fractal	*frac;
	t_img		*img;

	frac = &vars->data.fractal;
	img = &vars->data.img;
	fr_color_selector(frac, ++frac->func_num % 5);
	ft_render_next_frame(frac, img, img->canvas.width, img->canvas.height);
	return (0);
}
