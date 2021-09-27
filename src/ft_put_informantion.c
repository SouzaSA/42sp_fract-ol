/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_informantion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:13:37 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/26 21:09:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void	ft_put_txt_center(t_vars *vars, int pos_v, char *str);

int	ft_put_informantion(t_vars *vars)
{
	ft_put_txt_center(vars, 30, "Informations");
	ft_put_txt(vars, 70, 10,  "Fractal: ");
	ft_put_txt(vars, 100, 10, "Zoom level: ");
	ft_put_txt(vars, 130, 10, "Select Point:");
	ft_put_val(vars, 130, 110, "Left Mouse Button");
	ft_put_txt(vars, 150, 10, "Unselect Point: ");
	ft_put_val(vars, 150, 110, "Right Mouse Button");
	ft_put_txt(vars, 170, 10, "Complex point selected:");
	ft_put_txt(vars, 190, 10, "   Re:");
	ft_put_txt(vars, 210, 10, "   Im:");
	ft_put_txt(vars, 230, 10, "Change Movement Type:");
	ft_put_val(vars, 230, 150, "M");
	ft_put_txt(vars, 250, 10, "Movement Type:");
	ft_put_txt(vars, 270, 10, "Movement Keys:");
	ft_put_val(vars, 270, 110, "UP, DOWN, LEFT, RIGHT");
	ft_put_txt(vars, 290, 10, "Zoom Key:");
	ft_put_val(vars, 290, 70, "MOUSE WHEEL");
	ft_put_txt(vars, 310, 10, "Change Color:");
	ft_put_val(vars, 310, 100, "C");
	ft_put_txt(vars, 340, 10, "Minimap:");
	ft_put_info_vals(vars);
	return (0);
}

static void	ft_put_txt_center(t_vars *vars, int pos_v, char *str)
{
	int mid_info;
	int	start_pos;
	int color;

	color = 0xAFAFAF;
	mid_info = vars->info.img.canvas.start_w + vars->info.img.canvas.width / 2;
	start_pos = mid_info - (ft_strlen(str) * 5) / 2;
	mlx_string_put(vars->mlx, vars->win, start_pos, pos_v, color, str);
}
