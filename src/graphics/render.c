/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:58:26 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:05:36 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_view(t_data *data)
{
	static t_dda	var = {0};
	float			player_dir[2];
	float			perp[2];

	var.line = 0;
	init_dda(&var, player_dir, perp, data);
	floor_dda(data, player_dir, perp);
	wall_dda(data, &var, player_dir, perp);
	render_zombie_loop(data, &var);
	if (!data->game_over)
	{
		draw_crosshair(data);
		if (data->binary_input & (1 << SHOT))
			draw_gunshot(data);
		draw_gun(data, (int *)data->textures.gun.addr,
			data->textures.gun.h, data->textures.gun.w);
	}
	mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.win,
		data->mlx_data.layers[VIEWPORT].img, 0, 0);
}
