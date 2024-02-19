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

/**
 * @brief Move the player up or down.
 * 
 * @param data  
 * @param x 1 is the distance the number move. By default 1 for 1 tile on the map.
 * @return int 
 */
int ft_process_up_down(t_data *data, int x)
{
    if(data->map->map[data->p_x_pos+x][data->p_y_pos] != '1')
    {
        if(data->map->map[data->p_x_pos+x][data->p_y_pos] == 'C')
        {
            ft_move(data,x,1);
            data->collec_count--;
        }
        else if(data->map->map[data->p_x_pos+x][data->p_y_pos] == 'E' 
                && data->collec_count == 0)
            ft_quit(data,"Congrats you beat the game !!!!");
        else if(data->map->map[data->p_x_pos + x][data->p_y_pos] == 'E')
        {
            data->e_x_pos = data->p_x_pos + x;
            data->e_y_pos = data->p_y_pos;
            ft_move(data,x,1);
        }   
        else
            ft_move(data,x,1);   
    }
    return(0);
}

/**
 * @brief Move the player left or right
 * 
 * @param data 
 * @param y 1 is the distance the number move. By default 1 for 1 tile on the map.
 * @return int 
 */
int ft_process_left_right(t_data *data, int y)
{
    if( data->map->map[data->p_x_pos][data->p_y_pos+y] != '1')
    {
        if(data->map->map[data->p_x_pos][data->p_y_pos+y] == 'C')
        {
            ft_move(data,y,0);
            data->collec_count--;
        }
        else if(data->map->map[data->p_x_pos][data->p_y_pos+y] == 'E' 
                && data->collec_count == 0)
            ft_quit(data,"Congrats you beat the game !!!!");
        else if(data->map->map[data->p_x_pos][data->p_y_pos+y] == 'E')
        {
            data->e_x_pos = data->p_x_pos;
            data->e_y_pos = data->p_y_pos + y;
            ft_move(data,y,0);
        }
        else
        {
            ft_move(data,y,0);
        }
    }
    return(0);
}

/**
 * @brief If the user enter the w a s d or ESC key. It's being process.
 * 
 * @param keycode The number that represent a key on the keyboard.
 * @param data Struct that contain many information about the game.
 * @return int 
 */
int ft_keypress(int keycode, t_data *data)
{
    if (keycode == l_esc)
    {
        mlx_destroy_window(data->mlx,data->window);
        ft_quit(data,"Bye\n");
    }
    if(keycode == l_w)
        ft_process_up_down(data, -1);
    if(keycode == l_a)
        ft_process_left_right(data, -1);
    if(keycode == l_s)
        ft_process_up_down(data, 1);
    if(keycode == l_d)
        ft_process_left_right(data, 1);
   return(0);
}

/**
 * @brief Handle the button quit on the window.
 * 
 * @param data Struct that contain many information about the game.
 * @return int 
 */
int ft_buttonquit(t_data *data)
{
    mlx_destroy_window(data->mlx,data->window);
    ft_quit(data,"Bye\n");
    return (0);
}

/**
 * @brief Handle when it's a key being press or the quit button being clicked.
 * 
 * @param data Struct that contain many information about the game.
 * @return int 
 */
int ft_controls(t_data *data)
{
    mlx_hook(data->window,2, 0,ft_keypress,data);
    mlx_hook(data->window,17,0,ft_buttonquit,data); // Quand appuyer sur le bouton exit quit
    return(0);
}
