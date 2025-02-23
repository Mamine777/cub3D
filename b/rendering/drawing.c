/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:15:23 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/02 14:57:00 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	wall_hit(t_game *game, t_ray *draw)
{
	if (draw->sideDistX < draw->sideDistY)
	{
		draw->sideDistX += draw->deltaDistX;
		draw->mapX += draw->stepX;
		draw->side = 0;
	}
	else
	{
		draw->sideDistY += draw->deltaDistY;
		draw->mapY += draw->stepY;
		draw->side = 1;
	}
	if (game->y3d->map[draw->mapY][draw->mapX] == '1')
		draw->hit = 1;
}

void	wall_dist(t_game *game, t_ray *draw, int x)
{
	init_ray(game, draw, x);
	draw->hit = 0;
	while (!draw->hit)
	{
		wall_hit(game, draw);
	}
	if (draw->side == 0)
		draw->perpWallDist = (draw->sideDistX - draw->deltaDistX);
	else
		draw->perpWallDist = (draw->sideDistY - draw->deltaDistY);
	if (draw->perpWallDist <= 0)
		draw->perpWallDist = 0.01;
	draw->lineHeight = (int)(HEIGHT / draw->perpWallDist);
}

void	wall_size(t_game *game, t_ray *draw)
{
	draw->drawStart = -draw->lineHeight / 2 + (HEIGHT) / 2;
	if (draw->drawStart < 0)
		draw->drawStart = 0;
	draw->drawEnd = draw->lineHeight / 2 + (HEIGHT) / 2;
	if (draw->drawEnd >= (HEIGHT))
		draw->drawEnd = (HEIGHT) - 1;
	if (draw->side == 0)
		draw->wallX = game->player.y + draw->perpWallDist * draw->rayDirY;
	else
		draw->wallX = game->player.x + draw->perpWallDist * draw->rayDirX;
	draw->wallX -= floor((draw->wallX));
	draw->tex_x = (int)(draw->wallX * (double)64);
	if (draw->side == 0 && draw->rayDirX > 0)
		draw->tex_x = 64 - draw->tex_x - 1;
	if (draw->side == 1 && draw->rayDirY < 0)
		draw->tex_x = 64 - draw->tex_x - 1;
	draw->step = 1.0 * 64 / draw->lineHeight;
	draw->texPos = (draw->drawStart - HEIGHT / 2 + draw->lineHeight / 2)
		* draw->step;
}

void	draw_game(t_game *game, t_ray *ray, int x)
{
	int		y;
	int		color;
	int		texy;
	t_xpm	*wall;

	wall = wall_side(game, ray);
	(void)texy;
	y = -1;
	while (++y < ray->drawStart)
		put_pixel(x, y, game->y3d->texture->ceiling_color, game);
	y--;
	while (y++ <= ray->drawEnd)
	{
		texy = (int)ray->texPos & (64 - 1);
		ray->texPos += ray->step;
		color = get_color(game, ray, wall);
		put_pixel(x, y, color, game);
	}
	y--;
	while (y++ < HEIGHT)
		put_pixel(x, y, game->y3d->texture->floor_color, game);
}

int	draw_loop(t_extra *extra)
{
	int		x;
	t_y3d	*data;
	t_game	*game;
	t_ray	ray;

	game = extra->game;
	data = game->y3d;
	(void)data;
	clear_screen(game);
	x = 0;
	while (x < WIDTH)
	{
		wall_dist(game, &ray, x);
		wall_size(game, &ray);
		draw_game(game, &ray, x);
		x++;
	}
	move_player(&game->player, game->y3d);
	draw_map(extra->game);
	draw_player(&game->player, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
