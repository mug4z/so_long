/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:53:33 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/07 14:43:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
  void *mlx;
  void *mlx_win;

  ft_printf("HELLO WORLD\n");

  mlx = mlx_init();
  mlx_win = mlx_new_window(mlx,1920,1080,"Hello World");
  mlx_loop(mlx);

  free(mlx);
  free(mlx_win);
	return (0);
}
