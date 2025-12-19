/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:33:13 by tfiette           #+#    #+#             */
/*   Updated: 2025/11/30 19:14:27 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float	ft_fclamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float	ft_fclamp_loop(float value, float min, float max)
{
	if (value < min)
		return (max - (min - value));
	if (value > max)
		return (min + (value - max));
	return (value);
}

void	map_pos_to_world_pos(int map_y, int map_x, float (*world_pos)[2])
{
	(*world_pos)[1] = map_y + 0.5;
	(*world_pos)[0] = map_x + 0.5;
}
