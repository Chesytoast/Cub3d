/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:32:45 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/21 16:03:15 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_main_screen(t_data *data)
{
	data->main_screen = malloc(sizeof(t_img));
	if (!data->main_screen)
		errors(data, MALLOC);
	data->main_screen->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, \
	WIN_HEIGHT);
	if (!data->main_screen->mlx_img)
		errors(data, INIT_IMG);
	data->main_screen->bpp = 0;
	data->main_screen->line_len = 0;
	data->main_screen->endian = 0;
	data->main_screen->addr = mlx_get_data_addr(data->main_screen->mlx_img, \
	&data->main_screen->bpp, &data->main_screen->line_len, \
	&data->main_screen->endian);
	if (!data->main_screen->addr)
		errors(data, INIT_IMG);
}

void	init_img(t_data *data)
{
	data->mini_map = malloc(sizeof(t_img));
	if (!data->mini_map)
		errors(data, MALLOC);
	data->mini_map->mlx_img = mlx_new_image(data->mlx, \
	data->map->max_width * TILE_PX, data->map->height * TILE_PX);
	if (!data->mini_map->mlx_img)
		errors(data, INIT_IMG);
	data->mini_map->bpp = 0;
	data->mini_map->line_len = 0;
	data->mini_map->endian = 0;
	data->mini_map->addr = mlx_get_data_addr(data->mini_map->mlx_img, \
	&data->mini_map->bpp, &data->mini_map->line_len, &data->mini_map->endian);
	if (!data->mini_map->addr)
		errors(data, INIT_IMG);
	init_main_screen(data);
}
