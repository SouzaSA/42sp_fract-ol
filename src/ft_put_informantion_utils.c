/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_informantion_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:31:28 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/26 20:33:29 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_put_txt(t_vars *vars, int pos_v, int pos_h, char *str)
{
	int	start_pos;
	int color;

	color = 0xAFAFAF;
	start_pos = vars->info.img.canvas.start_w + pos_h;
	mlx_string_put(vars->mlx, vars->win, start_pos, pos_v, color, str);
	return (0);
}

int	ft_put_val(t_vars *vars, int pos_v, int pos_h, char *str)
{
	int	start_pos;
	int		color_v;

	color_v = 0xFFAAAA;
	start_pos = vars->info.img.canvas.start_w + pos_h;
	mlx_string_put(vars->mlx, vars->win, start_pos, pos_v, color_v, str);
	return (0);
}
