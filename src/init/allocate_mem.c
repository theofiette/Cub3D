/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:52:15 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/17 10:47:46 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	*ft_malloc(t_data *data, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		set_error(data, ERR_MALLOC_PROBLEM);
	return (ptr);
}

void	*ft_calloc_(t_data *data, size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb && (size > (__SIZE_MAX__ / nmemb)))
		return (NULL);
	ptr = ft_malloc(data, nmemb * size);
	if (data->err)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
