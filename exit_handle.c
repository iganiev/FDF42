/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:21:49 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/17 17:03:04 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_map(t_dot *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->matrix[i])
	{
		j = 0;
		while (data->matrix[i][j])
		{
			free(&data->matrix[i][j]);
			j++;
		}
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
}

void	clean_color(t_dot *data)
{
	int	i;

	i = 0;
	while (data->col_matrix[i])
	{
		free(data->col_matrix[i]);
		i++;
	}
	free(data->col_matrix);
}

int	esc_win(int key, t_dot *data)
{
	if (key == 53)
	{
		clean_map(data);
		clean_color(data);
		mlx_destroy_image(data->mlx_ptr, data->img_buff.img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	return (0);
}

int	close_win(t_dot *data)
{
	clean_map(data);
	clean_color(data);
	mlx_destroy_image(data->mlx_ptr, data->img_buff.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(1);
	return (0);
}
