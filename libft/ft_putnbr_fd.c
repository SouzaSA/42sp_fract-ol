/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:57:12 by sde-alva          #+#    #+#             */
/*   Updated: 2021/07/26 21:25:31 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	aux;

	if (n >= 0 && n < 10)
	{
		aux = n % 10 + '0';
		write(fd, &aux, 1);
		return ;
	}
	if (n < 0)
	{
		aux = -1 * (n % 10) + '0';
		write(fd, "-", 1);
		n /= -10;
	}
	else
	{
		aux = n % 10 + '0';
		n /= 10;
	}
	if (n > 0)
		ft_putnbr_fd(n, fd);
	write(fd, &aux, 1);
}
