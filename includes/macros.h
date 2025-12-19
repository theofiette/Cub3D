/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:33 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 16:19:28 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
*	UI
*/

# define WIN_WIDTH	1920.0f
# define WIN_HEIGHT 1080.0f

# define WIN_TITLE	"CUB3D"

# define MAX_HP			2
# define VIEW			5.0f
# define S_VIEW			7.0f
# define HEADBOB_OFFSET	-4

# define FOV			90.0f
# define MAP_RATIO		6.0f
# define MAP_OFFSET 	20
# define TILE_SIZE 		35.0f

# define MAP_BG_OUTL_COLOR	0x00FDFDFD 
# define MAP_BG_COLOR		0x00202020
# define MAP_PLAYER_COLOR	0x00000000
# define MAP_FLOOR_COLOR	0X00FDF5F5
# define MAP_WALL_COLOR		0x00404040

# define COLOR_SHADOW 0x001f0d0d

# define MAX_SPEED	1.8f
# define MAX_PAN	8.0f
# define PAN_ACCEL 16.0f
# define PAN_DECCEL 25.0f
# define PAN_ACCEL_NO_MOVE 25.0f
# define MAX_PAN_NO_MOVE 12.0f
# define DIRECTION_NORM 0.70710678f
# define ACCEL 10.0f
# define DECCEL 5.0f
# define PLAYER_RADIUS 0.2f
# define ZOMBIE_RADIUS 0.25f
# define ZOMBIE_SPEED 1.0f
# define MOUSE_SENSI 0.04f
# define MAX_AMMO 6
# define RELOAD_TIME 1.5f

# define DEG_TO_RAD	0.017453


# define CACHE_COUNT		14

# define ZOMBIE_MAX_NBR		30
# define DOOR_MAX_NBR		30

# define TEXTURES_NBR		6
# define LAYERS_NBR			3
# define VALIDCHAR			"01NSEW DZ"
# define PLAYERCHAR			"NESW"
# define CROSSABLECHAR		"0 NSEWDZ"

# define DDA_NO_HIT		0
# define DDA_DOOR_HIT	-1
/*
*	UILITY
*/

# define UCHAR		unsigned char

/*
*	ERROR MESSAGES
*/

# define ERR_NUMBER	19
# define PERR_INV_ARGUMENT_COUNT	"Error\nInvalid argument count.\n"
# define PERR_INV_FILE_EXT			"Error\nInvalid file extension.\n"
# define PERR_INV_FILE_FOK			"Error\nCan't find argument given file.\n"
# define PERR_INV_FILE_ROK			"Error\nCan't read argument given file.\n"
# define PERR_INV_TEXTURE_COUNT		"Error\nInvalid number of textures.\n"
# define PERR_INV_COLOR_COUNT		"Error\nInvalid number of RGBs.\n"
# define PERR_INV_TEXTURE_FOK		"Error\nCan't find texture file.\n"
# define PERR_INV_TEXTURE_ROK		"Error\nCan't read texture file.\n"
# define PERR_INV_RGB_FORMAT		"Error\nBad rgb format in file.\n"
# define PERR_MISSING_MAP_INFO		"Error\nMissing map info.\n"
# define PERR_INV_PLAYER_COUNT		"Error\nInvalid number of player(s).\n"
# define PERR_INV_MAP_CHAR			"Error\nInvalid character in map.\n"
# define PERR_DOOR					"Error\nInvalid door position.\n"
# define PERR_MAP_OPEN				"Error\nMap not closed by walls.\n"
# define PERR_DIMENSION			"Error\n\
Ceilling and floor dimensions aren't the same.\n"
# define PERR_ZOMBIE_NBR			"Error\nToo many zombies.\n"
# define PERR_DOOR_NBR			"Error\nToo many doors.\n"
# define PERR_MALLOC_PROBLEM		"Error\nInternal malloc fail.\n"

/*
*	PROMPT USER INFOS
*/

# define PUI_KEEP_FILE		"Do you wanna save the generated file ?"
# define PUI_FILE_NAME		"Enter file name or leave empty... > "
# define PUI_FULL_RANDOM	"Do you want to skip map personalization ?"
# define PUI_MAP_SIZE		"How big should the map be ?"
# define PUI_ROOM_NBR		"How many rooms should there be ?"
# define PUI_RANDOMNESS		"How crazy should the generation go ? [1-9] > "

#endif