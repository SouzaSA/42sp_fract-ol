/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:48:00 by sde-alva          #+#    #+#             */
/*   Updated: 2021/07/30 00:02:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (dest || src)
	{
		if (dest < src)
		{
			ft_memcpy(dest, src, n);
		}
		else
		{
			while (i < n)
			{
				((char *)dest)[n - i - 1] = ((char *)src)[n - i - 1];
				i++;
			}
		}
	}
	return (dest);
}
