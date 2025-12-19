/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:49:07 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_door_open(t_data *data, int door_id)
{
	t_door	*curr_door;

	curr_door = data->d_tab + door_id;
	curr_door->close = 0;
	data->map[curr_door->pos[1] * data->width + curr_door->pos[0]] = '0';
}

static int	is_door_near(t_data *data, t_door door)
{
	int	x;
	int	y;

	x = (int)data->player.pos[0] - door.pos[0];
	y = (int)data->player.pos[1] - door.pos[1];
	return (abs(x) + abs(y) == 1);
}

void	door_manager(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->door_nbr)
	{
		if (data->d_tab[i].close)
		{
			if (is_door_near(data, data->d_tab[i]))
			{
				data->d_tab[i].close -= data->cache[DELTA] / 2;
				if (data->d_tab[i].close < 0)
					set_door_open(data, i);
			}
			else if (data->d_tab[i].close != 1)
			{
				data->d_tab[i].close += data->cache[DELTA] / 6;
				if (data->d_tab[i].close > 1)
					data->d_tab[i].close = 1;
			}
		}
		i++;
	}
}
