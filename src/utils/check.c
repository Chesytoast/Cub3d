/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:09:11 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 15:25:17 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_character_map_and_init_player_pos_y_x(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map->map && data->map->map[++y])
	{
		x = -1;
		while (data->map->map[y][++x])
		{
			if (data->map->map[y][x] != ' ' && data->map->map[y][x] != '1'
				&& data->map->map[y][x] != '0' && data->map->map[y][x] != 'N'
				&& data->map->map[y][x] != 'S' && data->map->map[y][x] != 'E'
				&& data->map->map[y][x] != 'W')
			{
				ft_putstr_fd(2, "\033[1m\033[31mError\n\033[0m");
				ft_putstr_fd(2, ERR_MAP_FORBIDDEN_CHAR);
				ft_putchar_fd(2, '\n');
				print_error_char_map(data);
				errors(data, MAP_FORBIDDEN_CHAR);
			}
			s_player_fill_pos_direction(data, x, y);
		}
	}
}

void	check_if_var_s_map_exist(t_data *data)
{
	if (!data->map->path_no)
		errors(data, TEXTURE_NORTH);
	if (!data->map->path_so)
		errors(data, TEXTURE_SOUTH);
	if (!data->map->path_ea)
		errors(data, TEXTURE_EAST);
	if (!data->map->path_we)
		errors(data, TEXTURE_WEST);
	if (!data->map->color_f)
		errors(data, COLOR_F);
	if (!data->map->color_c)
		errors(data, COLOR_C);
	if (!data->map->map)
		errors(data, MAP);
}

void	check_wall_map(t_data *data, char **map, int y, int x)
{
	int	height;

	height = data->map->height;
	if (x > (int)ft_strlen(map[y]) - 1 || map[y][x] == ' ')
		errors(data, MAP_NOT_CLOSE);
	if (map[y][x] == '1')
		return ;
	if (y == 0 || x == 0 || y == height - 1 || x == (int)ft_strlen(map[y]) - 1)
		errors(data, MAP_NOT_CLOSE);
	map[y][x] = '1';
	check_wall_map(data, map, y + 1, x);
	check_wall_map(data, map, y, x + 1);
	check_wall_map(data, map, y, x - 1);
	check_wall_map(data, map, y - 1, x);
	check_wall_map(data, map, y + 1, x + 1);
	check_wall_map(data, map, y - 1, x + 1);
	check_wall_map(data, map, y + 1, x - 1);
	check_wall_map(data, map, y - 1, x - 1);
}

void	check_output_color_cf(t_data *data, char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab && tab[++i])
	{
		j = -1;
		while (tab[i] && tab[i][++j])
			if (!ft_isdigit(tab[i][j]))
				errors(data, PARSE_CF);
	}
}
