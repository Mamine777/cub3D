/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanUp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:16:42 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 15:17:11 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	clean_texture(t_textures *texture)
{
	if (!texture)
		return ;
	if (texture->east)
		free(texture->east);
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->west)
		free(texture->west);
	free(texture);
}

void	clean_y3d(t_y3d *y3d)
{
	if (!y3d)
		return ;
	couble_free(y3d->map, y3d->height);
	free(y3d);
}
