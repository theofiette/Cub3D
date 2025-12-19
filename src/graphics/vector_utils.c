/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:07:16 by tfiette           #+#    #+#             */
/*   Updated: 2025/12/10 15:52:11 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
* VECTOR ROTATION MATRIX
* [ cos(a) -sin(a) ]
* [ sin(a)  cos(a) ]
*/
void	rotate_vector_by_degrees(int vector[2], int degrees)
{
	float			radian;
	float			temp[2];
	static float	factor = DEG_TO_RAD;

	radian = (float)degrees * factor;
	temp[0] = (float)vector[0];
	temp[1] = (float)vector[1];
	vector[0] = round(temp[0] * cos(radian)) - (temp[1] * sin(radian));
	vector[1] = round(temp[0] * sin(radian)) + (temp[1] * cos(radian));
}

void	rotate_float_vector_by_degrees(float vector[2], int degrees)
{
	float			radian;
	float			temp[2];
	static float	factor = DEG_TO_RAD;

	radian = (float)degrees * factor;
	temp[0] = vector[0];
	temp[1] = vector[1];
	vector[0] = (temp[0] * cos(radian)) - (temp[1] * sin(radian));
	vector[1] = (temp[0] * sin(radian)) + (temp[1] * cos(radian));
}

void	rotate_float_vector_by_float_degrees(
	float to[2], float degrees)
{
	float	radian;
	float	temp[2];

	temp[0] = to[0];
	temp[1] = to[1];
	radian = degrees * DEG_TO_RAD;
	to[0] = (temp[0] * cos(radian)) - (temp[1] * sin(radian));
	to[1] = (temp[0] * sin(radian)) + (temp[1] * cos(radian));
}
