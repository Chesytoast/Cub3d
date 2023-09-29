/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:25:45 by mcourtin          #+#    #+#             */
/*   Updated: 2023/09/29 15:22:50 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	which_signv(t_data *data, t_ray *ray, float *len)
{
	if (ray->vx < 0)
	{
		ray->fv_x = (int)data->player->pos_x;
		*len = data->player->pos_x - ray->fv_x;
		return (-1);
	}
	else
	{
		ray->fv_x = (int)data->player->pos_x + 1;
		*len = ray->fv_x - data->player->pos_x;
		return (1);
	}
}

float	assign_disty(t_data *data, t_ray *ray)
{
	return (sqrt((ray->endv_x - data->player->pos_x) \
	* (ray->endv_x - data->player->pos_x) + (ray->endv_y - \
	data->player->pos_y) * (ray->endv_y - data->player->pos_y)));
}

void	find_disty(t_data *data, t_ray *ray, int sign)
{
	while (1)
	{
		if (ray->vx > 0)
		{
			if (ray->endv_y > data->map->height - 1 || \
			ray->endv_x <= 0 || ray->endv_y <= 0 || \
			ray->endv_x > ft_strlen(data->map->map[(int)ray->endv_y]) || \
			data->map->map[(int)ray->endv_y][(int)ray->endv_x] == '1' || \
			data->map->map[(int)ray->endv_y][(int)ray->endv_x - 1] == ' ')
				break ;
		}
		else
		{
			if (ray->endv_y > data->map->height - 1 || \
			ray->endv_x <= 0 || ray->endv_y <= 0 || \
			ray->endv_x > ft_strlen(data->map->map[(int)ray->endv_y]) || \
			data->map->map[(int)ray->endv_y][(int)ray->endv_x - 1] == '1' || \
			data->map->map[(int)ray->endv_y][(int)ray->endv_x - 1] == ' ')
				break ;
		}
		ray->endv_x += sign;
		ray->endv_y += ray->deltay;
	}
	ray->disty = assign_disty(data, ray);
}

void	collision_vertical(t_data *data, t_ray *ray)
{
	float	len;
	float	nb_v;
	int		sign;

	sign = which_signv(data, ray, &len);
	nb_v = len / ray->vx;
	nb_v = fabs(nb_v);
	ray->fv_y = nb_v * ray->vy + data->player->pos_y ;
	if (ray->fv_y > data->map->height || ray->fv_y < 0)
	{
		ray->fv_x = 0;
		ray->deltay = 0;
		return ;
	}
	else
		ray->deltay = tan(ray->angle);
	ray->deltay = fabs(ray->deltay);
	if (ray->vy < 0)
		ray->deltay *= -1;
	ray->endv_x = ray->fv_x;
	ray->endv_y = ray->fv_y;
	find_disty(data, ray, sign);
}
