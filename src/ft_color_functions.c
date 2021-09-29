/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:12:34 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 15:00:19 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Group of functions responsible to mix color, exchanging components got by  */
/* Bernstein polynomial                                                       */
/* ************************************************************************** */
int	ft_color_mix1(int a, int b, int c)
{
	return (a << 16 | b << 8 | c);
}

int	ft_color_mix2(int a, int b, int c)
{
	return (b << 16 | a << 8 | c);
}

int	ft_color_mix3(int a, int b, int c)
{
	return (c << 16 | b << 8 | a);
}

int	ft_color_mix4(int a, int b, int c)
{
	return ((c / 2) << 16 | a << 8 | b);
}

int	ft_color_mix5(int a, int b, int c)
{
	return (b << 16 | c << 8 | a);
}
