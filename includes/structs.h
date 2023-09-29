/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:03:46 by aabda             #+#    #+#             */
/*   Updated: 2023/09/22 12:21:44 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_key
{
	bool	key_w;
	bool	key_a;
	bool	key_s;
	bool	key_d;
	bool	key_la;
	bool	key_ra;
	bool	key_spc;
	bool	key_p;
	int		sprint;
}	t_key;

typedef struct s_player
{
	char	direction;
	float	angle;
	float	pos_y;
	float	pos_x;
	float	vx;
	float	vy;
	char	texture;
}	t_player;

typedef struct s_map
{
	int		height;
	int		max_width;
	char	**map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*color_f;
	char	*color_c;
	int		hex_f;
	int		hex_c;
}	t_map;

typedef struct s_ray
{
	float	angle;
	float	vx;
	float	vy;
	float	fh_x;
	float	fh_y;
	float	fv_x;
	float	fv_y;
	float	deltax;
	float	deltay;
	float	endh_x;
	float	endh_y;
	float	endv_x;
	float	endv_y;
	float	distx;
	float	disty;
	float	dist_true;
	char	texture;
}	t_ray;

typedef struct s_coord
{
	int	x;
	int	h;
	int	w_h;
}	t_coord;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	struct s_map	*map;
	struct s_player	*player;
	struct s_img	*mini_map;
	struct s_img	*main_screen;
	struct s_img	*north_texture;
	struct s_img	*south_texture;
	struct s_img	*east_texture;
	struct s_img	*west_texture;
	struct s_key	*key;
}	t_data;

#endif