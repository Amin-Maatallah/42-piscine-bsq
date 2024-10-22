/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:56:38 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/22 20:39:21 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Frees any allocated memory */
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

/* Builds a map from a valid string */
void	make_map(char *map_str, char *filename)
{
	t_legend	legend;
	t_map		map;

	legend = parse_legend(map_str);
	if (1 == legend.is_valid)
	{
		map = parse_map(map_str, legend);
		if (map.is_valid)
		{
			map.filename = filename;
			solve_map(map);
			free_all(map);
		}
		else
			write(2, "map error\n", 10);
	}
	free(map_str);
}

/* No args = stdin, otherwise a list of map files */
int	main(int argc, char *argv[])
{
	char	*map_str;
	int		i;
	t_map	map;
	t_legend	legend;

	if (1 == argc)
	{
		//TODO Replace with stdin map
		map_str = file_to_str("maps/pdf");
		make_map(map_str, "maps/pdf");
	}
	else if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			map_str = file_to_str(argv[i]);
			if (NULL == map_str)
				write(2, "map error\n", 10);
			else
				make_map(map_str, argv[i]);
			i++;
		}
	}
	return (0);
}
