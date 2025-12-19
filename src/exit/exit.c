/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:33:08 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/10 15:28:54 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < LAYERS_NBR)
	{
		if (data->mlx_data.layers[i].img)
			mlx_destroy_image(data->mlx_data.mlx, data->mlx_data.layers[i].img);
		i++;
	}
}

void	clean_mlx(t_data *data)
{
	clear_img(data);
	if (data->mlx_data.win)
		mlx_destroy_window(data->mlx_data.mlx, data->mlx_data.win);
	if (data->mlx_data.mlx)
	{
		mlx_destroy_display(data->mlx_data.mlx);
		ft_free_(&data->mlx_data.mlx);
	}
}

void	clean_map(t_data *data)
{
	if (data->map)
		free(data->map);
}

void	check_parsing_error(t_data *data, int map_file)
{
	if (data->err)
	{
		close(map_file);
		safe_exit(data);
	}
}
