/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:55:20 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/12 16:10:08 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bgra_to_argb(unsigned char (*color)[4])
{
	unsigned char	temp;

	temp = (*color)[3];
	(*color)[3] = (*color)[0];
	(*color)[0] = temp;
	temp = (*color)[2];
	(*color)[2] = (*color)[1];
	(*color)[1] = temp;
}

__attribute__((always_inline)) int	shadow(int pixel, int inv)
{
	unsigned int	rb;
	unsigned int	g;

	inv = 255 - inv;
	rb = (pixel & 0x00FF00FF) * inv >> 8;
	g = (pixel & 0x0000FF00) * inv >> 8 & 0x0000FF00;
	return ((rb & 0x00FF00FF) | g);
}

__attribute__((always_inline)) int	shadow_red(int pixel, int inv)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	inv = 255 - inv;
	r = ((pixel >> 16) & 0xFF) * inv >> 8;
	g = ((pixel >> 8) & 0xFF) * inv >> 9;
	b = (pixel & 0xFF) * inv >> 9;
	r += r >> 5;
	if (r > 255)
	r = 255;
	return ((r << 16) | (g << 8) | b);
}

__attribute__((always_inline)) void	set_shadow(
	t_data *data, int *color, int blender)
{
	if (data->player.hp <= 1)
		*color = shadow_red(*color, blender);
	else
		*color = shadow(*color, blender);
}

__attribute__((always_inline)) int	blend(int bg, int fg, int alpha)
{
	unsigned int	inv;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	inv = 255 - alpha;
	r = (((bg >> 16 & 0xFF) * inv + (fg >> 16 & 0xFF) * alpha) >> 8) << 16;
	g = (((bg >> 8 & 0xFF) * inv + (fg >> 8 & 0xFF) * alpha) >> 8) << 8;
	b = (((bg & 0xFF) * inv + (fg & 0xFF) * alpha) >> 8);
	return (r | g | b);
}
