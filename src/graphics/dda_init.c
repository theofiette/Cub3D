/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:30:35 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/10 19:54:10 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	dda_init_map(t_dda *var, t_data *data)
{
	var->pos[0] = (int)data->player.pos[0];
	var->pos[1] = (int)data->player.pos[1];
}

inline static void	dda_init_ray(t_dda *var)
{
	if (var->ray_dir[0])
		var->ray[0] = fabs(1 / var->ray_dir[0]);
	else
		var->ray[0] = 1e30;
	if (var->ray_dir[1])
		var->ray[1] = fabs(1 / var->ray_dir[1]);
	else
		var->ray[1] = 1e30;
}

inline static void	dda_init_step(t_dda *var)
{
	if (var->ray_dir[0] < 0)
		var->step[0] = -1;
	else
		var->step[0] = 1;
	if (var->ray_dir[1] < 0)
		var->step[1] = -1;
	else
		var->step[1] = 1;
}

inline static void	dda_init_dist(t_dda *var, t_data *data)
{
	if (var->ray_dir[0] < 0.0f)
		var->dist[0] = (float)(data->player.pos[0] - var->pos[0]) * var->ray[0];
	else
		var->dist[0] = (1.0f - (float)(data->player.pos[0] \
			- var->pos[0])) * var->ray[0];
	if (var->ray_dir[1] < 0.0f)
		var->dist[1] = (data->player.pos[1] \
		- var->pos[1]) * var->ray[1];
	else
		var->dist[1] = (1.0f - (float)(data->player.pos[1] \
		- var->pos[1])) * var->ray[1];
}

inline void	dda_init(t_data *data, t_dda *var)
{
	dda_init_map(var, data);
	dda_init_ray(var);
	dda_init_step(var);
	dda_init_dist(var, data);
	var->door_dist = 0;
	var->side = 0;
}
