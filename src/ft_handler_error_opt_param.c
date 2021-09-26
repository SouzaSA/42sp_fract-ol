/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_error_opt_param.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:30:46 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/26 11:29:28 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_check_valid_chars(char *nb);
static int	ft_check_signal_amount(char *nb);
static int	ft_check_signal_before_num(char *nb, int idx);
static int	ft_check_dots_on_num(char *nb, int idx);

int	ft_check_invalid_complex_str(char *nb)
{
	int	i;
	int	error_flag;

	i = 0;
	error_flag = 0;
	if (!ft_check_valid_chars(nb))
		error_flag = 1;
	if (!ft_check_signal_amount(nb))
		error_flag = 1;
	if (error_flag)
	{
		free(nb);
		ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	}
	i = ft_check_signal_before_num(nb, i);
	i = ft_check_dots_on_num(nb, i);
	i = ft_check_signal_before_num(nb, i);
	i = ft_check_dots_on_num(nb, i);
	return (0);
}

static int	ft_check_valid_chars(char *nb)
{
	int		i;
	int		is_valid;
	char	*valid_chars;

	i = 0;
	is_valid = 1;
	valid_chars = "0123456789+-.i \t\v\r\n\f";
	while (nb[i] != '\0')
	{
		if (!ft_strchr(valid_chars, nb[i]))
			is_valid = 0;
		i++;
	}
	return (is_valid);
}

static int	ft_check_signal_amount(char *nb)
{
	int	i;
	int	signal_count;
	int	dot_count;
	int	i_char_count;
	int	is_valid;

	i = 0;
	signal_count = 0;
	dot_count = 0;
	i_char_count = 0;
	is_valid = 1;
	while (nb[i] != '\0')
	{
		if (nb[i] == '+' || nb[i] == '-')
			signal_count++;
		if (nb[i] == '.')
			dot_count++;
		if (nb[i] == 'i')
			i_char_count++;
		i++;
	}
	if (signal_count > 2 || dot_count > 2 || i_char_count > 1)
		is_valid = 0;
	return (is_valid);
}

static int	ft_check_signal_before_num(char *nb, int idx)
{
	int	i;
	int	signal_count;

	i = idx;
	signal_count = 0;
	while (nb[i] && !ft_isdigit(nb[i]) && nb[i] != '.')
	{
		if (nb[i] == '+' || nb[i] == '-')
			signal_count++;
		i++;
	}
	while (nb[i] && ft_isdigit(nb[i]) && nb[i] != '.')
		i++;
	if (signal_count > 1)
	{
		free(nb);
		ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	}
	return (i);
}

static int	ft_check_dots_on_num(char *nb, int idx)
{
	int	i;
	int	dot_count;

	i = idx;
	dot_count = 0;
	while (nb[i] && (ft_isdigit(nb[i]) || nb[i] == '.'))
	{
		if (nb[i] == '.')
			dot_count++;
		i++;
	}
	if (dot_count > 1)
	{
		free(nb);
		ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	}
	return (i);
}
