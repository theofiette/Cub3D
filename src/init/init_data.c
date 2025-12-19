/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:31:58 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:55:50 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_data_error_tab(t_data *data)
{
	data->error_tab[ERR_INV_ARGUMENT_COUNT] = PERR_INV_ARGUMENT_COUNT;
	data->error_tab[ERR_INV_FILE_EXT] = PERR_INV_FILE_EXT;
	data->error_tab[ERR_INV_FILE_FOK] = PERR_INV_FILE_FOK;
	data->error_tab[ERR_INV_FILE_ROK] = PERR_INV_FILE_ROK;
	data->error_tab[ERR_INV_TEXTURE_COUNT] = PERR_INV_TEXTURE_COUNT;
	data->error_tab[ERR_INV_COLOR_COUNT] = PERR_INV_COLOR_COUNT;
	data->error_tab[ERR_INV_TEXTURE_FOK] = PERR_INV_TEXTURE_FOK;
	data->error_tab[ERR_INV_TEXTURE_ROK] = PERR_INV_TEXTURE_ROK;
	data->error_tab[ERR_INV_RGB_FORMAT] = PERR_INV_RGB_FORMAT;
	data->error_tab[ERR_MISSING_MAP_INFO] = PERR_MISSING_MAP_INFO;
	data->error_tab[ERR_INV_PLAYER_COUNT] = PERR_INV_PLAYER_COUNT;
	data->error_tab[ERR_INV_MAP_CHAR] = PERR_INV_MAP_CHAR;
	data->error_tab[ERR_DOOR] = PERR_DOOR;
	data->error_tab[ERR_MAP_OPEN] = PERR_MAP_OPEN;
	data->error_tab[ERR_DIMENSION] = PERR_DIMENSION;
	data->error_tab[ERR_ZOMBIE_NBR] = PERR_ZOMBIE_NBR;
	data->error_tab[ERR_DOOR_NBR] = PERR_DOOR_NBR;
	data->error_tab[ERR_MALLOC_PROBLEM] = PERR_MALLOC_PROBLEM;
}

void	fill_data_var_tab(t_data *data)
{
	data->cache[MID_WIDTH] = WIN_WIDTH / 2.0f;
	data->cache[MID_HEIGHT] = WIN_HEIGHT / 2.0f;
	data->cache[MAP_W] = WIN_WIDTH / MAP_RATIO;
	data->cache[MAP_H] = WIN_HEIGHT / MAP_RATIO;
	data->cache[CURSOR_X] = data->cache[MAP_W] / 2.0f;
	data->cache[CURSOR_Y] = data->cache[MAP_H] / 2.0f;
	data->cache[CURSOR_LEN] = TILE_SIZE / 2.0f;
	data->cache[TILE_NBR_X] = (int)data->cache[MAP_W] / TILE_SIZE;
	data->cache[TILE_NBR_Y] = (int)data->cache[MAP_H] / TILE_SIZE;
	data->cache[MID_TILE_X] = (int)data->cache[TILE_NBR_X] / 2 + 1;
	data->cache[MID_TILE_Y] = (int)data->cache[TILE_NBR_Y] / 2 + 1;
	data->cache[DELTA] = 0.0f;
	data->cache[HEADBOB] = 0.0f;
	data->cache[FOV_STEP] = 2.0f / WIN_WIDTH;
	data->player.ammo = 6;
	data->player.timer = 0;
	data->player.hp = MAX_HP;
	data->player.is_reloading = 0;
	data->player.reload_timer = 0;
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(*data));
	fill_data_var_tab(data);
	fill_data_error_tab(data);
}
