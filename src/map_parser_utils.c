/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:20:06 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/09 15:37:19 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_opener(t_data *data)
{
	if(ft_chkdirectory(data->map_name) == -2)
	{
		ft_err_directory(data);
		exit(1);
	}
	else if (ft_chkfdvalid(data->map_name) == -2)
	{
		ft_err_filevalid(data);
		exit(1);
	}
	else
		data->map_fd = open(data->map_name,O_RDONLY);
}

void ft_remove_new_line(char *line)
{
	int len;
	
	if(line != NULL)
	{
		len = ft_strlen(line);
		if (line[len-1] == '\n')
			line[len-1] = '\0';
	}
}

int ft_map_line_count(char *lin)
{
	
}