/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zombies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:20:24 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/12 18:23:14 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_zombie_number(t_data *data)
{
	if (data->zombie_nbr + 1 > ZOMBIE_MAX_NBR)
	{
		set_error(data, ERR_ZOMBIE_NBR);
		safe_exit(data);
	}
}

static void	instantiate_zombie(t_data *data, int x, int y)
{
	data->z_tab[data->zombie_nbr].index = data->zombie_nbr;
	data->z_tab[data->zombie_nbr].hp = 2;
	data->z_tab[data->zombie_nbr].is_dead = 0;
	data->z_tab[data->zombie_nbr].is_hit = 0;
	data->z_tab[data->zombie_nbr].is_shot = 0;
	data->z_tab[data->zombie_nbr].is_visible = 0;
	data->z_tab[data->zombie_nbr].pos[0] = x + 0.5;
	data->z_tab[data->zombie_nbr].pos[1] = y + 0.5;
	data->z_tab[data->zombie_nbr].timer = 0;
	data->z_tab[data->zombie_nbr].base_frame = rand() % 11;
	data->z_tab[data->zombie_nbr].target[0] = x + 0.5;
	data->z_tab[data->zombie_nbr].target[1] = y + 0.5;
	data->z_tab[data->zombie_nbr].map_pos[0] = x;
	data->z_tab[data->zombie_nbr].map_pos[1] = y;
	data->z_tab[data->zombie_nbr].dist = -1;
	data->zombie_nbr++;
}

void	check_and_instantiate_zombies(t_data *data)
{
	int	y;
	int	x;

	data->zombie_nbr = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y * data->width + x] == 'Z')
			{
				check_zombie_number(data);
				instantiate_zombie(data, x, y);
			}
			x++;
		}
		y++;
	}
}
