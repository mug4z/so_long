/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:34:17 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/15 18:17:59 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_up(t_data *data)
{	
    if(data->map->map[data->p_x_pos-1][data->p_y_pos] != '1')
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = '0';
        data->p_x_pos -= 1;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        ft_render_map(data);
    }
	
    return (0);
}
int ft_down(t_data *data)
{
    if(data->map->map[data->p_x_pos+1][data->p_y_pos] != '1')
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = '0';
        data->p_x_pos += 1;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        ft_render_map(data);
    }
    return (0);
}

int ft_right(t_data *data)
{
	if(data->map->map[data->p_x_pos][data->p_y_pos+1] != '1')
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = '0';
        data->p_y_pos += 1;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        ft_render_map(data);
    }
    return (0);
}

int ft_left(t_data *data)
{
	if(data->map->map[data->p_x_pos][data->p_y_pos-1] != '1')
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = '0';
        data->p_y_pos -= 1;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        ft_render_map(data);
    }
    return (0);
}

//ft_printf("%d\n",keycode);