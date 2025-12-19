/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_n_crosshair.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:37:26 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:04:38 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_crosshair(t_data *data)
{
	float	start[2];
	float	end[2];

	start[0] = data->cache[MID_WIDTH] - 3;
	end[0] = start[0] - 3;
	start[1] = data->cache[MID_HEIGHT];
	end[1] = start[1];
	draw_line_to_img_hex(&data->mlx_data.layers[VIEWPORT],
		start, end, MAP_FLOOR_COLOR);
	start[0] += 6;
	end[0] = start[0] + 3;
	draw_line_to_img_hex(&data->mlx_data.layers[VIEWPORT],
		start, end, MAP_FLOOR_COLOR);
	start[0] = data->cache[MID_WIDTH];
	end[0] = start[0];
	start[1] = data->cache[MID_HEIGHT] - 3;
	end[1] = start[1] - 3;
	draw_line_to_img_hex(&data->mlx_data.layers[VIEWPORT],
		start, end, MAP_FLOOR_COLOR);
	start[1] += 6;
	end[1] = start[1] + 3;
	draw_line_to_img_hex(&data->mlx_data.layers[VIEWPORT],
		start, end, MAP_FLOOR_COLOR);
}

void	draw_gunshot_inner_loop(t_data *data, int color_val, int *x, int y)
{
	int				color;

	color = color_val;
	if (color & (0x0e << 3))
		img_pix_put_hex(&data->mlx_data.layers[VIEWPORT],
			WIN_WIDTH / 2 + *x + 40
			+ ((int)(data->cache[DELTA] * 10000))
			% 20, WIN_HEIGHT / 2 - 70 + y
			+ ((int)(data->cache[DELTA] * 10000))
			% 10
			+ data->textures.gunshot.w / 4, color);
	*x += 1;
}

void	draw_gunshot(t_data *data)
{
	int				x;
	int				y;
	static float	timer = 0;

	if (timer <= 0.08f)
	{
		y = 0;
		while (y < data->textures.gunshot.h)
		{
			x = 0;
			while (x < data->textures.gunshot.w)
				draw_gunshot_inner_loop(data,
					((int *)data->textures.gunshot.addr)[
					y * data->textures.gunshot.w + x], &x, y);
			y++;
		}
		timer += data->cache[DELTA];
	}
	if (timer >= 0.08f)
	{
		timer = 0.0f;
		data->binary_input &= ~(1 << SHOT);
		data->player.has_shot = 0;
	}
}

void	draw_gun_inner_loop(t_data *data, int color_val, int width, int height)
{
	int	color;

	color = color_val;
	if (color)
	{
		if (data->player.hp <= 1)
			set_shadow(data, &color, 10);
		img_pix_put_hex(&data->mlx_data.layers[VIEWPORT],
			width, height, color);
	}
}

void	draw_gun(t_data *data, int *img, float h, int w)
{
	int			x;
	int			y;
	static int	x_step = WIN_WIDTH / 10;
	float		offset;

	offset = 0;
	if (data->binary_input & (1 << SHOT))
		offset = -8;
	set_gun_data_reload(data, &h);
	y = 0;
	while (y < h)
	{
		x = -1;
		if (y + (data->cache[HEADBOB] * 2) + 8 + offset - h < WIN_HEIGHT)
		{
			while (++x < w
				&& data->cache[MID_WIDTH] + x + x_step < WIN_WIDTH)
			{
				draw_gun_inner_loop(data, img[y * w + x],
					data->cache[MID_WIDTH] + x + x_step, WIN_HEIGHT - h + y
					+ (data->cache[HEADBOB] * 2) + 8 - offset);
			}
		}
		y++;
	}
}
