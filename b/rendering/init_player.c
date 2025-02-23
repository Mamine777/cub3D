/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:40:23 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 17:59:57 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	init_player(t_player *player, t_y3d *data)
{
	char	locate;
	int		x;
	int		y;

	if (set_x_y(data, &x, &y))
	{
		player->x = (double)x + 0.5;
		player->y = (double)y + 0.5;
		locate = data->map[y][x];
		set_player_direction(player, locate);
	}
	init_player_keys(player);
	player->game = data->game;
	player->xpm = data->game->xpm;
}

static void	rotate_player(t_player *player, double angle_speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = player->dirX;
	player->dirX = player->dirX * cos(angle_speed) - player->dirY
		* sin(angle_speed);
	player->dirY = olddirx * sin(angle_speed) + player->dirY * cos(angle_speed);
	oldplanex = player->planeX;
	player->planeX = player->planeX * cos(angle_speed) - player->planeY
		* sin(angle_speed);
	player->planeY = oldplanex * sin(angle_speed) + player->planeY
		* cos(angle_speed);
}

static void	move_forward_backward(t_player *player, t_y3d *data, double speed)
{
	if (player->key_up)
		move_if_valid(player->x + player->dirX * speed, player->y + player->dirY
			* speed, player, data);
	if (player->key_down)
		move_if_valid(player->x - player->dirX * speed, player->y - player->dirY
			* speed, player, data);
}

static void	move_left_right(t_player *player, t_y3d *data, double speed)
{
	if (player->key_left)
		move_if_valid(player->x - player->planeX * speed, player->y
			- player->planeY * speed, player, data);
	if (player->key_right)
		move_if_valid(player->x + player->planeX * speed, player->y
			+ player->planeY * speed, player, data);
}

void	move_player(t_player *player, t_y3d *data)
{
	double	speed;
	double	angle_speed;

	speed = 0.111;
	angle_speed = 0.1;
	if (player->left_rotate)
		rotate_player(player, -angle_speed);
	if (player->right_rotate)
		rotate_player(player, angle_speed);
	move_forward_backward(player, data, speed);
	move_left_right(player, data, speed);
}
