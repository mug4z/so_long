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


int ft_up(t_data *data)
{
    
}
// int ft_down()
// int ft_left()
// int ft_right()
int ft_keypress(int keycode, t_data *data)
{
    ft_printf("%d\n",keycode);
    if (keycode == l_esc)
    {
        mlx_destroy_window(data->mlx,data->window);
        ft_print_error("so_long",": Bye",data);
        exit(1);
    }
    if (keycode == l_w)
    {

    }
        
   return(0);
}
int ft_controls(t_data *data)
{
    mlx_hook(data->window,2, 0,ft_keypress,data);
    //mlx_hook(data->window,17,0,ft_buttonquit); // Quand appuyer sur le bouton exit quit
    
    return(0);
}
