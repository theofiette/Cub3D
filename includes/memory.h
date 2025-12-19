/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:33:39 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:36:35 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

//Init
void	init_data(t_data *data);
void	load_textures(t_data *data);
void	init_texture(t_textures *textures);
void	allocate_map(t_data *data);
void	instanciate_mlx(t_mlx_data *mlx_data, t_data *data);
void	instanciate_window(t_mlx_data *mlx_data, t_data *data);
void	check_and_instantiate_zombies(t_data *data);
void	check_and_instantiate_doors(t_data *data);

//Cleaning
void	clean_mlx(t_data *data);
void	clean_map(t_data *data);
void	clean_textures(t_data *data);

#endif
