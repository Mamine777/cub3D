/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:20:58 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 15:46:26 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	init_bool(t_textures *texture)
{
	texture->no = false;
	texture->so = false;
	texture->we = false;
	texture->ea = false;
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->ceiling_color = -1;
	texture->floor_color = -1;
}

int	validate_textures(t_textures *texture)
{
	if (!texture->no || !texture->so || !texture->we || !texture->ea)
	{
		error("Missing required textures (NO, SO, WE, EA)");
		return (1);
	}
	return (0);
}

static int	validate_texture_format(char **path)
{
	if (!path || !path[0] || !path[1] || path[2])
	{
		couble_free(path, len(path));
		return (error("Invalid texture format"), 1);
	}
	return (0);
}

static int	process_texture_direction(t_textures *texture, char **path)
{
	if (!ft_strncmp(path[0], "NO", 3))
	{
		if (set_north(texture, path[1], &texture->no))
			return (1);
	}
	else if (!ft_strncmp(path[0], "SO", 3))
	{
		if (set_south(texture, path[1], &texture->so))
			return (1);
	}
	else if (!ft_strncmp(path[0], "WE", 3))
	{
		if (set_west(texture, path[1], &texture->we))
			return (1);
	}
	else if (!ft_strncmp(path[0], "EA", 3))
	{
		if (set_east(texture, path[1], &texture->ea))
			return (1);
	}
	return (0);
}

int	set_texture(int fd, t_textures *texture)
{
	char	*line;
	char	**path;

	line = get_next_line(fd);
	if (!line)
		return (error("gnl failed"), 1);
	init_bool(texture);
	while (line)
	{
		path = ft_split(line, ' ');
		free(line);
		if (!ft_strncmp(path[0], "NO", 3) || !ft_strncmp(path[0], "SO", 3)
			|| !ft_strncmp(path[0], "WE", 3) || !ft_strncmp(path[0], "EA", 3))
		{
			if (validate_texture_format(path))
				return (1);
			if (process_texture_direction(texture, path))
				return (1);
		}
		couble_free(path, len(path));
		line = get_next_line(fd);
	}
	return (validate_textures(texture), 0);
}
