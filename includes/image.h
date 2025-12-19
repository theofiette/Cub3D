/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:35:36 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:46:00 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

//Colors
void	bgra_to_argb(unsigned char (*color)[4]);
int		blend(int bg, int fg, int alpha);
int		shadow(int c, int k);
void	set_shadow(t_data *data, int *color, int blender);

//Image
void	img_pix_put_rgb(t_image *img, int x, int y, unsigned char color[4]);
void	img_pix_put_hex(t_image *img, int x, int y, int color);
void	draw_line_to_img_hex(
			t_image *img, float start[2], float end[2], int color);
void	draw_map_line_to_img(
			t_image *img, float start[2], float end[2]);
void	draw_map_line_to_img_ver_door(
			t_image *img, float start[2], float end[2]);

#endif
