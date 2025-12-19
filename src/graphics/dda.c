/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:19:28 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/12 17:02:42 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_hit_zombie(t_data *data, t_dda *var, float dist)
{
	int	i;

	i = 0;
	while (i < data->zombie_nbr)
	{
		if (data->z_tab[i].map_pos[0] == var->pos[0]
			&& data->z_tab[i].map_pos[1] == var->pos[1])
			break ;
		i++;
	}
	if (i == data->zombie_nbr)
		return ;
	if (!data->z_tab[i].is_visible)
		update_zombie(data, var, dist, i);
}

static inline float	dda_x(
	t_data *data, t_dda *var, int door_pos[2])
{
	if (var->side == 2)
	{
		if (try_render_door_line(data, var, door_pos))
			return (DDA_DOOR_HIT);
		var->side = 0;
		var->door_dist = 0;
	}
	var->pos[0] += var->step[0];
	if (data->map[var->pos[1] * data->width + var->pos[0]] == ' ')
	{
		if ((var->door_dist && var->door_dist < var->dist[0])
			&& try_render_door_line(data, var, door_pos))
			return (DDA_DOOR_HIT);
		return (var->side = 0, var->dist[0]);
	}
	else if (data->map[var->pos[1] * data->width + var->pos[0]] == 'D')
	{
		door_pos[0] = var->pos[0];
		door_pos[1] = var->pos[1];
		var->door_dist = var->dist[0] + var->ray[0] / 2;
		var->side = 2;
	}
	else if (data->map[var->pos[1] * data->width + var->pos[0]] == 'Z')
		dda_hit_zombie(data, var, var->dist[0]);
	return (var->dist[0] += var->ray[0], 0);
}

static inline float	dda_y(
	t_data *data, t_dda *var, int door_pos[2])
{
	if (var->side == 3)
	{
		if (try_render_door_line(data, var, door_pos))
			return (DDA_DOOR_HIT);
		var->side = 0;
		var->door_dist = 0;
	}
	var->pos[1] += var->step[1];
	if (data->map[var->pos[1] * data->width + var->pos[0]] == ' ')
	{
		if ((var->door_dist && var->door_dist < var->dist[1])
			&& try_render_door_line(data, var, door_pos))
			return (DDA_DOOR_HIT);
		return (var->side = 1, var->dist[1]);
	}
	else if (data->map[var->pos[1] * data->width + var->pos[0]] == 'D')
	{
		door_pos[0] = var->pos[0];
		door_pos[1] = var->pos[1];
		var->door_dist = var->dist[1] + var->ray[1] / 2;
		var->side = 3;
	}
	else if (data->map[var->pos[1] * data->width + var->pos[0]] == 'Z')
		dda_hit_zombie(data, var, var->dist[1]);
	return (var->dist[1] += var->ray[1], 0);
}

static inline float	dda_check_max_dist(char input, float dist[2])
{
	if (input & (1 << SHOT))
	{
		if (dist[0] > S_VIEW && dist[1] > S_VIEW)
			return (S_VIEW);
	}
	else if (dist[0] > VIEW && dist[1] > VIEW)
		return (VIEW);
	return (0);
}

float	dda(t_data *data, t_dda *var)
{
	int		door_pos[2];
	float	result;

	dda_init(data, var);
	while (1)
	{
		if (var->dist[0] < var->dist[1])
		{
			result = dda_x(data, var, door_pos);
			if (result)
				return (result);
		}
		else
		{
			result = dda_y(data, var, door_pos);
			if (result)
				return (result);
		}
		result = dda_check_max_dist(data->binary_input, var->dist);
		if (result)
			return (result);
	}
	return (DDA_NO_HIT);
}
