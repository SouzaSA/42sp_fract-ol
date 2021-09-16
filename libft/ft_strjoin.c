/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:58:32 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/04 09:20:42 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	dst = NULL;
	if (s1)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
		if (dst)
		{
			ft_memcpy(dst, s1, s1_len);
			ft_memcpy(dst + s1_len, s2, s2_len);
			dst[s1_len + s2_len] = '\0';
		}
	}
	return (dst);
}
