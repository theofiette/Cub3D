/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:12:21 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:05:21 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	pick_texture(
	t_data *data, t_texture **texture, int side, float dir[2])
{
	if (side == 0)
	{
		if (dir[0] < 0)
			*texture = &(data->textures.sprites[EA]);
		else
			*texture = &(data->textures.sprites[WE]);
	}
	else if (side == 1)
	{
		if (dir[1] < 0)
			*texture = &(data->textures.sprites[SO]);
		else
			*texture = &(data->textures.sprites[NO]);
	}
}

static inline void	update_texture_cache(t_data *data, t_texture *sprite)
{
	data->render.texture_y = ft_fclamp(data->render.texture_pos,
			0.0f, sprite->h - 1);
	data->render.texture_pos += data->render.texture_step;
}

static inline void	reverse_text(
	t_data *data, float dir[2], t_texture *sprite, int side)
{
	if ((!side || side == 2) && dir[0] < 0)
		data->render.texture_x = sprite->w - data->render.texture_x - 1;
	else if ((side == 1 || side == 3) && dir[1] > 0)
		data->render.texture_x = sprite->w - data->render.texture_x - 1;
}

void	render_view_vertical_line_black(t_data *data, t_dda *var)
{
	int			y;
	int			x;
	t_image		*img;

	assign_drawing_point(data, var->final_dist, var->line);
	y = data->render.start[1];
	x = var->line;
	img = &data->mlx_data.layers[VIEWPORT];
	while (y <= data->render.end[1])
	{
		((int *)(img->addr + y * img->line_length))[x] = 0;
		y++;
	}
}

void	render_view_vertical_line(t_data *data, t_dda *var)
{
	int			y;
	int			color;
	t_texture	*sprite;
	t_image		*img;

	pick_texture(data, &sprite, var->side, var->ray_dir);
	assign_wall_coord(data, var);
	assign_drawing_point(data, var->final_dist, var->line);
	assign_texture_cache(data, data->render.start, data->render.end, sprite);
	reverse_text(data, var->ray_dir, sprite, var->side);
	img = &data->mlx_data.layers[VIEWPORT];
	y = data->render.start[1] - 1;
	while (++y <= data->render.end[1])
	{
		update_texture_cache(data, sprite);
		color = ((int *)sprite->addr)[data->render.texture_y
			* sprite->w + data->render.texture_x];
		if (!(data->binary_input & (1 << SHOT)))
			set_shadow(data, &color, 255 / VIEW * var->raw_dist);
		else
			set_shadow(data, &color, 255 / S_VIEW * var->raw_dist);
		((int *)(img->addr + y * img->line_length))[var->line] = color;
	}
}
