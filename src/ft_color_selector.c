/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:18:00 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 15:35:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible to exchange function pointer to function to mix colors.        */
/* ************************************************************************** */
int	fr_color_selector(t_fractal *frac, int func_idx)
{
	int	(*function[5])(int, int, int);

	function[0] = &ft_color_mix1;
	function[1] = &ft_color_mix2;
	function[2] = &ft_color_mix3;
	function[3] = &ft_color_mix4;
	function[4] = &ft_color_mix5;
	frac->fractal_color = function[func_idx];
	return (0);
}
