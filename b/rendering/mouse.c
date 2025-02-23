/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:01:07 by mokariou          #+#    #+#             */
/*   Updated: 2025/02/02 17:12:45 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../y3d.h"

void	decide(int *x, int *ax, int *ls_mousex)
{
	*ax = 0;
	if (*ls_mousex == -1)
	{
		*ls_mousex = *x;
		return ;
	}
	if (*x == *ls_mousex)
		ax = 0;
	else if (*x < *ls_mousex)
		*ax = 1;
	else
		*ax = -1;
	*ls_mousex = *x;
}

int	mouse(int x, int y, t_game *game)
{
	static int	last_mousex = -1;
	int			deltax;
	double		rot_speed;
	double		old_dirx;
	double		old_planex;

	(void) y;
	decide(&x, &deltax, &last_mousex);
	rot_speed = 0.02 * deltax;
	old_dirx = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(-rot_speed)
		- game->player.dirY * sin(-rot_speed);
	game->player.dirY = old_dirx * sin(-rot_speed)
		+ game->player.dirY * cos(-rot_speed);
	old_planex = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(-rot_speed)
		- game->player.planeY * sin(-rot_speed);
	game->player.planeY = old_planex * sin(-rot_speed)
		+ game->player.planeY * cos(-rot_speed);
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	last_mousex = WIDTH / 2;
	return (0);
}
