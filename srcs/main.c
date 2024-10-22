/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:56:38 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/22 19:37:00 by lwillis          ###   ########.fr       */
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

void	make_map(char *map_str)
{
	t_legend	legend;
	t_map		map;

	legend = parse_legend(map_str);
	if (1 == legend.is_valid)
	{
		map = parse_map(map_str, legend);
		if (map.is_valid)
		{
			solve_map(&map);
			free_all(map);
		}
	}
	free(map_str);
}

int	main(int argc, char *argv[])
{
	char	*map_str;
	t_map	map;
	t_legend	legend;

	if (1 == argc)
	{
		//TODO Replace with stdin map
		map_str = file_to_str("maps/15-10-4");
		make_map(map_str);
	}
	else if (2 == argc)
	{
		//seg fault on no file
		map_str = file_to_str(argv[1]);
		make_map(map_str);
	}
	return (0);
}
