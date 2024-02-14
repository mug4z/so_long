/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:04:41 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/13 13:22:06 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Check that only correct elements are on the map and the map is not empty or file start with \n
 * 
 * @param fd 
 * @return int 
 */
void ft_chk_elements(t_data *data)
{
	char *res;
	
	res = get_next_line(data->map_fd);
	if(res == NULL)
	{
		ft_err_empty_map(data);
		exit(1);
	}
	ft_remove_new_line(res);
	while(res != NULL)
	{
		if(res[0] == '\0')
		{
			ft_err_invalid_map(data);
			exit(1);
		}
		ft_chk_elements_line(res);
		res = get_next_line(data->map_fd);
		ft_remove_new_line(res);
	}
	close(data->map_fd);
}

/**
 * @brief Check if the map is rectangular
 * 
 * @param data Struct that contain information about the map
 */
void ft_chk_rect(t_data *data)
{
	int col;
	int col2;
	int	x;

	x = 0;
	col = ft_strlen(data->map->map[x]);
	while (data->map->map[x++])
	{
		col2 = ft_strlen(data->map->map[x]);
		if ((col != col2 && data->map->map[x] != NULL)
			|| col == data->map->lines)
		{
			ft_err_not_rectangular(data);
			exit (1);
		}
	}
}

/**
 * @brief Check if the map is well close by walls
 * 
 * @param data 
 */
void ft_chk_surround_wall(t_data *data)
{
	int 	x;

	x = 0;
	while(data->map->map[0][x] && data->map->map[data->map->lines - 1][x])
	{
		if (data->map->map[0][x] != '1' || 
			data->map->map[data->map->lines - 1][x] != '1')
		{
			ft_err_surrounded_wall(data);
			exit(1);
		}
		x++;
	}
	x = 1;
	while(data->map->map[x])
	{
		if(data->map->map[x][0] != '1' || 
		   data->map->map[x][ft_strlen(data->map->map[x]) - 1] != '1')
		{
			ft_err_surrounded_wall(data);
			exit(1);
		}
		x++;
	}
}

/**
 * @brief Check if the required elements are 
 * 
 * @param data 
 */
void ft_chk_min_elements(t_data *data)
{
	if (ft_count_elements(data->map->map, 'C') < 1)
	{
		ft_err_not_engough_item(data);
		exit(1);			
	}
	if(ft_count_elements(data->map->map, 'E') != 1)
	{
		ft_err_exit(data);
		exit(1);
	}
	if(ft_count_elements(data->map->map, 'P') != 1)
	{
		ft_err_player(data);
		exit(1);
	}
}

void ft_chk_map_validity(int p_position[2],t_data *data)
{
	ft_floodfill(p_position[0],p_position[1],data->map);
	if(ft_count_elements(data->map->map, 'C') != 0 || ft_count_elements(data->map->map,'E') != 0)
	{
		ft_print_err(data,": is impossible to complete");
		exit(1);
	}
	
}

