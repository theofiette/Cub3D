/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:35:29 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	vector_multiply(float vec[2], float n)
{
	vec[0] *= n;
	vec[1] *= n;
}

static int	check_collision(t_data *data, float x, float y)
{
	float	r_pos_x[4];
	float	r_pos_y[4];
	int		new_pos[2];
	int		count;

	r_pos_x[0] = x - PLAYER_RADIUS;
	r_pos_x[1] = x + PLAYER_RADIUS;
	r_pos_x[2] = x - PLAYER_RADIUS;
	r_pos_x[3] = x + PLAYER_RADIUS;
	r_pos_y[0] = y - PLAYER_RADIUS;
	r_pos_y[1] = y - PLAYER_RADIUS;
	r_pos_y[2] = y + PLAYER_RADIUS;
	r_pos_y[3] = y + PLAYER_RADIUS;
	count = 0;
	while (count < 4)
	{
		new_pos[0] = (int)r_pos_x[count];
		new_pos[1] = (int)r_pos_y[count];
		if (data->map[new_pos[1] * data->width + new_pos[0]] == ' '
			|| data->map[new_pos[1] * data->width + new_pos[0]] == 'D')
			return (1);
		count++;
	}
	return (0);
}

static void	move_player_apply(t_data *data, t_player *player)
{
	float	forward[2];
	float	new_x;
	float	new_y;

	forward[0] = player->velocity[0];
	forward[1] = player->velocity[1];
	rotate_float_vector_by_degrees(forward, player->rotation);
	new_x = player->pos[0] + forward[0] * data->cache[DELTA] * player->speed;
	new_y = player->pos[1] + forward[1] * data->cache[DELTA] * player->speed;
	if (!check_collision(data, new_x, player->pos[1]))
		player->pos[0] = new_x;
	if (!check_collision(data, player->pos[0], new_y))
		player->pos[1] = new_y;
}

void	move_player(t_data *data, t_player *player)
{
	float	curr_speed;

	if (player->direction[0] && player->direction[1])
		vector_multiply(player->direction, DIRECTION_NORM);
	if (player->direction[0] || player->direction[1])
	{
		player->velocity[0] += player->direction[0] * ACCEL * data->cache[DELTA];
		player->velocity[1] += player->direction[1] * ACCEL * data->cache[DELTA];
	}
	else
		vector_multiply(player->velocity, 1.0f - DECCEL * data->cache[DELTA]);
	curr_speed = sqrtf(player->velocity[0] * player->velocity[0] + \
		player->velocity[1] * player->velocity[1]);
	if (curr_speed > MAX_SPEED)
	{
		vector_multiply(player->velocity, MAX_SPEED / curr_speed);
		curr_speed = MAX_SPEED;
	}
	player->speed = MAX_SPEED * (1 - cos(M_PI * (curr_speed / MAX_SPEED)) / 2);
	if (player->speed)
		move_player_apply(data, player);
}
