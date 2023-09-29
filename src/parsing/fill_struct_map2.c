/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:26:17 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 13:59:37 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	s_map_check_and_fill_params2(t_data *data, char *file, size_t *i)
{
	if (file[*i] == 'E' && file[*i + 1] == 'A' && file[*i + 2] == ' ')
	{
		if (data->map->path_ea)
			errors(data, PATH_EA_DUPLI);
		else
			s_map_patern_fill_params(data, &data->map->path_ea, file, i);
	}
	if (file[*i] == 'F' && file[*i + 1] == ' '
		&& ft_isdigit(file[*i + 2]))
	{
		if (data->map->color_f)
			errors(data, COLOR_F_DUPLI);
		else
			s_map_patern_fill_params(data, &data->map->color_f, file, i);
	}
	if (file[*i] == 'C' && file[*i + 1] == ' '
		&& ft_isdigit(file[*i + 2]))
	{
		if (data->map->color_c)
			errors(data, COLOR_C_DUPLI);
		else
			s_map_patern_fill_params(data, &data->map->color_c, file, i);
	}
}

static void	check_garbage(t_data *data, char *file, size_t *i)
{
	while (file && file[*i] == '\n')
		++(*i);
	if (!(file[*i] == 'N' && file[*i + 1] == 'O' && file[*i + 2] == ' ')
		&& !(file[*i] == 'S' && file[*i + 1] == 'O' && file[*i + 2] == ' ')
		&& !(file[*i] == 'W' && file[*i + 1] == 'E' && file[*i + 2] == ' ')
		&& !(file[*i] == 'E' && file[*i + 1] == 'A' && file[*i + 2] == ' ')
		&& !(file[*i] == 'C' && file[*i + 1] == ' ' \
		&& ft_isdigit(file[*i + 2]))
		&& !(file[*i] == 'F' && file[*i + 1] == ' ' \
		&& ft_isdigit(file[*i + 2])))
		errors(data, CUB_FORMAT);
}

void	s_map_check_and_fill_params(t_data *data, char *file, size_t *i)
{
	check_garbage(data, file, i);
	if (file[*i] == 'N' && file[*i + 1] == 'O' && file[*i + 2] == ' ')
	{
		if (data->map->path_no)
			errors(data, PATH_NO_DUPLI);
		else
			s_map_patern_fill_params(data, &data->map->path_no, file, i);
	}
	if (file[*i] == 'S' && file[*i + 1] == 'O' && file[*i + 2] == ' ')
	{
		if (data->map->path_so)
			errors(data, PATH_SO_DUPLI);
		else
			s_map_patern_fill_params(data, &data->map->path_so, file, i);
	}
	if (file[*i] == 'W' && file[*i + 1] == 'E' && file[*i + 2] == ' ')
	{
		if (data->map->path_we)
			errors(data, PATH_WE_DUPLI);
		else
			s_map_patern_fill_params(data, &data->map->path_we, file, i);
	}
	s_map_check_and_fill_params2(data, file, i);
}
