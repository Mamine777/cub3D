/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:41:03 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/02 17:09:49 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	calcul_ray(t_game *game, t_ray *draw, int x)
{
	draw->cameraX = 2 * x / (double)WIDTH - 1;
	draw->rayDirX = (game->player.dirX + game->player.planeX * draw->cameraX);
	draw->rayDirY = (game->player.dirY + game->player.planeY * draw->cameraX);
	draw->mapX = (int)game->player.x;
	draw->mapY = (int)game->player.y;
	draw->deltaDistX = fabs(1 / draw->rayDirX);
	draw->deltaDistY = fabs(1 / draw->rayDirY);
}

void	init_ray(t_game *game, t_ray *draw, int x)
{
	calcul_ray(game, draw, x);
	if (draw->rayDirX < 0)
	{
		draw->stepX = -1;
		draw->sideDistX = (game->player.x - draw->mapX) * draw->deltaDistX;
	}
	else
	{
		draw->stepX = 1;
		draw->sideDistX = (draw->mapX + 1.0 - game->player.x)
			* draw->deltaDistX;
	}
	if (draw->rayDirY < 0)
	{
		draw->stepY = -1;
		draw->sideDistY = (game->player.y - draw->mapY) * draw->deltaDistY;
	}
	else
	{
		draw->stepY = 1;
		draw->sideDistY = (draw->mapY + 1.0 - game->player.y)
			* draw->deltaDistY;
	}
}
