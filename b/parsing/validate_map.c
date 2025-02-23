/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:19:36 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 17:30:38 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

bool	check_angles(t_y3d *data)
{
	if (check_horizontal_edges(data, 0))
		return (true);
	if (check_horizontal_edges(data, data->height - 1))
		return (true);
	if (check_vertical_edges(data))
		return (true);
	return (false);
}

char	**copy(t_y3d *y3d)
{
	int		i;
	char	**copied;

	copied = malloc(sizeof(char *) * (y3d->height + 1));
	if (!copied)
		return (NULL);
	i = -1;
	while (++i < y3d->height)
	{
		copied[i] = ft_strdup(y3d->map[i]);
		if (!copied[i])
		{
			couble_free(copied, i);
			return (NULL);
		}
	}
	copied[i] = NULL;
	return (copied);
}

bool	flood_fill_backtrack(t_y3d *data, int x, int y, char **visited)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->row_width[x])
		return (true);
	if (data->map[x][y] == '1' || visited[x][y] == '1')
		return (false);
	visited[x][y] = '1';
	return (flood_fill_backtrack(data, x + 1, y, visited)
		|| flood_fill_backtrack(data, x - 1, y, visited)
		|| flood_fill_backtrack(data, x, y + 1, visited)
		|| flood_fill_backtrack(data, x, y - 1, visited));
}

bool	validate_map_spaces(t_y3d *data, char **visited)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->row_width[i])
		{
			if ((data->map[i][j] == ' ' && !is_valid_space(data, i, j))
				|| flood_fill_backtrack(data, i, j, visited))
				return (error("not the right structure for the map!"),
					couble_free(visited, data->height), true);
		}
	}
	return (false);
}

bool	check_map_spaces(t_y3d *data)
{
	char	**visited;

	if (!data->map || !data->map[0])
		return (true);
	visited = copy(data);
	if (!visited)
		return (true);
	if (check_angles(data))
		return (error("not the right structure for the map!"),
			couble_free(visited, data->height), true);
	if (validate_map_spaces(data, visited))
		return (true);
	couble_free(visited, data->height);
	return (false);
}
