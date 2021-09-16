/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_parameter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:20:10 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/15 21:19:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int		ft_fractal_name_handler(int argc, char **argv, char **dst);
static size_t	ft_strncmp_ncs(char *s1, char *s2, int n);
static int		ft_buningship_checker(int argc, char **argv);

int	ft_param_handler(int argc, char **argv, t_point *point, char **dst)
{
	point->x = 0;
	point->y = 0;
	if (argc > 2 && ft_strncmp_ncs(argv[1], "julia", ft_strlen(argv[1])) == 0)
		ft_get_cte(argc, argv, point);
	ft_fractal_name_handler(argc, argv, dst);
	free(*dst);
	return (0);
}

static int	ft_fractal_name_handler(int argc, char **argv, char **dst)
{
	int	nxt_param;

	nxt_param = 0;
	if (ft_strncmp_ncs(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
	{
		*dst = ft_strdup(MANDELBROT);
	}
	else if (ft_strncmp_ncs(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		*dst = ft_strdup(JULIA);
	}
	else if (ft_strncmp_ncs(argv[1], "burning", 7) == 0)
	{
		if (ft_buningship_checker(argc, argv) == 0)
			*dst = ft_strdup(BURNING_SHIP);
		else
			ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	}
	else
	{
		ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	}
	return (nxt_param);
}

static size_t	ft_strncmp_ncs(char *s1, char *s2, int n)
{
	size_t	diff;
	char	*s1_lower;
	char	*s2_lower;

	s1_lower = ft_strtolower(ft_strdup(s1));
	s2_lower = ft_strtolower(ft_strdup(s2));
	diff = ft_strncmp(s1_lower, s2_lower, n);
	free(s1_lower);
	free(s2_lower);
	return (diff);
}

static int	ft_buningship_checker(int argc, char **argv)
{
	int	rtn;
	int	a1_len;
	int	a2_len;
	int	has_ship;
	int	has_sep;

	rtn = 1;
	a1_len = ft_strlen(argv[1]);
	has_ship = ft_strncmp_ncs(argv[1] + a1_len - 4, "ship", 4) == 0;
	has_sep = argv[1][7] == '_' || argv[1][7] == '-' || argv[1][7] == ' ';
	if (argc > 2)
		a2_len = ft_strlen(argv[2]);
	if ((a1_len == 11 && has_ship) || (a1_len == 12 && has_sep && has_ship))
		rtn = 0;
	else if (argc > 2 && a2_len == 4 && ft_strncmp_ncs(argv[2], "ship", 4) == 0)
		rtn = 0;
	else
		rtn = 1;
	return (rtn);
}
