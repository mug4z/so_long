/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:29:01 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/19 13:30:12 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Check if the extension of the given map is .ber
 * 
 * @param data 
 * @return int Return 0 NOK , 1 OK
 */
int	ft_chk_map_ext(t_data *data)
{
	int	len;

	if (data == NULL || data->map_name == NULL)
		return (-2);
	len = ft_strlen(data->map_name);
	while (data->map_name[len] != '.')
		len--;
	if (ft_strncmp(data->map_name + len, ".ber", len) == 0)
		return (1);
	return (-2);
}

/**
 * @brief Check if the file is a directory
 * 
 * @param path_file The arguments given by the user.
 * @return int -2 if it is a directory, 0 if it's not a directory
 */
int	ft_chkdirectory(char *path_file)
{
	if (open(path_file, O_DIRECTORY) > 0)
		return (-2);
	return (0);
}

/**
 * @brief check if the opening of the file is possible in read only
 * 
 * @param path_file The arguments given by the user.
 * @return int  -2 if NOK and 0 if ok
 */
int	ft_chkfdvalid(char *path_file)
{
	if (open(path_file, O_RDONLY) > 0)
		return (0);
	return (-2);
}

/**
 * @brief Check if the line contain accepted elements 
 * 
 * @param line 
 */
void	ft_chk_elements_line(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != 'C'
			&& line[x] != 'E' && line[x] != 'P')
		{
			ft_err_elements(line[x], line);
			exit(1);
		}
		x++;
	}
	ft_clean(line);
}

/**
 * @brief Checker function
 * 
 * @param data Struct that contain many information about the game.
 */
void	ft_checker(t_data *data)
{
	int	map_ext;

	map_ext = ft_chk_map_ext(data);
	if (map_ext == -2)
	{
		ft_err_ext(data);
		exit(1);
	}
	ft_parser(data);
}
