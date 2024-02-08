/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:29:01 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/08 18:38:05 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
// Check that the map name is correct

/**
 * @brief Check if the extension of the given map is .ber
 * 
 * @param data 
 * @return int Return 0 NOK , 1 OK
 */
int ft_chk_map_ext(t_data *data)
{
	int len;
	
	if(data == NULL || data->map_name == NULL)
		return (-2);
	len = ft_strlen(data->map_name);
	while (data->map_name[len] != '.')
		len--;	
	if(ft_strncmp(data->map_name+len,".ber",len) == 0)
		return (1);
	return (-2);
}
/**
 * @brief Checker
 * 
 * @param data 
 */
void ft_checker(t_data *data)
{
	int map_ext;
	
	map_ext = ft_chk_map_ext(data);
	if (map_ext == -2)
	{
		ft_err_ext(data);
		exit(1);
	}
}