/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:03:47 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/12 11:43:36 by tfrily           ###   ########.fr       */
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