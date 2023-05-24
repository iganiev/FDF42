/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:56:18 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 08:41:34 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_row(char *map)
{
	char	*line;
	int		fd;
	int		row;

	fd = open(map, O_RDONLY);
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		row++;
		free(line);
	}
	free(line);
	close(fd);
	return (row);
}

int	get_column(char *map)
{
	int		column;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	column = element_count(line, ' ');
	free(line);
	close(fd);
	return (column);
}

void	fill_matrix(int *matrix, char *line, int expected_columns)
{
	char	**element;
	int		i;

	element = ft_split(line, ' ');
	i = 0;
	while (element[i] && i < expected_columns)
	{
		matrix[i] = ft_atoi(element[i]);
		free(element[i]);
		i++;
	}
	free(element);
}

void	get_map(char *map, t_dot *data)
{
	int		i;
	t_var	var;

	i = 0;
	while (i < data->row)
		data->matrix[i++] = malloc(sizeof(int) * (data->column));
	data->matrix[i] = NULL;
	i = 0;
	var.fd = open(map, O_RDONLY);
	while (data->matrix[i] != NULL)
	{
		var.line = get_next_line(var.fd);
		if (!var.line)
		{
			free(var.line);
			break ;
		}
		fill_matrix(data->matrix[i], var.line, data->column);
		free (var.line);
		i++;
	}
	close(var.fd);
}

void	read_map(char *map, t_dot *data)
{
	data->row = get_row(map);
	data->column = get_column(map);
	data->matrix = malloc(sizeof(int *) * (data->row + 1));
	data->col_matrix = malloc(sizeof(int *) * (data->row + 1));
	get_map(map, data);
	get_color(map, data);
}

// int	main(int ac, char *av[])
// {
// 	(void)ac;
// 	// printf("HELLO\n");
// 	t_dot	*data;
// 	int		i;
// 	int		j;

// 	data = malloc(sizeof(t_dot));
// 	read_map(av[1], data);
// 	printf("ROWS = %d\n", data->row);
// 	printf("COLUMN = %d\n", data->column);
// 	i = 0;
// 	while (i < data->row && data->col_matrix[i])
// 	{
// 		j = 0;
// 		while (j < data->column)
// 		{
// 			printf("%3d", data->col_matrix[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }