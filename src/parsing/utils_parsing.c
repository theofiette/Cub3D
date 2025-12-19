/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:25:57 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/16 18:31:05 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ext_check(char *str, t_data *data)
{
	char	*ext;
	int		map_len;

	map_len = ft_strlen(str);
	ext = str + map_len - 4;
	if (map_len < 4 || ft_strncmp(ext, ".cub", 4))
		set_error(data, ERR_INV_FILE_EXT);
	else if (access(str, F_OK))
		set_error(data, ERR_INV_FILE_FOK);
	else if (access(str, R_OK))
		set_error(data, ERR_INV_FILE_ROK);
	if (data->err)
		safe_exit(data);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	simple_atoi(const char *line)
{
	long int	res;

	if (!ft_isdigit(*line))
	{
		return (-1);
	}
	res = 0;
	while (*line && ft_isdigit(*line))
	{
		res = res * 10 + (*line - '0');
		if (res < 0 || res >= 2147483647)
			return (-1);
		line++;
	}
	return (res);
}

int	is_empty(char *str)
{
	if (str[0])
		return (0);
	return (1);
}
