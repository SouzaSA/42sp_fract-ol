/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_opt_parameter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:22:45 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/17 14:43:27 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static char		*ft_praram_concat(int argc, char **argv, int arg_idx);

int	ft_get_cte(int argc, char **argv, t_point *point)
{
	char	*params;

	params = ft_praram_concat(argc, argv, 2);
	ft_set_complex_point(params, point);
	free(params);
	return (0);
}

static char	*ft_praram_concat(int argc, char **argv, int arg_idx)
{
	int		i;
	char	*tmp;
	char	*concated_params;

	i = 0;
	concated_params = ft_strjoin(argv[arg_idx], "");
	while (i < argc - (arg_idx + 1))
	{
		tmp = concated_params;
		concated_params = ft_strjoin(tmp, " ");
		free (tmp);
		tmp = concated_params;
		concated_params = ft_strjoin(tmp, argv[arg_idx + i + 1]);
		free (tmp);
		i++;
	}
	tmp = concated_params;
	concated_params = ft_strtrim(concated_params, " \t\n\r\f\v");
	free (tmp);
	tmp = NULL;
	return (concated_params);
}
