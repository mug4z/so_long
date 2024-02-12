/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:03:47 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/12 15:45:46 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_err_invalid_map(t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(": invalid map\n", 2);
	ft_clean((char *)data);
}

// Les prochain exit on doit aussi free la map en plus de data.
void ft_err_not_rectangular(t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(": is not rectangular\n", 2);
	ft_clean2dtable(data->map->map);
	ft_clean((char *)data);
}

void ft_err_surrounded_wall(t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(": is not surrounded by walls\n", 2);
	ft_clean2dtable(data->map->map);
	ft_clean((char *)data);
}

void ft_err_not_engough_item(t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(": not enough colectible\n", 2);
	ft_clean2dtable(data->map->map);
	ft_clean((char *)data);
}

void ft_err_exit(t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(": less or more than one exit\n", 2);
	ft_clean2dtable(data->map->map);
	ft_clean((char *)data);
}