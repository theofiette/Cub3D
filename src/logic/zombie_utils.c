/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:59:33 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/12 18:35:14 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pick_zombie_texture(
	t_texture **sprite, t_data *data, t_render_zomb *render, int i)
{
	render->z = &data->z_tab[i];
	if (!data->z_tab[i].hp)
		*sprite = &data->textures.zombie[12 + (render->z->index % 2)];
	else if (data->z_tab[i].is_shot || data->z_tab[i].is_hit)
		*sprite = &data->textures.zombie[11];
	else
		*sprite = &data->textures.zombie[render->z->curr_frame];
}

void	zombie_set_target_player(t_zombie *zombie, float pos[2])
{
	zombie->target[0] = pos[0];
	zombie->target[1] = pos[1];
}

inline static void	get_dir(int dir[2])
{
	int			r;
	static int	dirs[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
	};

	r = rand() % 4;
	dir[0] = dirs[r][0];
	dir[1] = dirs[r][1];
}

void	zombie_set_target_random(t_data *data, t_zombie *zombie, int max_step)
{
	int			pos[2];
	int			dir[2];
	int			step;

	step = 1;
	get_dir(dir);
	while (step < max_step)
	{
		pos[0] = zombie->map_pos[0] + step * dir[0];
		pos[1] = zombie->map_pos[1] + step * dir[1];
		if (pos[0] < 0 || pos[0] > data->width
			|| pos[1] < 0 || pos[1] > data->height
			|| data->map[pos[1] * data->width + pos[0]] == ' '
			|| data->map[pos[1] * data->width + pos[0]] == 'D')
		{
			step--;
			break ;
		}
		step++;
	}
	if (step)
	{
		zombie->target[0] = zombie->map_pos[0] + step * dir[0];
		zombie->target[1] = zombie->map_pos[1] + step * dir[1];
	}
}

int	has_zombie_reached_target(float pos[2], float target[2])
{
	if ((int)pos[0] == (int)target[0] && (int)pos[1] == (int)target[1])
		return (1);
	return (0);
}
