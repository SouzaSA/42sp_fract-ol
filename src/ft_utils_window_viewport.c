/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_window_viewport.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:25:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 22:25:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible for convert a point on window to a point on viewport.          */
/* ************************************************************************** */
int	ft_win_to_viewport(t_fractal *fractal, int i, int j, t_point *point)
{
	point->x = i * fractal->pixel_size.x + fractal->limit.min.x;
	point->y = -1 * (j * fractal->pixel_size.y + fractal->limit.min.y);
	return (0);
}
