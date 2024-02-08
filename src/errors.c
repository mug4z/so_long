/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:59:21 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/08 18:39:21 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Functions to print error.


void ft_err_ext(t_data *data)
{	
	ft_putstr_fd("Error\n",2);
	ft_putstr_fd(data->map_name,2);
	ft_putstr_fd(": wrong extension",2);
	ft_clean((char *)data);
}