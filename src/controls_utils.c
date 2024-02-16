/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:34:17 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/16 15:37:34 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void ft_move_from_exit(t_data *data, int nb, int direction)
{
    if (direction == 1)
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = 'E';
        data->p_x_pos += nb;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        data->step_count++;        
    }
    else
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = 'E';
        data->p_y_pos += nb;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        data->step_count++;
    }
    ft_printf("Number of movement %d\n",data->step_count);
    ft_render_map(data);
    
}

void ft_move(t_data *data, int nb, int direction)
{
    if (data->map->map[data->p_x_pos][data->p_y_pos] == 
            data->map->map[data->e_x_pos][data->e_y_pos])
    {
        ft_move_from_exit(data,nb,direction); 
        return;
    }
    if (direction == 1)
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = '0';
        data->p_x_pos += nb;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        data->step_count++;
    }
    else
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = '0';
        data->p_y_pos += nb;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        data->step_count++;
    }
    ft_printf("Number of movement %d\n",data->step_count);
    ft_render_map(data);
}
