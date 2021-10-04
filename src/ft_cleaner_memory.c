/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:47:01 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 19:01:45 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_clean_data(void *mlx, t_data *data);
static int	ft_clean_data_info(void *mlx, t_data_info *data);
static int	ft_clean_minimap(void *mlx, t_minimap *data);

/* ************************************************************************** */
/* Responsible to clean allocated memory destroing mlx and window, and freeing*/
/* allocated memory in arrays of factal data. (main and minimap)              */
/* ************************************************************************** */
int	ft_clear_memory(t_vars *vars)
{
	ft_clean_data(vars->mlx, &vars->data);
	ft_clean_data_info(vars->mlx, &vars->info);
	ft_clean_minimap(vars->mlx, &vars->minimap);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

static int	ft_clean_data(void *mlx, t_data *data)
{
	free(data->fractal.vals);
	data->fractal.vals = NULL;
	free(data->img.palette);
	data->img.palette = NULL;
	mlx_destroy_image(mlx, data->img.img);
	return (0);
}

static int	ft_clean_data_info(void *mlx, t_data_info *data)
{
	mlx_destroy_image(mlx, data->img.img);
	return (0);
}

static int	ft_clean_minimap(void *mlx, t_minimap *data)
{
	free(data->fractal.vals);
	data->fractal.vals = NULL;
	free(data->img.palette);
	data->img.palette = NULL;
	mlx_destroy_image(mlx, data->img.img);
	return (0);
}
