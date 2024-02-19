/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:53:33 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/19 13:23:25 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Main function for the so_long game. 
 *        Failed directly if the arguments are not equal to two.
 * 
 * @param argc  The number of arguments
 * @param argv  The arguments
 * @return int 
 */
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || argv[1][0] == '\0')
	{
		ft_printf("invalid arguments");
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (1);
	data->map_name = argv[1];
	data->map_fd = -1;
	ft_checker(data);
	data->map = ft_filltable(data);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, ft_strlen(data->map->map[0]) * 40,
			(data->map->lines * 40), "so_long");
	data->step_count = 0;
	data->collec_count = ft_count_elements(data->map->map, 'C');
	data->e_x_pos = 0;
	data->e_y_pos = 0;
	ft_render(data);
	ft_controls(data);
	mlx_loop(data->mlx);
	return (0);
}
