/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:56:38 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 19:21:24 by amaatall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map	map;

	// read_map(argv[1]);
	map = mock_map();
	solve_map(map);
	print_grid(map.grid, map.rows, map.cols);
	print_grid(get_obstacles_grid(map), map.rows, map.cols);
	return (argc - argc);
}
