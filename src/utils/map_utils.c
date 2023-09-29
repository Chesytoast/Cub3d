/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:08:44 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 11:40:04 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_extension_map(t_data *data, const char *path)
{
	if (path[ft_strlen(path) - 4] != '.'
		|| path[ft_strlen(path) - 3] != 'c'
		|| path[ft_strlen(path) - 2] != 'u'
		|| path[ft_strlen(path) - 1] != 'b')
		errors(data, BAD_EXTENSION);
}

size_t	size_of_file(t_data *data, const char *path)
{
	char	buffer;
	size_t	count;
	int		res;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		errors(data, MAP_NOT_FOUND);
	res = 1;
	count = 0;
	while (res > 0)
	{
		res = read(fd, &buffer, 1);
		if (res < 0)
			errors(data, READ);
		count += res;
	}
	if (close(fd) < 0)
		errors(data, CLOSE_FILE);
	if (!count)
		errors(data, EMPTY_FILE_CUB);
	return (count);
}

void	fill_file_var(t_data *data, const char *path, \
	char **file, size_t size_file)
{
	int		fd;
	char	buffer;
	int		res;
	int		i;

	*file = malloc(sizeof(char) * size_file + 1);
	if (!(*file))
		errors(data, MALLOC);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		errors(data, MAP_NOT_FOUND);
	res = 1;
	i = 0;
	while (res > 0)
	{
		res = read(fd, &buffer, 1);
		if (res < 0)
			errors(data, READ);
		(*file)[i++] = buffer;
	}
	(*file)[--i] = '\0';
	if (close(fd) < 0)
		errors(data, CLOSE_FILE);
}

char	**copy_map(t_data *data)
{
	char	**cp_map;
	int		i;

	cp_map = malloc(sizeof(char *) * (data->map->height + 1));
	if (!cp_map)
		errors(data, MALLOC);
	i = -1;
	data->map->max_width = ft_strlen(data->map->map[0]);
	while (data->map->map[++i])
	{
		if ((int)ft_strlen(data->map->map[i]) > data->map->max_width)
			data->map->max_width = ft_strlen(data->map->map[i]);
		cp_map[i] = ft_strdup(data->map->map[i]);
	}
	cp_map[i] = NULL;
	if (data->map->max_width >= MAXFLOAT)
		errors(data, MAX_FLOAT);
	return (cp_map);
}

void	convert_str_hex(t_data *data, char *color_fc, int i)
{
	int		rgb[3];
	int		hex_color;
	char	**str_rgb;

	str_rgb = ft_split(data, color_fc, ',');
	if (!str_rgb)
		errors(data, MALLOC);
	while (str_rgb[++i])
		;
	if (i != 3)
		errors(data, RGB_COMMA);
	check_output_color_cf(data, str_rgb);
	rgb[0] = ft_atoi(str_rgb[0]);
	rgb[1] = ft_atoi(str_rgb[1]);
	rgb[2] = ft_atoi(str_rgb[2]);
	if ((rgb[0] < 0 || rgb[0] > 255)
		|| (rgb[1] < 0 || rgb[1] > 255)
		|| (rgb[2] < 0 || rgb[2] > 255))
		errors(data, RGB_MAX);
	hex_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	if (data->map->color_f == color_fc)
		data->map->hex_f = hex_color;
	else
		data->map->hex_c = hex_color;
	free_tab(str_rgb);
}
