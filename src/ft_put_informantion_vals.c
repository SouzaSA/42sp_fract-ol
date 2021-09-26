/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_informantion_vals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:43:28 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/26 17:38:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void	ft_put_val(t_vars *vars, int pos_v, char *str, int color);
static char *ft_get_zoom_level(t_vars *vars);
static char *ft_lftoa_p(double num, int p);
static int ft_put_num(t_vars *vars, int color);

int	ft_put_info_vals(t_vars *vars)
{
	int		start_pos;
	int		color_v;
	char	*aux;

	start_pos = vars->info.img.canvas.start_w + 110;
	color_v = 0xFFAAAA;
	ft_put_val(vars, 70, vars->data.fractal.title, color_v);
	aux = ft_get_zoom_level(vars);
	ft_put_val(vars, 100, aux, color_v);
	free(aux);
	ft_put_num(vars, color_v);
	ft_put_val(vars, 320, vars->minimap.fractal.title, color_v);
	if (vars->mov_type)
	{
		mlx_string_put(vars->mlx, vars->win, start_pos, 220, color_v, "Viewport");
		mlx_string_put(vars->mlx, vars->win, start_pos + 60, 220, 0xAFAFAF, "Window");
	}
	else
	{
		mlx_string_put(vars->mlx, vars->win, start_pos, 220, 0xAFAFAF, "Viewport");
		mlx_string_put(vars->mlx, vars->win, start_pos + 60, 220, color_v, "Window");
	}
	return (0);
}

static void	ft_put_val(t_vars *vars, int pos_v, char *str, int color)
{
	int	start_pos;

	start_pos = vars->info.img.canvas.start_w + 90;
	mlx_string_put(vars->mlx, vars->win, start_pos, pos_v, color, str);
}

static char *ft_get_zoom_level(t_vars *vars)
{
	double	zoom;
	char	*tmp;
	char	*num_str;

	if (*vars->info.total_zoom < 1000 && *vars->info.total_zoom >= 0.9)
	{
		zoom = *vars->info.total_zoom;
		num_str = ft_lftoa_p(zoom, 4);
	}
	else
	{
		zoom = log10(*vars->info.total_zoom);
		tmp = ft_lftoa_p(zoom, 4);
		num_str = ft_strjoin("1E", tmp);
		free(tmp);
	}
	printf("%lf\n", zoom); //tirar
	return (num_str);
}

static char *ft_lftoa_p(double num, int p)
{
	int		dec;
	int		frac;
	char	*tmp;
	char	*tmp2;
	char	*num_str;

	dec = (int)num;
	frac = (int)((num - dec) * pow(10, p));
	num_str = ft_itoa(abs(dec));
	tmp = num_str;
	num_str = ft_strjoin(tmp, ".");
	free(tmp);
	tmp = ft_itoa(abs(frac));
	tmp2 = num_str;
	num_str = ft_strjoin(num_str, tmp);
	free(tmp);
	free(tmp2);
	if (num < 0)
	{
		tmp = num_str;
		num_str = ft_strjoin("-", tmp);
		free(tmp);
	}
	return (num_str);
}

static int ft_put_num(t_vars *vars, int color)
{
	char	*re_str;
	char	*im_str;

	if (*vars->info.has_selected)
	{
		re_str = ft_lftoa_p(vars->info.selected->x, 3);
		im_str = ft_lftoa_p(vars->info.selected->y, 3);
	}
	else
	{
		re_str = ft_strdup("none");
		im_str = ft_strdup("none");
	}
	ft_put_val(vars, 150, re_str, color);
	ft_put_val(vars, 170, im_str, color);
	free(re_str);
	free(im_str);
	return (0);
}