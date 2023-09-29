/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:11:04 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 13:58:05 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	errors_tab(int res)
{
	static const char	*tab[] = {
		ERR_ARG, ERR_MALLOC, ERR_MLX_INIT, ERR_MLX_WIN, ERR_MAP_NOT_FOUND,
		ERR_CLOSE_FILE, ERR_BAD_EXTENSION, ERR_READ, ERR_EMPTY_FILE_CUB,
		ERR_TEXTURE_NORTH, ERR_TEXTURE_SOUTH, ERR_TEXTURE_EAST,
		ERR_TEXTURE_WEST, ERR_MAP, ERR_COLOR_F, ERR_COLOR_C,
		ERR_MAP_FORBIDDEN_CHAR, ERR_PATH_NO_DUPLI, ERR_PATH_SO_DUPLI,
		ERR_PATH_WE_DUPLI, ERR_PATH_EA_DUPLI, ERR_COLOR_F_DUPLI,
		ERR_COLOR_C_DUPLI, ERR_NO_PLAYER_INIT, ERR_TOO_MANY_PLAYER,
		ERR_MAP_NOT_CLOSE, ERR_RGB_COMMA, ERR_RGB_MAX, ERR_INIT_IMG,
		ERR_PARSE_COLOR_CF, ERR_MAX_FLOAT_BIG, ERR_CUB_FORMAT, NULL
	};

	ft_putstr_fd(2, "\033[1m\033[31mError\n\033[0m");
	ft_putstr_fd(2, tab[res]);
}

void	errors(t_data *data, int err)
{
	if (err != MAP_FORBIDDEN_CHAR)
		errors_tab(--err);
	free_all(data);
	exit(EXIT_FAILURE);
}

void	print_error_char_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map->map[++i])
	{
		j = -1;
		while (data->map->map[i][++j])
		{
			if (data->map->map[i][j] != ' ' && data->map->map[i][j] != '1'
				&& data->map->map[i][j] != '0' && data->map->map[i][j] != 'N'
				&& data->map->map[i][j] != 'S' && data->map->map[i][j] != 'E'
				&& data->map->map[i][j] != 'W')
			{
				ft_putstr_fd(2, BOLDRED);
				ft_putchar_fd(2, data->map->map[i][j]);
				ft_putstr_fd(2, RESET);
			}
			else
				ft_putchar_fd(2, data->map->map[i][j]);
		}
		ft_putchar_fd(2, '\n');
	}
	ft_putchar_fd(2, '\n');
}
