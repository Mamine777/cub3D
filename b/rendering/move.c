/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:54:30 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/01 17:55:10 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	set_player_direction(t_player *player, char locate)
{
	set_player_direction_values(player, locate);
	set_player_plane_values(player, locate);
}

void	init_player_keys(t_player *player)
{
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

bool	can_move_to_position(t_y3d *data, float y, float x)
{
	int	new_x;
	int	new_y;

	new_x = (int)(x);
	new_y = (int)(y);
	if (new_y < 0 || new_y >= data->height || new_x < 0
		|| new_x >= data->row_width[new_y] || data->map[new_y][new_x] == '1')
		return (false);
	return (true);
}

void	move_if_valid(float new_x, float new_y, t_player *player, t_y3d *data)
{
	if (can_move_to_position(data, new_y, new_x))
	{
		player->x = new_x;
		player->y = new_y;
	}
}
