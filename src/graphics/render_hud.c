/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:13:56 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:05:07 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_ammo_inner_loop(
	t_data *data, t_texture texture, int coord[2])
{
	int	i;
	int	color;

	i = 1;
	while (i <= data->player.ammo)
	{
		color = ((int *)(texture.addr))[coord[1] * texture.w + coord[0]];
		if (color)
			img_pix_put_hex(&data->mlx_data.layers[VIEWPORT],
				WIN_WIDTH - (texture.w * (1.6 * i)) + coord[0],
				WIN_HEIGHT - 10 - texture.h + coord[1], color);
		i++;
	}
}

static void	render_ammo(t_data *data)
{
	int			coord[2];
	t_texture	texture;

	texture = data->textures.bullet;
	coord[1] = 0;
	while (coord[1] < texture.h)
	{
		coord[0] = 0;
		while (coord[0] < texture.w)
		{
			render_ammo_inner_loop(data, texture, coord);
			coord[0]++;
		}
		coord[1]++;
	}
}

void	render_game_over_inner_loop(
	t_data *data, int coord[2], int blender, t_texture sprite)
{
	int	color;
	int	bg;

	color = ((int *)sprite.addr)[coord[1] * sprite.w + coord[0]];
	if (blender)
	{
		bg = ((int *)data->mlx_data.layers[VIEWPORT].addr)[
			(int)(data->cache[MID_HEIGHT] - sprite.h / 2 + coord[1])
			* sprite.w + (int)data->cache[MID_WIDTH] - sprite.w / 2 + coord[0]];
		color = blend(bg, color, blender);
	}
	img_pix_put_hex(&data->mlx_data.layers[VIEWPORT],
		data->cache[MID_WIDTH] - sprite.w / 2 + coord[0],
		data->cache[MID_HEIGHT] - sprite.h / 2 + coord[1], color);
}

static void	render_game_over(t_data *data)
{
	int			texture_coord[2];
	t_texture	*sprite;
	int			blender;

	texture_coord[1] = 0;
	sprite = &data->textures.game_over;
	while (texture_coord[1] < sprite->h)
	{
		if (texture_coord[1] < 40)
			blender = 255 - (255 / 40 * (40 - texture_coord[1]));
		else if (texture_coord[1] > sprite->h - 40)
			blender = 255 + (255 / 40 * (sprite->h - 40 - texture_coord[1]));
		else
			blender = 0;
		texture_coord[0] = 0;
		while (texture_coord[0] < sprite->w)
		{
			render_game_over_inner_loop(data, texture_coord, blender, *sprite);
			texture_coord[0]++;
		}
		texture_coord[1]++;
	}
}

void	render_hud(t_data *data)
{
	if (data->game_over)
		render_game_over(data);
	else
	{
		render_minimap(data);
		render_ammo(data);
	}
}
