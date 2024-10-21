/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:56:38 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 19:58:01 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>

void	free_all(t_map map)
{
	int	i;

	if (map.cols > 0)
	{
		i = 0;
		while (i < map.rows)
		{
			free(map.grid[i]);
			i++;
		}
		free(map.grid);
	}
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (1 == argc)
	{
		//TODO Replace with stdin map
		map = mock_map();
		solve_map(map);
	}
	else if (2 == argc)
	{
		map = read_map_file(argv[1]);
		solve_map(map);
		free_all(map);
	}
	return (0);
}
