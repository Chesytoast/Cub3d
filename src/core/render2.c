/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:30:37 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/25 13:04:15 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	the_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		if (!(x > WIN_WIDTH - MM_WIDTH + 5 && y < MM_HEIGHT - 5) \
		|| data->key->key_spc)
		{
			dst = data->main_screen->addr + (y * \
			data->main_screen->line_len + x * \
			(data->main_screen->bpp / 8));
			*(unsigned int *)dst = color;
		}
		else 
		{
			dst = data->main_screen->addr + (y * \
			data->main_screen->line_len + x * \
			(data->main_screen->bpp / 8));
			*(unsigned int *)dst = -1;
		}
	}
}

void	render_map_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_HEIGHT)
	{
		j = (WIN_WIDTH - MM_WIDTH);
		while (j < WIN_WIDTH)
		{
			if (i < 5 || i > MM_HEIGHT - 5 || j > WIN_WIDTH - 5 \
			|| j < WIN_WIDTH - MM_WIDTH + 5)
				the_mlx_pixel_put(data, j, i, H_YELLOW);
			j++;
		}
		i++;
	}
}

int	draw_ray(t_data *data, t_ray *ray, int color)
{
	int		pixels;
	int		i;
	float	deltax;
	float	deltay;

	deltax = ray->vx * ray->dist_true * TILE_PX;
	deltay = ray->vy * ray->dist_true * TILE_PX;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	i = 0;
	while (pixels)
	{
		if (data->player->pos_x * TILE_PX + (deltax * i) < \
		data->map->max_width * TILE_PX && data->player->pos_x * TILE_PX + \
		(deltax * i) > 0 && data->player->pos_y * TILE_PX + \
		(deltay * i) > 0 && data->player->pos_y * TILE_PX + (deltay * i) \
		< data->map->height * TILE_PX)
			my_mlx_pixel_put(data, data->player->pos_x * TILE_PX + \
			(deltax * i), data->player->pos_y * TILE_PX + (deltay * i), color);
		i++;
		pixels--;
	}
	return (0);
}

void	true_distance(t_ray *ray)
{
	if ((ray->distx > ray->disty && ray->disty != 0) || ray->distx == 0)
	{
		ray->dist_true = ray->disty;
		if (ray->vx > 0)
			ray->texture = 'E';
		else
			ray->texture = 'W';
	}
	else
	{
		ray->dist_true = ray->distx;
		if (ray->vy > 0)
			ray->texture = 'S';
		else
			ray->texture = 'N';
	}
}

void	ray_fct(t_data *data)
{
	t_ray	ray;
	int		i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		init_ray(data->player->angle + (FOV * RAD) / 2 - (float)i / WIN_WIDTH * \
		(FOV * RAD), &ray);
		ray_collision(data, &ray);
		true_distance(&ray);
		if (!data->key->key_spc)
			draw_ray(data, &ray, H_WHITE);
		ray.dist_true = ray.dist_true * cos(ray.angle - data->player->angle);
		raycast(data, &ray, i);
		i++;
	}
}
