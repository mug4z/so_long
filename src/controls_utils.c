/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:34:17 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/19 13:22:12 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Handle the move from the exit to print back the exit.
 * 
 * @param data Struct that contain many information about the game.
 * @param nb Equal to 1 or -1. It moves player or exit on the map.
 * @param direction 1 or 0. to separate the up left and down right.
 */
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
    ft_render_map(data,ft_itoa(data->step_count));   
}

/**
 * @brief Move the player accross the map.
 * 
 * @param data Struct that contain many information about the game.
 * @param nb Equal to 1 or -1. It moves player or exit on the map.
 * @param direction 1 or 0. to separate the up left and down right.
 */
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
    
    ft_render_map(data,ft_itoa(data->step_count));
}
// ft_printf("Movement : %d",data->step_count):