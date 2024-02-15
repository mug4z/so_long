/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:12:01 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/15 11:46:51 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//  La carte comporte des element non valide.
// - La carte n'est pas rectangulaire.
// - La carte ne contient pas
// 	- 1 SORTIE MAX
// 	- 1 ITEM MIN
// 	- 1 POSITION DE DÉPART MAX.

// Les elements autorisés
	// 0 -> sols
	// 1 -> murs
	// C -> element a collecter
	// E -> pour la sortie
	// P -> position de départ du personnage.
	
// Check if map line too long str len on line if not the same size of the first one = ERROR

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
	map->map =  ft_calloc(map->lines+1, sizeof(char **));
	if (map->map == NULL)
		return (NULL);
	ft_opener(data);
	line = get_next_line(data->map_fd);
	ft_remove_new_line(line);
	while(line != NULL)
	{
		map->map[x++] = line;
		line = get_next_line(data->map_fd);
		ft_remove_new_line(line);
	}
	close(data->map_fd);
	return (map);
}
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

void ft_parser(t_data *data)
{
	int *p_position;

	ft_opener(data);
	ft_chk_elements(data);
	data->map =  ft_filltable(data);
	// FROM THIS POINT WHEN EXIT for ERROR DON'T FORGET TO FREE THE MAP AND THE DATA
	if (data->map != NULL)
	{
		ft_chk_rect(data);
		ft_chk_surround_wall(data);
		ft_chk_min_elements(data);
		p_position = ft_P_position(data);
		data->p_x_pos = p_position[0];
		data->p_x_pos = p_position[1];
		ft_chk_map_validity(p_position,data);
	}
	ft_clean2dtable(data->map->map);
}
