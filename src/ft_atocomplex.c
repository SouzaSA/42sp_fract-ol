/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atocomplex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:43:48 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/15 21:25:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void		ft_get_pos_idxs(char *nb, t_num_idx *num);
static void		ft_set_number(char *nb, t_num_idx *num, t_point *point);
static double	ft_parse_float(char *nb, t_num_idx *num);

void	ft_set_complex_point(char *nb, t_point *point)
{
	int			i;
	t_num_idx	num;

	i = 0;
	ft_check_invalid_complex_str(nb);
	num.start = 0;
	num.end = 0;
	num.dot = 0;
	num.i_char = 0;
	num.parts = 0;
	ft_get_pos_idxs(nb, &num);
	ft_set_number(nb, &num, point);
	if (nb[num.end] == 'i')
		nb[num.end]++;
	ft_get_pos_idxs(nb, &num);
	ft_set_number(nb, &num, point);
	if (num.parts == 2 && num.i_char == 0)
	{
		free(nb);
		ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	}
}

static void	ft_get_pos_idxs(char *nb, t_num_idx *num)
{
	int	i;

	i = num->end;
	while (nb[i] && !ft_isdigit(nb[i]) && nb[i] != 'i')
		i++;
	if (i > 0 && nb[i - 1] == '.')
		i--;
	num->start = i;
	while (nb[i] && (ft_isdigit(nb[i]) || nb[i] == '.'))
		i++;
	num->end = i;
	i = num->start;
	while (nb[i] && nb[i] != '.' && i < num->end)
		i++;
	num->dot = i;
	i = 0;
	while (nb[i] && nb[i] != 'i')
		i++;
	if (nb[i] == 'i')
		num->i_char = i;
}

static void	ft_set_number(char *nb, t_num_idx *num, t_point *point)
{
	int		i;
	double	number;

	number = ft_parse_float(nb, num);
	i = num->start - 1;
	while (i >= 0 && !ft_isdigit(nb[i]))
	{
		if (nb[i] == '-')
			number *= -1;
		i--;
	}
	if (num->end > num->start || (nb[num->end] == 'i' && point->y == 0))
	{
		if (nb[num->end] == 'i')
			point->y = number;
		else
			point->x = number;
		num->parts++;
	}
}

static double	ft_parse_float(char *nb, t_num_idx *num)
{
	int		dec;
	int		frac;
	int		frac_size;
	double	rtn;

	dec = ft_atoi(nb + num->start);
	frac = 0.0;
	rtn = dec;
	frac_size = num->end - num->dot - 1;
	if (frac_size > 0)
	{
		frac = ft_atoi(nb + num->dot + 1);
		rtn = dec + (double)frac / pow(10, frac_size);
	}
	if (nb[num->end] == 'i')
	{
		if (ft_strlen(nb) == 1
			|| ft_strchr("+- ", nb[num->end - 1]))
			rtn = 1.0;
	}
	return (rtn);
}
