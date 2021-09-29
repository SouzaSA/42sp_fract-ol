/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atocomplex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:43:48 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 14:47:15 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void		ft_get_pos_idxs(char *nb, t_num_idx *num);
static void		ft_set_number(char *nb, t_num_idx *num, t_point *point);
static double	ft_parse_float(char *nb, t_num_idx *num);
static void		ft_check_signal_and_i(char *nb, t_num_idx *num);

/* ************************************************************************** */
/* Responsible to set convert the string with a complex number and put the    */
/* real part into point->x and imaginary part on point->y.                    */
/* ************************************************************************** */
int	ft_set_complex_point(char *nb, t_point *point)
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
	if (num.parts == 2)
		ft_check_signal_and_i(nb, &num);
	return (0);
}

/* ************************************************************************** */
/* Responsible to get index position of start and end of number, as well the  */
/* "." index and the "i" index in the string.                                 */
/* ************************************************************************** */
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

/* ************************************************************************** */
/* Responsible for properly set the number to the right place                 */
/* ************************************************************************** */
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

/* ************************************************************************** */
/* Responsible for parse the string to a float, this function is caled for    */
/* each part of the complex number.                                           */
/* ************************************************************************** */
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

/* ************************************************************************** */
/* Responsible to check if the complex number has a signal between two parts. */
/* This function also check if the complex number has an "i" letter and if    */
/* there is not a digit after the "i", if some of this fail, a error msg is   */
/* sent to terminal                                                           */
/* ************************************************************************** */
static void	ft_check_signal_and_i(char *nb, t_num_idx *num)
{
	int	i;
	int	signal;

	i = 0;
	signal = 0;
	while (nb[i] && !ft_isdigit(nb[i]))
		i++;
	while (nb[i] && (ft_isdigit(nb[i]) || nb[i] == '.'))
		i++;
	while (nb[i] && !ft_isdigit(nb[i]))
	{
		if (nb[i] == '+' || nb[i] == '-')
			signal++;
		i++;
	}
	if (num->i_char == 0 || signal != 1 || ft_isdigit(nb[num->i_char + 1]))
	{
		free(nb);
		ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	}
}
