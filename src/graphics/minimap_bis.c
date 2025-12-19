/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:15:52 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

__attribute__((always_inline)) static inline void	draw_map_tile_to_img(
	t_image *img, int off[2], int gap[2], t_data *data)
{
	int		i;
	float	start[2];
	float	end[2];

	i = 0;
	start[0] = data->cache[MAP_W] / 2 + gap[0] * TILE_SIZE - off[0];
	start[1] = data->cache[MAP_H] / 2 + gap[1] * TILE_SIZE - off[1];
	end[0] = fmin(start[0] + TILE_SIZE, data->cache[MAP_W]);
	start[0] = fmax(start[0], 0);
	if (start[1] < 0)
		i = -start[1];
	start[1] = fmax(start[1], 0);
	end[1] = start[1];
	while (i++ < TILE_SIZE)
	{
		if (end[0] < 0 || end[1] < 0 || \
			start[0] >= data->cache[MAP_W] || start[1] >= data->cache[MAP_H])
			return ;
		end[1] = fmin(end[1], data->cache[MAP_H]);
		draw_map_line_to_img(img, start, end);
		start[1]++;
		end[1]++;
	}
}

__attribute__((always_inline)) static inline void	draw_map_door_hor_to_img(
	t_image *img, int off[2], int gap[2], t_data *data)
{
	int		i;
	float	start[2];
	float	end[2];

	i = 0;
	start[0] = data->cache[MAP_W] / 2 + gap[0] * TILE_SIZE - off[0];
	start[1] = data->cache[MAP_H] / 2 + gap[1] * TILE_SIZE - off[1];
	end[0] = fmin(start[0] + TILE_SIZE, data->cache[MAP_W]);
	start[0] = fmax(start[0], 0);
	if (start[1] < 0)
		i = -start[1];
	start[1] = fmax(start[1], 0);
	end[1] = start[1];
	while (i++ < TILE_SIZE)
	{
		if (end[0] < 0 || end[1] < 0 || \
			start[0] >= data->cache[MAP_W] || start[1] >= data->cache[MAP_H])
			return ;
		end[1] = fmin(end[1], data->cache[MAP_H]);
		if (i < (TILE_SIZE / 2) - (TILE_SIZE / 8)
			|| i > (TILE_SIZE / 2) + TILE_SIZE / 8)
			draw_map_line_to_img(img, start, end);
		start[1]++;
		end[1]++;
	}
}

__attribute__((always_inline)) static inline void	draw_map_door_ver_to_img(
	t_image *img, int off[2], int gap[2], t_data *data)
{
	int		i;
	float	start[2];
	float	end[2];

	i = 0;
	start[0] = data->cache[MAP_W] / 2 + gap[0] * TILE_SIZE - off[0];
	start[1] = data->cache[MAP_H] / 2 + gap[1] * TILE_SIZE - off[1];
	end[0] = fmin(start[0] + TILE_SIZE, data->cache[MAP_W]);
	start[0] = fmax(start[0], 0);
	if (start[1] < 0)
		i = -start[1];
	start[1] = fmax(start[1], 0);
	end[1] = start[1];
	while (i++ < TILE_SIZE)
	{
		if (end[0] < 0 || end[1] < 0 || \
			start[0] >= data->cache[MAP_W] || start[1] >= data->cache[MAP_H])
			return ;
		end[1] = fmin(end[1], data->cache[MAP_H]);
		draw_map_line_to_img_ver_door(img, start, end);
		start[1]++;
		end[1]++;
	}
}

void	draw_doors_minimap(
	t_data *data, int index[2], int offset[2], int gap[2])
{
	if (data->map[index[1] * data->width + index[0] + 1] == ' ')
		draw_map_door_hor_to_img(
			&data->mlx_data.layers[MINIMAP], offset, gap, data);
	else
		draw_map_door_ver_to_img(
			&data->mlx_data.layers[MINIMAP], offset, gap, data);
}

void	draw_floor_loop(
	t_image *img, t_data *data, int offset[2], int p_wpos[2])
{
	int		gap[2];
	int		index[2];
	char	c;

	gap[0] = -data->cache[MID_TILE_X];
	index[0] = p_wpos[0] + gap[0];
	while (gap[0] <= data->cache[MID_TILE_X])
	{
		gap[1] = -data->cache[MID_TILE_Y];
		index[1] = p_wpos[1] + gap[1];
		while (gap[1] <= data->cache[MID_TILE_Y])
		{
			if (index[0] >= 0 && index[0] < data->width && \
				index[1] >= 0 && index[1] < data->height)
			{
				c = data->map[index[1] * data->width + index[0]];
				if (is_char_in_string(c, "0NESWPZO"))
					draw_map_tile_to_img(img, offset, gap, data);
				else if (c == 'D')
					draw_doors_minimap(data, index, offset, gap);
			}
			next_tile(&gap[1], &index[1]);
		}
		next_tile(&gap[0], &index[0]);
	}
}
