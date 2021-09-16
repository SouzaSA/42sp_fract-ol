/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_palete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:52:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/15 11:57:04 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void ft_palette_init(unsigned int *pal);

int	ft_set_palette(int palette_num, unsigned int *pal)
{
	if (palette_num == 0)
		ft_palette_init(pal);

	return (0);
}

static void ft_palette_init(unsigned int *pal)
{
	pal[0] = 0x7F1637;
	pal[1] = 0x047878;
	pal[2] = 0xFFB733;
	pal[3] = 0xF57336;
	pal[4] = 0xC22121;
}