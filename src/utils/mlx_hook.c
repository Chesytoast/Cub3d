/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 23:11:23 by aabda             #+#    #+#             */
/*   Updated: 2023/09/25 12:27:45 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_key(t_data *data)
{
	data->key = malloc(sizeof(t_key));
	if (!data->key)
		errors(data, MALLOC);
	data->key->key_w = false;
	data->key->key_a = false;
	data->key->key_s = false;
	data->key->key_d = false;
	data->key->key_la = false;
	data->key->key_ra = false;
	data->key->key_spc = false;
	data->key->key_p = false;
	data->key->sprint = 1;
}

static void	pause_fct(t_data *data)
{
	data->key->key_p = !data->key->key_p;
	if (data->key->key_p)
		mlx_mouse_show();
	else
	{
		mlx_mouse_hide();
		mlx_mouse_move(data->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_W)
		data->key->key_w = true;
	if (keycode == KEY_A)
		data->key->key_a = true;
	if (keycode == KEY_S)
		data->key->key_s = true;
	if (keycode == KEY_D)
		data->key->key_d = true;
	if (keycode == L_AR)
		data->key->key_la = true;
	if (keycode == R_AR)
		data->key->key_ra = true;
	if (keycode == SPRINT)
		data->key->sprint = SS;
	if (keycode == SPACE)
		data->key->key_spc = !data->key->key_spc;
	if (keycode == KEY_P)
		pause_fct(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key->key_w = false;
	if (keycode == KEY_A)
		data->key->key_a = false;
	if (keycode == KEY_S)
		data->key->key_s = false;
	if (keycode == KEY_D)
		data->key->key_d = false;
	if (keycode == L_AR)
		data->key->key_la = false;
	if (keycode == R_AR)
		data->key->key_ra = false;
	if (keycode == SPRINT)
		data->key->sprint = 1;
	return (0);
}

int	red_cross(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}
