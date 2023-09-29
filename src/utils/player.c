/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:43:02 by aabda             #+#    #+#             */
/*   Updated: 2023/09/21 15:21:27 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	s_player_fill_pos_direction(t_data *data, int x, int y)
{
	static int	player = 0;

	if (data->map->map[y][x] == 'N' || data->map->map[y][x] == 'S'
		|| data->map->map[y][x] == 'W' || data->map->map[y][x] == 'E')
	{
		data->player->pos_y = y;
		data->player->pos_x = x;
		data->player->direction = data->map->map[y][x];
		if (data->player->direction == 'N')
			data->player->angle = PI / 2;
		if (data->player->direction == 'E')
			data->player->angle = 0;
		if (data->player->direction == 'W')
			data->player->angle = PI;
		if (data->player->direction == 'S')
			data->player->angle = 3 * PI / 2;
		++player;
		calculate_vector(data);
	}
	if (player > 1)
		errors(data, TOO_MANY_PLAYER);
}
