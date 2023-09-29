/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_in_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:30:14 by aabda             #+#    #+#             */
/*   Updated: 2023/09/22 12:46:04 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_new_line(char *str)
{
	int	i;
	int	nl;

	i = -1;
	nl = 0;
	while (str && str[++i])
		if (str[i] == '\n')
			++nl;
	if (!str[i] && str[i - 1] != '\n')
		++nl;
	return (nl);
}

static int	i_to_backslash_n(char *buffer, int *i)
{
	int	len;

	len = 0;
	while (buffer && buffer[*i] && buffer[*i] != '\n')
	{
		++len;
		++(*i);
	}
	*i -= len;
	return (len);
}

static char	*create_one_line(t_data *data, char *buffer, int len_line, int *i)
{
	char	*str;
	int		j;

	str = malloc(sizeof(char) * len_line + 1);
	if (!str)
		errors(data, MALLOC);
	j = 0;
	while (buffer && buffer[*i] && buffer[*i] != '\n')
	{
		str[j] = buffer[*i];
		++(*i);
		++j;
	}
	str[j] = '\0';
	return (str);
}

void	create_map_in_struct(t_data *data, char *buffer, int i)
{
	int	j;
	int	nl;
	int	len_line;

	nl = count_new_line(buffer);
	if (!nl)
		errors(data, MAP);
	data->map->height = nl;
	if (data->map->max_width >= MAXFLOAT)
		errors(data, MAX_FLOAT);
	data->map->map = malloc(sizeof(char *) * (nl + 1));
	if (!data->map->map)
		errors(data, MALLOC);
	j = 0;
	while (buffer && buffer[++i])
	{
		len_line = i_to_backslash_n(buffer, &i);
		data->map->map[j] = create_one_line(data, buffer, len_line, &i);
		++j;
		if (j == nl)
			break ;
	}
	data->map->map[j] = NULL;
	ft_free((void **)&buffer);
}
