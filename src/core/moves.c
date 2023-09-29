/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:07:26 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/21 12:06:20 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	modif_position(t_data *data, float x, float y)
{
	if (data->map->map[(int)data->player->pos_y][(int)(x)] != '1' && \
		data->map->map[(int)data->player->pos_y][(int)(x + U_D)] != '1' && \
		data->map->map[(int)data->player->pos_y][(int)(x - U_D)] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)(y)][(int)data->player->pos_x] != '1' && \
	data->map->map[(int)(y + U_D)][(int)data->player->pos_x] != '1' && \
	data->map->map[(int)(y - U_D)][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}

void	movement(t_data *data, float x, float y)
{
	x = data->player->pos_x;
	y = data->player->pos_y;
	if (data->key->key_s == true)
	{
		x += data->player->vx * -1 * U_D * data->key->sprint;
		y += data->player->vy * -1 * U_D * data->key->sprint;
	}
	if (data->key->key_a == true)
	{
		x += cos(data->player->angle + (PI / 2)) * U_D * data->key->sprint;
		y -= sin(data->player->angle + (PI / 2)) * U_D * data->key->sprint;
	}
	if (data->key->key_d == true)
	{
		x += cos(data->player->angle - (PI / 2)) * U_D * data->key->sprint;
		y -= sin(data->player->angle - (PI / 2)) * U_D * data->key->sprint;
	}
	if (data->key->key_w == true)
	{
		x += data->player->vx * U_D * data->key->sprint;
		y += data->player->vy * U_D * data->key->sprint;
	}
	modif_position(data, x, y);
}

void	calculate_vector(t_data *data)
{
	data->player->vx = cos(data->player->angle);
	data->player->vy = sin(data->player->angle) * -1;
}

void	rotate(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx_win, &x, &y);
	if (data->key->key_la)
		data->player->angle += RAD * (RS / 100);
	if (data->key->key_ra)
		data->player->angle -= RAD * (RS / 100);
	if (x < WIN_WIDTH / 2)
		data->player->angle += RAD * MRS * (RS / 100);
	if (x > WIN_WIDTH / 2)
		data->player->angle -= RAD * MRS * (RS / 100);
	mlx_mouse_move(data->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	calculate_vector(data);
}
