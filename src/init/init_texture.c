/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:14:11 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/16 18:47:17 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	assign_img(t_data *data, t_texture *texture, char *path)
{
	texture->texture_ptr = mlx_xpm_file_to_image(data->mlx_data.mlx,
			path, &texture->w,
			&texture->h);
	if (!texture->texture_ptr)
		set_error(data, ERR_MALLOC_PROBLEM);
	texture->addr = mlx_get_data_addr(texture->texture_ptr,
			&texture->bits_per_pixel, \
			&texture->line_length, &texture->endian);
	if (!texture->addr)
		set_error(data, ERR_MALLOC_PROBLEM);
}

void	load_textures(t_data *data)
{
	assign_img(data, &data->textures.gunshot, "ASSETS/gunshot.xpm");
	assign_img(data, &data->textures.gun, "ASSETS/Gun_v2.xpm");
	assign_img(data, &data->textures.bullet, "ASSETS/bullet.xpm");
	assign_img(data, &data->textures.door,
		"ASSETS/temp_slidable_door_512.xpm");
	assign_img(data, &data->textures.game_over,
		"ASSETS/game_over.xpm");
	assign_img(data, &data->textures.zombie[0], "ASSETS/z0.xpm");
	assign_img(data, &data->textures.zombie[1], "ASSETS/z1.xpm");
	assign_img(data, &data->textures.zombie[2], "ASSETS/z2.xpm");
	assign_img(data, &data->textures.zombie[3], "ASSETS/z3.xpm");
	assign_img(data, &data->textures.zombie[4], "ASSETS/z4.xpm");
	assign_img(data, &data->textures.zombie[5], "ASSETS/z5.xpm");
	assign_img(data, &data->textures.zombie[6], "ASSETS/z6.xpm");
	assign_img(data, &data->textures.zombie[7], "ASSETS/z7.xpm");
	assign_img(data, &data->textures.zombie[8], "ASSETS/z8.xpm");
	assign_img(data, &data->textures.zombie[9], "ASSETS/z9.xpm");
	assign_img(data, &data->textures.zombie[10], "ASSETS/z10.xpm");
	assign_img(data, &data->textures.zombie[11], "ASSETS/z_hit.xpm");
	assign_img(data, &data->textures.zombie[12],
		"ASSETS/z_dead_1.xpm");
	assign_img(data, &data->textures.zombie[13],
		"ASSETS/z_dead_2.xpm");
}

void	init_texture(t_textures *textures)
{
	ft_bzero(textures, sizeof(*textures));
}
