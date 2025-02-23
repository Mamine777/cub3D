/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:49:38 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 18:03:02 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

int	key_press(int keycode, t_player *player)
{
	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		cleanup_and_exit(player->game->y3d, player->game->xpm);
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

bool	set_x_y(t_y3d *data, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->row_width[i])
		{
			if (data->map[i][j] == 'W' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'S')
			{
				*x = j;
				*y = i;
				return (true);
			}
		}
	}
	return (false);
}

void	set_player_direction_values(t_player *player, char locate)
{
	if (locate == 'E')
	{
		player->dirX = 1;
		player->dirY = 0;
	}
	else if (locate == 'W')
	{
		player->dirX = -1;
		player->dirY = 0;
	}
	else if (locate == 'S')
	{
		player->dirX = 0;
		player->dirY = 1;
	}
	else if (locate == 'N')
	{
		player->dirX = 0;
		player->dirY = -1;
	}
}

void	set_player_plane_values(t_player *player, char locate)
{
	if (locate == 'E')
	{
		player->planeX = 0;
		player->planeY = 0.66;
	}
	else if (locate == 'W')
	{
		player->planeX = 0;
		player->planeY = -0.66;
	}
	else if (locate == 'S')
	{
		player->planeX = -0.66;
		player->planeY = 0;
	}
	else if (locate == 'N')
	{
		player->planeX = 0.66;
		player->planeY = 0;
	}
}
