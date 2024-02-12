/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:53:33 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/12 11:34:37 by tfrily           ###   ########.fr       */
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
    // Checker
    ft_checker(data);
    // Opener in parser_utils
    // Parser
    // After the map is well checked go render
    
    ft_clean2dtable(data->map->map);
    ft_clean((char *)data->map);
    ft_clean((char *)data);
    

	return (0);
}
//   void *mlx;
//   void *mlx_win;
//   //t_img img;
//   int img_withd;
//   int img_height;
//   void *img;
//   void *img_grass;
//   char *relative_path = "./ressources/decor/xpm/tree.xpm";
//   char *relative_path_grass = "./ressources/decor/xpm/Grass.xpm";
  

//   ft_printf("HELLO WORLD\n");
//  //int acc = access(relative_path,F_OK);
//   mlx = mlx_init();
//   mlx_win = mlx_new_window(mlx, 560, 200, "so_long");
//   //img.img = mlx_new_image(mlx, 720, 720);
//   //img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
//   img = mlx_xpm_file_to_image(mlx, relative_path, &img_withd, &img_height);
//   img_grass = mlx_xpm_file_to_image(mlx, relative_path_grass, &img_withd, &img_height);
//   ft_printf("%d\n",img_height);
//   mlx_put_image_to_window(mlx, mlx_win, img_grass, 0, 0);
//   mlx_put_image_to_window(mlx, mlx_win, img, 5, 5);
//   mlx_loop(mlx);

//   free(mlx);
//   free(mlx_win);