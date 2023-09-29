/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:45:23 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/21 16:29:03 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_north_texture(t_data *data)
{
	data->north_texture = malloc(sizeof(t_img));
	if (!data->north_texture)
		errors(data, MALLOC);
	data->north_texture->mlx_img = mlx_xpm_file_to_image(data->mlx, \
	data->map->path_no, &data->north_texture->width, \
	&data->north_texture->height);
	if (!data->north_texture->mlx_img)
		errors(data, INIT_IMG);
	data->north_texture->bpp = 0;
	data->north_texture->line_len = 0;
	data->north_texture->endian = 0;
	data->north_texture->addr = mlx_get_data_addr(data->north_texture->mlx_img, \
	&data->north_texture->bpp, &data->north_texture->line_len, \
	&data->north_texture->endian);
	if (!data->north_texture->addr)
		errors(data, INIT_IMG);
}

void	init_south_texture(t_data *data)
{
	data->south_texture = malloc(sizeof(t_img));
	if (!data->south_texture)
		errors(data, MALLOC);
	data->south_texture->mlx_img = mlx_xpm_file_to_image(data->mlx, \
	data->map->path_so, &data->south_texture->width, \
	&data->south_texture->height);
	if (!data->south_texture->mlx_img)
		errors(data, INIT_IMG);
	data->south_texture->bpp = 0;
	data->south_texture->line_len = 0;
	data->south_texture->endian = 0;
	data->south_texture->addr = mlx_get_data_addr(data->south_texture->mlx_img, \
	&data->south_texture->bpp, &data->south_texture->line_len, \
	&data->south_texture->endian);
	if (!data->south_texture->addr)
		errors(data, INIT_IMG);
}

void	init_east_texture(t_data *data)
{
	data->east_texture = malloc(sizeof(t_img));
	if (!data->east_texture)
		errors(data, MALLOC);
	data->east_texture->mlx_img = mlx_xpm_file_to_image(data->mlx, \
	data->map->path_ea, &data->east_texture->width, \
	&data->east_texture->height);
	if (!data->east_texture->mlx_img)
		errors(data, INIT_IMG);
	data->east_texture->bpp = 0;
	data->east_texture->line_len = 0;
	data->east_texture->endian = 0;
	data->east_texture->addr = mlx_get_data_addr(data->east_texture->mlx_img, \
	&data->east_texture->bpp, &data->east_texture->line_len, \
	&data->east_texture->endian);
	if (!data->east_texture->addr)
		errors(data, INIT_IMG);
}

void	init_west_texture(t_data *data)
{
	data->west_texture = malloc(sizeof(t_img));
	if (!data->west_texture)
		errors(data, MALLOC);
	data->west_texture->mlx_img = mlx_xpm_file_to_image(data->mlx, \
	data->map->path_we, &data->west_texture->width, \
	&data->west_texture->height);
	if (!data->west_texture->mlx_img)
		errors(data, INIT_IMG);
	data->west_texture->bpp = 0;
	data->west_texture->line_len = 0;
	data->west_texture->endian = 0;
	data->west_texture->addr = mlx_get_data_addr(data->west_texture->mlx_img, \
	&data->west_texture->bpp, &data->west_texture->line_len, \
	&data->west_texture->endian);
	if (!data->west_texture->addr)
		errors(data, INIT_IMG);
}

void	init_textures(t_data *data)
{
	init_north_texture(data);
	init_south_texture(data);
	init_west_texture(data);
	init_east_texture(data);
}
