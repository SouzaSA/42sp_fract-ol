/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_informantion_vals.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:43:28 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 21:59:10 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible for put variables on info area on the right position.          */
/* ************************************************************************** */
static char	*ft_get_zoom_level(t_vars *vars);
static char	*ft_lftoa_p(double num, int p);
static int	ft_put_num(t_vars *vars, int pos_v, int pos_h);

int	ft_put_info_vals(t_vars *vars)
{
	char	*aux;

	ft_put_val(vars, 60, 70, vars->data.fractal.title);
	aux = ft_get_zoom_level(vars);
	ft_put_val(vars, 90, 90, aux);
	free(aux);
	ft_put_num(vars, 190, 60);
	ft_put_val(vars, 340, 70, vars->minimap.fractal.title);
	if (vars->mov_type)
	{
		ft_put_val(vars, 250, 100, "Viewport");
		ft_put_txt(vars, 250, 160, "Window");
	}
	else
	{
		ft_put_txt(vars, 250, 100, "Viewport");
		ft_put_val(vars, 250, 160, "Window");
	}
	return (0);
}

static char	*ft_get_zoom_level(t_vars *vars)
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
	return (num_str);
}

static char	*ft_lftoa_p(double num, int p)
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

static int	ft_put_num(t_vars *vars, int pos_v, int pos_h)
{
	char	*re_str;
	char	*im_str;
	int		color_v;

	color_v = 0xFFAAAA;
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
	ft_put_val(vars, pos_v, pos_h, re_str);
	ft_put_val(vars, pos_v + 20, pos_h, im_str);
	free(re_str);
	free(im_str);
	return (0);
}
