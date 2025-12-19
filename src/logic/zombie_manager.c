/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:58:56 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:24:45 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_zombie_collision(
	t_data *data, t_zombie *curr_zombie, float x, float y)
{
	float	r_pos_x[4];
	float	r_pos_y[4];
	int		new_pos[2];
	int		count;

	r_pos_x[0] = x - ZOMBIE_RADIUS;
	r_pos_x[1] = x + ZOMBIE_RADIUS;
	r_pos_x[2] = x - ZOMBIE_RADIUS;
	r_pos_x[3] = x + ZOMBIE_RADIUS;
	r_pos_y[0] = y - ZOMBIE_RADIUS;
	r_pos_y[1] = y - ZOMBIE_RADIUS;
	r_pos_y[2] = y + ZOMBIE_RADIUS;
	r_pos_y[3] = y + ZOMBIE_RADIUS;
	count = -1;
	while (++count < 4)
	{
		new_pos[0] = (int)r_pos_x[count];
		new_pos[1] = (int)r_pos_y[count];
		if (data->map[new_pos[1] * data->width + new_pos[0]] == ' '
			|| data->map[new_pos[1] * data->width + new_pos[0]] == 'D')
			return (1);
	}
	return (((int)y != curr_zombie->map_pos[1]
			|| (int)x != curr_zombie->map_pos[0])
		&& data->map[(int)y * data->width + (int)x] == 'Z');
}

static void	move_zombie(t_data *data, t_zombie *zombie)
{
	if (zombie->map_pos[0] != (int)zombie->pos[0]
		|| zombie->map_pos[1] != (int)zombie->pos[1])
	{
		data->map[zombie->map_pos[1] * data->width + zombie->map_pos[0]] = '0';
		zombie->map_pos[0] = (int)zombie->pos[0];
		zombie->map_pos[1] = (int)zombie->pos[1];
		data->map[zombie->map_pos[1] * data->width + zombie->map_pos[0]] = 'Z';
	}
}

static void	update_zombie_cache(t_data *data, t_zombie *zombie)
{
	float	dir[2];
	float	distance;
	float	new_pos[2];

	dir[0] = zombie->target[0] - zombie->pos[0];
	dir[1] = zombie->target[1] - zombie->pos[1];
	distance = sqrtf(dir[0] * dir[0] + dir[1] * dir[1]);
	if (distance < 0.1f)
		return ;
	dir[0] /= distance;
	dir[1] /= distance;
	new_pos[0] = zombie->pos[0] + (dir[0] * (ZOMBIE_SPEED * data->cache[DELTA]));
	new_pos[1] = zombie->pos[1] + (dir[1] * (ZOMBIE_SPEED * data->cache[DELTA]));
	if (check_player_hit(data, new_pos))
		return ;
	if (!check_zombie_collision(data, zombie, new_pos[0], zombie->pos[1]))
		zombie->pos[0] = new_pos[0];
	if (!check_zombie_collision(data, zombie, zombie->pos[0], new_pos[1]))
		zombie->pos[1] = new_pos[1];
	move_zombie(data, zombie);
}

void	zombie_manager(t_data *data)
{
	int			z;
	t_zombie	*zombie;

	z = 0;
	while (z < data->zombie_nbr)
	{
		zombie = &data->z_tab[z];
		if (zombie->is_dead)
		{
			z++;
			continue ;
		}
		check_zombie_hit(data, zombie);
		if (zombie->is_visible)
			zombie_set_target_player(zombie, data->player.pos);
		else if (has_zombie_reached_target(zombie->pos, zombie->target))
			zombie_set_target_random(data, zombie, 10);
		if (data->z_tab[z].hp > 0 && !zombie->is_hit)
			update_zombie_cache(data, zombie);
		z++;
		if (!data->player.hp)
			data->game_over = 1;
	}
}
