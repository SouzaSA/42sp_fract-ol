/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_viewport_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:24:33 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 22:25:06 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible for convert a point on viewport to a point on window.          */
/* ************************************************************************** */
int	ft_viewport_to_win(t_fractal *fractal, double x, double y, t_point *point)
{
	point->x = (x - fractal->limit.min.x) / fractal->pixel_size.x;
	point->y = (-y - fractal->limit.min.y) / fractal->pixel_size.y;
	return (0);
}
