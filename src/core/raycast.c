/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:15:05 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/25 19:05:13 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	my_get_color(t_img *img, t_coord pos, t_ray *ray, int i)
{
	int		color;
	int		x_offset;
	int		y_offset;
	char	*color_add;

	if (ray->texture == 'E' || ray->texture == 'W')
		x_offset = (int)(ray->endv_y * WALL_H) % WALL_H;
	else
		x_offset = (int)(ray->endh_x * WALL_H) % WALL_H;
	if (ray->texture == 'S' || ray->texture == 'W')
		x_offset = WALL_H - 1 - x_offset;
	y_offset = (int)((i - WIN_HEIGHT / 2 + pos.h) * img->height / (2 * pos.h));
	color_add = img->addr + (y_offset * img->line_len + \
	x_offset * (img->bpp / 8));
	color = *(int *)color_add;
	return (color);
}

int	get_height_pxl(t_coord pos)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (i < WIN_HEIGHT)
	{
		if (i > WIN_HEIGHT / 2 - pos.h && i < WIN_HEIGHT / 2 + pos.h)
			height++;
		++i;
	}
	return (height);
}

void	raycast2(t_data *data, t_coord pos, t_img *img, t_ray *ray)
{
	int		i;
	int		color;

	i = 0;
	pos.w_h = get_height_pxl(pos);
	while (i < WIN_HEIGHT)
	{
		if (i > WIN_HEIGHT / 2 - pos.h && i < WIN_HEIGHT / 2 + pos.h)
		{
			color = my_get_color(img, pos, ray, i);
			the_mlx_pixel_put(data, pos.x, i, color);
		}
		else if (i > WIN_HEIGHT / 2)
			the_mlx_pixel_put(data, pos.x, i, data->map->hex_f);
		else
			the_mlx_pixel_put(data, pos.x, i, data->map->hex_c);
		i++;
	}
}

void	raycast(t_data *data, t_ray *ray, int x)
{
	t_coord	pos;
	t_img	*img;

	if (ray->texture == 'N')
		img = data->north_texture;
	if (ray->texture == 'S')
		img = data->south_texture;
	if (ray->texture == 'E')
		img = data->east_texture;
	if (ray->texture == 'W')
		img = data->west_texture;
	pos.h = WALL_H / (ray->dist_true * WALL_H) * CAM;
	pos.x = x;
	raycast2(data, pos, img, ray);
}
