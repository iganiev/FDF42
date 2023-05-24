/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:33:00 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/17 19:44:53 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_col_matrix(int *matrix, char *line, int expected_columns)
{
	char	**element;
	char	**color;
	int		i;

	element = ft_split(line, ' ');
	i = 0;
	while (element[i] && i < expected_columns)
	{
		color = ft_split(element[i], ',');
		if (color[1])
			matrix[i] = ft_atoi_base(color[1] + 2, 16);
		else
			matrix[i] = 0;
		if (color[1])
			free (color[1]);
		free(color[0]);
		free (color);
		free (element[i]);
		i++;
	}
	free(element);
}

void	get_color(char *map, t_dot *data)
{
	int		i;
	t_var	var;

	i = 0;
	while (i < data->row)
		data->col_matrix[i++] = malloc(sizeof(int) * (data->column));
	data->col_matrix[i] = NULL;
	i = 0;
	var.fd = open(map, O_RDONLY);
	while (data->col_matrix[i] != NULL)
	{
		var.line = get_next_line(var.fd);
		if (!var.line)
		{
			free(var.line);
			break ;
		}
		fill_col_matrix(data->col_matrix[i], var.line, data->column);
		free (var.line);
		i++;
	}
	close(var.fd);
}
