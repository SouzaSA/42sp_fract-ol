/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:07:54 by sde-alva          #+#    #+#             */
/*   Updated: 2021/07/26 12:19:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_of_digits(int n);

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = number_of_digits(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		str[len] = '\0';
		if (n == 0)
			str[0] = '0';
		if (n < 0)
		{
			str[0] = '-';
			str[--len] = -1 * (n % 10) + '0';
			n /= -10;
		}
		while (n > 0)
		{
			str[--len] = n % 10 + '0';
			n /= 10;
		}
	}
	return (str);
}

static int	number_of_digits(int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
