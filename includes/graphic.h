/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:49:13 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 16:01:51 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

//HUD
void		draw_crosshair(t_data *data);
void		render_hud(t_data *data);

void		render_view_vertical_line_black(t_data *data, t_dda *var);
void		render_view_vertical_line(t_data *data, t_dda *var);
void		assign_wall_coord(t_data *data, t_dda *var);
void		assign_texture_cache(
				t_data *data, float start[2], float end[2], t_texture *sprite);
void		assign_drawing_point(t_data *data, float dist, int x);

void		init_dda(
				t_dda *var, float player_dir[2], float perp[2], t_data *data);

//Minimap
void		render_minimap(t_data *data);
void		next_tile(int *gap, int *index);
void		draw_doors_minimap(
				t_data *data, int index[2], int offset[2], int gap[2]);
void		draw_floor_loop(
				t_image *img, t_data *data, int offset[2], int p_wpos[2]);
void		draw_minimap_background(t_image *img, t_image *bg, t_data *data);
int			check_edges(char *temp, t_image *img, int coord[2], t_data *data);
void		outline_walls(t_image *img, t_data *data);	
void		draw_minimap_cursor_arm(t_image *img, t_data *data, int sign);

//3D View
void		render_view(t_data *data);
float		dda(t_data *data, t_dda *var);
void		dda_init(t_data *data, t_dda *var);
void		floor_dda(t_data *data, float player_dir[2], float perp[2]);
void		wall_dda(
				t_data *data, t_dda *var, float player_dir[2], float perp[2]);
int			try_render_door_line(t_data *data, t_dda *var, int pos[2]);
void		assign_texture_cache_door(
				t_data *data, float start[2], float end[2], t_texture *sprite);
void		pick_zombie_texture(
				t_texture **sprite, t_data *data, t_render_zomb *render, int i);
void		render_zombie_loop(t_data *data, t_dda *var);
t_zombie	*render_zombie_core(t_data *data, t_dda *var, int i);
void		draw_gun(t_data *data, int *img, float h, int w);
void		draw_gunshot(t_data *data);

#endif
