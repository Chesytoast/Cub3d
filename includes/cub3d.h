/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:59:56 by aabda             #+#    #+#             */
/*   Updated: 2023/09/29 14:02:00 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "./graphic.h"
# include "./enums.h"
# include "./colors.h"
# include "./structs.h"
# include "./errors.h"
# include <math.h>

//		utils/libft_utils.c
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(int fd, const char *s);
void	ft_putchar_fd(int fd, char c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_isdigit(int c);

//		utils/libft_utils2.c
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);

//		utils/libft_utils3.c
char	**ft_split(t_data *data, char const *s, char c);

//		utils/errors.c
void	errors(t_data *data, int err);
void	print_error_char_map(t_data *data);

//		utils/mlx_hook.c
void	init_key(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		mouse_hook(int keycode, t_data *data);
int		red_cross(t_data *data);

//		utils/utils.c
void	ft_free(void **value);
void	free_tab(char **map);
void	free_all(t_data *data);

//		utils/check.c
void	check_character_map_and_init_player_pos_y_x(t_data *data);
void	check_if_var_s_map_exist(t_data *data);
void	check_wall_map(t_data *data, char **map, int y, int x);
void	check_output_color_cf(t_data *data, char **tab);

//		utils/player.c
void	s_player_fill_pos_direction(t_data *data, int x, int y);

//		utils/map_utils.c
void	check_extension_map(t_data *data, const char *path);
size_t	size_of_file(t_data *data, const char *path);
void	fill_file_var(t_data *data, const char *path, \
		char **file, size_t size_file);
char	**copy_map(t_data *data);
void	convert_str_hex(t_data *data, char *color_fc, int i);

//		parsing/fill_struct_map.c
void	fill_params_map_var(t_data *data, char *file, size_t i, size_t save_i);
void	s_map_patern_fill_params(t_data *data, char **fill, \
		char *str, size_t *index);

//		parsing/fill_struct_map2.c
void	s_map_check_and_fill_params(t_data *data, char *file, size_t *i);

//		parsing/create_map_in_struct.c
void	create_map_in_struct(t_data *data, char *buffer, int i);

//		core/render.c
int		render(t_data *data);
void	render_map_border(t_data *data);
void	the_mlx_pixel_put(t_data *data, int x, int y, int color);
void	clean_minimap(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//		core/render2.c
void	ray_fct(t_data *data);

//		core/init_img.c
void	init_img(t_data *data);
void	init_textures(t_data *data);

//		core/moves.c
void	calculate_vector(t_data *data);
void	movement(t_data *data, float x, float y);
void	rotate(t_data *data);

//		core/ray.c
void	init_ray(float angle, t_ray *ray);
void	ray_collision(t_data *data, t_ray *ray);
void	collision_vertical(t_data *data, t_ray *ray);

//		core/ray_vertical.c
void	collision_vertical(t_data *data, t_ray *ray);

//		core/raycast.c
void	raycast(t_data *data, t_ray *ray, int x);

#endif