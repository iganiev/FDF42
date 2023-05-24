/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:29:34 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 10:54:29 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_var(t_dot *data)
{
	if (data->column >= 500)
		data->zoom = 2;
	else if (data->column > 200)
		data->zoom = 3;
	else if (data->column > 100)
		data->zoom = 5;
	else
		data->zoom = 25;
	data->img_buff.win_width = 2000;
	data->img_buff.win_length = 1300;
	data->move_x = 0;
	data->move_y = 0;
	data->move_z = 0;
	data->z_scale = 1;
	data->alpha = 35.526 * (M_PI / 180);
	data->betta = 0 * (M_PI / 180);
	data->gamma = 45 * (M_PI / 180);
}

int	main(int ac, char *av[])
{
	t_dot	*data;

	if (ac == 2 && valid_parameter(av[1], "fdf"))
	{
		if (valid_map(av[1]) == 0 || empty_map(av[1]) == 0)
			ft_printf("ERROR: Invalid Map!\n");
		else
		{
			data = malloc(sizeof(t_dot));
			read_map(av[1], data);
			init_var(data);
			use_mlx(data);
			clean_map(data);
			clean_color(data);
			free(data);
		}
	}
	else
		ft_printf("ERROR: Invalid Parameter!");
}
