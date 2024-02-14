/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:39:45 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/14 11:03:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// render grass -> OK
// render tree  -> OK
// render collectible -> OK
// render exit ->
// render character -> OK
void ft_render_grass(t_data *data)
{
	int x;
	int y;

	x = 0;
	while(data->map->map[x])
	{
		y = 0;
		while (data->map->map[x][y])
		{
			mlx_put_image_to_window(data->mlx, data->window, data->img_grass, y*40,x*40);
			y++;
		}
		x++;
	}
}

void ft_render_item(t_data *data, void *img, char c)
{
	int x;
	int y;

	x = 0;
	while(data->map->map[x])
	{
		y = 0;
		while (data->map->map[x][y])
		{
			if (data->map->map[x][y] == c)
				mlx_put_image_to_window(data->mlx, data->window,img, y*40,x*40);
			y++;
		}
		x++;
	}
}
void ft_img_to_struct(t_data *data)
{
	char *grass;
	char *tree;
	char *collec;
	char *character;
	char *exit;
	// Faire

	grass = "./ressources/decor/xpm/Grass.xpm";
	tree  = "./ressources/decor/xpm/big_tree.xpm";
	collec = "./ressources/decor/xpm/collectible2.xpm";
	character = "./ressources/decor/xpm/character.xpm";
	exit = "./ressources/decor/xpm/exit.xpm";
	data->img_grass = mlx_xpm_file_to_image(data->mlx, grass,
					  &data->img_withd, &data->img_withd);
	data->img_tree  = mlx_xpm_file_to_image(data->mlx, tree,
					 &data->img_withd, &data->img_withd);
	data->img_collec  = mlx_xpm_file_to_image(data->mlx, collec,
					 &data->img_withd, &data->img_withd);
	data->img_character  = mlx_xpm_file_to_image(data->mlx, character,
						  &data->img_withd, &data->img_withd);
	data->img_exit  = mlx_xpm_file_to_image(data->mlx, exit,
						  &data->img_withd, &data->img_withd);
}

void ft_render(t_data *data)
{
	ft_opener(data);
	ft_filltable(data);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx,ft_strlen(data->map->map[0]) * 40,
			  				(data->map->lines * 40) , "so_long");
	ft_img_to_struct(data);
	ft_render_grass(data);
	ft_render_item(data,data->img_tree,'1');
	ft_render_item(data,data->img_character,'P');
	ft_render_item(data,data->img_collec,'C');
	ft_render_item(data,data->img_exit,'E');
	mlx_loop(data->mlx);
}
//   void *mlx;
//   void *mlx_win;
//   //t_img img;
//   int img_withd;
//   int img_height;
//   void *img;
//   void *img_grass;
//   `
//   char *relative_path_grass = "./ressources/decor/xpm/Grass.xpm";


//   ft_printf("HELLO WORLD\n");
//  //int acc = access(relative_path,F_OK);
//   mlx = mlx_init();
//   mlx_win = mlx_new_window(mlx, 560, 200, "so_long");
//   //img.img = mlx_new_image(mlx, 720, 720);
//   //img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
//   img = mlx_xpm_file_to_image(mlx, relative_path, &img_withd, &img_height);
//   img = mlx_xpm_file_to_image(mlx, relative_path, &img_withd, &img_height);
//   ft_printf("%d\n",img_height);
//   mlx_put_image_to_window(mlx, mlx_win, img_grass, 0, 0);
//   mlx_put_image_to_window(mlx, mlx_win, img, 5, 5);
//   mlx_loop(mlx);

//   free(mlx);
//   free(mlx_win);