/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:40:12 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/19 14:37:36 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_err_player(t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(": less or more than one player spawn\n", 2);
	ft_clean2dtable(data->map->map);
	ft_clean((char *)data->map);
	ft_clean((char *)data);
}

void	ft_print_err(t_data *data, char *msg)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(msg, 2);
	if (data->map != NULL)
		ft_clean2dtable(data->map->map);
	ft_clean((char *)data->map);
	ft_clean((char *)data);
}

void	ft_print_error(char *what, char *msg, t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(what, 2);
	ft_putstr_fd(msg, 2);
	if (data->map != NULL)
		ft_clean2dtable(data->map->map);
	mlx_destroy_image(data->mlx, data->img_grass);
	mlx_destroy_image(data->mlx, data->img_tree);
	mlx_destroy_image(data->mlx, data->img_collec);
	mlx_destroy_image(data->mlx, data->img_exit);
	mlx_destroy_image(data->mlx, data->img_character);
	ft_clean((char *) data->map);
	ft_clean((char *)data);
}
