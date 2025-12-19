/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:55:04 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/26 17:42:24 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error(t_data *data)
{
	if (data->err)
		ft_putstr_fd(data->error_tab[data->err], 2);
}

void	set_error(t_data *data, enum e_error err)
{
	data->err = err;
}

int	safe_exit(t_data *data)
{
	clean_textures(data);
	clean_mlx(data);
	clean_map(data);
	print_error(data);
	exit(data->err);
	return (42);
}
