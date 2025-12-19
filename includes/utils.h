/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:01:15 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:37:29 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_isspace(char c);
int		is_char_in_string(char c, char *str);
int		is_empty(char *str);
void	ft_free_(void **ptr);
void	*ft_calloc_(t_data *data, size_t nmemb, size_t size);
void	*ft_malloc(t_data *data, size_t size);
int		get_char_index(char c, char *str);
size_t	ft_strlcat_cub(char *dst, const char *src, int siz, t_data *data);
float	ft_fclamp_loop(float value, float min, float max);
float	ft_fclamp(float value, float min, float max);
int		ft_clamp(int value, int min, int max);
void	map_pos_to_world_pos(int map_y, int map_x, float (*world_pos)[2]);

//Errors
void	set_error(t_data *data, enum e_error err);
int		safe_exit(t_data *data);

//Vectors
void	rotate_vector_by_degrees(int vector[2], int degrees);
void	rotate_float_vector_by_degrees(float vector[2], int degrees);
void	rotate_float_vector_by_float_degrees(float to[2], float degrees);

#endif