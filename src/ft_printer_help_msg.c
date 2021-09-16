/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_help_msg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:21:18 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/15 13:23:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_help_msg(void)
{
	ft_putendl_fd("Fract-ol usage:", 1);
	ft_putendl_fd(" ./fractol <fractal set name> [constant complex number]", 1);
	ft_putendl_fd("\nFractal set names: (not case sensitive)", 1);
	ft_putendl_fd(" Maldelbrot;", 1);
	ft_putendl_fd(" Julia;", 1);
	ft_putendl_fd(" Burning-ship.", 1);
	ft_putendl_fd("\nConstant complex number (Optional)", 1);
	ft_putendl_fd(" A constant complex value used in julia set.", 1);
	ft_putendl_fd(" Examples:", 1);
	ft_putendl_fd(" +0.6 -1.0i", 1);
	ft_putendl_fd(" + 0.6 - 1.0i", 1);
	ft_putendl_fd(" \"0.6 - 1.0i\"", 1);
	ft_putendl_fd(" Real part signal is optional.", 1);
	ft_putendl_fd(" Imaginary part signal is mandatory.", 1);
	ft_putendl_fd(" The imaginary part must have 'i' char terminator.", 1);
	ft_putendl_fd("\nExamples:", 1);
	ft_putendl_fd(" ./fractol julia - 0.4 + 0.6i", 1);
	ft_putendl_fd(" ./fractol maldelbrot", 1);
	ft_putendl_fd(" ./fractol burning-ship", 1);
	ft_putendl_fd("\t\t by sde-alva", 1);
	return (0);
}
