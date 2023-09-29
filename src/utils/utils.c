/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:46:39 by aabda             #+#    #+#             */
/*   Updated: 2023/09/21 16:48:19 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free(void **value)
{
	if (*value)
	{
		free(*value);
		*value = NULL;
	}
}

void	free_tab(char **map)
{
	int	i;

	i = -1;
	while (map && map[++i])
		ft_free((void **)&map[i]);
	ft_free((void **)&map);
}

static void	free_s_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map)
		free_tab(map->map);
	if (map->path_no)
		ft_free((void **)&map->path_no);
	if (map->path_so)
		ft_free((void **)&map->path_so);
	if (map->path_we)
		ft_free((void **)&map->path_we);
	if (map->path_ea)
		ft_free((void **)&map->path_ea);
	if (map->color_f)
		ft_free((void **)&map->color_f);
	if (map->color_c)
		ft_free((void **)&map->color_c);
	ft_free((void **)&map);
}

static void	free_img(t_data *data, t_img *img)
{
	if (!img)
		return ;
	if (img->mlx_img)
		mlx_destroy_image(data->mlx, img->mlx_img);
	ft_free((void **)&img);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_s_map(data->map);
	if (data->player)
		ft_free((void **)&data->player);
	if (data->key)
		ft_free((void **)&data->key);
	if (data->mini_map)
		free_img(data, data->mini_map);
	if (data->main_screen)
		free_img(data, data->main_screen);
	if (data->north_texture)
		free_img(data, data->north_texture);
	if (data->south_texture)
		free_img(data, data->south_texture);
	if (data->east_texture)
		free_img(data, data->east_texture);
	if (data->west_texture)
		free_img(data, data->west_texture);
	if (data->mlx_win)
		mlx_clear_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_window(data->mlx, data->mlx_win);
}
