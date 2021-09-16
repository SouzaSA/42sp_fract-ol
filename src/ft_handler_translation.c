/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:25:57 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/06 19:01:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_shift(t_data *data, int width, int height, char direction)
{
	double	shift_factor;

	shift_factor = 0.05;
	if (direction == SHIFT_UP)
		ft_shift_up(data->fractol.vals, width, height, shift_factor);
	else if (direction == SHIFT_DOWN)
		ft_shift_dow(data, width, height, shift_factor);
	else if (direction == SHIFT_LEFT)
		ft_shift_left(data, width, height, shift_factor);
	else
		ft_shift_right(data, width, height, shift_factor);
	return (0);
}

static int ft_shift_up(int **vals, int height, double shift_factor)
{
	int i;
	int j;
	int	shift_val;

	shift_val = height * shift_factor;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i + shift_val < height)
				vals[i][j] = vals[i + shift_val][j];
			j++;
		}
		i++;
	}

}