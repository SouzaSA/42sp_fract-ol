/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:11:02 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 21:07:26 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Main function of program, cheking parameters number and calling functions  */
/* to check factol names and complex number is valid.                         */
/* ************************************************************************** */
int	main(int argc, char **argv)
{
	t_point	point;
	char	*name;

	if (argc < 2 && argv[0])
		ft_frac_error_handler("", WRONG_PARAMETER_PASSED);
	point.x = 0;
	point.y = 0;
	ft_param_handler(argc, argv, &point, &name);
	name = argv[1];
	ft_fractol(name, 800, 500, &point);
	return (0);
}
