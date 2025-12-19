/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:13:07 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/17 10:45:59 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char *ptr)
{
	if (ptr)
		free(ptr);
}

char	*ft_get_line(char *buffer, char *read_line, size_t read, char *keep)
{
	char		*temp;

	if (read == 0)
		return (NULL);
	temp = 0;
	if (!keep && !read_line)
		temp = ftt_strjoin("", buffer);
	else if (read_line)
	{
		temp = ftt_strjoin(read_line, buffer);
		free(read_line);
	}
	else if (keep)
	{
		temp = ftt_strjoin(keep, buffer);
		if (!temp)
			return (free(read_line), NULL);
	}
	return (temp);
}

static char	*read_loop(int fd, char *keep, int *check_free)
{
	char	*buffer;
	int		read_check;
	char	*read_line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (keep[0] = 0, NULL);
	read_line = NULL;
	read_check = 1;
	while (!check_endl(read_line) && read_check > 0)
	{
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (!read_line && read_check == 0 && keep[0])
			return (free(buffer), read_line = ft_strjoin("", keep));
		if (read_check < 0)
			return (free(buffer), free(read_line), keep[0] = 0, keep);
		buffer[read_check] = 0;
		if (read_check == 0 && read_line)
			return (free(buffer), read_line);
		read_line = ft_get_line(buffer, read_line, read_check, keep);
		if (!read_line)
			return (free(buffer), \
			(*check_free = 1 * (0 + read_check != 0)), NULL);
	}
	return (free(buffer), read_line);
}

char	*get_next_line(int fd, int *check_free)
{
	static char	keep[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	char		*read_line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	line = 0;
	read_line = read_loop(fd, keep, check_free);
	if (!read_line || !read_line[0])
		return (NULL);
	keep[0] = 0;
	line = copy_endl(read_line);
	if (!line)
		return (free(read_line), *check_free = 1, NULL);
	temp = trim_temp(read_line);
	if (!temp)
		return (ft_free(read_line), *check_free = 1, free(line), NULL);
	else if (!temp[0])
		return (free(temp), line);
	else
		ft_strlcpy(keep, temp, ft_strlen(temp) + 1);
	return (free(temp), ft_free(read_line), line);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main (int argc, char **argv)
// {
// 	int fd;
// 	(void)argc;
// 	(void)argv;
// 	char *res;
// 	// if (argc == 2)
// 	// {
// 		fd = open(argv[1], O_RDONLY);
// 	// 	while (i++ < 2)
// 	// 	{
// 			printf("Ligne 1 : %s",res = get_next_line(fd));
// 			free(res);
// 			printf("Ligne 2 : %s",res = get_next_line(fd));
// 			free(res);
// 	// 	}
// 	// }
// 	return (0);
// }
