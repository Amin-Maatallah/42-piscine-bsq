/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:56:38 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 18:57:09 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
<<<<<<< HEAD
	if (1 == argc)
		solve_map(mock_map());
	else if (2 == argc)
		solve_map(read_map_file(argv[1]));
=======
	//read_map(argv[1]);
	t_map map = mock_map();
	solve_map(map);
	print_grid(map.grid, map.rows, map.cols);
	print_grid(get_obstacles_grid(map), map.rows, map.cols);
>>>>>>> 361e10a027e06c2df841783e5f87ddc55577d215
	return (argc - argc);
}
