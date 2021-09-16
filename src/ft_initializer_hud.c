/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer_hud.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:28:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/15 21:12:51 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_data_init(t_vars *vars, char *name);
static int	ft_info_init(t_vars *vars);
static int	ft_minimap_init(t_vars *vars, char *name);

int	ft_hud_init(t_vars *vars, char *frac_name, int width, int height)
{
	if (width <= 200 || height <= 120)
		ft_frac_error_handler("Wrong window size", WRONG_WINDOW_SIZE);
	ft_data_init(vars, frac_name);
	ft_info_init(vars);
	ft_minimap_init(vars, frac_name);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->minimap.img.img,
		vars->minimap.img.canvas.start_w, vars->minimap.img.canvas.start_h);
	return (0);
}

static int	ft_data_init(t_vars *vars, char *name)
{
	t_img	*img;
	t_data	*data;

	img = &vars->data.img;
	data = &vars->data;
	data->zoom_factor = 0.25;
	data->shift_factor = 0.05;
	//ft_set_palette(0, img->palette);
	img->canvas.start_w = 0;
	img->canvas.start_h = 0;
	img->canvas.width = vars->win_canvas.width * 0.7;
	img->canvas.height = vars->win_canvas.height;
	img->title = ft_strdup(name);
	img->img = mlx_new_image(vars->mlx, img->canvas.width, img->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	ft_fractol_init(&data->fractal, name, img->canvas.width, img->canvas.height);
	return (0);
}

static int	ft_info_init(t_vars *vars)
{
	t_img	*img;

	img = &vars->info.img;
	img->canvas.start_w = vars->win_canvas.width * 0.7;
	img->canvas.start_h = 0;
	img->canvas.width = vars->win_canvas.width - vars->win_canvas.width * 0.7;
	img->canvas.height = vars->win_canvas.height * 0.7;
	img->title = ft_strdup("informations");
	img->img = mlx_new_image(vars->mlx, img->canvas.width, img->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	vars->info.zoom = 0;
	vars->info.limits = &vars->data.fractal.limit;
	ft_render_info_img(vars);
	return (0);
}

static int	ft_minimap_init(t_vars *vars, char *name)
{
	t_img		*img;
	t_minimap	*mmap;
	char		*name_lower;

	name_lower = ft_strtolower(ft_strdup(name));
	img = &vars->minimap.img;
	mmap = &vars->minimap;
	img->canvas.start_w = vars->win_canvas.width * 0.7;
	img->canvas.start_h = vars->win_canvas.height * 0.7;
	img->canvas.width = vars->win_canvas.width - vars->win_canvas.width * 0.7;
	img->canvas.height = vars->win_canvas.height - vars->win_canvas.height * 0.7;
	if (ft_strcmp(name_lower, "mandelbrot") == 0)
		img->title = ft_strdup("julia");
	else if (ft_strcmp(name_lower, "julia") == 0)
		img->title = ft_strdup("mandelbrot");
	else
		img->title = ft_strdup(name);
	img->img = mlx_new_image(vars->mlx, img->canvas.width, img->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	//ft_set_palette(0, img->palette);
	ft_fractol_init(&mmap->fractal, img->title, img->canvas.width, img->canvas.height);
	free(name_lower);
	return (0);
}
