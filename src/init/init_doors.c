/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:24:49 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/10 19:45:10 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	check_opposite_walls(t_data *data, char *map, int x, int y)
{
	if (map[(y + 1) * data->width + x] == ' '
		&& map[(y - 1) * data->width + x] == ' ')
	{
		if (map[y * data->width + x + 1] == ' '
			|| map[y * data->width + (x - 1)] == ' ')
		{
			set_error(data, ERR_DOOR);
			safe_exit(data);
		}
		return ;
	}
	if (map[y * data->width + x + 1] == ' '
		&& map[y * data->width + (x - 1)] == ' ')
	{
		if (map[(y + 1) * data->width + x] == ' '
			|| map[(y - 1) * data->width + x] == ' ')
		{
			set_error(data, ERR_DOOR);
			safe_exit(data);
		}
		return ;
	}
	set_error(data, ERR_DOOR);
}

static void	check_door_number(t_data *data)
{
	if (data->door_nbr + 1 > DOOR_MAX_NBR)
	{
		set_error(data, ERR_DOOR_NBR);
		safe_exit(data);
	}
}

static void	instantiate_door(t_data *data, int x, int y)
{
	data->d_tab[data->door_nbr].close = 0.8;
	data->d_tab[data->door_nbr].pos[0] = x;
	data->d_tab[data->door_nbr].pos[1] = y;
	data->door_nbr++;
}

void	check_and_instantiate_doors(t_data *data)
{
	int	y;
	int	x;

	data->door_nbr = 0;
	ft_memset(data->d_tab, 0, sizeof(data->d_tab));
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y * data->width + x] == 'D')
			{
				check_opposite_walls(data, data->map, x, y);
				check_door_number(data);
				instantiate_door(data, x, y);
			}
			x++;
		}
		y++;
	}
}
