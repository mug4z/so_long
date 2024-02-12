/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:53:55 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/12 12:46:49 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <stdio.h>

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

// Map Parser
void	ft_parser(t_data *data);
int		ft_map_line_count(t_data *data);

//Errors
void	ft_err_ext(t_data *data);
void	ft_err_directory(t_data *data);
void	ft_err_filevalid(t_data *data);
void	ft_err_elements(char c, char *line);
void	ft_err_empty_map(t_data *data);
void 	ft_err_invalid_map(t_data *data);
void	ft_err_not_rectangular(t_data *data);
void	ft_chk_surround_wall();

#endif
