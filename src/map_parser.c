/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:12:01 by tfrily            #+#    #+#             */
/*   Updated: 2024/02/09 15:38:48 by tfrily           ###   ########.fr       */
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
t_map  *ft_filltable(t_data *data)
{
	// t_map *map;
	
	ft_opener(data);
	// line counter
	// Allocation memoire de mon table a 2d
	// While gnl pour remplir mes cellule + remove les \n
	
	
	// map = ft_calloc(1,sizeof(t_map));
	// map->map = ft_calloc(3,sizeof(char **));
}

void ft_parser(t_data *data)
{
	ft_opener(data);
	ft_chk_elements(data);
}