/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:13:05 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/26 17:39:15 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_endl(char *temp)
{
	int	i;

	i = 0;
	while (temp && temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ftt_strjoin(char *keep, char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc((ft_strlen(buffer) + ft_strlen(keep) + 1) * 1);
	if (!new_str)
		return (0);
	i = 0;
	while (keep[i])
	{
		new_str[i] = keep[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		new_str[i++] = buffer[j++];
	new_str[i] = 0;
	return (new_str);
}

char	*trim_temp(char *read_line)
{
	int		i;
	int		j;
	int		len;
	char	*new_temp;

	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (read_line[i] && read_line[i] == '\n')
		i++;
	if (!read_line[i])
		return (read_line[0] = 0, read_line);
	len = ft_strlen(read_line + i);
	new_temp = malloc((len + 1) * sizeof(char));
	if (!new_temp)
		return (NULL);
	j = 0;
	while (read_line[i])
		new_temp[j++] = read_line[i++];
	new_temp[j] = 0;
	return (new_temp);
}

char	*copy_endl(char *temp)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	while (temp[j] && temp[j] != '\n')
		j++;
	line = malloc((j + (temp[j] == '\n') + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < j)
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
