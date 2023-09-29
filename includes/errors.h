/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:55:20 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 13:57:24 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARG "Invalid number of argument !\n./cub3D maps/map[X].cub\n"
# define ERR_MALLOC "Impossible to use malloc function !\n"
# define ERR_MLX_INIT "Impossible to init MLX !\n"
# define ERR_MLX_WIN "Impossible to create the window !\n"
# define ERR_MAP_NOT_FOUND "[MAP] - Wrong path or map doesn't exist !\n"
# define ERR_CLOSE_FILE "[CLOSE] - Impossible to close the file descriptor !\n"
# define ERR_BAD_EXTENSION "Bad extension, the extension need to be \".cub\"!\n"
# define ERR_READ "[READ] - Impossible to use the function read !\n"
# define ERR_EMPTY_FILE_CUB "[FILE] - The .cub file is empty !\n"
# define ERR_TEXTURE_NORTH "Missing texture north !\n"
# define ERR_TEXTURE_SOUTH "Missing texture south !\n"
# define ERR_TEXTURE_EAST "Missing texture east !\n"
# define ERR_TEXTURE_WEST "Missing texture west !\n"
# define ERR_MAP "Missing map !\n"
# define ERR_COLOR_F "Missing color of the floor !\n"
# define ERR_COLOR_C "Missing color of the celling !\n"
# define ERR_MAP_FORBIDDEN_CHAR "[MAP] - forbidden characters in the map !\n"
# define ERR_PATH_NO_DUPLI "Only one texture for north is allowed !\n"
# define ERR_PATH_SO_DUPLI "Only one texture for south is allowed !\n"
# define ERR_PATH_WE_DUPLI "Only one texture for west is allowed !\n"
# define ERR_PATH_EA_DUPLI "Only one texture for east is allowed !\n"
# define ERR_COLOR_F_DUPLI "Only one color for the floor is allowed !\n"
# define ERR_COLOR_C_DUPLI "Only one color for the celling is allowed !\n"
# define ERR_NO_PLAYER_INIT "There is no player on your map !\n"
# define ERR_TOO_MANY_PLAYER "There is too many player on the map !\nOnly one \
player is allowed !\n"
# define ERR_MAP_NOT_CLOSE "The map is not totaly close by wall !\n"
# define ERR_RGB_COMMA "Invalid format RGB !\n"
# define ERR_RGB_MAX "Invalid RGB value \
(the value need to be between 0 - 255) !\n"
# define ERR_INIT_IMG "Impossible to init the image !\n"
# define ERR_PARSE_COLOR_CF "Color of the celling or floor need \
only to be digit !\n"
# define ERR_MAX_FLOAT_BIG	"Map is too big\n"
# define ERR_CUB_FORMAT "Bad format .cub file\n"

#endif