/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:12:01 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/19 13:03:16 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Fill the map table.
 * 
 * @param data Struct that contain many information about the game.
 * @return t_map* A 2D array.
 */
t_map	*ft_filltable(t_data *data)
{
	t_map	*map;
	char	*line;
	int		x;
	
	x = 0;
	map = ft_calloc(1, sizeof(t_map));
	if(map == NULL)
		return (NULL);
	map->lines = ft_map_line_count(data);
	map->map =  ft_calloc(map->lines+1, sizeof(char *));
	if (map->map == NULL)
		return (NULL);
	ft_opener(data);
	line = get_next_line(data->map_fd);
	ft_remove_new_line(line);
	while(line != NULL)
	{
		map->map[x] = line;
		line = get_next_line(data->map_fd);
		ft_remove_new_line(line);
		x++;
	}
	close(data->map_fd);
	return (map);
}

/**
 * @brief Get the player postion on the map.
 * 
 * @param data 
 * @return int* The x y postion of the player.
 */
int *ft_P_position(t_data *data)
{
	int x;
	int y;
	static int res[2];

	y = 0;
	x = 0;
	while(data->map->map[x])
	{
		y = 0;
		while(data->map->map[x][y])
		{
			if(data->map->map[x][y] == 'P')
			{
				res[0] = x;
				res[1] = y;
				return (res);
			}
			y++;
		}
		x++;
	}
	res[0] = x;
	res[1] = y;
	return (res);
}

/**
 * @brief The parser function, it start the parsing functions for the rest of the programm.
 * 
 * @param data 
 */
void ft_parser(t_data *data)
{
	int *p_position;

	ft_opener(data);
	ft_chk_elements(data);
	data->map =  ft_filltable(data);
	if (data->map != NULL)
	{
		ft_chk_rect(data);
		ft_chk_surround_wall(data);
		ft_chk_min_elements(data);
		p_position = ft_P_position(data);
		data->p_x_pos = p_position[0];
		data->p_y_pos = p_position[1];
		ft_chk_map_validity(p_position,data);
	}
	ft_clean2dtable(data->map->map);
	ft_clean((char *)data->map);
}
