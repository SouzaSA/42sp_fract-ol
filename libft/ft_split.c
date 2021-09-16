/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:16:48 by sde-alva          #+#    #+#             */
/*   Updated: 2021/08/09 19:07:16 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_slices(char const *s, char c);
static char		*ft_get_str(char const *s, char c, size_t start);
static char		**ft_free_split(char **splited);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**splited;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	splited = (char **)malloc((ft_count_slices(s, c) + 1) * sizeof(char *));
	if (splited)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c && (i == 0 || s[i - 1] == c))
			{
				splited[j] = ft_get_str(s, c, i);
				if (!splited)
					return (ft_free_split(splited));
				j++;
			}
			i++;
		}
		splited[j] = NULL;
	}
	return (splited);
}

static size_t	ft_count_slices(char const *s, char c)
{
	size_t	i;
	size_t	num_slices;

	i = 0;
	num_slices = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			num_slices++;
		i++;
	}
	return (num_slices);
}

static char	*ft_get_str(char const *s, char c, size_t start)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	if (str)
	{
		while (s[start + i] != c && s[start + i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

static char	**ft_free_split(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (NULL);
}
