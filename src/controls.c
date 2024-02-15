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


// Faire une fonction cell valid !!!
// process_move
int ft_process_move(t_data *data, int x, int y)
{
    if( data->map->map[data->p_x_pos+x][data->p_y_pos+y] != '1')
    {
        data->map->map[data->p_x_pos][data->p_y_pos] = '0';
        data->p_x_pos -= x;
        data->map->map[data->p_x_pos][data->p_y_pos] = 'P';
        ft_render_map(data);
    }
}

int ft_keypress(int keycode, t_data *data)
{
    ft_printf("%d\n",keycode);
    if (keycode == l_esc)
    {
        mlx_destroy_window(data->mlx,data->window);
        ft_quit(data);
    }
    if(keycode == l_w)
        ft_up(data);
    if(keycode == l_a)
        ft_left(data);
    if(keycode == l_s)
        ft_down(data);
    if(keycode == l_d)
        ft_right(data);
   return(0);
}

int ft_buttonquit(t_data *data)
{
    mlx_destroy_window(data->mlx,data->window);
    ft_quit(data);
    return (0);
}

int ft_controls(t_data *data)
{
    mlx_hook(data->window,2, 0,ft_keypress,data);
    mlx_hook(data->window,17,0,ft_buttonquit,data); // Quand appuyer sur le bouton exit quit
    return(0);
}
