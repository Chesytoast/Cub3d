/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:58:47 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 15:26:08 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_data_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->map)
		errors(data, MAP_NOT_FOUND);
	if (!data->mlx)
		errors(data, MLX_INIT);
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!data->mlx_win)
		errors(data, MLX_WIN);
	init_key(data);
	init_img(data);
	init_textures(data);
	data->player->pos_x += 0.5;
	data->player->pos_y += 0.5;
	mlx_mouse_hide();
	mlx_mouse_move(data->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_loop_hook(data->mlx, &render, data);
	mlx_hook(data->mlx_win, 17, 0, red_cross, data);
	mlx_hook(data->mlx_win, 02, 1L << 0, &key_press, data);
	mlx_hook(data->mlx_win, 03, 2L << 0, &key_release, data);
	mlx_loop(data->mlx);
}

static void	init_struct_map(t_data *data, const char *path)
{
	size_t	size_file;
	char	*file;
	char	**cp_map;

	size_file = size_of_file(data, path);
	fill_file_var(data, path, &file, size_file);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		errors(data, MALLOC);
	ft_memset(data->map, 0, sizeof(t_map));
	fill_params_map_var(data, file, 0, 0);
	ft_free((void **)&file);
	check_if_var_s_map_exist(data);
	check_character_map_and_init_player_pos_y_x(data);
	if (!data->player->direction)
		errors(data, NO_PLAYER_MAP);
	cp_map = copy_map(data);
	check_wall_map(data, cp_map,
		data->player->pos_y, data->player->pos_x);
	free_tab(cp_map);
	convert_str_hex(data, data->map->color_f, -1);
	convert_str_hex(data, data->map->color_c, -1);
}

static void	init_player_struct(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		errors(data, MALLOC);
	ft_memset(data->player, 0, sizeof(t_player));
}

static void	init_struct(t_data *data, const char *path)
{
	init_player_struct(data);
	init_struct_map(data, path);
	init_data_mlx(data);
}

int	main(int argc, const char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		errors(&data, ARGS);
	check_extension_map(&data, argv[1]);
	init_struct(&data, argv[1]);
	return (0);
}
