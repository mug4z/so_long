/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:53:55 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/08 18:39:40 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
typedef struct s_data
{
	int		map_fd;
	char 	*map_name;
}		t_data;

// map_parser_utils
void	ft_opener(t_data *data);

// checker
int		ft_chk_map_ext(t_data *data);
void 	ft_checker(t_data *data);

//Errors
void	ft_err_ext(t_data *data);

#endif
