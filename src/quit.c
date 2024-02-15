/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:51 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/15 15:37:05 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_quit(t_data *data)
{
	ft_printf("Bye\n");
	if (data->map != NULL)
		ft_clean2dtable(data->map->map);
	mlx_destroy_image(data->mlx,data->img_grass);
	mlx_destroy_image(data->mlx,data->img_tree);
	mlx_destroy_image(data->mlx,data->img_collec);
	mlx_destroy_image(data->mlx,data->img_exit);
	mlx_destroy_image(data->mlx,data->img_character);
	ft_clean((char *) data->map);
	ft_clean((char *)data);
	exit(0);
}
