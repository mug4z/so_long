/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:12:01 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/09 11:51:48 by tfrily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//  La carte comporte des element non valide.
// - La carte n'est pas rectangulaire.
// - La carte ne contient pas
// 	- 1 SORTIE MAX
// 	- 1 ITEM MIN
// 	- 1 POSITION DE DÉPART MAX.

// Les elements autorisés
	// 0 -> sols
	// 1 -> murs
	// C -> element a collecter
	// E -> pour la sortie
	// P -> position de départ du personnage.
	
// Check if map line too long str len on line if not the same size of the first one = ERROR

/**
 * @brief Check that only correct elements are on the map
 * 
 * @param fd 
 * @return int 
 */
int ft_elements(int fd)
{
	char *res;
	
	res = get_next_line(fd);
	while(res != NULL)
	{
		res = get_next_line(fd);
	}
	return (0);
}

void ft_parser(t_data *data)
{
	// ouvrir le fichier
	//Verifier que l'ouverture c'est bien passer.
	ft_opener(data);
	// Check que la map ne soit pas vide.
	
	ft_elements(data->map_fd);
}