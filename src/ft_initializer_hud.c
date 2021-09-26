/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer_hud.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:28:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/25 17:45:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_data_init(t_vars *vars, char *name, t_point *cte);
static int	ft_info_init(t_vars *vars, t_point *cte);
static int	ft_minimap_init(t_vars *vars, char *name, t_point *cte);

int	ft_init_hud(t_vars *vars, char *name, t_point *cte)
{
	ft_data_init(vars, name, cte);
	ft_info_init(vars, cte);
	ft_minimap_init(vars, name, cte);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->minimap.img.img,
		vars->minimap.img.canvas.start_w, vars->minimap.img.canvas.start_h);
	if (cte->x != 0 || cte->y != 0)
	{
		vars->selection = 1;
		ft_viewport_to_win(&vars->minimap.fractal, cte->x, cte->y, &vars->mark_pos);
		vars->mark_pos.x += vars->minimap.img.canvas.start_w;
		vars->mark_pos.y += vars->minimap.img.canvas.start_h;
	}
	return (0);
}

static int	ft_data_init(t_vars *vars, char *name, t_point *cte)
{
	t_img	*img;
	t_data	*data;

	img = &vars->data.img;
	data = &vars->data;
	vars->selection = 0;
	data->zoom_factor = 0.25;
	data->shift_factor = 0.05;
	data->total_zoom = 1;
	//ft_set_palette(0, img->palette);
	img->canvas.start_w = 0;
	img->canvas.start_h = 0;
	img->canvas.width = vars->win_canvas.width * 0.7;
	img->canvas.height = vars->win_canvas.height;
	img->img = mlx_new_image(vars->mlx, img->canvas.width, img->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	ft_init_frac(&data->fractal, name, &img->canvas, cte);
	return (0);
}

static int	ft_info_init(t_vars *vars, t_point *cte)
{
	t_img		*img;
	t_canvas	*win_canvas;

	img = &vars->info.img;
	win_canvas = &vars->win_canvas;
	img->canvas.start_w = win_canvas->width * 0.7;
	img->canvas.start_h = 0;
	img->canvas.width = win_canvas->width - win_canvas->width * 0.7;
	img->canvas.height = win_canvas->height * 0.7;
	img->img = mlx_new_image(vars->mlx, img->canvas.width, img->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	vars->info.zoom = 0;
	vars->info.limits = &vars->data.fractal.limit;
	vars->info.selected.x = cte->x;
	vars->info.selected.y = cte->y;
	ft_render_info_img(vars);
	return (0);
}

static int	ft_minimap_init(t_vars *vars, char *name, t_point *cte)
{
	t_img		*img;
	t_canvas	*win_canvas;
	char		*name_lower;
	char		*minimap_name;

	name_lower = ft_strtolower(ft_strdup(name));
	img = &vars->minimap.img;
	win_canvas = &vars->win_canvas;
	img->canvas.start_w = win_canvas->width * 0.7;
	img->canvas.start_h = win_canvas->height * 0.7;
	img->canvas.width = win_canvas->width - win_canvas->width * 0.7;
	img->canvas.height = win_canvas->height - win_canvas->height * 0.7;
	if (ft_strcmp(name_lower, "mandelbrot") == 0)
		minimap_name = "julia";
	else if (ft_strcmp(name_lower, "julia") == 0)
		minimap_name = "mandelbrot";
	else
		minimap_name = name_lower;
	img->img = mlx_new_image(vars->mlx, img->canvas.width, img->canvas.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	//ft_set_palette(0, img->palette);
	ft_init_frac(&vars->minimap.fractal, minimap_name, &img->canvas, cte);
	free(name_lower);
	return (0);
}
