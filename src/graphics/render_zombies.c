/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_zombies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:35:34 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	zombie_sort(t_data *data, t_dda *var)
{
	int			i;
	t_zombie	temp;

	if (!var->sprite_count)
		return ;
	i = 0;
	while (i < ZOMBIE_MAX_NBR)
	{
		if (!data->z_tab[i].is_visible || data->z_tab[i].is_dead)
			data->z_tab[i].dist = 0;
		i++;
	}
	i = 0;
	while (i < ZOMBIE_MAX_NBR - 1)
	{
		if (data->z_tab[i].dist < data->z_tab[i + 1].dist)
		{
			temp = data->z_tab[i + 1];
			data->z_tab[i + 1] = data->z_tab[i];
			data->z_tab[i] = temp;
			i = -1;
		}
		i++;
	}
}

void	render_zombie_loop(t_data *data, t_dda *var)
{
	int			i;
	t_zombie	*zombie;
	t_zombie	*last_zombie;

	zombie_sort(data, var);
	i = 0;
	last_zombie = NULL;
	while (i < var->sprite_count)
	{
		if (data->z_tab[i].is_visible)
		{
			zombie = render_zombie_core(data, var, i);
			if (zombie)
				last_zombie = zombie;
		}
		i++;
	}
	if (last_zombie && !last_zombie->is_shot && !data->player.has_shot)
		last_zombie->is_shot = 1;
}

void	update_zombie(
	t_data *data, t_dda *var, float dist, int i)
{
	data->z_tab[i].is_visible = 1;
	data->z_tab[i].dist = var->dist[1] + var->dist[0];
	data->z_tab[i].raw_dist = dist;
	data->z_tab[i].ray_dir[0] = var->ray_dir[0];
	data->z_tab[i].ray_dir[1] = var->ray_dir[1];
	data->z_tab[i].relative_pos[0] = (data->z_tab[i].pos[0]
			- data->player.pos[0]) * -1;
	data->z_tab[i].relative_pos[1] = data->z_tab[i].pos[1]
		- data->player.pos[1];
	data->z_tab[i].timer += data->cache[DELTA] * 5;
	if (!data->z_tab[i].is_hit)
		data->z_tab[i].curr_frame = (int)data->z_tab[i].timer % 11;
	var->sprite_count++;
}
