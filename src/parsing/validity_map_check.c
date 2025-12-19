/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_map_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:00:47 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/10 19:42:21 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	floodfill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
	{
		set_error(data, ERR_MAP_OPEN);
		return ;
	}
	if (!is_char_in_string(data->map[y * data->width + x], VALIDCHAR) \
		&& data->map[y * data->width + x] != '\0')
		return ;
	if (!is_char_in_string(data->map[y * data->width + x], CROSSABLECHAR))
		return ;
	if (is_char_in_string(data->map[y * data->width + x], PLAYERCHAR))
		data->map[y * data->width + x] = '0';
	data->map[y * data->width + x] = -data->map[y * data->width + x];
	floodfill(data, x + 1, y);
	floodfill(data, x - 1, y);
	floodfill(data, x, y + 1);
	floodfill(data, x, y - 1);
}

void	get_player_position(t_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (is_char_in_string(data->map[i * data->width + j], PLAYERCHAR))
			{
				*y = i;
				*x = j;
				data->player.rotation = 90 * get_char_index(\
					data->map[i * data->width + j], PLAYERCHAR);
				map_pos_to_world_pos(*y, *x, &data->player.pos);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	map_refacto(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y * data->width + x] == '0'
				|| data->map[y * data->width + x] == '1')
				data->map[y * data->width + x] = ' ';
			else if (data->map[y * data->width + x] != ' ')
				data->map[y * data->width + x] = -data->map[
					y * data->width + x];
			x++;
		}
		y++;
	}
}

void	validity_map_check(t_data *data)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	get_player_position(data, &player_x, &player_y);
	floodfill(data, player_x, player_y);
	if (data->err)
		safe_exit(data);
}
