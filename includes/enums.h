/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:31:29 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:07:17 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum e_inputs
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SHOT,
	RELOAD
};

enum e_textures
{
	NO,
	SO,
	EA,
	WE,
	CE,
	FL
};

enum e_layers
{
	VIEWPORT,
	MINIMAP
};

enum e_cache
{
	MID_WIDTH,
	MID_HEIGHT,
	MAP_W,
	MAP_H,
	CURSOR_X,
	CURSOR_Y,
	CURSOR_LEN,
	TILE_NBR_X,
	TILE_NBR_Y,
	MID_TILE_X,
	MID_TILE_Y,
	DELTA,
	HEADBOB,
	FOV_STEP
};

enum e_error
{
	ERR_SUCCESS,
	ERR_INV_ARGUMENT_COUNT,
	ERR_INV_FILE_EXT,
	ERR_INV_FILE_FOK,
	ERR_INV_FILE_ROK,
	ERR_INV_TEXTURE_FOK,
	ERR_INV_TEXTURE_ROK,
	ERR_INV_TEXTURE_COUNT,
	ERR_INV_COLOR_COUNT,
	ERR_INV_RGB_FORMAT,
	ERR_MISSING_MAP_INFO,
	ERR_INV_PLAYER_COUNT,
	ERR_INV_MAP_CHAR,
	ERR_DIMENSION,
	ERR_DOOR,
	ERR_MAP_OPEN,
	ERR_ZOMBIE_NBR,
	ERR_DOOR_NBR,
	ERR_MALLOC_PROBLEM
};

#endif