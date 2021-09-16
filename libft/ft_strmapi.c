/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:32:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/04 09:55:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	if (!s)
		return (NULL);
	i = 0;
	dst = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dst)
	{
		while (s[i] != '\0')
		{
			dst[i] = f(i, (char)s[i]);
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
