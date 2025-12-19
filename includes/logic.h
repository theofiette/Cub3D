/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:53:03 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/17 16:59:03 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

//Handler
void		delta_time(t_data *data);
void		compute_headbob(t_data *data);

int			handle_input_press(int input, t_data *data);
int			handle_input_release(int input, t_data *data);
int			handle_mouse_input(int input, int x, int y, t_data *data);
void		apply_inputs(t_data *data);

//Player
void		reset_hp(t_data *data);
void		rotate_player(t_data *data, t_player *player);
void		move_player(t_data *data, t_player *player);

//Player Reloading
void		start_reloading(t_data *data);
void		update_reloading(t_data *data);
void		set_gun_data_reload(t_data *data, float *h);

//Door
void		door_manager(t_data *data);

//Zombie
void		zombie_manager(t_data *data);
void		zombie_set_target_player(t_zombie *zombie, float pos[2]);
void		zombie_set_target_random(
				t_data *data, t_zombie *zombie, int max_step);
int			has_zombie_reached_target(float pos[2], float target[2]);
void		update_zombie(t_data *data, t_dda *var, float dist, int i);
int			check_player_hit(t_data *data, float z_pos[2]);
void		check_zombie_hit(t_data *data, t_zombie *zombie);

#endif