/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:55:32 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 14:01:21 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	s_map_patern_fill_params(t_data *data, char **fill, char *str, \
		size_t *index)
{
	int	len;
	int	i;
	int	j;
	int	tmp;

	len = 0;
	if (str && (str[*index] == 'F' || str[*index] == 'C'))
		i = *index + 1;
	else
		i = *index + 2;
	tmp = i;
	while (str && str[++i] && str[i] != '\n')
		++len;
	*fill = malloc(sizeof(char) * len + 1);
	if (!(*fill))
		errors(data, MALLOC);
	i = tmp;
	j = 0;
	while (str && str[++i] && str[i] != '\n')
		(*fill)[j++] = str[i];
	(*fill)[j] = '\0';
	*index = i;
}

static void	map_err(char *file, size_t index)
{
	char	*s;
	int		i;

	i = -1;
	s = &file[index];
	ft_putstr_fd(2, "\033[1m\033[31mError\n\033[0m");
	ft_putstr_fd(2, ERR_MAP_FORBIDDEN_CHAR);
	ft_putchar_fd(2, '\n');
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '1'
			&& s[i] != '0' && s[i] != 'N'
			&& s[i] != 'S' && s[i] != 'E'
			&& s[i] != 'W')
		{
			ft_putstr_fd(2, BOLDRED);
			ft_putchar_fd(2, s[i]);
			ft_putstr_fd(2, RESET);
		}
		else
			ft_putchar_fd(2, s[i]);
	}
	ft_putchar_fd(2, '\n');
}

static size_t	len_rest(t_data *data, char *file, size_t i, size_t *save_i)
{
	size_t	len;
	int		backslash_n;

	len = 0;
	backslash_n = *save_i;
	while (file && file[++i])
	{
		if (file[i] == '\n')
			backslash_n = i;
		if (ft_isdigit(file[i]) || file[i] == ' ' || file[i] == 'N' 
			|| file[i] == 'S' || file[i] == 'E' || file[i] == 'W')
			break ;
		else
		{
			map_err(file, i);
			errors(data, MAP_FORBIDDEN_CHAR);
		}
	}
	if (backslash_n != (int)*save_i)
		*save_i = backslash_n + 1;
	else
		--backslash_n;
	while (file[++backslash_n])
		++len;
	return (len);
}

static char	*fill_rest(t_data *data, char *file, size_t *i)
{
	char	*buffer;
	size_t	len;
	size_t	save_i;
	size_t	j;

	if (!file || !file[*i])
		return (NULL);
	--(*i);
	while (file[++(*i)] && file[*i] == '\n')
		;
	if (!file[*i])
		return (NULL);
	save_i = *i;
	len = len_rest(data, file, *i - 1, &save_i);
	buffer = malloc(sizeof(char) * len + 1);
	if (!buffer)
		errors(data, MALLOC);
	*i = save_i;
	j = 0;
	while (file && file[*i])
		buffer[j++] = file[(*i)++];
	buffer[j] = '\0';
	return (buffer);
}

void	fill_params_map_var(t_data *data, char *file, size_t i, size_t save_i)
{
	char	*buffer;

	while (file && file[i])
	{
		if (file[i] && file[i] == '\n')
			++i;
		s_map_check_and_fill_params(data, file, &i);
		if (file[i] && data->map->path_no && data->map->path_so
			&& data->map->path_we && data->map->path_ea
			&& data->map->color_f && data->map->color_c)
		{
			if (!save_i)
				save_i = i;
			break ;
		}
		if (!file[i])
			break ;
		++i;
	}
	i = save_i;
	buffer = fill_rest(data, file, &i);
	if (!buffer)
		return ;
	create_map_in_struct(data, buffer, -1);
}
