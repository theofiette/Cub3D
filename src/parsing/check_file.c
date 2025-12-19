/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:25:53 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/28 16:56:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_line(char *line, int is_complete, t_data *data)
{
	static int	player;

	if (is_complete)
	{
		if (player != 1)
			set_error(data, ERR_INV_PLAYER_COUNT);
		return ;
	}
	while (*line)
	{
		if (!is_char_in_string(*line, VALIDCHAR))
		{
			set_error(data, ERR_INV_MAP_CHAR);
			return ;
		}
		else if (is_char_in_string(*line, PLAYERCHAR))
		{
			player++;
		}
		line++;
	}
}

void	check_map(char *line, int is_complete, t_data *data)
{
	static int	x;
	static int	y;

	if (is_complete)
	{
		data->height = x;
		data->width = y;
		return ;
	}
	check_map_line(line, 0, data);
	if (data->err)
		return ;
	x++;
	if (y < (int)ft_strlen(line))
		y = ft_strlen(line);
}

static inline void	check_line(char *line, int *found_map, t_data *data)
{
	if (*line == '\0' && !*found_map)
		return ;
	if (!*found_map)
	{
		check_color_and_texture(line, data, found_map);
		if (data->err || !*found_map)
			return ;
	}
	check_map(line, 0, data);
	return ;
}

static void	check_map_file_loop(int map_fd, t_data *data)
{
	int		gnl_success;
	char	*line;
	int		found_map;

	gnl_success = 0;
	found_map = 0;
	while (!data->err)
	{
		line = get_next_line(map_fd, &gnl_success);
		if (!line)
		{
			if (gnl_success)
				set_error(data, ERR_MALLOC_PROBLEM);
			break ;
		}
		check_line(line, &found_map, data);
		free(line);
	}
	if (!found_map && !data->err)
		set_error(data, ERR_MISSING_MAP_INFO);
	else if (!data->err)
	{
		check_map_line(NULL, 1, data);
		check_map(NULL, 1, data);
	}
}

void	check_map_file(char *str, t_data *data)
{
	int	map_file;

	map_file = open(str, O_RDONLY);
	check_map_file_loop(map_file, data);
	close(map_file);
	if (data->err)
		safe_exit(data);
}
