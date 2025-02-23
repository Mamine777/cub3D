/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:26:03 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/02 14:55:45 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	draw_player(t_player *player, t_game *game)
{
	int	px;
	int	py;
	int	size;

	px = player->x * 10;
	py = player->y * 10;
	size = 5;
	draw_square(px - size / 2, py - size / 2, size, game);
}

void	draw_square(int x, int y, int size, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(x + j, y + i, 255, game);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;
	int	scale;

	scale = 20;
	y = -1;
	while (++y < game->y3d->height)
	{
		x = -1;
		while (++x < game->y3d->row_width[y])
		{
			if (game->y3d->map[y][x] == '1')
				draw_square(x * scale, y * scale, scale, game);
		}
	}
}
