/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:32:18 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:36:49 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	get_texture(char *line, t_texture *texture, t_data *data);
void	get_color_and_texture_loop(t_data *data, int map_file);
void	get_map_loop(t_data *data, int map_file);
void	map_refacto(t_data *data);
void	parse_file(t_data *data, char *str);
void	check_parsing_error(t_data *data, int map_file);

//Validity Check
void	ext_check(char *str, t_data *data);
void	check_map_file(char *str, t_data *data);
void	check_textures(const char *line, int texture_id,
			int is_complete, t_data *data);
int		simple_atoi(const char *line);
void	check_color_and_texture(char *line, t_data *data, int *found_map);
int		match_texture_id(
			char *line, t_data *data, int valid_check, int set_data);
void	validity_map_check(t_data *data);

#endif