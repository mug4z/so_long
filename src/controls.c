/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:35:28 by marvin            #+#    #+#             */
/*   Updated: 2024/02/14 11:35:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_close(int keycode, t_data *data)
{
    ft_printf("%d\n",keycode);
    if ( keycode == l_esc)
        mlx_destroy_window(data->mlx,data->window);
   return(0);
}

// int ft_up()
// int ft_down()
// int ft_left()
// int ft_right()