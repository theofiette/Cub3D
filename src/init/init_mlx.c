/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:34:23 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:56:16 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	instanciate_img(t_image *layer, t_mlx_data *mlx_data, t_data *data)
{
	int	i;

	i = 0;
	while (i < LAYERS_NBR && !data->err)
	{
		if (i < MINIMAP)
			layer->img = mlx_new_image(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT);
		else
			layer->img = mlx_new_image(mlx_data->mlx, \
				data->cache[MAP_W], data->cache[MAP_H]);
		if (!layer->img)
		{
			set_error(data, ERR_MALLOC_PROBLEM);
			break ;
		}
		layer->addr = mlx_get_data_addr(layer->img, &layer->bits_per_pixel, \
			&layer->line_length, &layer->endian);
		layer++;
		i++;
	}
}

void	instanciate_mlx(t_mlx_data *mlx_data, t_data *data)
{
	ft_bzero(mlx_data, sizeof(*mlx_data));
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		set_error(data, ERR_MALLOC_PROBLEM);
	instanciate_img(mlx_data->layers, mlx_data, data);
	if (data->err)
		safe_exit(data);
}

void	instanciate_window(t_mlx_data *mlx_data, t_data *data)
{
	mlx_data->win = mlx_new_window(
			mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!mlx_data->win)
		set_error(data, ERR_MALLOC_PROBLEM);
	if (data->err)
		safe_exit(data);
}
