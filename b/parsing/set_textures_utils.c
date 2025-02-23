/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:44:29 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 15:44:40 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

bool	set_east(t_textures *texture, char *line, bool *flag)
{
	if (*flag == true)
	{
		error("testure duplication");
		return (true);
	}
	if (texture->ea)
		free(texture->east);
	texture->ea = true;
	texture->east = ft_strdup(line);
	return (false);
}

bool	set_west(t_textures *texture, char *line, bool *flag)
{
	if (*flag == true)
	{
		error("testure duplication");
		return (true);
	}
	if (texture->west)
		free(texture->west);
	texture->we = true;
	texture->west = ft_strdup(line);
	return (false);
}

bool	set_south(t_textures *texture, char *line, bool *flag)
{
	if (*flag == true)
	{
		error("testure duplication");
		return (true);
	}
	if (texture->south)
		free(texture->south);
	texture->so = true;
	texture->south = ft_strdup(line);
	return (false);
}

bool	set_north(t_textures *texture, char *line, bool *flag)
{
	if (*flag == true)
	{
		error("testure duplication");
		return (true);
	}
	if (texture->north)
		free(texture->north);
	texture->no = true;
	texture->north = ft_strdup(line);
	return (false);
}
