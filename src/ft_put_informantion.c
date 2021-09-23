/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_informantion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:13:37 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/23 11:21:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void	ft_put_txt_center(t_vars *vars, int pos_v, char *str, int color);
static void	ft_put_txt(t_vars *vars, int pos_v, char *str, int color);
static void	ft_put_val(t_vars *vars, int pos_v, char *str, int color);
static char *ft_get_zoom_level(t_vars *vars);

int	ft_put_informantion(t_vars *vars)
{
	int 	color;
	int		color_v;
	//char	*aux;

	color = 0xAFAFAF;
	color_v = 0xFFAAAA;
	ft_put_txt_center(vars, 30, "Informations", color);
	ft_put_txt(vars, 70, "Fractal: ", color);
	ft_put_val(vars, 70, vars->data.fractal.title, color_v);
	ft_put_txt(vars, 100, "Zoom level: ", color);
	ft_put_txt(vars, 130, "Complex point selected:", color);
	ft_put_txt(vars, 150, "Re:", color);
	ft_put_txt(vars, 170, "Im:", color);
	ft_put_txt(vars, 200, "Keys:", color);
	ft_put_txt(vars, 220, "Movement Keys: UP, DOWN, LEFT, RIGHT", color);
	ft_put_txt(vars, 240, "Zoom Key:      MOUSE WHEEL", color);
	ft_put_txt(vars, 280, "Minimap:", color);
	ft_put_val(vars, 280, vars->minimap.fractal.title, color_v);
	ft_get_zoom_level(vars);
	return (0);
}
static char *ft_get_zoom_level(t_vars *vars)
{
	double zoom;

	zoom = log(*vars->info.total_zoom);
	printf("%lf\n", zoom); //tirar
	return (NULL);
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


static void	ft_put_val(t_vars *vars, int pos_v, char *str, int color)
{
	int	start_pos;

	start_pos = vars->info.img.canvas.start_w + 90;
	mlx_string_put(vars->mlx, vars->win, start_pos, pos_v, color, str);
}