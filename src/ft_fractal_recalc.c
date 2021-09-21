/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_recalc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:08:05 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/21 10:45:30 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int ft_frac_recalc_h(t_fractal *frac, int start_h, int end_h, t_canvas *screen)
{
	t_point	p;
	int		i;
	int		j;
	int		idx;

	i = 0;
	while (i < screen->width)
	{
		j = start_h;
		while (j < end_h)
		{
			idx = j * screen->width + i;
			ft_win_to_viewport(frac, i, j, &p);
			frac->vals[idx] = frac->fractal_calc(frac, p.x, p.y);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_frac_recalc_w(t_fractal *frac, int start_w, int end_w, t_canvas *screen)
{
	t_point	p;
	int		i;
	int		j;
	int		idx;

	i = start_w;
	while (i < end_w)
	{
		j = 0;
		while (j < screen->height)
		{
			idx = j * screen->width + i;
			ft_win_to_viewport(frac, i, j, &p);
			frac->vals[idx] = frac->fractal_calc(frac, p.x, p.y);
			j++;
		}
		i++;
	}
	return (0);
}