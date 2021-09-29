/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_translation_set.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:29:25 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/28 20:32:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

/* ************************************************************************** */
/* Responsible by set the movement type (viewport or window), changing the    */
/* function pointer to respecive movement type. */
/* ************************************************************************** */
int	ft_translation_set(t_vars *vars)
{
	vars->mov_type = !vars->mov_type;
	vars->mv_function = &ft_shift_vp;
	if (!vars->mov_type)
		vars->mv_function = &ft_shift_win;
	return (0);
}
