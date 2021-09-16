/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_viewport_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:25:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/12 17:30:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_win_to_viewport(t_fractal *fractal, int i, int j, t_point *point)
{
	point->x = i * fractal->pixel_size.x + fractal->limit.min.x;
	point->y = j * fractal->pixel_size.y + fractal->limit.min.y;
	return (0);
}
