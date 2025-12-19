/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:34:42 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:57:27 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enums.h"
# include "macros.h"

typedef struct s_dict
{
	const char	*key;
	int			value;
}	t_dict;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_player
{
	int		hp;
	float	timer;
	float	pos[2];
	float	rotation;
	float	direction[2];
	float	velocity[2];
	int		pan;
	float	speed;
	float	pan_speed;
	int		ammo;
	int		is_reloading;
	float	reload_timer;
	int		has_shot;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	layers[LAYERS_NBR];
}	t_mlx_data;

typedef struct s_texture
{
	void	*texture_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}	t_texture;

typedef struct s_textures
{
	t_texture	gun;
	t_texture	gunshot;
	t_texture	bullet;
	t_texture	door;
	t_texture	zombie[14];
	t_texture	sprites[TEXTURES_NBR];
	t_texture	game_over;
}	t_textures;

typedef struct s_dda_floor
{
	float	step[2];
	float	floor[2];
	float	row_dist;
	int		z_dist;
	int		cell[2];
	int		texture_coord[2];
	int		curr_row;
	int		curr_column;
	int		blender;
	int		color;
}	t_dda_floor;

typedef struct s_render_walls
{
	float	wall_coord;
	float	texture_pos;
	int		texture_x;
	int		texture_y;
	float	texture_step;
	float	start[2];
	float	end[2];
}	t_render_walls;

typedef struct s_dda
{
	float	dist_tab[(int)WIN_WIDTH];
	int		line;
	int		pos[2];
	float	ray[2];
	float	ray_dir[2];
	float	dist[2];
	int		step[2];
	float	target_angle;
	float	angle_step;
	float	raw_dist;
	float	perp_dist;
	float	final_dist;
	float	door_dist;
	int		side;
	int		sprite_count;
}	t_dda;

typedef struct s_zombie
{
	int		index;
	int		is_shot;
	int		is_hit;
	int		is_dead;
	int		hp;
	int		is_visible;
	int		map_pos[2];
	float	pos[2];
	float	dist;
	float	raw_dist;
	float	ray_dir[2];
	float	relative_pos[2];
	float	timer;
	int		curr_frame;
	int		base_frame;
	float	target[2];
}	t_zombie;

typedef struct s_render_zomb
{
	int			texture_pos[2];
	int			curr_x;
	int			curr_y;
	int			start[2];
	int			end[2];
	int			screen_x;
	int			sprite_size;
	float		texture_step;
	float		lower;
	t_zombie	*z;
}	t_render_zomb;

typedef struct s_door
{
	float	close;
	int		pos[2];
}	t_door;

typedef struct s_data
{
	char			binary_input;
	int				game_over;
	float			cache[CACHE_COUNT];
	int				zombie_nbr;
	t_zombie		z_tab[ZOMBIE_MAX_NBR];
	t_door			d_tab[DOOR_MAX_NBR];
	int				door_nbr;
	int				height;
	int				width;
	char			*map;
	t_mlx_data		mlx_data;
	t_textures		textures;
	t_player		player;
	t_render_walls	render;
	enum e_error	err;
	char			*error_tab[ERR_NUMBER];
}	t_data;

typedef struct s_info
{
	int		keep_file;
	char	*name;
	int		random;
	int		map_size;
	int		room_number;
	int		randomness;
}	t_info;

#endif