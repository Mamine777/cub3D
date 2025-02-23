/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:49:45 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 15:50:46 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

bool	is_valid_space(t_y3d *data, int x, int y)
{
	static int	dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	static int	dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int			i;
	int			nx;
	int			ny;

	i = -1;
	while (++i, i < 8)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx >= 0 && nx < data->height && ny >= 0 && ny < data->row_width[nx])
		{
			if (data->map[nx][ny] != '1' && data->map[nx][ny] != ' ')
				return (false);
		}
	}
	return (true);
}

bool	check_horizontal_edges(t_y3d *data, int row)
{
	int	i;

	i = -1;
	while (++i < data->row_width[row])
	{
		if (data->map[row][i] != ' ' && data->map[row][i] != '1')
			return (true);
	}
	return (false);
}

bool	check_vertical_edges(t_y3d *data)
{
	int	i;

	i = -1;
	while (++i < data->height)
	{
		if (data->row_width[i] > 0 && data->map[i][0] != ' '
			&& data->map[i][0] != '1')
			return (true);
		if (data->row_width[i] > 1 && data->map[i][data->row_width[i]
			- 1] != ' ' && data->map[i][data->row_width[i] - 1] != '1')
			return (true);
	}
	return (false);
}
