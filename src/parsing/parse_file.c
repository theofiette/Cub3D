/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:01:11 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/02 17:01:21 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_empty_lines(t_data *data, int map_file)
{
	char	*line;
	int		gnl_success;

	gnl_success = 0;
	line = get_next_line(map_file, &gnl_success);
	while (line)
	{
		if (line && is_empty(line))
		{
			free(line);
			line = get_next_line(map_file, &gnl_success);
		}
		else
			break ;
	}
	if (!line && gnl_success)
		set_error(data, ERR_MALLOC_PROBLEM);
	check_parsing_error(data, map_file);
	return (line);
}

void	get_map_loop(t_data *data, int map_file)
{
	char	*line;
	int		gnl_success;

	gnl_success = 0;
	line = skip_empty_lines(data, map_file);
	while (line)
	{
		ft_strlcat_cub(data->map, line, (data->width * data->height) + 1, data);
		free(line);
		line = get_next_line(map_file, &gnl_success);
	}
	if (!line && gnl_success)
		set_error(data, ERR_MALLOC_PROBLEM);
	close(map_file);
	if (data->err)
		safe_exit(data);
}

static inline void	check_ce_fl_dimensions(t_data *data)
{
	if ((data->textures.sprites[CE].h != data->textures.sprites[FL].h)
		|| (data->textures.sprites[CE].w != data->textures.sprites[FL].w))
		set_error(data, ERR_DIMENSION);
}

void	get_color_and_texture_loop(t_data *data, int map_file)
{
	char	*line;
	int		gnl_success;
	int		count;

	count = 0;
	gnl_success = 0;
	while (!count || line)
	{
		line = get_next_line(map_file, &gnl_success);
		if (!line && gnl_success)
		{
			set_error(data, ERR_MALLOC_PROBLEM);
			break ;
		}
		else if (line)
		{
			if (match_texture_id(line, data, 0, 1))
				count ++;
		}
		free(line);
		if (count == TEXTURES_NBR)
			break ;
	}
	check_ce_fl_dimensions(data);
	check_parsing_error(data, map_file);
}

void	parse_file(t_data *data, char *str)
{
	int	map_file;

	map_file = open(str, O_RDONLY);
	allocate_map(data);
	get_color_and_texture_loop(data, map_file);
	get_map_loop(data, map_file);
	validity_map_check(data);
}
