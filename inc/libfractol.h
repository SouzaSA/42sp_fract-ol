/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 09:06:00 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 22:45:06 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFRACTOL_H
# define LIBFRACTOL_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

/* window name */
# define PROG_NAME "Fractol 42sp v.0.9"

/* key codes */
# define KEY_ESC 65307
# define KEY_R 114
# define KEY_M 109
# define KEY_C 99
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

/* fractal names */
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"
# define BURNING_SHIP "Burning Ship"

/* zoom direction */
# define ZOOM_IN 4
# define ZOOM_OUT 5

/* custom errors macros */
# define WRONG_WINDOW_SIZE 2000
# define WRONG_PARAMETER_PASSED 2001

typedef struct s_num_idx
{
	int	start;
	int	end;
	int	dot;
	int	i_char;
	int	parts;
}	t_num_idx;

typedef struct s_canvas {
	int	start_w;
	int	start_h;
	int	width;
	int	height;
}	t_canvas;

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef struct s_boundaries {
	t_point	max;
	t_point	min;
}	t_boundaries;

typedef struct s_fractal {
	int				*vals;
	int				max_iter;
	int				(*fractal_calc)(struct s_fractal *, double, double);
	int				(*fractal_color)(int, int, int);
	int				func_num;
	char			*title;
	t_point			cte;
	t_point			pixel_size;
	t_point			focus;
	t_boundaries	limit;
	t_boundaries	std;
}	t_fractal;

typedef struct s_img {
	void		*img;
	char		*addr;
	double		*palette;
	int			bpp;
	int			line_len;
	int			endian;
	t_canvas	canvas;
}	t_img;

typedef struct s_data_info {
	t_img			img;
	int				*has_selected;
	int				*mov_type;
	double			*total_zoom;
	t_point			*selected;
}	t_data_info;

typedef struct s_minimap {
	t_img		img;
	t_fractal	fractal;
}	t_minimap;

typedef struct s_data {
	t_img		img;
	double		zoom_factor;
	double		total_zoom;
	double		shift_factor;
	t_fractal	fractal;
}	t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			selection;
	int			mov_type;
	int			(*mv_function)(t_data *, int);
	t_point		mark_pos;
	t_canvas	win_canvas;
	t_data		data;
	t_data_info	info;
	t_minimap	minimap;
}	t_vars;

int	ft_set_palette(int palette_num, unsigned int *pal);

int	ft_frac_error_handler(char *msg, int errnum);

int	ft_init_frac(t_fractal *frac, char *name, t_canvas *canvas, t_point *cte);

int	ft_fractol(char *fractal_name, int width, int height, t_point *constant);

int	ft_render_next_frame(t_fractal *frac, t_img *img, int width, int height);

int	ft_key_hook(int keycode, t_vars *vars);
int	ft_mouse_hook(int button, int x, int y, t_vars	*vars);
int	ft_mouse_motion_hook(int x, int y, t_vars *vars);

int	ft_init_hud(t_vars *vars, char *name, t_point *cte);

int	ft_translation_set(t_vars *vars);
int	ft_shift_vp(t_data *data, int direction);
int	ft_shift_win(t_data *data, int direction);
int	ft_shift_up(t_data *data, int shift_h, t_canvas *screen);
int	ft_shift_down(t_data *data, int shift_h, t_canvas *screen);
int	ft_shift_left(t_data *data, int shift_h, t_canvas *screen);
int	ft_shift_right(t_data *data, int shift_h, t_canvas *screen);

int	ft_frac_recalc_h(t_fractal *frac, int start_h, int end_h, t_canvas *screen);
int	ft_frac_recalc_w(t_fractal *frac, int start_w, int end_w, t_canvas *screen);
int	ft_fractal_calc(t_fractal *fractal, int width, int height);
int	ft_mandelbrot_calc(t_fractal *fractal, double x, double y);
int	ft_burning_ship_calc(t_fractal *fractal, double x, double y);
int	ft_julia_calc(t_fractal *fractal, double x, double y);

int	ft_render_hud(t_vars *vars);
int	ft_render_info_img(t_vars *vars);

int	ft_clear_memory(t_vars *vars);

int	ft_param_handler(int argc, char **argv, t_point *point, char **dst);

int	ft_zoom(t_data *data, int width, int height, char direction);

int	ft_win_to_viewport(t_fractal *fractal, int i, int j, t_point *point);
int	ft_viewport_to_win(t_fractal *fractal, double x, double y, t_point *point);

int	ft_help_msg(void);

int	ft_get_cte(int argc, char **argv, t_point *point);

int	ft_set_complex_point(char *nb, t_point *point);
int	ft_check_invalid_complex_str(char *nb);

int	ft_put_hud_to_window(t_vars *vars);
int	ft_put_informantion(t_vars *vars);
int	ft_put_info_vals(t_vars *vars);
int	ft_put_txt(t_vars *vars, int pos_v, int pos_h, char *str);
int	ft_put_val(t_vars *vars, int pos_v, int pos_h, char *str);

int	ft_redraw_frac(t_vars *vars, int i, int j);

int	ft_set_mark(t_vars *vars, int i, int j);
int	ft_put_mark(t_vars *vars);

int	ft_color_set(t_vars *vars);
int	fr_color_selector(t_fractal *frac, int func_idx);
int	ft_color_mix1(int a, int b, int c);
int	ft_color_mix2(int a, int b, int c);
int	ft_color_mix3(int a, int b, int c);
int	ft_color_mix4(int a, int b, int c);
int	ft_color_mix5(int a, int b, int c);

int	ft_draw_square(t_vars *vars);
int	ft_reset(t_vars *vars);
#endif