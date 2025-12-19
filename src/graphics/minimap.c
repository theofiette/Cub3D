/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:51:28 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 16:04:44 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_floor(t_image *img, t_data *data)
{
	int		player_wp[2];
	float	f_offset[2];
	int		offset[2];

	player_wp[0] = data->player.pos[0];
	player_wp[1] = data->player.pos[1];
	f_offset[0] = data->player.pos[0] - (float)player_wp[0];
	f_offset[1] = data->player.pos[1] - (float)player_wp[1];
	offset[0] = f_offset[0] * TILE_SIZE;
	offset[1] = f_offset[1] * TILE_SIZE;
	draw_floor_loop(img, data, offset, player_wp);
}

static void	draw_minimap_to_img(t_image *img, t_data *data)
{
	draw_minimap_background(img, &data->mlx_data.layers[VIEWPORT], data);
	draw_floor(img, data);
	draw_minimap_cursor_arm(img, data, 1);
	draw_minimap_cursor_arm(img, data, -1);
	outline_walls(&data->mlx_data.layers[MINIMAP], data);
}

__attribute__((always_inline)) inline void	render_minimap(t_data *data)
{
	draw_minimap_to_img(&data->mlx_data.layers[MINIMAP], data);
	mlx_put_image_to_window(
		data->mlx_data.mlx, data->mlx_data.win,
		data->mlx_data.layers[MINIMAP].img, MAP_OFFSET, MAP_OFFSET);
}
