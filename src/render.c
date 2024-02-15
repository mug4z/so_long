/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:39:45 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/15 16:55:21 by tfrily           ###   ########.fr       */
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
void ft_render_player(t_data *data, void *img)
{
	int x;
	int y;

	x = 0;
	while(data->map->map[x])
	{
		y = 0;
		while (data->map->map[x][y])
		{
			if (data->map->map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx, data->window,img, y*40-5,x*40-7);
			y++;
		}
		x++;
	}
}
void ft_render_map(t_data *data)
{
	ft_render_grass(data);
	ft_render_item(data,data->img_tree,'1');
	ft_render_player(data,data->img_character);
	ft_render_item(data,data->img_collec,'C');
	ft_render_item(data,data->img_exit,'E');
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
	ft_render_map(data);
}
