/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:12:01 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/09 10:43:48 by tfrily           ###   ########.fr       */
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


// int ft_elemtents(int fd)
// {
	
// }

void ft_parser(t_data *data)
{
	char *res;
	// ouvrir le fichier
	ft_opener(data);
	//Verifier que l'ouverture c'est bien passer.
	res = get_next_line(data->map_fd);
}