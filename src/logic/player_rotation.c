/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:18:42 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_data *data, t_player *player)
{
	int	mouse[2];

	mlx_mouse_get_pos(data->mlx_data.mlx, data->mlx_data.win, mouse, mouse + 1);
	if (*mouse - data->cache[MID_WIDTH])
	{
		player->pan_speed = (*mouse - data->cache[MID_WIDTH]) * MOUSE_SENSI;
		mlx_mouse_move(data->mlx_data.mlx, data->mlx_data.win,
			data->cache[MID_WIDTH], data->cache[MID_HEIGHT]);
		player->rotation = ft_fclamp_loop(
				player->rotation + player->pan_speed, 0, 360);
	}
}
