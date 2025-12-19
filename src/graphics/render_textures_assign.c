/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures_assign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:59:21 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 16:01:51 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	assign_texture_cache_door(
	t_data *data, float start[2], float end[2], t_texture *sprite)
{
	data->render.texture_x = (int)(data->render.wall_coord
			* (float)sprite->w);
	data->render.texture_step = (float)sprite->h / (end[1] - start[1]);
	data->render.texture_pos = 0.0f;
	if (data->render.start[1] < 0)
		data->render.texture_pos += data->render.texture_step
			* fabs(data->render.start[1]);
	data->render.start[1] = ft_fclamp(data->render.start[1], 0, WIN_HEIGHT);
	data->render.end[1] = ft_fclamp(data->render.end[1], 0, WIN_HEIGHT);
}

inline void	assign_wall_coord(t_data *data, t_dda *var)
{
	if (var->side == 1 || var->side == 3)
		data->render.wall_coord = data->player.pos[0]
			+ var->raw_dist * var->ray_dir[0];
	else if (!var->side || var->side == 2)
		data->render.wall_coord = data->player.pos[1]
			+ var->raw_dist * var->ray_dir[1];
	data->render.wall_coord -= floorf(data->render.wall_coord);
}

inline void	assign_texture_cache(
	t_data *data, float start[2], float end[2], t_texture *sprite)
{
	data->render.texture_x = (int)(data->render.wall_coord
			* (float)sprite->w);
	data->render.texture_step = (float)sprite->h / (end[1] - start[1]);
	data->render.texture_pos = 0.0f;
	if (data->render.start[1] < 0)
		data->render.texture_pos += data->render.texture_step
			* fabs(data->render.start[1]);
	data->render.start[1] = ft_fclamp(data->render.start[1], 0, WIN_HEIGHT);
	data->render.end[1] = ft_fclamp(data->render.end[1], 0, WIN_HEIGHT);
}

inline void	assign_drawing_point(t_data *data, float dist, int x)
{
	float	mid_dist;

	mid_dist = dist / 2;
	data->render.start[0] = x;
	data->render.end[0] = x;
	data->render.start[1] = data->cache[MID_HEIGHT] - mid_dist
		+ data->cache[HEADBOB];
	data->render.end[1] = data->cache[MID_HEIGHT] + mid_dist
		+ data->cache[HEADBOB];
}
