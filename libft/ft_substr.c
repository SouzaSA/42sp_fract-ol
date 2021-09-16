/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:53:33 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/04 11:26:42 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sub_len(size_t start, size_t s_len, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	sub = NULL;
	if (s)
	{
		s_len = ft_strlen(s);
		sub = (char *)malloc(ft_sub_len(start, s_len, len) * sizeof(char));
		if (sub)
		{
			while (i + start < s_len && i < len && s[start + i] != '\0')
			{
				sub[i] = s[start + i];
				i++;
			}
			sub[i] = '\0';
		}
	}
	return (sub);
}

static size_t	ft_sub_len(size_t start, size_t s_len, size_t len)
{
	size_t	sub_len;

	sub_len = 0;
	if (start < s_len)
	{
		sub_len = s_len - start;
		if (sub_len > len)
			sub_len = len;
	}
	sub_len++;
	return (sub_len);
}
