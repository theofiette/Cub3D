/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:45:13 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delta_time(t_data *data)
{
	struct timeval			time;
	static struct timeval	last;
	static int				init_delta;

	gettimeofday(&time, 0);
	if (!init_delta)
	{
		gettimeofday(&last, 0);
		srand((int)last.tv_sec);
		init_delta = !init_delta;
	}
	else
	{
		data->cache[DELTA] = (time.tv_sec - last.tv_sec) + \
		(time.tv_usec - last.tv_usec) / 1000000.0f;
		last = time;
	}
}

void	compute_headbob(t_data *data)
{
	float			headbob_freq;
	float			headbob_amp;
	static float	headbob_time = 0.0f;

	headbob_freq = 12.0f;
	headbob_amp = 4.0f;
	if (data->binary_input
		&& data->binary_input < 15
		&& data->binary_input != 3
		&& data->binary_input != 12)
	{
		headbob_time += data->cache[DELTA];
		data->cache[HEADBOB] = sin(headbob_time * headbob_freq) * headbob_amp;
	}
	else
	{
		headbob_time = 0;
		data->cache[HEADBOB] = 0;
	}
}
