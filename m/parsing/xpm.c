/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:35:22 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 20:02:23 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

static bool	init_xpm_path(char *old_path, char **path)
{
	size_t	len;

	len = ft_strlen(old_path);
	if (old_path[len - 1] == '\n')
		len--;
	*path = malloc(len + 1);
	if (!*path)
		return (true);
	ft_strlcpy(*path, old_path, len + 1);
	return (false);
}

static bool	load_xpm_image(t_game *game, char *path, t_xpm *xpm)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error("Error: File not accessible"), true);
	xpm->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &xpm->width,
			&xpm->height);
	if (!xpm->img_ptr)
		return (error("failed xpm"), true);
	xpm->data = (int *)mlx_get_data_addr(xpm->img_ptr, &xpm->bbp,
			&xpm->size_line, &xpm->endian);
	if (!xpm->data)
		return (true);
	return (false);
}

static bool	copy_xpm_colors(t_game *game, t_xpm *xpm)
{
	int	x;
	int	y;

	xpm->colors = (int *)malloc(xpm->width * xpm->height * sizeof(int));
	if (!xpm->colors)
		return (mlx_destroy_image(game->mlx, xpm->img_ptr), true);
	y = -1;
	while (++y < xpm->height)
	{
		x = -1;
		while (++x < xpm->width)
			xpm->colors[y * xpm->width + x] = xpm->data[y * xpm->width + x];
	}
	return (false);
}

bool	set_xpm(t_game *game, char *old_path, t_xpm *xpm, int i)
{
	char	*path;

	if (init_xpm_path(old_path, &path))
		return (true);
	if (load_xpm_image(game, path, &xpm[i]))
		return (free(path), true);
	if (copy_xpm_colors(game, &xpm[i]))
		return (free(path), true);
	mlx_destroy_image(game->mlx, xpm[i].img_ptr);
	free(path);
	return (false);
}

bool	init_xpm(t_textures *texture, t_game *game, t_xpm *xpm)
{
	(void)xpm;
	(void)texture;
	if (set_xpm(game, texture->north, xpm, 0) || set_xpm(game, texture->south,
			xpm, 1) || set_xpm(game, texture->west, xpm, 2) || set_xpm(game,
			texture->east, xpm, 3))
		return (true);
	return (false);
}
