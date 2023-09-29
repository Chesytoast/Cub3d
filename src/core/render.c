/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:50:02 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/25 13:04:44 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->map->max_width * TILE_PX && y >= 0 && y < \
	data->map->height * TILE_PX)
	{
		dst = data->mini_map->addr + (y * data->mini_map->line_len + x * \
		(data->mini_map->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	render_wall_floor(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_PX)
	{
		j = 0;
		while (j < TILE_PX)
		{
			if (j == 0 || j == TILE_PX - 1 || i == 0 || i == TILE_PX - 1)
				my_mlx_pixel_put(data, (x * TILE_PX) + j, (y * TILE_PX) \
				+ i, 0xDC6400);
			else
				my_mlx_pixel_put(data, (x * TILE_PX) + j, (y * TILE_PX) \
				+ i, color);
			j++;
		}
		i++;
	}
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == '1')
				render_wall_floor(data, j, i, H_BLUE);
			else if (data->map->map[i][j] == ' ')
				;
			else 
				render_wall_floor(data, j, i, H_BROWN);
			j++;
		}
		i++;
	}
}

void	render_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLR_PX)
	{
		j = 0;
		while (j < PLR_PX)
		{
			my_mlx_pixel_put(data, (data->player->pos_x * TILE_PX) + j - \
			PLR_PX / 2, (data->player->pos_y * TILE_PX) + i - PLR_PX / 2, \
			H_RED);
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
	if (!data->key->key_p)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		rotate(data);
		movement(data, data->player->pos_x, data->player->pos_y);
		if (!data->key->key_spc)
		{
			render_map(data);
			render_player(data);
			render_map_border(data);
		}
		ray_fct(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->mini_map->mlx_img, \
		(WIN_WIDTH - MM_WIDTH / 2) - (data->player->pos_x * TILE_PX), \
		(MM_HEIGHT / 2) - (data->player->pos_y * TILE_PX));
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->main_screen->mlx_img, 0, 0);
	}
	return (0);
}
