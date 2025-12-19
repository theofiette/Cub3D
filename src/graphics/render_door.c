/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:35:47 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 16:04:51 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline float	get_door_closeness(t_data *data, int pos[2])
{
	int		i;

	i = 0;
	while (i < data->door_nbr)
	{
		if (data->d_tab[i].pos[0] == pos[0]
			&& data->d_tab[i].pos[1] == pos[1])
		{
			return (data->d_tab[i].close);
		}
		i++;
	}
	return (0);
}

static inline int	apply_door_closeness(
	t_data *data, int pos[2], t_texture *sprite, int inv)
{
	float	close;

	close = get_door_closeness(data, pos);
	if (inv)
	{
		if (data->render.texture_x < (float)sprite->w * (1 - close))
			return (1);
		data->render.texture_x += sprite->w - (float)sprite->w * (1 - close);
	}
	else
	{
		if (data->render.texture_x > (float)sprite->w * close)
			return (1);
		data->render.texture_x += sprite->w - (float)sprite->w * close;
	}
	return (0);
}

void	render_door_vertical_line(t_data *data, t_texture *sprite, t_dda *var)
{
	int			y;
	int			color;
	float		blender[2];
	t_image		*img;

	img = &data->mlx_data.layers[VIEWPORT];
	y = data->render.start[1];
	blender[0] = 255 / VIEW * var->raw_dist;
	blender[1] = 255 / S_VIEW * var->raw_dist;
	while (y <= data->render.end[1])
	{
		data->render.texture_y = ft_fclamp(data->render.texture_pos,
				0.0f, sprite->h - 1);
		data->render.texture_pos += data->render.texture_step;
		color = ((int *)sprite->addr)[data->render.texture_y
			* sprite->w + data->render.texture_x];
		if (!(data->binary_input & (1 << SHOT)))
			set_shadow(data, &color, blender[0]);
		else
			set_shadow(data, &color, blender[1]);
		((int *)(img->addr + y * img->line_length))[var->line] = color;
		y++;
	}
}

static inline int	reverse_text_door(
	t_data *data, float dir[2], t_texture *sprite, int side)
{
	if (((side == 2) && dir[0] < 0) || ((side == 3) && dir[1] > 0))
	{
		data->render.texture_x = sprite->w - data->render.texture_x - 1;
		return (1);
	}
	return (0);
}

int	try_render_door_line(
	t_data *data, t_dda *var, int pos[2])
{
	int			inverted;
	t_texture	*sprite;

	sprite = &data->textures.door;
	var->raw_dist = var->door_dist;
	var->dist_tab[var->line] = var->raw_dist;
	var->final_dist = WIN_HEIGHT / var->raw_dist;
	assign_wall_coord(data, var);
	assign_drawing_point(data, var->final_dist, var->line);
	assign_texture_cache_door(data, data->render.start,
		data->render.end, sprite);
	inverted = reverse_text_door(data, var->ray_dir,
			sprite, var->side);
	if (apply_door_closeness(data, pos, sprite, inverted))
		return (DDA_NO_HIT);
	render_door_vertical_line(data, sprite, var);
	return (DDA_DOOR_HIT);
}
