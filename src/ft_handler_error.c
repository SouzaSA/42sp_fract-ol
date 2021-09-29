/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:36:40 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 18:01:28 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_print_msg(char *msg);

/* ************************************************************************** */
/* Responsible for error handling, sending the error or help msg to terminal. */
/* ************************************************************************** */
int	ft_frac_error_handler(char *msg, int errnum)
{
	if (errnum == WRONG_WINDOW_SIZE)
	{
		ft_print_msg(msg);
		ft_print_msg("Width must be bigger than 800");
		ft_print_msg("Height must be bigger than 500");
	}
	else if (errnum == WRONG_PARAMETER_PASSED)
	{
		ft_help_msg();
	}
	else
	{
		errno = errnum;
		perror(msg);
	}
	exit(-1);
}

static int	ft_print_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (0);
}
