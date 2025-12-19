/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:46:30 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/19 12:51:41 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_char_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_char_index(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_char_invalid(char c)
{
	int	i;

	i = 0;
	while (VALIDCHAR[i])
	{
		if (c == VALIDCHAR[i])
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlcat_cub(char *dst, const char *src, int siz, t_data *data)
{
	int	i;
	int	dest_len;
	int	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (siz <= dest_len || siz == 0)
		return (src_len + siz);
	i = 0;
	while (src[i] && (dest_len + i) < siz - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	while (i < data->width)
	{
		dst[dest_len + i] = ' ';
		i++;
	}
	dst[dest_len + i] = 0;
	return (dest_len + src_len);
}
