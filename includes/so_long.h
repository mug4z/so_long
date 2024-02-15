/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:53:55 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/15 18:06:28 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
// # define l_esc 65307
// # define l_w	119
// # define l_a    97
// # define l_s    115
// # define l_d    100
# define l_esc  53
# define l_w	13
# define l_a    0
# define l_s    1
# define l_d    2

// faire une tab char ** qui contient la map
typedef struct s_map
{
	char	**map;
	int		lines;
}			t_map;

//char	wrong_element;
typedef struct s_data
{
	int		map_fd;
	char 	*map_name;
	t_map	*map;
	void	*mlx;
	void	*window;
	void	*img_grass;
	void	*img_tree;
	void	*img_collec;
	void	*img_exit;
	void	*img_character;
	int		p_x_pos;
	int		p_y_pos;
	int		img_withd;
	int		img_height;
	int		step_count;
	int		collec_count;
}			   t_data;

// map_parser_utils
void	ft_opener(t_data *data);
void 	ft_remove_new_line(char *line);

// checker
int		ft_chk_map_ext(t_data *data);
void 	ft_checker(t_data *data);
int		ft_chkdirectory(char *path_file);
int		ft_chkfdvalid(char *path_file);
void	ft_chk_elements_line(char *line);

// checker_utils
void	ft_chk_elements(t_data *data);
void 	ft_chk_rect(t_data *data);
void 	ft_chk_surround_wall(t_data *data);
void 	ft_chk_min_elements(t_data *data);
int		ft_count_elements(char **map, char element);
void 	ft_chk_map_validity(int p_position[2],t_data *data);

// Map Parser
void	ft_parser(t_data *data);
t_map	*ft_filltable(t_data *data);
int		ft_map_line_count(t_data *data);
void	ft_floodfill(int x, int y,t_map *map);

//Errors
void 	ft_print_err(t_data *data, char *msg);
void 	ft_print_error(char *what, char *msg, t_data *data);
void	ft_err_ext(t_data *data);
void	ft_err_directory(t_data *data);
void	ft_err_filevalid(t_data *data);
void	ft_err_elements(char c, char *line);
void	ft_err_empty_map(t_data *data);
void 	ft_err_invalid_map(t_data *data);
void	ft_err_not_rectangular(t_data *data);
void 	ft_chk_surround_wall(t_data *data);
void 	ft_err_surrounded_wall(t_data *data);
void	ft_err_not_engough_item(t_data *data);
void	ft_err_exit(t_data *data);
void 	ft_err_player(t_data *data);

// Renders
void ft_render(t_data *data);
void ft_render_map(t_data *data);

// Controls
int ft_keypress(int keycode, t_data *data);
int ft_controls(t_data *data);
int ft_process_move(t_data *data, int x, int y);

//Controls utils
int ft_up(t_data *data);
int ft_down(t_data *data);
int ft_right(t_data *data);
int ft_left(t_data *data);
//quit
void ft_quit(t_data *data);


#endif
