/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:18:23 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/22 11:07:05 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	n_elems_in_char_array(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

int	valid_parameter(char *file, char *extention)
{
	char	*file_ext;

	file_ext = ft_strrchr(file, '.');
	if (file_ext == NULL)
		return (0);
	return (ft_strcmp(file_ext, extention));
}

int	valid_map(char *map_file)
{
	t_var	var;

	var.fd = open(map_file, O_RDONLY);
	if (var.fd < 0)
		return (0);
	var.n_prev_line_elems = -1;
	while (1)
	{
		var.line_from_map = get_next_line(var.fd);
		if (var.line_from_map == NULL)
			break ;
		var.splitted_line = ft_split(var.line_from_map, ' ');
		var.current_elems = n_elems_in_char_array(var.splitted_line);
		if (var.n_prev_line_elems == -1)
		{
			var.n_prev_line_elems = var.current_elems;
			free(var.line_from_map);
			continue ;
		}
		if (var.n_prev_line_elems != var.current_elems)
			return (0);
		var.n_prev_line_elems = var.current_elems;
		free(var.line_from_map);
	}
	return (close(var.fd), 1);
}

int	empty_map(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line || *line == '\n')
	{
		free(line);
		close(fd);
		return (0);
	}
	free(line);
	close(fd);
	return (1);
}
