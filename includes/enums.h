/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:51:58 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 13:58:34 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum	e_keybind
{
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_W = 13,
	KEY_ESC = 53,
	SPRINT = 257,
	SPACE = 49,
	L_AR = 123,
	R_AR = 124,
	KEY_P = 35
};

enum	e_errors
{
	ARGS = 1,
	MALLOC,
	MLX_INIT,
	MLX_WIN,
	MAP_NOT_FOUND,
	CLOSE_FILE,
	BAD_EXTENSION,
	READ,
	EMPTY_FILE_CUB,
	TEXTURE_NORTH,
	TEXTURE_SOUTH,
	TEXTURE_EAST,
	TEXTURE_WEST,
	MAP,
	COLOR_F,
	COLOR_C,
	MAP_FORBIDDEN_CHAR,
	PATH_NO_DUPLI,
	PATH_SO_DUPLI,
	PATH_WE_DUPLI,
	PATH_EA_DUPLI,
	COLOR_F_DUPLI,
	COLOR_C_DUPLI,
	NO_PLAYER_MAP,
	TOO_MANY_PLAYER,
	MAP_NOT_CLOSE,
	RGB_COMMA,
	RGB_MAX,
	INIT_IMG,
	PARSE_CF,
	MAX_FLOAT,
	CUB_FORMAT
};

#endif