/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:20:18 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/13 16:38:57 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input_press(int input, t_data *data)
{
	if (!input)
		return (0);
	if (input == XK_Escape)
		safe_exit(data);
	else if (input == 119)
		data->binary_input |= (1 << UP);
	else if (input == 115)
		data->binary_input |= (1 << DOWN);
	else if (input == 97)
		data->binary_input |= (1 << LEFT);
	else if (input == 100)
		data->binary_input |= (1 << RIGHT);
	return (0);
}

int	handle_input_release(int input, t_data *data)
{
	if (!input)
		return (0);
	else if (input == 119)
		data->binary_input &= ~(1 << UP);
	else if (input == 115)
		data->binary_input &= ~(1 << DOWN);
	else if (input == 97)
		data->binary_input &= ~(1 << LEFT);
	else if (input == 100)
		data->binary_input &= ~(1 << RIGHT);
	return (0);
}

int	handle_mouse_input(int input, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (data->player.is_reloading)
		return (0);
	if (input == 1 && data->player.ammo)
	{
		data->player.ammo--;
		data->binary_input |= (1 << SHOT);
	}
	else
		data->binary_input &= ~(1 << SHOT);
	if (input == 3)
		data->binary_input |= (1 << RELOAD);
	return (0);
}

void	apply_inputs(t_data *data)
{
	data->player.direction[0] = 0;
	data->player.direction[1] = 0;
	data->player.pan = 0;
	if (!data->binary_input)
		return ;
	if (data->binary_input & (1 << UP))
		data->player.direction[1] -= 1;
	if (data->binary_input & (1 << DOWN))
		data->player.direction[1] += 1;
	if (data->binary_input & (1 << LEFT))
		data->player.direction[0] -= 1;
	if (data->binary_input & (1 << RIGHT))
		data->player.direction[0] += 1;
	if (data->binary_input & (1 << RELOAD))
	{
		if (data->player.is_reloading == 0)
			start_reloading(data);
		else
			update_reloading(data);
	}
}
