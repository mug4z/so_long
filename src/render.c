/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:39:45 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/15 11:21:58 by tfrily           ###   ########.fr       */
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

void *ft_img_to_struct(t_data *data, char *file)
{
	void *img_ptr;
	
	if (open(file,O_RDONLY) < 0)
	{
		close(data->map_fd);
		ft_print_error(file,": file don't exist",data);
		exit(1);
	}
	img_ptr = mlx_xpm_file_to_image(data->mlx, file, &data->img_withd,
								&data->img_withd);
	if(img_ptr == NULL)
	{
		close(data->map_fd);
		ft_print_error(file,": couldn't load the image",data);
		exit(1);
	}
	return (img_ptr);
}

void ft_render(t_data *data)
{
	data->img_grass = ft_img_to_struct(data, 
						"./ressources/decor/xpm/Grass.xpm");
	 data->img_tree = ft_img_to_struct(data,
	 					"./ressources/decor/xpm/big_tree.xpm");
	data->img_collec = ft_img_to_struct(data,
						"./ressources/decor/xpm/collectible2.xpm");
	 data->img_exit = ft_img_to_struct(data,
	 					"./ressources/decor/xpm/exit.xpm");
	 data->img_character = ft_img_to_struct(data,
	 					"./ressources/decor/xpm/character.xpm");
	ft_render_grass(data);
	ft_render_item(data,data->img_tree,'1');
	ft_render_item(data,data->img_character,'P');
	ft_render_item(data,data->img_collec,'C');
	ft_render_item(data,data->img_exit,'E');
	//mlx_key_hook(data->window,ft_close,&data);
	
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