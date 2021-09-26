/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_informantion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:13:37 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/26 13:52:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void	ft_put_txt_center(t_vars *vars, int pos_v, char *str, int color);
static void	ft_put_txt(t_vars *vars, int pos_v, char *str, int color);

int	ft_put_informantion(t_vars *vars)
{
	int 	color;

	color = 0xAFAFAF;
	ft_put_txt_center(vars, 30, "Informations", color);
	ft_put_txt(vars, 70, "Fractal: ", color);
	ft_put_txt(vars, 100, "Zoom level: ", color);
	ft_put_txt(vars, 130, "Complex point selected:", color);
	ft_put_txt(vars, 150, "Re:", color);
	ft_put_txt(vars, 170, "Im:", color);
	ft_put_txt(vars, 200, "Keys:", color);
	ft_put_txt(vars, 220, "Movement Type:", color);
	ft_put_txt(vars, 240, "Movement Keys: UP, DOWN, LEFT, RIGHT", color);
	ft_put_txt(vars, 260, "Zoom Key:      MOUSE WHEEL", color);
	ft_put_txt(vars, 300, "Minimap:", color);
	ft_put_info_vals(vars);
	return (0);
}

static void	ft_put_txt_center(t_vars *vars, int pos_v, char *str, int color)
{
	int mid_info;
	int	start_pos;

	mid_info = vars->info.img.canvas.start_w + vars->info.img.canvas.width / 2;
	start_pos = mid_info - (ft_strlen(str) * 5) / 2;
	mlx_string_put(vars->mlx, vars->win, start_pos, pos_v, color, str);
}

static void	ft_put_txt(t_vars *vars, int pos_v, char *str, int color)
{
	int	start_pos;

	start_pos = vars->info.img.canvas.start_w + 10;
	mlx_string_put(vars->mlx, vars->win, start_pos, pos_v, color, str);
}
