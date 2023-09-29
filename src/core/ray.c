/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:15:45 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/29 15:23:23 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(float angle, t_ray *ray)
{
	ray->angle = angle;
	ray->vx = cos(angle);
	ray->vy = sin(angle) * -1;
	ray->distx = 0;
	ray->disty = 0;
	ray->dist_true = 0;
}

int	which_signh(t_data *data, t_ray *ray, float *len)
{
	if (ray->vy < 0)
	{
		ray->fh_y = (int)data->player->pos_y - 1;
		*len = ray->fh_y - data->player->pos_y + 1;
		return (-1);
	}
	else
	{
		ray->fh_y = (int)data->player->pos_y + 1;
		*len = ray->fh_y - data->player->pos_y;
		return (1);
	}
}

void	find_distx(t_data *data, t_ray *ray, int sign)
{
	while (1)
	{
		if (ray->endh_x > ft_strlen(data->map->map[(int)ray->endh_y]) \
		|| ray->endh_x <= 0 \
		|| ray->endh_y <= 0 || ray->endh_y > data->map->height || \
		data->map->map[(int)ray->endh_y][(int)ray->endh_x] == '1' || \
		data->map->map[(int)ray->endh_y][(int)ray->endh_x] == ' ')
			break ;
		ray->endh_x += ray->deltax;
		ray->endh_y += sign;
	}
	if (sign == -1)
		ray->endh_y -= sign;
	ray->distx = sqrt((ray->endh_x - data->player->pos_x) \
	* (ray->endh_x - data->player->pos_x) + (ray->endh_y - \
	data->player->pos_y) * (ray->endh_y - data->player->pos_y));
}

void	collision_horizontal(t_data *data, t_ray *ray)
{
	float	len;
	float	nb_v;
	int		sign;

	sign = which_signh(data, ray, &len);
	nb_v = len / ray->vy;
	nb_v = fabs(nb_v);
	ray->fh_x = nb_v * ray->vx + data->player->pos_x;
	if (ray->fh_x > data->map->max_width || ray->fh_x < 0)
	{
		ray->fh_x = data->player->pos_x;
		ray->deltax = 0;
		return ;
	}
	else
		ray->deltax = 1 / tan(ray->angle);
	ray->deltax = fabs(ray->deltax);
	if (ray->vx < 0)
		ray->deltax *= -1;
	ray->endh_x = ray->fh_x;
	ray->endh_y = ray->fh_y;
	find_distx(data, ray, sign);
}

void	ray_collision(t_data *data, t_ray *ray)
{
	collision_horizontal(data, ray);
	collision_vertical(data, ray);
}
