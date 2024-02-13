/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:53:33 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/13 14:01:09 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// void my_mlx_pixel_put(t_img *data,int x, int y,int color)
// {
//     char *dst;

//     dst = data->addr + (y * data->size_line + x *(data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }
// Tree :  HAUT    30
//         LARGEUR 17
int main(int argc, char **argv)
{
    t_data *data;
    
    if (argc != 2 || argv[1][0] == '\0')
    {
      ft_printf("invalid arguments");
      return (1);
    }
    data = ft_calloc(1,sizeof(t_data));
    if (data == NULL)
      return (1);
    data->map_name = argv[1];
    data->map_fd = -1;
    ft_checker(data);
    ft_render(data);
    // After the map is well checked go render
    //ft_clean2dtable(data->map->map);
    ft_clean((char *)data->map);
    ft_clean((char *)data);
	return (0);
}
