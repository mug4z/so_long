/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:04:41 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/09 15:32:55 by tfrily           ###   ########.fr       */
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
