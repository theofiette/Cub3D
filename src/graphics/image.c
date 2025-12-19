/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:53:08 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/19 13:46:00 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

__attribute__((always_inline)) inline void	img_pix_put_rgb(
	t_image *img, int x, int y, unsigned char color[4])
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + (x * img->bits_per_pixel / 8));
	pixel[0] = color[0];
	pixel[1] = color[1];
	pixel[2] = color[2];
	pixel[3] = color[3];
}

__attribute__((always_inline)) inline void	img_pix_put_hex(
	t_image *img, int x, int y, int color)
{
	((int *)(img->addr + y * img->line_length))[x] = color;
}

__attribute__((always_inline)) inline void	draw_map_line_to_img_ver_door(
	t_image *img, float start[2], float end[2])
{
	float	steps[2];
	float	start_x;

	steps[1] = 0;
	steps[0] = end[0] - start[0];
	start_x = start[0];
	while (steps[1]++ < steps[0])
	{
		if (start_x - start[0] + TILE_SIZE + start[0]
			- end[0] < (TILE_SIZE / 2) - (TILE_SIZE / 8) || \
			start_x - start[0] + TILE_SIZE + start[0] - end[0]
			> (TILE_SIZE / 2) + (TILE_SIZE / 8))
			img_pix_put_hex(img, start_x, start[1], MAP_FLOOR_COLOR);
		start_x++;
	}
}

__attribute__((always_inline)) inline void	draw_map_line_to_img(
	t_image *img, float start[2], float end[2])
{
	int		steps[2];
	float	start_x;

	steps[1] = 0;
	steps[0] = end[0] - start[0];
	start_x = start[0];
	while (steps[1]++ < steps[0])
	{
		img_pix_put_hex(img, start_x, start[1], MAP_FLOOR_COLOR);
		start_x++;
	}
}

__attribute__((always_inline)) inline void	draw_line_to_img_hex(
	t_image *img, float start[2], float end[2], int color)
{
	float	steps[2];
	float	vec_incr[2];
	float	vec_img[2];

	if (fabsf(end[0] - start[0]) > fabsf(end[1] - start[1]))
		steps[0] = fabsf(end[0] - start[0]);
	else
		steps[0] = fabsf(end[1] - start[1]);
	vec_incr[0] = (end[0] - start[0]) / steps[0];
	vec_incr[1] = (end[1] - start[1]) / steps[0];
	vec_img[0] = start[0];
	vec_img[1] = start[1];
	steps[1] = 0;
	while (steps[1]++ < steps[0])
	{
		img_pix_put_hex(img, vec_img[0], vec_img[1], color);
		vec_img[0] += vec_incr[0];
		vec_img[1] += vec_incr[1];
	}
}
