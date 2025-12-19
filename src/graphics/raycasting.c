/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:00:48 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:55:35 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dda(
	t_dda *var, float player_dir[2], float perp[2], t_data *data)
{
	static int	init = 0;
	int			z;

	if (!init)
	{
		var->target_angle = FOV / 2.0f;
		var->angle_step = FOV / WIN_WIDTH;
		init = 1;
	}
	z = 0;
	while (var->sprite_count)
	{
		if (data->z_tab[z].is_visible)
		{
			data->z_tab[z].is_visible = 0;
			var->sprite_count--;
		}
		z++;
	}
	player_dir[0] = 0.0f;
	player_dir[1] = -1.0f;
	rotate_float_vector_by_degrees(player_dir, data->player.rotation);
	perp[0] = player_dir[0];
	perp[1] = player_dir[1];
	rotate_float_vector_by_float_degrees(perp, 90);
}

static inline void	set_var_for_render(t_dda *var, float dda_result)
{
	var->raw_dist = dda_result;
	var->dist_tab[var->line] = var->raw_dist;
	var->final_dist = WIN_HEIGHT / var->raw_dist;
}

static inline void	next_column(t_dda *var, t_data data, float *fov_ratio)
{
	var->line ++;
	*fov_ratio += data.cache[FOV_STEP];
}

void	wall_dda(t_data *data, t_dda *var, float player_dir[2], float perp[2])
{
	float	fov_ratio;
	float	dda_result;

	fov_ratio = -1;
	while (var->line < WIN_WIDTH)
	{
		var->ray_dir[0] = player_dir[0] + perp[0] * fov_ratio;
		var->ray_dir[1] = player_dir[1] + perp[1] * fov_ratio;
		dda_result = dda(data, var);
		if (dda_result == DDA_DOOR_HIT)
		{
			next_column(var, *data, &fov_ratio);
			continue ;
		}
		set_var_for_render(var, dda_result);
		if (var->raw_dist < S_VIEW && ((data->binary_input & (1 << SHOT)
					&& var->raw_dist > VIEW) || (var->raw_dist < VIEW)))
			render_view_vertical_line(data, var);
		else
			render_view_vertical_line_black(data, var);
		next_column(var, *data, &fov_ratio);
	}
}
