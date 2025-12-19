/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_zombies_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:39:19 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:05:30 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	draw_zombie(
	t_data *data, t_render_zomb *render, t_texture curr_sprite)
{
	int	hit;
	int	color;

	hit = 0;
	color = ((int *)(curr_sprite.addr))[render->texture_pos[1]
		* curr_sprite.w + render->texture_pos[0]];
	if (color != 0x1b1b1b)
	{
		if (!(data->binary_input & (1 << SHOT)))
			set_shadow(data, &color, 255.0f / VIEW * render->z->raw_dist);
		else
		{
			if (render->start[0] + render->curr_x == data->cache[MID_WIDTH]
				&& render->start[1] + render->curr_y == data->cache[MID_HEIGHT])
					hit = 1;
			set_shadow(data, &color, 255.0f / S_VIEW * render->z->raw_dist);
		}
		img_pix_put_hex(&data->mlx_data.layers[VIEWPORT],
			render->start[0] + render->curr_x,
			render->start[1] + render->curr_y, color);
	}
	return (hit);
}

static int	render_zombie_inner_loop(
	t_render_zomb *render_z, t_dda *var, t_data *data, t_texture curr_sprite)
{
	int	hit;

	hit = 0;
	if (render_z->start[0] + render_z->curr_x > WIN_WIDTH)
		return (0);
	if (render_z->z->raw_dist > var->dist_tab[
			render_z->start[0] + render_z->curr_x])
		return (1);
	if (render_z->start[1] < 0)
		render_z->curr_y = -render_z->start[1];
	render_z->texture_pos[0] = render_z->texture_step * render_z->curr_x;
	while (render_z->start[1] + render_z->curr_y < render_z->end[1])
	{
		if (render_z->start[1] + render_z->curr_y > WIN_HEIGHT)
			break ;
		render_z->texture_pos[1] = render_z->texture_step * render_z->curr_y;
		if (draw_zombie(data, render_z, curr_sprite))
			hit = 1;
		render_z->curr_y++;
	}
	if (hit)
		return (-1);
	return (1);
}

static void	set_render_infos(
	t_render_zomb *render, t_data *data, t_texture curr_sprite)
{
	rotate_float_vector_by_float_degrees(render->z->relative_pos,
		data->player.rotation);
	render->screen_x = data->cache[MID_WIDTH]
		* (1 + render->z->relative_pos[0] / render->z->relative_pos[1]);
	render->sprite_size = WIN_HEIGHT / fabsf(render->z->relative_pos[1]);
	render->lower = (int)(200.0f / fabsf(render->z->relative_pos[1]))
		+ data->cache[HEADBOB];
	render->start[0] = render->screen_x - render->sprite_size / 2;
	render->end[0] = render->screen_x + render->sprite_size / 2;
	render->start[1] = data->cache[MID_HEIGHT] - render->sprite_size
		/ 2 + render->lower;
	render->end[1] = data->cache[MID_HEIGHT] + render->sprite_size
		/ 2 + render->lower;
	render->texture_step = (float)(curr_sprite.h)
		/ (float)(render->end[0] - render->start[0]);
	render->curr_x = 0;
	if (render->start[0] < 0)
		render->curr_x = -render->start[0];
}

t_zombie	*render_zombie_core(t_data *data, t_dda *var, int i)
{
	t_render_zomb	render_z;
	t_texture		*curr_sprite;
	t_zombie		*zombie;
	int				result;

	pick_zombie_texture(&curr_sprite, data, &render_z, i);
	set_render_infos(&render_z, data, *curr_sprite);
	zombie = NULL;
	while (render_z.start[0] + render_z.curr_x < render_z.end[0])
	{
		render_z.curr_y = 0;
		result = render_zombie_inner_loop(&render_z, var, data, *curr_sprite);
		if (!result)
			return (zombie);
		if (result == -1)
			zombie = render_z.z;
		render_z.curr_x++;
	}
	return (zombie);
}
