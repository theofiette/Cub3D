/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:46:51 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/17 10:47:55 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocate_map(t_data *data)
{
	data->map = ft_calloc_(data, \
		((data->height * data->width) + 1), sizeof(*data->map));
	if (data->err)
	{
		set_error(data, ERR_MALLOC_PROBLEM);
		safe_exit(data);
	}
}
