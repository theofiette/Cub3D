/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:36:09 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:18:52 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

__attribute__((always_inline)) static inline void	assign_vars_data_per_row(
	t_data *data, t_dda_floor *vars, float perp[2], float player_dir[2])
{
	vars->row_dist = WIN_HEIGHT / 2 / vars->z_dist;
	vars->step[0] = vars->row_dist * 2 * perp[0] / WIN_WIDTH;
	vars->step[1] = vars->row_dist * 2 * perp[1] / WIN_WIDTH;
	vars->floor[0] = -data->player.pos[0] + vars->row_dist
		* (player_dir[0] - perp[0]);
	vars->floor[1] = -data->player.pos[1] + vars->row_dist
		* (player_dir[1] - perp[1]);
	vars->curr_column = 0;
}

__attribute__((always_inline)) static inline void	update_vars_data_per_col(
	t_data *data, t_dda_floor *vars)
{
	vars->cell[0] = (int)vars->floor[0];
	vars->cell[1] = (int)vars->floor[1];
	vars->texture_coord[0] = (int)(data->textures.sprites[CE].w
			* (vars->floor[0] - vars->cell[0]))
		& (data->textures.sprites[CE].w - 1);
	vars->texture_coord[1] = (int)(data->textures.sprites[FL].h
			* (vars->floor[1] - vars->cell[1]))
		& (data->textures.sprites[FL].h - 1);
	vars->floor[0] += vars->step[0];
	vars->floor[1] += vars->step[1];
}

__attribute__((always_inline)) static inline void	floor_dda_print_pixels(
	t_data *data, t_dda_floor vars)
{
	int		x;
	int		y;
	t_image	*img;

	img = &data->mlx_data.layers[VIEWPORT];
	x = vars.curr_column;
	y = vars.curr_row + data->cache[HEADBOB];
	if (y >= 0)
	{
		vars.color = ((int *)data->textures.sprites[CE].addr)
		[data->textures.sprites[CE].w * vars.texture_coord[1]
			+ vars.texture_coord[0]];
		set_shadow(data, &vars.color, vars.blender);
		((int *)(img->addr + y * img->line_length))[x] = vars.color;
	}
	y = WIN_HEIGHT - vars.curr_row - 1 + data->cache[HEADBOB];
	if (y <= WIN_HEIGHT)
	{
		vars.color = ((int *)data->textures.sprites[FL].addr)
		[data->textures.sprites[FL].w * vars.texture_coord[1]
			+ vars.texture_coord[0]];
		set_shadow(data, &vars.color, vars.blender);
		((int *)(img->addr + y * img->line_length))[x] = vars.color;
	}
}

__attribute__((always_inline)) inline
void	floor_dda(t_data *data, float player_dir[2], float perp[2])
{
	t_dda_floor	vars;
	float	pos_z;

	vars.curr_row = HEADBOB_OFFSET;
	pos_z = data->cache[MID_HEIGHT];
	vars.z_dist = vars.curr_row - pos_z;
	while (vars.curr_row < pos_z)
	{	
		assign_vars_data_per_row(data, &vars, perp, player_dir);
		if (!(data->binary_input & (1 << SHOT)))
			vars.blender = ft_clamp(255.0f / ((pos_z / vars.curr_row))
					* 1.2f, 0, 255);
		else
			vars.blender = ft_clamp(255.0f
					/ ((pos_z / vars.curr_row)) * 1.1f, 0, 255);
		while (vars.curr_column < WIN_WIDTH)
		{
			update_vars_data_per_col(data, &vars);
			floor_dda_print_pixels(data, vars);
			vars.curr_column++;
		}
		vars.curr_row++;
		vars.z_dist++;
	}
}
