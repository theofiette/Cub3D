/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:28:23 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/11 12:30:44 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_tex(t_data *data, t_texture *tex)
{
	if (tex->texture_ptr)
	{
		mlx_destroy_image(
			data->mlx_data.mlx, tex->texture_ptr);
	}
}

void	clean_textures(t_data *data)
{
	int	i;

	i = 0;
	while (data && i < TEXTURES_NBR)
	{
		if (data->textures.sprites[i].texture_ptr)
		{
			mlx_destroy_image(
				data->mlx_data.mlx, data->textures.sprites[i].texture_ptr);
		}
		i++;
	}
	clean_tex(data, &data->textures.door);
	clean_tex(data, &data->textures.game_over);
	clean_tex(data, &data->textures.gun);
	clean_tex(data, &data->textures.gunshot);
	clean_tex(data, &data->textures.bullet);
	i = 0;
	while (i < 14)
		clean_tex(data, &data->textures.zombie[i++]);
}
