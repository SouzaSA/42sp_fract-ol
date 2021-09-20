/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:11:02 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/17 14:06:59 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int main (int argc, char **argv)
{
	t_point point;
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