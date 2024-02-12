/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:40:12 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/12 15:45:31 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_err_player(t_data *data)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(data->map_name, 2);
	ft_putstr_fd(": less or more than one player spawn\n", 2);
	ft_clean2dtable(data->map->map);
	ft_clean((char *)data);
}