/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:36:03 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player_hit(t_data *data, float z_pos[2])
{
	if ((int)data->player.pos[0] == (int)z_pos[0]
		&& (int)data->player.pos[1] == (int)z_pos[1])
	{
		if (data->player.timer >= 5)
		{
			data->player.timer = 0;
			data->player.hp--;
		}
		if (!data->game_over)
			return (1);
	}
	return (0);
}

void	check_zombie_hit(t_data *data, t_zombie *zombie)
{
	if (zombie->is_shot)
	{
		zombie->hp--;
		zombie->is_hit = 1;
		zombie->timer = 0;
		data->player.has_shot = 1;
		zombie->is_shot = 0;
	}
	if (zombie->hp == 0)
		zombie->timer += data->cache[DELTA] * 5;
	if (zombie->timer > 2)
		zombie->is_hit = 0;
	if (!zombie->hp && zombie->timer > 10 && !zombie->is_dead)
	{
		zombie->is_hit = 0;
		zombie->dist = 0;
		zombie->is_dead = 1;
		data->map[zombie->map_pos[1]
			* data->width + zombie->map_pos[0]] = '0';
	}
}
