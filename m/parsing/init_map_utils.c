/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:39:34 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 15:40:29 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

int	allocate_map_row(t_y3d *data, char *line, int row)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	data->map[row] = (char *)malloc(len + 1);
	if (!data->map[row])
	{
		error("Memory allocation failed for map row!");
		if (row == 0)
			free(data->map);
		else
			couble_free(data->map, data->height);
		if (row > 0)
			free(line);
		return (1);
	}
	ft_strlcpy(data->map[row], line, len + 1);
	return (0);
}

int	process_map_line(t_y3d *data, char *line, int index)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		data->row_width[index] = line_len - 1;
	else
		data->row_width[index] = line_len;
	if (data->biggest_width < data->row_width[index])
		data->biggest_width = data->row_width[index];
	if (check_map_line(line))
	{
		error("Invalid map content");
		free(line);
		return (1);
	}
	return (0);
}
