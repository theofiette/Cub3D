/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reloading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:46:18 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_reloading(t_data *data)
{
	data->player.is_reloading = 1;
	data->player.reload_timer = 0;
}

static void	finish_reloading(t_data *data)
{
	data->player.ammo = MAX_AMMO;
	data->player.is_reloading = 0;
	data->binary_input &= ~(1 << RELOAD);
}

void	update_reloading(t_data *data)
{
	data->player.reload_timer += data->cache[DELTA];
	if (data->player.reload_timer >= RELOAD_TIME)
		finish_reloading(data);
}

void	set_gun_data_reload(t_data *data, float *h)
{
	if (data->binary_input & (1 << RELOAD))
	{
		if (data->player.reload_timer < 1.0f)
			*h -= *h * powf(data->player.reload_timer * 3, 4);
		else if (data->player.reload_timer > 1.2f)
			*h -= *h / powf(data->player.reload_timer * 3, 3);
	}
}
