/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:41:34 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/30 16:24:29 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	match_texture_id(char *line, t_data *data, int valid_check, int set_data)
{
	static t_dict	texture_dict[TEXTURES_NBR + 1] = {
	{"NO", NO},
	{"SO", SO},
	{"EA", EA},
	{"WE", WE},
	{"CE", CE},
	{"FL", FL},
	{NULL, -1}
	};
	int				i;

	i = 0;
	while (texture_dict[i].key != NULL)
	{
		if (!ft_strncmp(texture_dict[i].key, line, 2))
		{
			if (valid_check)
				check_textures(line + 2, texture_dict[i].value, 0, data);
			else if (set_data)
				get_texture(line + 2, data->textures.sprites + i, data);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_textures(
	const char *line, int texture_id, int is_complete, t_data *data)
{
	static int	texture_tab[TEXTURES_NBR];
	static int	texture_count;

	if (is_complete)
	{
		if (texture_count != TEXTURES_NBR)
			set_error(data, ERR_INV_TEXTURE_COUNT);
		return ;
	}
	texture_count++;
	if (texture_count > TEXTURES_NBR)
	{
		set_error(data, ERR_INV_TEXTURE_COUNT);
		return ;
	}
	texture_tab[texture_id]++;
	while (*line && *line == 32)
		line++;
	if (texture_tab[texture_id] > 1)
		set_error(data, ERR_INV_TEXTURE_COUNT);
	else if (line[ft_strlen(line) - 1] == '/' || access(line, F_OK))
		set_error(data, ERR_INV_TEXTURE_FOK);
	else if (access(line, R_OK))
		set_error(data, ERR_INV_TEXTURE_ROK);
}

static void	check_color_and_texture_completude(t_data *data, int *found_map)
{
	check_textures(NULL, 0, 1, data);
	*found_map = 1;
}

void	check_color_and_texture(char *line, t_data *data, int *found_map)
{
	if (!match_texture_id(line, data, 1, 0))
		check_color_and_texture_completude(data, found_map);
}

void	get_texture(char *line, t_texture *texture, t_data *data)
{
	while (*line && *line == ' ')
		line++;
	texture->texture_ptr = mlx_xpm_file_to_image(data->mlx_data.mlx,
			line, &texture->w, &texture->h);
	if (!texture->texture_ptr)
		set_error(data, ERR_MALLOC_PROBLEM);
	else
	{
		texture->addr = mlx_get_data_addr(texture->texture_ptr,
				&texture->bits_per_pixel, &texture->line_length,
				&texture->endian);
		if (!texture->addr)
			set_error(data, ERR_MALLOC_PROBLEM);
	}
}
