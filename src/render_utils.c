/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:55:44 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/19 15:06:03 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Render the player in the window
 * 
 * @param data 
 * @param img A pointer to the player picture.
 */
void	ft_render_player(t_data *data, void *img)
{
	int	x;
	int	y;

	x = 0;
	while (data->map->map[x])
	{
		y = 0;
		while (data->map->map[x][y])
		{
			if (data->map->map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx,
					data->window, img, y * 40 - 5, x * 40 - 7);
			y++;
		}
		x++;
	}
}
