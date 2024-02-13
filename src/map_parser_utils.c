/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:20:06 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/13 13:10:46 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_opener(t_data *data)
{
	if(ft_chkdirectory(data->map_name) == -2)
	{
		ft_err_directory(data);
		exit(1);
	}
	else if (ft_chkfdvalid(data->map_name) == -2)
	{
		ft_err_filevalid(data);
		exit(1);
	}
	else
		data->map_fd = open(data->map_name,O_RDONLY);
}

void ft_remove_new_line(char *line)
{
	int len;
	
	if(line != NULL)
	{
		len = ft_strlen(line);
		if (line[len-1] == '\n')
			line[len-1] = '\0';
	}
}

int ft_map_line_count(t_data *data)
{
	char *res;
	int  x;
	
	x = 0;
	ft_opener(data);
	res = get_next_line(data->map_fd);
	while(res != NULL)
	{
		ft_clean(res);
		x++;
		res = get_next_line(data->map_fd);
	}
	close(data->map_fd);
	return (x);
}

int ft_count_elements(char **map, char element)
{
	int x;
	int y;
	int res;
	
	x = 0;
	y = 0;
	res = 0;
	while(map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if(map[x][y] == element)
				res++;
			y++;
		}
		x++;
	}
	return (res);
}

// FlOOD FILL a faire en recursive.
// LOGIC: Visiter en x+1 x-1 et y+1 y-1
	// Changer Si une case est differente de 1.
	// Si eguale a 1 alors return

void ft_floodfill(int x, int y,t_map *map)
{
	if ( map->map[x][y] == '1' || (size_t) y >= ft_strlen(map->map[x])
		|| y < 0 || x < 0 || x >= map->lines)
		return ;
	map->map[x][y] = '1';
	ft_floodfill(x,y + 1,map);
	ft_floodfill(x,y - 1,map);
	ft_floodfill(x + 1,y,map);
	ft_floodfill(x - 1,y,map);
}