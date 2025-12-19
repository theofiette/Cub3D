/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiette <tfiette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:26:00 by tchevall          #+#    #+#             */
/*   Updated: 2025/12/19 13:55:14 by tfiette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validity_check(int argc, char **argv, t_data *data)
{
	if (argc != 2)
	{
		set_error(data, ERR_INV_ARGUMENT_COUNT);
		safe_exit(data);
	}
	ext_check(argv[1], data);
	check_map_file(argv[1], data);
}

static inline int	core_loop(t_data *data)
{
	delta_time(data);
	apply_inputs(data);
	if (!data->game_over)
	{
		reset_hp(data);
		rotate_player(data, &data->player);
		move_player(data, &data->player);
		compute_headbob(data);
	}
	render_view(data);
	zombie_manager(data);
	door_manager(data);
	render_hud(data);
	return (0);
}

static void	process(t_data *data)
{
	mlx_loop_hook(data->mlx_data.mlx, &core_loop, data);
	mlx_hook(data->mlx_data.win, KeyPress, \
		KeyPressMask, &handle_input_press, data);
	mlx_hook(data->mlx_data.win, KeyRelease, \
		KeyReleaseMask, &handle_input_release, data);
	mlx_hook(data->mlx_data.win, 4, 1L << 2, &handle_mouse_input, data);
	mlx_hook(data->mlx_data.win, DestroyNotify, 0, &safe_exit, data);
	mlx_loop(data->mlx_data.mlx);
}

static inline void	preprocess(int argc, char **argv, t_data *data)
{
	init_data(data);
	validity_check(argc, argv, data);
	instanciate_mlx(&data->mlx_data, data);
	init_texture(&data->textures);
	parse_file(data, argv[1]);
	map_refacto(data);
	check_and_instantiate_doors(data);
	check_and_instantiate_zombies(data);
	load_textures(data);
	instanciate_window(&data->mlx_data, data);
	XFixesHideCursor(((t_xvar *)data->mlx_data.mlx)->display,
		((t_win_list *)data->mlx_data.win)->window);
	mlx_mouse_move(data->mlx_data.mlx, data->mlx_data.win,
		data->cache[MID_WIDTH], data->cache[MID_HEIGHT]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	preprocess(argc, argv, &data);
	process(&data);
	safe_exit(&data);
	return (data.err);
}
