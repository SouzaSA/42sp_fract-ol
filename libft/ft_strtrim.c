/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:09:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/04 11:58:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_first_valid(char const *s1, char const *set);
static int	ft_get_last_valid(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	trimmed = NULL;
	if (s1 && set)
	{
		start = ft_get_first_valid(s1, set);
		end = ft_get_last_valid(s1, set);
		if (start > end)
			end = start;
		trimmed = ft_substr(s1, start, (end - start + 1));
	}
	return (trimmed);
}

static int	ft_get_first_valid(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_strrchr(set, s1[i]) && s1[i] != '\0')
		i++;
	return (i);
}

static int	ft_get_last_valid(char const *s1, char const *set)
{
	int	i;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && ft_strrchr(set, s1[i]))
		i--;
	return (i);
}
