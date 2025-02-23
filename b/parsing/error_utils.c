/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:03 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/02 13:34:24 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	error(const char *str)
{
	printf("%s\n", str);
}

void	couble_free(char **path, int height)
{
	int	i;

	if (!path)
		return ;
	i = 0;
	while (i < height && path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

bool	validate_input(t_y3d *data)
{
	int	i;
	int	count;
	int	j;

	if (!data->map || !data->map[0])
		return (true);
	i = -1;
	count = 0;
	while (++i, i < data->height)
	{
		if (!*data->map[i])
			return (error("Error"), true);
		j = -1;
		while (++j, j < data->row_width[i])
		{
			if (!data->map[i][j])
				return (error("not valid line"), true);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E')
				count++;
		}
	}
	if (count != 1)
		return (error("one player is required"), true);
	return (0);
}

int	check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '.')
			return (1);
		if (s[i] == '.' && s[i + 1] == 'c' && s[i + 2] == 'u' && s[i + 3] == 'b'
			&& s[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}
