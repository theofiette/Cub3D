/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:21:16 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	next_tile(int *gap, int *index)
{
	*gap += 1;
	*index += 1;
}

void	draw_minimap_cursor_arm(t_image *img, t_data *data, int sign)
{
	float	start[2];
	float	end[2];
	int		vector[2];
	int		offset[2];

	start[0] = data->cache[CURSOR_X];
	start[1] = data->cache[CURSOR_Y];
	vector[0] = sign * (data->cache[CURSOR_LEN] / 2);
	vector[1] = (data->cache[CURSOR_LEN] / 2);
	offset[0] = 0;
	offset[1] = data->cache[CURSOR_LEN] / 2;
	rotate_vector_by_degrees(vector, data->player.rotation);
	rotate_vector_by_degrees(offset, data->player.rotation);
	end[0] = start[0] + vector[0] - offset[0];
	start[0] -= offset[0];
	end[1] = start[1] + vector[1] - offset[1];
	start[1] -= offset[1];
	draw_line_to_img_hex(img, start, end, MAP_PLAYER_COLOR);
	img_pix_put_hex(img, data->cache[CURSOR_X], \
		data->cache[CURSOR_Y], MAP_PLAYER_COLOR);
}

void	draw_minimap_background(t_image *img, t_image *bg, t_data *data)
{
	int				x;
	int				y;
	char			*pixel;
	unsigned int	blend_color;

	y = 0;
	while (y < data->cache[MAP_H])
	{
		x = 0;
		while (x < data->cache[MAP_W])
		{
			pixel = &bg->addr[(y + MAP_OFFSET) * bg->line_length
				+ (x + MAP_OFFSET) * (bg->bits_per_pixel / 8)];
			blend_color = blend(*((int *)pixel), COLOR_SHADOW, 70);
			img_pix_put_hex(img, x, y, blend_color);
			x++;
		}
		y++;
	}
}

int	check_edges(char *temp, t_image *img, int coord[2], t_data *data)
{
	if (coord[1] + 1 < data->cache[MAP_H])
	{
		if (*(int *)(temp + img->line_length) == MAP_FLOOR_COLOR)
			return (1);
	}
	if (coord[1] - 1 >= 0)
	{
		if (*(int *)(temp - img->line_length) == MAP_FLOOR_COLOR)
			return (1);
	}
	if (coord[0] + 1 < data->cache[MAP_W])
	{
		if (*(int *)(temp + img->bits_per_pixel / 8) == MAP_FLOOR_COLOR)
			return (1);
	}
	if (coord[0] - 1 >= 0)
	{
		if (*(int *)(temp - img->bits_per_pixel / 8) == MAP_FLOOR_COLOR)
			return (1);
	}
	return (0);
}

void	outline_walls(t_image *img, t_data *data)
{
	int		coord[2];
	char	*temp;

	coord[1] = 0;
	while (coord[1] < data->cache[MAP_H])
	{
		coord[0] = 0;
		while (coord[0] < data->cache[MAP_W])
		{
			temp = img->addr + coord[1] * img->line_length
				+ coord[0] * img->bits_per_pixel / 8;
			if (*(int *)temp == MAP_PLAYER_COLOR
				|| *(int *)temp == MAP_FLOOR_COLOR)
			{
				coord[0]++;
				continue ;
			}
			if (check_edges(temp, img, coord, data))
				*(int *)temp = MAP_WALL_COLOR;
			coord[0]++;
		}
		coord[1]++;
	}
}
