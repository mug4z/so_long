/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:04:41 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/12 12:46:19 by tfrily           ###   ########.fr       */
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

// Check if the map is rectangle
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

// Chek if the map is surrounded by 1.
void ft_chk_surround_wall()
{
	
}

// Check if the map contain the min required elements to finish.
